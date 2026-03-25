-- Last updated: 3/25/2026, 9:06:16 AM
# Write your MySQL query statement below
SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM (
    SELECT
        id,
        name,
        salary,
        departmentId,
        DENSE_RANK() OVER (
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) AS salary_rank
    FROM Employee
) e
JOIN Department d
    ON e.departmentId = d.id
WHERE e.salary_rank <= 3;
