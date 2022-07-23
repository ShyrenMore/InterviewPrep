-- https://www.youtube.com/watch?v=zajIPJwLb78&list=PLqM7alHXFySGweLxxAdBDK1CcDEgF-Kwx&index=4
-- count func will tell use no of freq
-- we need to group our data based on empname
-- and finally we only want to see duplucate i.e count>1
-- when u use group by, you can't use WHere clause, you need to use having clause
select ename, count(*)
from emp 
group by ename; 
having count(*)>1;