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
