-- 코드를 입력하세요
SELECT 
    CAR_TYPE,
    sum(
        case 
            when 
                OPTIONS like '%통풍시트%' or 
                OPTIONS like '%열선시트%' or 
                OPTIONS like '%가죽시트%'
            then 1
            else 0
        end
    ) as CARS
from CAR_RENTAL_COMPANY_CAR
group by CAR_TYPE
order by CAR_TYPE;