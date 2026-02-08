/* Write your T-SQL query statement below */
SELECT
CASE
    WHEN E.employee_id IS NULL THEN S.employee_id
    ELSE    E.employee_id
END AS employee_id
FROM        Employees E
FULL OUTER JOIN  Salaries S ON E.employee_id = S.employee_id
WHERE       E.name IS NULL OR S.salary IS NULL
ORDER BY    employee_id