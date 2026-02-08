/* Write your T-SQL query statement below */
SELECT  name AS Customers
FROM    Customers AS C 
WHERE   C.id NOT IN (
    SELECT  customerId
    FROM    Orders
)