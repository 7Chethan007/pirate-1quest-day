-- Last updated: 3/25/2026, 9:04:09 AM
# Write your MySQL query statement below
SELECT
    product_id,
    COALESCE(new_price, 10) AS price
FROM (
    -- For each product, pick the last price change **on or before** 2019-08-16
    SELECT
        product_id,
        new_price,
        ROW_NUMBER() OVER (
            PARTITION BY product_id
            ORDER BY change_date DESC
        ) AS rn
    FROM Products
    WHERE change_date <= '2019-08-16'
) AS t
RIGHT JOIN (
    -- Make sure we include all products (even if they have no change before that date)
    SELECT DISTINCT product_id
    FROM Products
) AS all_p
USING (product_id)
WHERE rn = 1 OR rn IS NULL;
