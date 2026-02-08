/* Write your T-SQL query statement below */

DECLARE @totalUser INT;
SET @totalUser = (SELECT COUNT(*) FROM Users);

SELECT      R.contest_id, ROUND((COUNT(U.user_id) * 1.0 / @totalUser) * 100, 2) AS percentage
FROM        Register R
LEFT JOIN   Users U ON U.user_id = R.user_id
GROUP BY    R.contest_id 
ORDER BY    percentage DESC, R.contest_id ASC
