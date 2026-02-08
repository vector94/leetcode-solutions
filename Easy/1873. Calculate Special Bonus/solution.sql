/* Write your T-SQL query statement below */

Select      employee_id, salary as bonus
From        Employees
where       employee_id % 2 != 0 And name Not Like 'M%'

Union

Select      employee_id, 0 as bonus
From        Employees
where       employee_id % 2 = 0 Or name Like 'M%'

