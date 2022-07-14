/*
Two operations of DBMS
- storing
- query
- security constraints, etc

Entities:  about what r u storing data
eg: Student is an entity, so we can have a DB table containing name, student_roll_no and other params

Attributes/Fields: What data about entities are u storing
eg: for coutse enrollment: course_id, student_roll_no

student_roll_no is common in both student and course_enrollment table, so there is a relation b/w them

So a DBMS which stores data in form of entities and attr and relations between them can be known as R-DBMS
eg: MySQL, PostgresSQL

SQL - structured query language
query: statement that we use to fetch data from R-DBMS
clause: WHERE, GROUP BY, HAVING, ORDER BY
WHERE - filter records based on some conditions
ORDER BY - arrange or sorts the data by some criteria
GROUP BY - mostly associated with aggregate func 
    like SUM,  MIN, MAX or compute on large amount of data and return a res
HAVING - filter on aggregate func
*/

-- basic select query eg
select fname, lname
from students
where id = 1

-- sub-query
-- you need to give degree to students who r going to pass
-- Students: id, name, batch
-- Failed_Students: id
select id 
from students
where batch=2020 
and 
id not in (select id from Failed_Students)

-- Types of nested statements: 
-- co-related: subquery is not independent but needs main query to execute itself
-- non-corelated: main and subqueries are both independent

-- order by eg
-- if in a restrautent website, user selects to filter dishes based on the price
select food_id 
from food_table
order by price 

-- group by eg
-- you need to return those count of students who do not live in India, eg USA, UK, etc
select count(student_id), country
from students 
where country!='IN'
group by country
-- will return 
-- 2 | USA
-- 1 | UK

-- having eg
-- display only those countries where students do not live in india and are >1
select count(student_id), country
from students 
where country!='IN'
group by country
having count(id)>1

/*
Function in SQL:

UNION: returns union of two querysets and
returns duplicate only once 

UNION ALL: returns union of two querysets and
but keeps the duplicates

MINUS: returns union excluding common elements from both querysets 

INTERSECT: returns common values present in both querysets
*/

-- taking above eg
-- you need to give degree to students who r going to pass
select student_name from student
minus 
select name from Failed_Students

-- return every member of university
select name from Students
union
select name from employees
