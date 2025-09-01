# Write your MySQL query statement below
select w2.id from weather w1
join weather w2
where datediff(w2.recordDate,w1.recordDate) =1
and w2.temperature>w1.temperature