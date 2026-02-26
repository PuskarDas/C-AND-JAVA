import { useState } from "react";
import ResultCard from "../components/ResultCard";

export default function Home() {
  const [text, setText] = useState("");
  const [result, setResult] = useState(null);

  const verifyContent = async () => {
    const res = await fetch("http://localhost:5000/api/verify", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ text })
    });
    const data = await res.json();
    setResult(data);
  };

  return (
    <div style={{ padding: "2rem" }}>
      <h1>Content Verifier MVP</h1>
      <textarea
        rows="6"
        cols="60"
        value={text}
        onChange={(e) => setText(e.target.value)}
        placeholder="Paste article text here..."
      />
      <br />
      <button onClick={verifyContent}>Verify</button>
      {result && <ResultCard result={result} />}
    </div>
  );
}