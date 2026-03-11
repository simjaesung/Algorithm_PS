-- 코드를 입력하세요
SELECT count(distinct NAME) as count
from ANIMAL_INS
where NAME is not null;

# SELECT *
# from ANIMAL_INS
# order by NAME;