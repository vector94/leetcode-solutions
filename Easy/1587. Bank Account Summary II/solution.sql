/* Write your T-SQL query statement below */

Select      name, Sum(amount) as balance
From        Users as U
Join        Transactions as T on U.account = T.account
Group By    name
Having      Sum(amount) > 10000