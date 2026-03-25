-- Last updated: 3/25/2026, 9:04:53 AM
# Write your MySQL query statement below

SELECT 
    MAX(num) AS num
FROM 
    MyNumbers
WHERE 
    num IN (
        SELECT num
        FROM MyNumbers
        GROUP BY num
        HAVING COUNT(num) = 1
    );
