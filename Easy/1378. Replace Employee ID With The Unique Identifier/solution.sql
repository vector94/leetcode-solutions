/* Write your T-SQL query statement below */

SELECT      unique_id, name
FROM        Employees E
LEFT JOIN   EmployeeUNI EN ON E.id = EN.id       
