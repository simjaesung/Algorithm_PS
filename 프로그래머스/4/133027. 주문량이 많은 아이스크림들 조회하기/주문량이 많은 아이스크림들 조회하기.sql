-- 코드를 입력하세요
#July의 pk SHIPMENT_ID
#FIRST_HALF pk FLAVOR
select A.FLAVOR
from (select FLAVOR, sum(TOTAL_ORDER) s1 from FIRST_HALF group by FLAVOR) A
join (select FLAVOR, sum(TOTAL_ORDER) s2 from JULY group by FLAVOR) B
on A.FLAVOR = B.FLAVOR
order by s1+s2 desc limit 3;