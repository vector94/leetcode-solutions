/* Write your T-SQL query statement below */

Select      name, IIF(Sum(distance) Is null, 0, Sum(distance)) As travelled_distance
From        Users As U
Left Join   Rides As R On U.id = R.user_id
Group By    name
Order By    Sum(distance) DESC