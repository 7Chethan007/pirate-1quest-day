-- Last updated: 3/25/2026, 9:04:51 AM
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE MOD(id, 2) = 1       -- keep only odd-numbered IDs
  AND description <> 'boring'  -- exclude boring movies
ORDER BY rating DESC;       -- sort by rating descending
