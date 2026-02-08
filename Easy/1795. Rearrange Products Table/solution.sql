select  product_id, 'store1' As store, store1 as price
From    Products
where   store1 is not null

Union

select  product_id, 'store2' As store, store2 as price
From    Products
where   store2 is not null

Union

select  product_id, 'store3' As store, store3 as price
From    Products
where   store3 is not null