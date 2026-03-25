-- Last updated: 3/25/2026, 9:03:25 AM
# Write your MySQL query statement below
SELECT 
    user_id,
    COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;
