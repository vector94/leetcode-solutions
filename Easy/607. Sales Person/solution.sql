/* Write your T-SQL query statement below */
SELECT      name
FROM        SalesPerson
WHERE       name NOT IN (
    SELECT      S.name
    FROM        Orders O
    RIGHT JOIN  SalesPerson S on O.sales_id = S.sales_id
    LEFT JOIN   Company C on O.com_id = C.com_id
    WHERE       C.name = 'RED'
)
