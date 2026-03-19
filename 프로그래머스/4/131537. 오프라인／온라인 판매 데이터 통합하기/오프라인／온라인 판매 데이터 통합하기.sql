-- 코드를 입력하세요
SELECT
    DATE_FORMAT(SALES_DATE, '%Y-%m-%d') SALES_DATE, 
    PRODUCT_ID, 
    USER_ID, 
    SALES_AMOUNT
from (
        select SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT from ONLINE_SALE
        union all
        select SALES_DATE, PRODUCT_ID, null as USER_ID, SALES_AMOUNT from OFFLINE_SALE
    ) A
where SALES_DATE >= '2022-03-01' and SALES_DATE <= '2022-03-31'
order by SALES_DATE,PRODUCT_ID, USER_ID;