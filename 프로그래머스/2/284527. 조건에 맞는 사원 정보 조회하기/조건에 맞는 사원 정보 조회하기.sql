-- 코드를 작성해주세요
select 
    sum(G.SCORE) as SCORE, 
    E.EMP_NO,
    E.EMP_NAME,
    E.POSITION,
    E.EMAIL
from HR_EMPLOYEES E
join HR_GRADE G
on E.EMP_NO = G.EMP_NO
group by G.EMP_NO
order by SCORE desc limit 1;
    