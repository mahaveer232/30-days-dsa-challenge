# Day 04 — Pairing Lucky Stones in the Village Festival

## Problem Statement
Given P stones and two special numbers N and M,
find count of unique pairs where BOTH stones in
each pair are divisible by either N or M.
No repeated pairs allowed, stones must be different.

## Examples
P=5, N=2, M=3

Stones: [6, 9, 12, 15, 18]
| Stone | Div by 2? | Div by 3? | Valid? |
|-------|-----------|-----------|--------|
| 6 | ✅ | ✅ | ✅ |
| 9 | ❌ | ✅ | ✅ |
| 12 | ✅ | ✅ | ✅ |
| 15 | ❌ | ✅ | ✅ |
| 18 | ✅ | ✅ | ✅ |

All 5 valid → Pairs = 5×4/2 = **10** ✅
P=4, N=4, M=4

Stones: [2, 5, 5, 8]
Only 8 is valid → count=1 → Pairs = 1×0/2 = **0** ✅

## Platform
- Site: Unstop
- Difficulty: Easy
- Score: 100/100 ✅
- Test Cases: 12/12 Passed

## My Approach
- Step 1: Filter valid stones
  → `stones[i] % n == 0 || stones[i] % m == 0`
- Step 2: Count valid stones
- Step 3: Apply pair formula
  → `count * (count - 1) / 2`

## Why This Formula Works
If count = 5 valid stones:
- Pair with stone 1: (1,2) (1,3) (1,4) (1,5) → 4 pairs
- Pair with stone 2: (2,3) (2,4) (2,5) → 3 pairs
- And so on...
- Total = 4+3+2+1 = 10 = 5×4/2 ✅

## Key Insight
❌ Wrong approach: Check every pair → O(n²)
✅ Right approach: Count valid stones → Apply formula → O(n)

## What I Learned
- Divisibility check using modulo operator
- Combinatorics formula: n*(n-1)/2 for unique pairs
- Thinking mathematically saves time and code
- O(n) vs O(n²) — efficiency matters

## Constraints
- 1 ≤ P ≤ 1000
- 1 ≤ N, M ≤ 10^5
- 1 ≤ Stone value ≤ 10^5

## Files
- `solution.c` → Final accepted solution (100/100)
