## Stack
- is a linear DS that works like a box, i.e one end is closed 
- insertion operation is called push operation
- removal is called pop
- follows Last in first out order (LIFO)

## Operations on stack
- isEmpty() or empty(): return true if stack is empty, else false
- push(x): inserts an item to top of stack
- pop(): removes an item from the top
- peak() or top(): returns the top item
- size(): returns size of stack

## Corner conditions on stack

- underflow: when pop() or peek() function is called on empty stack
- overflow: when push called on a full stack

## Implementation

- [Array implementation of stack](array_stack.cpp)
- [Linked List implementation of stack](ll_stack.cpp)
- [Stack in C++ STL](builtin_stack.cpp)
    - by defualt STL implements stack using deque container (container adapter: built on top of other containers, work as an interface)

## Applications of stack DS

- function calls
- checking for balanced parentheses
- reversing items
- infix to prefix/postfix conversion
- evaluation of postfix/prefix
- stock span problem and it's variations
- undo/redo cmd
    - since stack follows LIFO, whatever was done last, has to be undone 
    - and whatever was undone last has to be re-do
- forward/backward in web-browsers

## Problems on Stack DS

- [Implement two stacks in an array](two_stacks.cpp)
- [Kstacks in an array]
    - damn idk, I didn't understand

- [Previous Greater Element](prev_greater_el.cpp)
- [Next Greater Element](next_greater_el.cpp)
- [Infix to Postfix conversion](infix_to_postfix.cpp)
- [Evaluation of Postfix expression](postfix.cpp)
    - dry run
- [Stock span problem](stock_span.cpp)

## Design questions on stack

- [Design a stack that supports getMin() in O(n) space](getMin_1.cpp)
    - dry run