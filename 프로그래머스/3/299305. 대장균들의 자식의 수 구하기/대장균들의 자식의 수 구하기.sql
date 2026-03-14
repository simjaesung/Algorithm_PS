-- 코드를 작성해주세요
select
    P.ID,
    count(C.ID) CHILD_COUNT
from ECOLI_DATA P
left join ECOLI_DATA C
on P.ID = C.PARENT_ID
group by P.ID
order by P.ID;