-- Last updated: 3/25/2026, 9:04:20 AM
# Write your MySQL query statement below
SELECT
  customer_id
FROM
  Customer
GROUP BY
  customer_id
HAVING
  COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product);
