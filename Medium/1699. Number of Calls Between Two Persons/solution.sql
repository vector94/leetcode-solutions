/* Write your T-SQL query statement below */
WITH CTE AS(
    SELECT  from_id, to_id, duration
    FROM    Calls
    WHERE   from_id < to_id

    UNION ALL

    SELECT  to_id, from_id, duration
    FROM    Calls
    Where   to_id < from_id
)

SELECT
from_id         AS person1,
to_id           AS person2,
COUNT(from_id)  AS call_count,
SUM(duration)   AS total_duration
FROM        CTE
GROUP BY    from_id, to_id