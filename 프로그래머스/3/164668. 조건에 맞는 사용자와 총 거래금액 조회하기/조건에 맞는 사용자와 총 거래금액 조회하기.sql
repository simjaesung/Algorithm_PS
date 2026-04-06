-- 코드를 입력하세요
SELECT
    U.USER_ID,
    U.NICKNAME,
    sum(B.PRICE) TOTAL_SALES
from USED_GOODS_USER U
join USED_GOODS_BOARD B
on U.USER_ID = B.WRITER_ID
where B.STATUS = 'DONE'
group by U.USER_ID
having sum(B.PRICE) >= 700000
order by TOTAL_SALES;