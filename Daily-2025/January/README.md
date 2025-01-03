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
