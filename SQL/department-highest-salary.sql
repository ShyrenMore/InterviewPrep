-- https://leetcode.com/problems/department-highest-salary/

-- find max sal 
-- we are categorising by dept so use group by 
-- psedo code
select max(sal), deptno
from employees
group by deptno; 



-- use alias(AS) for proper op
-- we find max sal for each dept in Employee table
-- then we do inner join on both tables
SELECT D.Name AS Department ,E.Name AS Employee ,E.Salary 
from 
	Employee E,
	Department D 
WHERE E.DepartmentId = D.id 
AND 
(DepartmentId,Salary) in 
  (
    SELECT DepartmentId,max(Salary) 
    FROM Employee 
    GROUP BY DepartmentId
);