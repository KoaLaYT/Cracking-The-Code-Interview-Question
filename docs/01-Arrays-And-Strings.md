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
