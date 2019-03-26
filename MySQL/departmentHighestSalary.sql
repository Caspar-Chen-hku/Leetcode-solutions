SELECT d.Name AS Department, e.Name AS Employee, e.Salary
FROM Employee e, Department d, (
    SELECT MAX(Salary) AS Sal, DepartmentId
    FROM Employee
    GROUP BY DepartmentId  
) r
WHERE e.DepartmentId = d.Id
AND d.Id = r.DepartmentId
AND e.Salary = r.Sal;