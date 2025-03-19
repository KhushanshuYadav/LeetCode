# Write your MySQL query statement below

SELECT
  d.name AS Department,
  e.name AS Employee,
  e.salary AS Salary
FROM
  Employee e
JOIN
  Department d
ON
  e.departmentId = d.id
JOIN
(
  SELECT 
    id,
    DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS row_num
  FROM 
    Employee
) ranked
ON
  e.id = ranked.id
WHERE
  ranked.row_num <= 3;
