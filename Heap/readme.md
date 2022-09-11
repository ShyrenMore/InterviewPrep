# Intro

**A Heap is a special Tree-based data structure in which the tree is a complete binary tree.**

# Operation on heap

- heapify: create a heap from array
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

# Binary heap

- 

- [Design min-heap](min_heap.cpp)
