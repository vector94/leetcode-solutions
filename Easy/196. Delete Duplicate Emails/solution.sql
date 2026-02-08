/* 
 Please write a DELETE statement and DO NOT write a SELECT statement.
 Write your T-SQL query statement below
 */


DELETE    Person
WHERE   id NOT IN   (
                        SELECT      MIN(id)
                        FROM        Person
                        GROUP BY    email
                    )