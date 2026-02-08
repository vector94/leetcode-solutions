/* Write your T-SQL query statement below */
Select      stock_name, 
            Sum(IIF(operation = 'Sell', price, 0)) - Sum(IIF(operation = 'Buy', price, 0))
            As capital_gain_loss
From        Stocks
Group By    stock_name