-- 코드를 입력하세요
SELECT
    month(START_DATE) as MONTH,
    CAR_ID,
    count(*) RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY C
where CAR_ID in (
    select CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE between '2022-08-01' and '2022-10-31'
    group by CAR_ID
    having count(*) >= 5
) 
group by CAR_ID, month(START_DATE)
having MONTH in (8,9,10)
order by MONTH, CAR_ID desc;