# Day 03 — Galactic Communication Towers

## Problem Statement
A binary tree network of relay towers is given.
A tower is called a **Peak Relay** if its signal strength
is strictly greater than ALL its descendants.
Leaf towers are always Peak Relays.
Find total number of Peak Relay towers.

## Examples
   50
  /   \
20     30
/ \     /

10 15  25
| Tower | Descendants | Peak Relay? |
|-------|-------------|-------------|
| 50 | 20,30,10,15,25 | ✅ Yes |
| 20 | 10, 15 | ✅ Yes |
| 30 | 25 | ✅ Yes |
| 10 | none (leaf) | ✅ Yes |
| 15 | none (leaf) | ✅ Yes |
| 25 | none (leaf) | ✅ Yes |
Total = 6

## Platform
- Site: Unstop
- Difficulty: Medium
- Score: 120/120 ✅
- Test Cases: 12/12 Passed

## My Approach
- Read all towers with value, left, right child index
- Process nodes in REVERSE order (bottom-up)
- Track max descendant value using `maxSubtree[]` array
- For each node, check if value > maxSubtree[node]
- Update parent's maxSubtree using child values

## Key Code Logic
```c
typedef struct {
    long long value;
    int left;
    int right;
} Tower;

// Process bottom-up (reverse order)
for (int i = count - 1; i >= 0; i--) {
    long long maxDescendant = 0;

    if (towers[i].left != -1)
        maxDescendant = max(maxDescendant,
                       max(towers[towers[i].left].value,
                           maxSubtree[towers[i].left]));

    if (towers[i].right != -1)
        maxDescendant = max(maxDescendant,
                        max(towers[towers[i].right].value,
                            maxSubtree[towers[i].right]));

    if (maxDescendant > maxSubtree[i])
        maxSubtree[i] = maxDescendant;

    if (towers[i].value > maxDescendant)
        peakCount++;
}
```

## What Went Wrong First
- Initially tried top-down approach — failed ❌
- Realized bottom-up is needed to track subtree max ✅
- Had to use `long long` for signal strength (up to 10^9)

## What I Learned
- Binary tree traversal using array representation
- Bottom-up processing using reverse iteration
- Tracking subtree maximum values efficiently
- Custom struct with multiple fields in C
- Difference between top-down and bottom-up tree approaches

## Constraints
- 1 ≤ N ≤ 10,000
- 1 ≤ SignalStrength ≤ 10^9

## Files
- `solution.c` → Final accepted solution (120/120)
