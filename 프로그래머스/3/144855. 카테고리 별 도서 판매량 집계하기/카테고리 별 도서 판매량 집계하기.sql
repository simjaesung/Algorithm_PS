-- 코드를 입력하세요
SELECT
    B.CATEGORY,
    sum(S.SALES) TOTAL_SALES
from BOOK B
join BOOK_SALES S
on B.BOOK_ID = S.BOOK_ID
where S.SALES_DATE >= '2022-01-01' and S.SALES_DATE <= '2022-01-31'
group by B.CATEGORY
order by B.CATEGORY;