/* Write your T-SQL query statement below */
SELECT      activity_date AS day,
            COUNT(DISTINCT(user_id)) AS active_users
FROM        Activity
WHERE       DATEDIFF(day, activity_date, '2019-07-27') >= 0 AND DATEDIFF(day, activity_date, '2019-07-27') < 30
GROUP BY    activity_date