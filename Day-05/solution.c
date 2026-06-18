# Day 05 — The Busiest Book Shelf

## Problem Statement
Given N book return records, find the most
frequently returned book ID.
If multiple IDs have same max frequency →
print the smallest ID among them.

## Examples
| Input | Frequencies | Output |
|-------|-------------|--------|
| 500 200 500 300 500 200 100 | 500→3, 200→2 | 500 |
| 12 45 12 78 45 12 90 45 | 12→3, 45→3 | 12 (smaller) |

## Platform
- Site: Unstop
- Difficulty: Easy
- Score: 100/100 ✅
- Test Cases: 12/12 Passed

## My Approach
- Sort array → same IDs group together
- Single pass frequency count
- Update answer only if currentFreq > maxFreq
- Tie-breaking handled by sort order automatically

## Key Code Logic
```c
qsort(books, n, sizeof(long long), compare);

for (int i = 1; i < n; i++) {
    if (books[i] == books[i-1]) {
        currentFreq++;
    } else {
        if (currentFreq > maxFreq) {
            maxFreq = currentFreq;
            answer = books[i-1];
        }
        currentFreq = 1;
    }
}
// Last group check
if (currentFreq > maxFreq)
    answer = books[n-1];
```

## Why Sort Works for Tie-breaking
- After sorting: smallest ID comes first
- We update answer ONLY if strictly greater
- So first max-freq ID (smallest) is kept ✅

## What I Learned
- Sorting to handle large value ranges (up to 10^9)
- O(n) frequency count after sorting
- Edge case: check last group after loop
- Always read constraints before choosing approach

## Constraints
- 1 ≤ N ≤ 10^5
- 1 ≤ Book ID ≤ 10^9

## Files
- `solution.c` → Final accepted solution (100/100)
