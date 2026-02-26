const axios = require("axios");

async function aiDetection(text) {
  const response = await axios.post(
    "https://api-inference.huggingface.co/models/openai-detector",
    { inputs: text },
    { headers: { Authorization: `Bearer ${process.env.HF_API_KEY}` } }
  );

  const score = response.data[0]?.score || 0;
  return {
    verdict: score > 0.7 ? "Likely AI-Generated" : "Likely Human-Written",
    confidence: score
  };
}

module.exports = aiDetection;