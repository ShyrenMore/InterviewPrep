### **Insert operation in binary min-heap**

- While doing insertion in array, we need to ensure that binary heap values still hold true 

- Steps:
1) Insert in the tree 
size + 1 and arr[size - 1] = key 
2) Compare newly inserted node with parent
if node is smaller swap it with parent 
swap(parent, keyNode)
3) we do step 2 again until:
    - newNode becomes greater than it's parent or
    - we reached the root
- Time: insertion takes O(1) and traverlling across height takes O(log(size)) so overall O(log(size))

### **Heapify operation (remove violation) in binary min-heap**

- argument for this function will be index of node which is violating the heap property i.e in case of min-heap the node which is greater than it's children
- compare node with left and right and take min(node, left, right)

```

if(node == min): no changes are required 
else:  
- swap(node, child_with_min_val)
- Recursively call heapify for particular child

```
- Time complexity: recursive call for child is ``O(h) = O(logN)`` since heap is complete tree
- Space complexity: `O(h)` stack space

### **getMin(Peak) operation in binary min-heap**
- return root of the min-heap i.e `arr[0]`

### **Extract min: delete the minimum from min-heap tree**

```
- swap root with last el: swap(arr[0], arr[size-1])
- decrement size: so og root will get lost
- call heapify(root) to make the resulting structure a proper heap
```

- Time: O(logN) due to calling min_heapify 

### **Decrease Key (update) in binary min-heap**

- arguments: 
    - index of element 
    - new value to be inserted at index

- after insertion we need to ensure that min-heap properties are not violated 

```
ip: 
idx = 3 and val = 5

        10
       /  \
      20   40
     / \   / 
    80 100 70 

op:
after insertion:
        10
       /  \
      20   40
     / \   / 
    5  100 70

stable op:
        5
       /  \
      10   40
     / \   / 
    20  100 70
```

- Steps:
```
- Go to idx and update: arr[idx] = val
- Compare updated node with parent
- if node is smaller swap it with parent: swap(parent, keyNode)
- do above step again until:
    - newNode becomes greater than it's parent or
    - we reached the root
```

- Time: O(h) = O(logN)

### **Delete operation in binary min-heap**

When we delete a node, the heap properties should hold true:
- modified min-heap has every node smaller than all of it's descendants
- should be complete binary tree

```
- Call decrease key function with params (idx, -INF)
This will make root as -INF
- Call extract Min function

This will swap last node with root i.e -INF
and reduce size thus getting lost of -INF

Extract_min will also internally call for heapify

ip:
idx = 3

        10
       /  \
      20  30
     / \  / \
    40 50 35 38
   /
  45    

Call decreaseKey(3, -INF)

       -INF
       /  \
      20  30
     / \  / \
    40 50 35 38
   /
  45    

Call extractMin

1) swap last and root

        45
       /  \
      20  30
     / \  / \
    40 50 35 38
   /
  -INF

2) elimnate last by size -= 1 and call heapify internally

        10
       /  \
      20  30
     / \  / \
    45 50 35 38

```
Time: O(logN)
