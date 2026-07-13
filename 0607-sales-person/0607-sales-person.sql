# Write your MySQL query statement below
select s.name
from (select * from Company where name = 'RED') t
join Orders o on t.com_id = o.com_id
right join SalesPerson s on o.sales_id = s.sales_id
where o.sales_id is null;