/* Write your T-SQL query statement below */

SELECT  product_id
FROM    Products P
WHERE   P.low_fats = 'Y' AND P.recyclable = 'Y'
