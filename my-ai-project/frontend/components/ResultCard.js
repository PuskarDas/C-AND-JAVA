export default function ResultCard({ result }) {
  return (
    <div style={{ marginTop: "2rem", padding: "1rem", border: "1px solid #ccc" }}>
      <h2>Verdict: {result.verdict}</h2>
      <p><strong>Fact Check Sources:</strong> {result.factCheck.sources.join(", ") || "None found"}</p>
      <p><strong>AI Detection:</strong> {result.aiDetection.verdict} (Confidence: {result.aiDetection.confidence})</p>
    </div>
  )
}