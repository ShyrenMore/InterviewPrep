/*

Design a stack that supports getMin() operation in O(1) time

ip: push(20), push(10), getMin(), push(5), getMin(), pop(), getMin(), pop(), getMin()
op: 10 5 10 20

ip: push(5), push(4), push(3), getMin(), pop(), getMin(), push(2), getMin()
op: 3 4 2

Naive method:
use push and pop operations
for implementing getMin operation
we traverse through the stack,
by popping items one by one
and storing them into an auxilary stack or an auxilary array
and then finding min of items present in array

This implementation does push and pop in O(1) but
getMin requires O(n) time with O(n) extra space for every call

Efficient method:
does getmin in O(1) time annd O(n) space overall, not for every call
Maintain an auxilary stack - AS which will always have
minimum element at the top
We do push and pop in aux stack only when required
we push and pop to main stack
for aux stack, we  check if newly added item is smaller than or equal to
top of the stack, then push to AS
when we pop from our main stack,
if popped item is same as top of AS => we pop from AS

push(x)
if(ms.empty)
    push first el to both stack
else
    ms.push(x)
    if(as.top() >= ms.top())
        as.push(x);

pop()
if(ms.top() == as.top())
    as.pop()
ms.pop()
*/