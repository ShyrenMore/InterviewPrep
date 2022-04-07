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
