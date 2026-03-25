-- Last updated: 3/25/2026, 9:06:15 AM
# Write your MySQL query statement below
DELETE p1
FROM Person p1
JOIN Person p2
  ON p1.email = p2.email
 AND p1.id > p2.id;   -- keep the smallest id, delete the larger ones
