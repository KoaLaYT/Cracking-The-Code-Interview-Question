# Linked Lists

### 1. Remove Dups

> Write code to remove duplicates from an unsorted linked list.
>
> FOLLOW UP: How would you solve this problem if a temporary buffer is not allowed.

📝 Reminder:

-   For the follow up, if the result order is irrelevant, we can sort the list and then using two pointers to scan the list, which is `O(NlogN)` time

### 2. Return Kth to Last

> Implement an algorithm to find the kth to last element of a singly linked list.

📝 Reminder:

-   Using two pointers seems more straightforward to me than recursive methods.

### 3. Delete Middle Node

> Implement an algorithm to delete a node in the middle (i.e., any node but first or last node, not necessarily the exact middle) of a singly linked list, given access only to that node.

🔨 Failed to consider:

-   Swap with the next node, and delete that node is just enough. No need to revise every node after the given node. So the time can be reduced from `O(N)` to `O(1)`.

### 4. Partition

> Write code to partition a linked list around a value `x`, such that all value less than `x` come before all nodes greater than or equal to `x`. If `x` is contained within the list, the values of `x` only need to be after the elements less than `x`. The partition element `x` can appear anywhere in "right partition"; it does not need to appear between the left and right partitions.

📝 Reminder:

-   Keeping an iterator to a list while modifying it, is very tricky in _c++_. Maybe it's just better to create two new lists and then concat them.

### 5. Sum Lists

> You have two numbers represented by a linked list, where each node contain a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds two numbers and return the sums as a linked list.
>
> Example:
>
> Input: 7 -> 1 -> 6 + 5 -> 9 -> 2. That is, 617 + 295.
>
> Output: 2 -> 1 -> 9. That is, 912.
>
> FOLLOW UP:
>
> Suppose the digits are stored in forward order. Repeat the above problem.
>
> Example:
>
> Input: 6 -> 1 -> 7 + 2 -> 9 -> 5. That is, 617 + 295.
>
> Output: 9 -> 1 -> 2. That is, 912.

🔨 Failed to consider:

-   Not consider two lists with different lengths!
