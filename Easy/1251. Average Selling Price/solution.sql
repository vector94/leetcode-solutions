/* Write your T-SQL query statement below */

SELECT      P.product_id, 
            CASE 
                WHEN SUM(U.units) IS NULL THEN 0
                ELSE ROUND(SUM(P.price * U.units) / (SUM(U.units) * 1.0), 2) 
            END AS average_price
FROM        Prices P
LEFT JOIN   UnitsSold U 
ON          P.product_id = U.product_id
AND         U.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY    P.product_id