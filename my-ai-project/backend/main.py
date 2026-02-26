from fastapi import FastAPI
from fastapi.responses import StreamingResponse
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
import ollama

app = FastAPI()

# Allows your Frontend to talk to this Backend
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
)

class ChatRequest(BaseModel):
    model: str = "llama3"
    prompt: str

@app.post("/chat")
async def chat_endpoint(request: ChatRequest):
    def generate():
        # This streams the response word-by-word
        stream = ollama.chat(
            model=request.model,
            messages=[{'role': 'user', 'content': request.prompt}],
            stream=True,
        )
        for chunk in stream:
            yield chunk['message']['content']

    return StreamingResponse(generate(), media_type="text/plain")