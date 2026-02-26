from fastapi import APIRouter, HTTPException
from pydantic import BaseModel
from app.services.fact_check import fact_check_text
from app.services.ai_detection import detect_ai_text
import logging

router = APIRouter()
logger = logging.getLogger("uvicorn.error")

class VerifyRequest(BaseModel):
    text: str

@router.post("/")
async def verify(req: VerifyRequest):
    text = req.text.strip()
    if not text:
        raise HTTPException(status_code=400, detail="No text provided")

    # Call fact-check service
    try:
        fact_result = await fact_check_text(text)
    except Exception as e:
        logger.exception("Fact check failed")
        fact_result = {"verdict": "Error", "sources": [], "error": str(e)}

    # Call AI detection service
    try:
        ai_result = await detect_ai_text(text)
    except Exception as e:
        logger.exception("AI detection failed")
        ai_result = {"verdict": "Error", "confidence": 0.0, "error": str(e)}

    # Simple combined verdict logic
    if fact_result.get("verdict") == "Needs Verification":
        verdict = "Needs Verification"
    elif ai_result.get("verdict") == "Likely AI-Generated":
        verdict = "Likely AI-Generated"
    else:
        verdict = "Likely Authentic"

    return {
        "verdict": verdict,
        "factCheck": fact_result,
        "aiDetection": ai_result
    }