-- https://www.youtube.com/watch?v=ZhcKee2weD4&list=PLqM7alHXFySGweLxxAdBDK1CcDEgF-Kwx&index=3
select * from 
(
    select empno, ename, sal, rownum rn 
    from  emp 
    order by empno
)
where mod(rn, 2) = 0;

-- mod(rn, 2) = 0 will display even records
-- mod(rn, 2) != 0 will diplay odd records 