# Day 02 — PrimeVibe Check

## Problem Summary
Given a number represented as a Linked List,
reconstruct the number and check prime condition.

## Platform
- Site: Unstop
- Difficulty: Easy
- Score: 100/100 ✅
- Test Cases: 12/12 Passed

## Approach
- Traverse LinkedList: while(curr != NULL)
- Reconstruct: num = num * 10 + curr->val
- Used long long to avoid overflow
- Applied prime check logic

## What I Learned
- Linked List struct in C
- Pointer traversal using curr->next
- Long long for overflow prevention

## Files
- solution.c → Accepted solution (100/100)
