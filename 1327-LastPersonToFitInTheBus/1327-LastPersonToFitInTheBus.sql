-- Last updated: 3/25/2026, 9:04:05 AM
# Write your MySQL query statement below
WITH boarded AS (
    SELECT
        person_name,
        turn,
        SUM(weight) OVER (
            ORDER BY turn
            ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
        ) AS cum_weight
    FROM Queue
)
SELECT person_name
FROM boarded
WHERE cum_weight <= 1000          -- must not exceed bus limit
ORDER BY turn DESC                -- get the last person who fits
LIMIT 1;
