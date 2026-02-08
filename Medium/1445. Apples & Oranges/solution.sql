/* Write your T-SQL query statement below */

SELECT
    S1.sale_date,
    S1.sold_num - S2.sold_num AS diff
FROM Sales AS S1
INNER JOIN (
    SELECT 
        sale_date,
        fruit,
        sold_num
    FROM Sales AS SQ
    WHERE SQ.fruit = 'oranges'
) AS S2
ON S1.sale_date = S2.sale_date
WHERE S1.fruit = 'apples'