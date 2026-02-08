/* Write your T-SQL query statement below */

With no_duplicate As
(
    Select  Distinct *
    From    Activities
)

Select      sell_date, Count(Distinct product) as num_sold, STRING_AGG(product, ',') WITHIN GROUP (ORDER BY product) as products
From        no_duplicate
Group By    sell_date
Order By    sell_date