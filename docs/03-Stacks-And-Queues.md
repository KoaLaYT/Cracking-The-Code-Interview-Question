# Stacks And Queues

### 1. Three in One

> Describe how you could use a single array to implement three stack.

📝 Reminder:

-   The `expand` strategy could be very sophisticated. Maybe extract that part to be an interface.

### 2. Stack Min

> How would you design a stack which, in addition to push and pop, has a function `min` which returns the minimum element?. `push`, `pop` and `min` should all work in `O(1)` time.

📝 Reminder:

-   Extending the `std::stack` seems complicated, so I'm using two stacks to do the implementation.

### 3. Stack of Plates

> Imagine a literal stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when previous stack exceeds some threhold. Implement a data structure `SetOfStacks` that mimics this. `SetOfStacks` should be composed of several stacks and should create a new stack once the previous one exceeds capacity. `SetOfStacks.push()` and `SetOfStacks.pop()` should behave identically to a single stack.
>
> FOLLOW UP:
>
> Implement a function `popAt(int index)` which perform a pop operation on a specific substack.

📝 Reminder:

-   Not tough one, but the `popAt` strategy should be well defined.

### 4. Queue via Stack

> Implement a MyQueue class which implements a queue with two stacks.

🔨 Failed to consider:

-   No need to shift two stacks back and forth between inqueue and dequeue. Thinking a queue is divided into two halfs, one has oldest on top, and the other has newest on top. We only shift when the oldest stack is empty!
