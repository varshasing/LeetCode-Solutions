## Jan 1: 1422. Maximum Score After Splitting a String

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Input: s = "011101"
Output: 5

###Approach: because the left side score only increments with '0' and right side score does the same with only '1', can keep a left and right score that increments in a one-way pass through the string.

I had three passes through the string, one forward pass for counting the lefthand zeroes, one backpass for counting the righthand ones, and another forward pass for finding the maximum score.

I used O(n) space to create a vector of score for each position, and runtime complexity is also O(n).

An issue I had with test cases such as "00" is that you cannot have empty splits, this required changing my code to not count the last index for lefthand score and to not count the first index for righthand score.
Runtime: 100.00%
Space: 18.31%
