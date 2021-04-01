# Trees And Graphs

### 1. Route between Nodes

> Given a directed graph, design an algorithm to find out whether there is a route between two nodes

📝 Reminder:

-   Classic graph search algorithm.

### 2. Minimal Tree

> Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.

📝 Reminder:

-   A typicial recursive algorithm for tree.

### 3. List of Depths

> Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth.

📝 Reminder:

-   BFS and DFS both work.

### 4. Check Balanced

> Implement a function to check if a binary tree is balanced. For the purpose of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never diff by more than one.

📝 Reminder:

-   Compare left and right subtree's height while recursion is enough, no need to store all the leaves' height and then do diff calculations.

### 5. Validate BST

> Implement a function to check if a binary tree is a binary search tree.

📝 Reminder:

-   A typicial recursive algorithm for tree.

### 6. Successor

> Write an algorithm to find the 'next' node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.

📝 Reminder:

-   Remember to classify into two situations:
    1. The node has a right child: the successor is the leftmost node of the right child.
    2. The node has not a right child: recursively finding its parent, when the parent is its parent's left child.

### 7. Build Order

> You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the second project is dependent on the first project). All of a project's dependencies must be built before the project is. Find a build order that will allow the project to be built. If there is no valid build order, return an error.
>
> EXAMPLE
>
> input:
>
> ```
>       projects: a, b, c, d, e, f
>
>       dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
> ```
>
> output:
>
> ```
>       f, e, a, b, d, c
> ```

📝 Reminder:

-   Topological Sort by using DFS.

### 8. First Common Ancestor

> Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure.

📝 Reminder:

-   Make sure whether the nodes has pointer to its parent.

### 9. BST Sequences

> A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.

🔨 Failed to consider:

-   Didn't quite understand the question before seeing the solution. For the solution, two related recursive functions are used and they are not that hard to reason about.

### 10. Check Subtree

> T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.
>
> A tree T2 is a subtree of T1 if there exists a node `n` in T1 such that the subtree of `n` is identical to T2. That is, if you cut off the tree at node `n`, the two trees will be identical.

📝 Reminder:

-   A typicial recursive algorithm for tree.
