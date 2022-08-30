## What's so special about BST?
- A balanced BST provides search, insert, delete, finding closest operation in O(logn) time with constant space complexity which is better than array and LL
- an unbalanced BST has a time of O(h) in general

## Idea behind BST
- Data is organised in a way so while searching we can skip half of items just like Binary search
- i.e we go to middle and find the element we are searching, if el is greater we discard right half and go search in left, vice versa is also true
- for every node, keys in left side are smaller and keys in right side are greater
- eg:
```
        50
       /  \
      30   70
     /  \  / \
    10  40 60 80
```
As we can see, 60 is greater than 50 since it lies on right side but less than 70 since it is left child of 70 or
60 should be in range of [50, 70]
- all keys are considered distinct
- Implemented in c++ as map, set, multimap, multiset containers & in Java: TreeSet and TreeMap

**Difference between Binary Search Tree and Binary Tree** <br>
While their structure is similar, BST has a specific insertion order, it's not like anything can go anywhere, and this order has to be maintain after you delete an item

### Exmaple operation
```
Insert 20, 15, 30, 40, 50, 12, 18, 35, 80 and 7

        20
       /  \
      15   30

        20
       /  \
      15   30
            \
             40

        20
       /  \
      15   30
     /       \
    12        40
               \
                50

        20
       /  \
      15   30
     /  \   \
    12  18   40
   /        /  \
  7        35   50
                 \
                  80
```

In the above example it is clear when  you insert a smallest value, it goes  in leftmost child and in case of insertion of greatest element, it will go in rightmost child