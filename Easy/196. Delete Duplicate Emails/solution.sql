/* 
 Please write a DELETE statement and DO NOT write a SELECT statement.
 Write your T-SQL query statement below
 */
Delete  p1  
From    Person p1
Where   id Not In   (   Select min(id) 
                        From Person
                        Group by Person.email
                    )