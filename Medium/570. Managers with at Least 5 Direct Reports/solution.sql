/* Write your T-SQL query statement below */

SELECT      Employee.name
FROM        Employee
WHERE       Employee.id IN (
    SELECT      E.managerId
    FROM        Employee E
    GROUP BY    E.managerId
    HAVING      COUNT(managerId) >= 5
)
