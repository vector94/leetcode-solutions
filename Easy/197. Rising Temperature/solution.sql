/* Write your T-SQL query statement below */

SELECT      T.id AS Id
FROM        Weather T
CROSS JOIN  Weather Y
WHERE       DATEDIFF(day, Y.recordDate, T.recordDate) = 1 AND T.temperature > Y.temperature   