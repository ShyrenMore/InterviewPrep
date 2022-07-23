-- https://leetcode.com/problems/second-highest-salary/

-- create dataset excluding first highest sal 
-- and then apply that max on that
select max(salary) as SecondHighestSalary
from Employee 
where salary not in (
    select max(salary) from Employee
);