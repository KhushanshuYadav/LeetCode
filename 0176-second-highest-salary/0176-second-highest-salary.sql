with cte as
(
    select salary,
    dense_rank() over ( order by salary desc) as rnk
    from
    Employee
)
select 
case
when max(rnk)=1 then null
else salary 
end as SecondHighestSalary from cte where rnk=2 