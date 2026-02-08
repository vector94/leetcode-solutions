Select      e.name as Employee
From        Employee e
Where       e.salary >  (
                        Select  Employee.salary
                        From    Employee
                        Where   Employee.id = e.managerId
                        )