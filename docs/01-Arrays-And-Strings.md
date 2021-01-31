# Arrays and Strings

### 1. Is unique

> Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

Something failed to consider at my first try:

-   Not consider if it's an **unicode** string, just assume ASCII
-   For recording previously appeared characters, no need to use `set`, plain `array` is enough, and `bitset` is even better (For it can reduce space usage by a factor of 8).
