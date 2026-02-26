const axios = require("axios");

async function factCheck(text) {
  const apiKey = process.env.GOOGLE_FACTCHECK_API_KEY;
  const url = `https://factchecktools.googleapis.com/v1alpha1/claims:search?query=${encodeURIComponent(text)}&key=${apiKey}`;

  const response = await axios.get(url);
  if (response.data.claims && response.data.claims.length > 0) {
    return {
      verdict: "Needs Verification",
      sources: response.data.claims.map(c => c.claimReview[0].publisher.name)
    };
  }
  return { verdict: "Likely Authentic", sources: [] };
}

module.exports = factCheck;