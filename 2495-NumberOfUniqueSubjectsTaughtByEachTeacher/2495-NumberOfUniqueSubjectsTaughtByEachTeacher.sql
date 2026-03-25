-- Last updated: 3/25/2026, 9:03:09 AM
# Write your MySQL query statement below
SELECT 
    teacher_id,
    COUNT(DISTINCT subject_id) AS cnt
FROM 
    Teacher
GROUP BY 
    teacher_id;
