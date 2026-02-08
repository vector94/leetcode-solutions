Select      d.name As Department,
            e.name As Employee,
            e.salary AS Salary
From        Employee e
Join        Department d On e.departmentId = d.id
Where       e.salary = (
                        Select      Max(salary)
                        From        Employee
                        Where       departmentId = e.departmentId
                        )