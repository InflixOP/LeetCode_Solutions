# Write your MySQL query statement below
select customer_id,count(*) as count_no_trans from Visits v left join Transactions t on
v.Visit_id=t.Visit_id where transaction_id is Null group by customer_id;