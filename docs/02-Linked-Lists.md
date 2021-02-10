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
