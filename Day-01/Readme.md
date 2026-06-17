# Day 01 — Alphabetic Treasure Hunt: Sorting Clues by Difficulty

## Problem Statement
You are organizing a treasure hunt where each clue is a lowercase 
Latin alphabet. Each character has a difficulty level based on its 
alphabetical position modulo 5.

- Difficulty = (position % 5)
- 'a' = 1%5 = 1, 'b' = 2%5 = 2, 'e' = 5%5 = 0

Sort characters in ascending order of difficulty.
If two characters have same difficulty → reverse alphabetical order
(closer to 'a' = more difficult = comes later)

## Examples
| Input | Output | Reason |
|-------|--------|--------|
| bca   | abc    | a(1) < b(2) < c(3) |
| abcde | eabcd  | e(0) < a(1) < b(2) < c(3) < d(4) |

## Difficulty Groups
| Difficulty | Characters |
|------------|------------|
| 0 | e, j, o, t, y |
| 1 | a, f, k, p, u, z |
| 2 | b, g, l, q, v |
| 3 | c, h, m, r, w |
| 4 | d, i, n, s, x |

## Platform
- Site: Unstop
- Difficulty: Medium
- Score: 120/120 ✅
- Test Cases: 12/12 Passed

## My Approach
- Calculate difficulty: `(c - 'a' + 1) % 5`
- Sort using `qsort()` with custom comparator
- Primary sort: difficulty ascending
- Tie-break: reverse alphabetical (`cb - ca`)

## What Went Wrong First
- First attempt: 4/12 test cases passed ❌
- Bug: Used `ca - cb` (ascending alpha) for tie-breaking
- Fix: Changed to `cb - ca` (reverse alpha) ✅

## Key Code Logic
```c
int difficulty(char c) {
    return (c - 'a' + 1) % 5;
}

int cmp(const void *a, const void *b) {
    char ca = *(char *)a;
    char cb = *(char *)b;
    int da = difficulty(ca);
    int db = difficulty(cb);
    if (da != db) return da - db;
    return cb - ca;  // reverse alpha for tie-breaking
}
```

## What I Learned
- Custom comparator with `qsort()` in C
- Modulo-based sorting logic
- Tie-breaking in reverse alphabetical order
- Importance of reading problem statement carefully

## Files
- `solution.c` → Final accepted solution (120/120)
