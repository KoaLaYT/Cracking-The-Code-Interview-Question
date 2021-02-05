# Arrays and Strings

### 1. Is unique

> Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

🔨 Failed to consider:

-   Not consider if it's an **unicode** string, just assume ASCII
-   For recording previously appeared characters, no need to use `set`, plain `array` is enough, and `bitset` is even better (For it can reduce space usage by a factor of 8).

### 2. Check Permutation

> Given two strings, write a method to decide if one is a permutation of the other.

🔨 Failed to consider:

-   Not check length as a fast test. And the consequence is that I need another iteration to confirm the chars' occurances in the `map` has all decreased to zero.
-   Not confirm whether permutation means case sensitive and if whitespace is significant, just assume they are both significant.

### 3. URLify

> Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

📝 Reminder:

-   Be careful to the 'off by one' error!
-   Do early return if there is no spaces in the string!

### 4. Palindrome Permutation

> Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phase that is the same forwards and backwards.

🔨 Failed to consider:

-   Using an `int` as a bit vector truly beyond my imagination, especially the method used to find if the bit vector only has one bit set. (But I think we can just use XOR to toggle the bit, which make this method more consice!)

```c++
bit_vec ^= (1 << c); // XOR
// -------
// Compare to the implementation in the book
// -------
int mask = 1 << c;
if ((bitVector & mask)
    bitVector |= mask;  // OR when 0
} else {
    bitVector &= ~mask; // AND when 1, and flip the mask
}
```

### 5. One Away

> There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit(or zero edits) away.

📝 Reminder:

-   If the inputs are raw `C` strings, we shouldn't use `strlen` to get their lengths, for one string maybe be extremely long, and we just want to know if their lengths' difference is larger than 2!

### 6. String Compression

> Implement a method to perform basic string compression using the counts of repeated characters. For example, the string `aabcccccaaa` would become `a2blc5a3`. If the "compressed" string would not become smaller than the origin string, your method should return the origin string.

🔨 Failed to consider:

-   Not thinking calculate the compressed length first. It can make the string has exact size it needs, maybe more suitable for its compression purpose.

### 7. Rotate Matrix

> Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degree.

📝 Reminder:

-   The index calculation is really tricky! Asumming a matrix of size `N` and clockwise rotation, `(i, j)` becomes `(j, N - i - 1)`. So for a total rotation, we need three swaps:
    -   top left -> top right: `(i, j)` -> `(j, N - i - 1)`
    -   top left -> bottom right: `(i, j)` -> `(N - i - 1, N - j - 1)`
    -   top left -> bottom left: `(i, j)` -> `(N - j - 1, i)`

### 8. Zero Matrix

> Write an algorithm such that if an element in an M x N matrix is 0, its entire row and column are set to 0.

🔨 Failed to consider:

-   Using first row and first column to record zero infos. It can reduce space from O(N) to O(1)!

### 9. String Rotation

> Assume you have a method `is_substring` which checks if one word is a substring of another. Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to `is_substring`.

🔨 Failed to consider:

-   Totally missing that I can double one string, then do a `is_substring` check!
