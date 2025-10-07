# Write your MySQL query statement below

-- SOLUTION 1

-- select distinct author_id as id
-- from Views
-- where author_id = viewer_id
-- order by id;

-- SOLUTION 2
select author_id as id
from Views
where author_id = viewer_id
group by id
order by id;