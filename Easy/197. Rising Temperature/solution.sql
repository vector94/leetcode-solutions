/* Write your T-SQL query statement below */
SELECT      Weather.id AS Id
FROM        Weather
JOIN        Weather W ON DATEDIFF(day, W.recordDate, Weather.recordDate) = 1 AND Weather.temperature > W.temperature