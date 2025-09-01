# Write your MySQL query statement below
WITH highest_salary as (
    SELECT e.salary as Salary,d.name as Department,e.name as Employee,
    DENSE_RANK() OVER(partition by d.name ORDER BY e.salary DESC) AS rnk 
    FROM Employee e
    JOIN department d
    ON e.departmentId =d.id
)
SELECT department,Employee,Salary
FROM highest_salary
WHERE rnk <=3

