-- 코드를 입력하세요
SELECT
    C.CAR_ID, 
    C.CAR_TYPE, 
    floor(C.DAILY_FEE * 30 * (100 - P.DISCOUNT_RATE) * 0.01) FEE
from CAR_RENTAL_COMPANY_CAR C 
join CAR_RENTAL_COMPANY_RENTAL_HISTORY H
    on C.CAR_ID = H.CAR_ID
join CAR_RENTAL_COMPANY_DISCOUNT_PLAN P
    on C.CAR_TYPE = P.CAR_TYPE
where C.CAR_TYPE in ('세단','SUV') 
    and P.DURATION_TYPE = '30일 이상'  
    AND NOT EXISTS (
        SELECT 1
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
        WHERE H.CAR_ID = C.CAR_ID
          AND NOT (
              H.END_DATE < '2022-11-01'
              OR H.START_DATE > '2022-11-30'
          )
    )
group by CAR_ID
having FEE >= 500000 and FEE <= 2000000
order by FEE desc, C.CAR_TYPE, C.CAR_ID desc;