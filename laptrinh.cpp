import { useEffect, useState } from "react";

export default function QuizPage() {
  const [questions, setQuestions] = useState([]);

  useEffect(() => {
    fetch("http://localhost:3000/api/questions")
      .then(res => res.json())
      .then(data => {
        console.log("DATA API:", data); // 👈 kiểm tra
        setQuestions(data);
      });
  }, []);

  return (
    <div>
      <h1>📝 Làm bài trắc nghiệm</h1>

      {questions.map((q, index) => (
        <div key={q.question_id} style={{ marginBottom: 20 }}>
          {/* ✅ CÂU HỎI */}
          <h3>
            {index + 1}. {q.content}
          </h3>

          {/* ✅ ĐÁP ÁN */}
         {questions.map((q, index) => (
  <div key={q.question_id} style={{ marginBottom: 24 }}>

    {/* ✅ CÂU HỎI */}
    <h3>
      {index + 1}. {q.content}
    </h3>

    {/* ✅ ĐÁP ÁN */}
    {q.answers.map(a => (
      <label key={a.answer_id} style={{ display: "block", marginLeft: 16 }}>
        <input
          type="radio"
          name={`question_${q.question_id}`}
          value={a.answer_id}
        />
        {a.content}
      </label>
    ))}
  </div>
))}

        </div>
      ))}
    </div>
  );
}
