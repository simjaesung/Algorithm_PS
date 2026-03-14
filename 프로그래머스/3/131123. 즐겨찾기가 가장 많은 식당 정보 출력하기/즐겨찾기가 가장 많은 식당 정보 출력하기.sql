-- 코드를 입력하세요
# SELECT
#     FOOD_TYPE,
#     REST_ID,
#     REST_NAME,
#     max(FAVORITES) as FAVORITES
# from REST_INFO
# group by FOOD_TYPE
# order by FOOD_TYPE desc;

select
    I.FOOD_TYPE,
    I.REST_ID,
    I.REST_NAME,
    I.FAVORITES
from REST_INFO I
where I.FAVORITES = (
    select max(FAVORITES) from REST_INFO
    WHERE FOOD_TYPE = I.FOOD_TYPE
)
order by FOOD_TYPE desc;