-- 코드를 작성해주세요
select 
    I.ITEM_ID,
    I.ITEM_NAME,
    I.RARITY
from ITEM_INFO I
join (
    select 
        T2.ITEM_ID
    from ITEM_INFO I2
    join ITEM_TREE T2
    on I2.ITEM_ID = T2.PARENT_ITEM_ID
    where I2.RARITY = 'RARE'
) J
on I.ITEM_ID = J.ITEM_ID
order by I.ITEM_ID desc;
