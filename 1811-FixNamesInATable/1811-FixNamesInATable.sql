-- Last updated: 3/25/2026, 9:03:30 AM
# Write your MySQL query statement below
SELECT user_id,
       CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;
