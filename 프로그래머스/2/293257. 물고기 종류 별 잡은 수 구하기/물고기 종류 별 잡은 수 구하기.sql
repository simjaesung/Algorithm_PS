-- 코드를 작성해주세요
select 
    count(*) FISH_COUNT,
    I.FISH_NAME
from FISH_NAME_INFO I
join FISH_INFO N
on I.FISH_TYPE = N.FISH_TYPE
group by I.FISH_TYPE, I.FISH_NAME
order by FISH_COUNT desc;