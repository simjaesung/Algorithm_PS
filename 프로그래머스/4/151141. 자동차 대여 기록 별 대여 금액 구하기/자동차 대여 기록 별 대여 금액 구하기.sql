-- 코드를 입력하세요
SELECT
    #C.CAR_TYPE,
    H.HISTORY_ID,
    FLOOR(
        C.DAILY_FEE * 
        (DATEDIFF(H.END_DATE, H.START_DATE) + 1) * 
        (100-IFNULL(P.DISCOUNT_RATE,0)) / 100
    ) FEE
from CAR_RENTAL_COMPANY_CAR C
    join CAR_RENTAL_COMPANY_RENTAL_HISTORY H
    on C.CAR_ID = H.CAR_ID
left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN P
on C.CAR_TYPE = P.CAR_TYPE
and (
    case
        when DATEDIFF(H.END_DATE, H.START_DATE) + 1 >= 90 then P.DURATION_TYPE = '90일 이상'
        when DATEDIFF(H.END_DATE, H.START_DATE) + 1 >= 30 then P.DURATION_TYPE = '30일 이상'
        when DATEDIFF(H.END_DATE, H.START_DATE) + 1 >= 7 then P.DURATION_TYPE = '7일 이상'
    end
)
where C.CAR_TYPE = '트럭'
order by FEE desc, H.HISTORY_ID desc;