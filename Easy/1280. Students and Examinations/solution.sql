/* Write your T-SQL query statement below */

SELECT      ST.student_id, ST.student_name, SB.subject_name, COUNT(E.student_id) attended_exams
FROM        Students ST
CROSS JOIN  Subjects SB
LEFT JOIN   Examinations E ON ST.student_id = E.student_id AND SB.subject_name = E.subject_name
GROUP BY    ST.student_id, ST.student_name, SB.subject_name
ORDER BY    ST.student_id, SB.subject_name
