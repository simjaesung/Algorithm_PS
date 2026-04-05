-- 코드를 입력하세요
SELECT
    P.MEMBER_NAME,
    R.REVIEW_TEXT,
    DATE_FORMAT(R.REVIEW_DATE,'%Y-%m-%d') REVIEW_DATE
from MEMBER_PROFILE P
join REST_REVIEW R
on P.MEMBER_ID = R.MEMBER_ID
where P.MEMBER_ID in (
    select MEMBER_ID
    from REST_REVIEW
    group by MEMBER_ID
    having count(*) = (
        select max(cnt)
        from (
            select count(*) cnt
            from REST_REVIEW
            group by MEMBER_ID
        ) t
    )
) order by REVIEW_DATE,  R.REVIEW_TEXT;
