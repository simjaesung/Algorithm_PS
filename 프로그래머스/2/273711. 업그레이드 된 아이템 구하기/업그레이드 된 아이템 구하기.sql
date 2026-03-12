-- 코드를 작성해주세요
select 
    I2.ITEM_ID,
    I2.ITEM_NAME,
    I2.RARITY
from ITEM_INFO I
join ITEM_TREE T
    on I.ITEM_ID = T.PARENT_ITEM_ID
join ITEM_INFO I2
    on T.ITEM_ID = I2.ITEM_ID
where I.RARITY = 'RARE'
order by I2.ITEM_ID desc;