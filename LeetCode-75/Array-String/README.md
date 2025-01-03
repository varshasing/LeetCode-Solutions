## 1768. Merge String Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"

### Approach
two cases:
- both words are of same length
- one word is longer than the other

Because you know that you will concatenate word1 index i and then word2 index i, I used a for loop that iterates for the minimum length word and check to see if either word length is greater than this. If this is true for either word, then this is a case 2 problem, and the remaining letters are concatenated to the answer.

The for loop adding alternatively runs n times, with n being the number of letters in the shorter word. the remaining letters are concatenated with a loop that runs m times, m being the number of letters that are out of range from the smaller word. If there was a variable g, for length of the longest word, this would be the upper bound on runtime complexity.

The runtime should be O(g), with g being the length of the longest word, and have a space complexity of O(n + g), with n being the length of the other word.

Runtime: 27.57%
Memory: 63.00%

## 1071. Greatest Common Divisor of Strings

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

### Approach

For t to be able to divide s, it means that they have to be composed of the same pattern and a repeating pattern. If this is the case, then adding str1 to str2 should be the same as adding str2 to str1. If this is the case, you can use the built-in loibrary function to find the gcd value. Else, can start with the minimum man length of the word and decrement, checking if both word lengths are divisible by the current iteration value.

The runtime complexity is finding the gcd and then concatenating a string for the pattern consisting of the gcd. The maximum time it can take to find the gcd depends on how it is implemented and how to compiler approaches it. I imagine that the upper limit is O(m), with m being the length of the longest string. The space complexity is O(n), n being the length of the shorter word.

Runtime: 100.00%
Memory: 17.52%

## 1431. Kids With the Greatest Number of Candies

There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]

### Approach

Iterate throughout the array to find that maximum number of candies without any extra candies.
Iterate again through the array, checking if giving all of the extra candies to the current iteration will result in that kid having more candies than the max number. If this is the case, push a true value, else false

This iterates through the array twice, once for finding the original max, and a second time for checking the the kids' candies agaist the max. This means that there will be a runtime of O(n), with n being the number of kids. The space required is also O(n), because of the returned value.

Runtime 100.00%
Memory: 15.94%

## 605. Can Place Flowers
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

### Approach
To plant a flower, need the plot to be empty, as well as the surrounding plots. For each empty plot, check its neighbors to see if this condition is met, and place a flower there and increment a counter. For the edge cases (start and end), check the second plot and second to last plot (as well as the first and last plot) to see if they are empty.

The time it takes to check and place flowers involves three checks per plot, this means that the runtime complexity is O(n), with n being the number of plots. The space requires involves directly editing the input vector flowerbed and holds an additional variable for number of plants placed. This means that the space component is O(n), with n being the number of plots.

Runtime: 100.00%
Memory: 47.25%

## 354. Reverse Vowels of a String
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Input: s = "IceCreAm"

Output: "AceCreIm"

### Approach

We only want to swap letters that are vowels, case-generally. Can do this by having two pointers that iterate through the word, and maintain that one pointer should have a lower index than the other. When both are on a vowel, swap the letters at each position and inc/decrement each pointer.

The time complexity for this involves checking if the letter is a vowel, and done n times. Thus, the runtime complexity is O(n). The space complexity is O(n), with n being the number of letters in the given string, as we need to edit the given string in-place.

Runtime: 56.44%
Memory: 36.90%

## 151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Input: s = "the sky is blue"
Output: "blue is sky the"

### Approach

I went about this by pushing all of the words onto a string stack, and then created a new string that concatenates the word at the top of the stack with a single space between. I then resize the string as this logic leaves the string with a trailing space.|

This approach requires psuhing all words onto a stack, and requires a single pass through the string to do so, as well as pushing each word until the stack is empty again. The runtime is O(n). with n being the number of letters in the string. The space used is a stack with m words, and creates a new string that is n characters long. Therefore, the space complexity is O(n), with n being the number of characters in the string.

Runtime: 6.41%
Memory: 5.09%

## Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

### Approach

The approach that can run in O(n) time requires a prefix and suffix sum, which computes the product before and after a variable, awith the total product of the arra except self being the prefix and suffix multiplied.

The runtime is O(n), and the memory complexity requires two arrays of n size, thus being O(n) as well, with n being the number of values in the given array.

Runtime: 40.93%
Memory: 6.37%

## 334. Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Input: nums = [1,2,3,4,5]
Output: true

### Approach

This problem gives parameters that the value of any number in `nums` will be no larger than $$2^31 -1$$. This tips off the idea of having two values, a min1 and min2 that are initalized to the maximum value an integer can hold. Iterate through the array to see if the current value is smaller than or equal to min1, if not, see if the current value is smaller than or equal to min2. If neither, then there already exists a sequence of increasing triplets. It is important to update min1 and only update min2 if the current value is larger than min1. This sequential process accounts for the requirement that the indices of the increasing triplet are in increasing order.

The runtime complexity for this solution passes through the array once, and is O(n), with n being the number of values in the array. The space complexity is O(1), as the variables for min1 and min2 do not depend on input.

Runtime: 42.93%
Memory: 65.40%

## 443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

### Approach

Because editing is done in-space and with constant memory, that means that all changes must be done in real time. I approached this by finding which letter I am on and increasing a counter until we reach a different letter. The counter should be split by decimal digit and appended in the array after the letter if greater than 9, so I used the log10 built-in function to figure out how many digits the number has, and subtracted the digits to make it less significant. This grabs the first digit and then I subtract the most significant number * 10^number of digits to reduce the number of digits.

Runtime: 22.91%
Memory: 88.22%%
