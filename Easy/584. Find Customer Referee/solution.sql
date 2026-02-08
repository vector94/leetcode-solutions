/* Write your T-SQL query statement below */

Select  name
From    Customer
Where   referee_id != 2 Or referee_id IS NULL;