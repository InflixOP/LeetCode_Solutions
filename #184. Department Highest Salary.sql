# Write your MySQL query statement below
select d.name as Department, e.name as Employee, salary as Salary from Department d join
Employee e on d.id=e.departmentId where (salary,departmentId) in (select max(salary),departmentId from employee group by departmentId);  