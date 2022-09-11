# Intro

**A Heap is a special Tree-based data structure in which the tree is a complete binary tree.**

# Operation on heap

- heapify: fix the heap having one violation
- insertion: insert an element in existing heap time complexity O(log N)
- deletion: deleting the top element of the heap or the highest priority element, and then organizing the heap and returning the element with time complexity O(log N)
- peek: check or find the most prior element in the heap
    - max el for max heap
    - min el for min heap

# Types of heap

1) Max - heap: The key present at the root node must be greatest among the keys present at all of it’s children

eg 

```
        100
       /   \
      40   50
     / \   / \
    10 15 50 40
```

2) Min - heap: The key present at the root node must be minimum among the keys present at all of it’s children.
eg

```
        10
       /  \
      40  50
     / \  / \
    10 15 50 40
```

# Application of Heap

- Heap Sort: Heap Sort uses Binary Heap to sort an array in `O(nLogn)` time
- Priority Queue: Priority queues can be efficiently implemented using Binary Heap because it supports `insert(), delete() and extractmax(), decreaseKey()` operations in `O(logn)` time. 
- Graph Algorithms: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.

# Binary heap

A Binary Heap is a Binary Tree with following properties.
- It’s a complete tree (All levels are completely filled except possibly **the last level and the last level has all keys as left as possible**). This property of Binary Heap makes them suitable to be stored in an array.
- A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. 

## Properties of binary heap
- the root element will be `arr[0]`
- how to get ith node's children and its own value

Index | return value
------- | :------: |
`arr[(i-1)/2]` | returns parent node |
`arr[2 * i + 1]` | returns left child node |
`arr[2 * i + 2]` | returns right child node |

- The traversal method use to achieve Array representation is Level Order

## Operations on Binary heap

- Insert, Delete, Decrease Key(Update), Extract Min(delete min), Heapify(remove violation)
- [Theory & explanation](MinHeap/readme.md)
- [Code](MinHeap/min_heap.cpp)
