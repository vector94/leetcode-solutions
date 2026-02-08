/* Write your T-SQL query statement below */

SELECT      Q.query_name, 
            ROUND(SUM((Q.rating * 1.0) / Q.position) / COUNT(Q.query_name), 2) AS quality,
            ROUND((
                SELECT COUNT(query_name) 
                FROM   Queries
                WHERE  query_name = Q.query_name AND rating < 3
            ) * 1.0 / COUNT(Q.query_name) * 100, 2) AS poor_query_percentage
FROM        Queries Q
GROUP BY    Q.query_name
