-- https://leetcode.com/problems/duplicate-emails/
select email as Email  
from Person
group by email 
having count(*)>1;