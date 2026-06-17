# Day 02 — PrimeVibe Check (Linked List Even/Odd)

## Problem Statement
Given a singly linked list of single-digit integers:
1. Concatenate digits to form a number
2. Reverse that number
3. Calculate sum of digits of reversed number
4. Subtract sum from reversed number
5. Check if result is even or odd

## Examples
| Input | Concat | Reversed | Digit Sum | Result | Output |
|-------|--------|----------|-----------|--------|--------|
| 3 2 2 8 9 | 32289 | 98223 | 24 | 98199 | odd |
| 0 1 2 | 12 | 21 | 3 | 18 | even |

## Platform
- Site: Unstop
- Difficulty: Easy
- Score: 100/100 ✅
- Test Cases: 12/12 Passed

## My Approach
Step 1 → Traverse linked list, build number:
         `num = num * 10 + curr->val`

Step 2 → Reverse the number:
         `reversed = reversed * 10 + temp % 10`

Step 3 → Sum digits of reversed number:
         `sum += temp % 10`

Step 4 → result = reversed - sum
         Even/Odd check: `result % 2 == 0`

## Key Code Logic
```c
// Concatenate
while (curr != NULL) {
    num = num * 10 + curr->val;
    curr = curr->next;
}

// Reverse
while (temp > 0) {
    reversed = reversed * 10 + temp % 10;
    temp /= 10;
}

// Digit sum
while (temp > 0) {
    sum += temp % 10;
    temp /= 10;
}
```

## What I Learned
- Linked List traversal in C
- Building number from digits using `num * 10 + digit`
- Number reversal using modulo logic
- Digit sum calculation
- Using `long long` to handle large numbers (N up to 15 digits)

## Files
- `solution.c` → Final accepted solution (100/100)
