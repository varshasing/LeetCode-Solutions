## Jan 1: 1422. Maximum Score After Splitting a String

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Input: s = "011101"
Output: 5

### Approach
Because the left side score only increments with '0' and right side score does the same with only '1', can keep a left and right score that increments in a one-way pass through the string.

I had three passes through the string, one forward pass for counting the lefthand zeroes, one backpass for counting the righthand ones, and another forward pass for finding the maximum score.

I used O(n) space to create a vector of score for each position, and runtime complexity is also O(n).

An issue I had with test cases such as "00" is that you cannot have empty splits, this required changing my code to not count the last index for lefthand score and to not count the first index for righthand score.

Runtime: 100.00%
Space: 18.31%

## Jan 2: 2559. Count Vowel Strings in Ranges

You are given a 0-indexed array of strings `words` and a 2D array of integers `queries`.

Each query `queries[i] = [li, ri]` asks us to find the number of strings present in the range `li` to `ri` (both inclusive) of `words` that start and end with a vowel.

Return an array `ans` of size `queries.length` where `ans[i]` is the answer to the `i`th query.

Note that the vowel letters are `a e i o u`.

Input: words = ["aba", "bcb", "ece", "aa", "e"],
queries = [[0,2], [1,4], [1,1]]
Output: [2,3,0]

### Approach
A valid word both starts and ends with a vowel, so use the first index of the string and the last (first with string.back) to get the first and last letter of the word. Check that it is valid by using built-in string function find().
Use a vector of integers for each word if it is a valid word (1) or not (0), then iterate through to make it a linear running-sum, with each score adding its value + the previous score.
Because inclusive, subtract the score of one left from the left query from the right query score, this gives the number of valid words between the two queries inclusive. For queries where the left/starting query is 0, do not subtract any value from the right query.

This approach has to see if any of the vowels match with the first and last character of a string, which is O(5) for both (addition), and does this n times, with n being the number of words. Thus, checking if a word is valid and putting it into the vector is O(n) time.
Calculating the running sum goes through each score position, and is also done in O(n) time.
The time for calculating each query is two indexes into the vector, and each one is done with O(2) time, done m times, with m being the number of queries. Therefore, the time to calculate each query is O(m).

This makes runtime complexity O(n + m), and space complexity is O(n + m) as well, with one vector storing int for each valid word -> running sum, and then another for storing the answer for each query.

I had an issue with the longest test case where my first approach took too much time. This required changing my code structure to take less time to lookup the value returned for each query, which introduced the idea of a running sum total, as queries are done with a range of words.

Runtime: 100.00%
Memory: 50.44%

## Jan 3: 2270. Number of Ways to Split Array

You are given a 0-indexed integer array `nums` of length `n`.
`nums` contains a valid split at index `i` if the following are true:
- the sum of the first `i+1` elements is greater than or equal to the sum of the last `n-i-1` elements.
- there is at least one element to the right of `i`. That is, `0<= i < n-1`

Return the number of valid splits in `nums`.

Input: nums = [10,4,-8,7]
Output: 2

### Approach

For this question, you need to know the sum of your left and right side of the split. This signaled to me that I can compute the left and right sums and then iterate through the array, adding the next split number to the left side and subtracting it from the right side. This is a prefix sum approach, and helps reduce compute time compared to other approaches which will compute the sum for the left and right side from scratch with each split.

I had an issue with a long test case where my sum had an overflow for integers. I fixed this by making my left and right summed parts instead being long long type.

Runtime: 100.00%
Memory: 62.32%

## Jan 4: 1930. Unique Length-3 Palindromic Subsequences

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Input: s = "aabca"
Output: 3

### Approach

A 3-lettered palindrome has to be a letter surrounded by the same letter. This introduces the idea of a prefix and suffix array for frequency counting. Because the string is limited to lowercase letters, this makes implementation bounded between 0-25 array size.
To begin, precompute the right side, assuming all letters are to the right of the starting middle letter. The left side array will start as 0, and then increment as we go along the string.
For every middle letter, check each of the positions in the left and right array. If there exists a letter that is in both the left and right side array, then there can exist a palindrome. Have a set that holds a unique hashing for each possible palindrome (multiply the middle letter by 26, adding the jth position of the array), as this will get rid of multiple of the same palindrome from being counted in a more memory-efficient manner.

This takes two passes throughout the given array, s, and s passes through the 26-sized arrays, this makes the runtime O(n), with n being the number of letters in the given string.
The memory complexity is dependent on the number of palindromes, with constant space taken for the left and right arrays and up to 26*26 different palindromes. Thid makes the space complexity O(m), with m being the size of the letter-set.

Runtime: 77.00%
Memory: 47.85%
