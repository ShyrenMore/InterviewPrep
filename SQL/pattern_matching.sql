-- use like operator
-- %: remaining chars 
-- _: one char
-- eg
select ename from emp 
where ename like 'M%'

-- will display name of employees which start with M

-- eg2
-- Display name of employees and hiredates who joined in dec
select ename, hiredate from emp 
where hiredate like '%DEC%';