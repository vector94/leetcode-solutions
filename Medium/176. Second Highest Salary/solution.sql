/* Write your T-SQL query statement below */
SELECT ISNULL(
    (
        SELECT      DISTINCT salary
        FROM        Employee
        ORDER BY    salary DESC
        OFFSET 1 ROWS
        FETCH NEXT 1 ROWS ONLY
    ), NULL
) AS SecondHighestSalary