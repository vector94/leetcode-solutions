/* Write your T-SQL query statement below */
Select      customer_id, Count(V.visit_id) as count_no_trans
From        Visits as V
Left Join   Transactions T On V.visit_id = T.visit_id
Where       transaction_id Is null
Group By    customer_id