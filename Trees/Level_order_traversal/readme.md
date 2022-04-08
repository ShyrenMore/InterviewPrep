# Level order traversal or BFS of binary tree 

- Given a binary tree print all nodes of the tree in level order fashion
## Question:
<p align="center">
  <img src="printKthNode_ques.jpg" width="680px" alt="sort" title="sort"/>
</p>

## Logic: 

### Simple solution
use two functions
- one to find height of binary tree 
- and the other to print nodes at distance k
- O(n) for finding height, theta(h) loop for print nodes, so
- time complexity: ```O(n + h*n) or O(h*n)```

### Efficient solution
- we have to understand recursion is not a good idea here, since after 20 we need to print 30
- we use queue DS
- the basic idea is to enqueue a level in the queue and take out these item, printing them, 
-  while taking out an item from queue, we enqueue the children too (i.e next level)
- we selected queue since it is FIFO, so when we take in the root, we will take out the root first 

## Code:

- [Level order traversal in C++](level_order_traversal.cpp)

## Variations of LOS:

```
ip: a tree
op: level wise print

ip: bin tree with root as 10, left child 20, right child 30

10
20 30
40 50 60
70 80
```

### Level order traversal 1st solution


- First solution: 
- when we traverse one level completely, push null marker in queue 
- when we see null in queue next time, it means we have reached end of current level so print new line and null into quueue for next iteration or level

[Level order traversal 1st solution](los_line_by_line_1.cpp)
- dry run

### Level order traversal 2nd solution

- Second sol:
- we break the logic into two loops 
- the outer loop calls the inner loop for every loop
- the inner loop prints one level at a time
- after completion of inner loop we print new line
- The outer loops runs till queue is empty
- the inner loop runs for how many items are present in queue which is actually the no of nodes present at that level 

[Level order traversal 2nd solution](los_line_by_line_2.cpp)