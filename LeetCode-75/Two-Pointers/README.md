# Two Pointers

## 283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

### Approach

We want to move all of the zeroes to the end of the array, which can be done with the builtin function swap. Keep a pointer for the next unsorted slot and have a traversing pointer which searches for the next nonzero number to swap.

This solution runs through the array once, making it O(n), there are n possible swaps, and the memory complexity is O(n), with n being the number of elements in the given array.

Runtime: 100.00%
Memory: 34.48%

## 392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Input: s = "abc", t = "ahbgdc"
Output: true

### Approach

If s is a subsequence of t, that means that you can find the letters of s linearly in t. Keep a pointer for both s and t, increment the s pointer when a match is found in t, and always increment t. If the s pointer is at the end of the string, that means that all letters have been found and s is a subsequence of t.

This iterates iterates througth the entirety of t, and might iterate throughout the entirety of s. The runtime should be O(n), with n being the number of letters in t, as the while loop always iterates while incrementing the t pointer. The memory complexity is having these two array pointers and checking the comparison for the letters each time in s and t, therefore O(n + m), n being the number of letters in t and m being the number of letters in s.

Runtime: 100.00%
Memory: 69.07%

## 11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

### Approach

You can have two pointers for the boundaries of the container, starting from the ends of the array, and then start to incrementally move them inwards, depending on which end has a lower height. You will move the lower height end because there is potentially a heigher height that might further maximize the seen max water amount,

The runtime for this is bounded to O(n), as you will check the volume of water for each index betwen rend and lend are the same. The space taken will be constant, as there are a constant amount of variables used for this solution O(1).

Runtime: 100.00%
Memory: 14.85%

## 1679. Max Number of K-Sum Pairs

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

Input: nums = [1,2,3,4], k = 5
Output: 2

### Approach

Because the operation is limited to sum of two numbers, this means that we can sort the array and move the left and right pointer based on how the sum compares to the target. If it equals the target, increment a counter and move both pointers inwards. If it is smaller than the target, move the left pointer inwards. If it is greater than the target, move the right pointer inwards.

Sorting the vector is done in O(n$log(n)$) time, and the memory component is the vector itself, O(n), with n being the number of elements in the vector.

Runtime: 97.92%
Memory: 47.32%
