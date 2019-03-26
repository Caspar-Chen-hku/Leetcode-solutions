# Write your MySQL query statement below
SELECT MAX(Salary) AS 'SecondHighestSalary'
FROM (
    SELECT Salary
    FROM Employee as e2
    WHERE Salary NOT IN (
        SELECT MAX(Salary)
        FROM Employee as e1
    )
) AS r;