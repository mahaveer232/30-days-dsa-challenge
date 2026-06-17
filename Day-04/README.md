# Day 04 — Pairing Lucky Stones in the Village Festival

## Problem Summary
Count unique pairs of stones where both are
divisible by either N or M.

## Platform
- Site: Unstop
- Difficulty: Easy
- Score: 100/100 ✅
- Test Cases: 12/12 Passed

## Approach
- Filter: stones[i] % n == 0 || stones[i] % m == 0
- Count valid stones
- Apply formula: count * (count - 1) / 2
- O(n) solution — no nested loops needed

## What I Learned
- Divisibility-based filtering
- Combinatorics formula for pair counting
- Mathematical thinking > brute force

## Files
- solution.c → Accepted solution (100/100)
