## 1. sort function in C++

- It is mainly used for data stored in containers which allow random access like normal arrays, vector, deque
- sort() expects two iterators/address
    - 1) address of first element
    - 2) address after last element 
    - 3) optional parameter: specifies order in which you want items to be sorted, mainly a comparison function that decides how array elements are to be compared. For eg: see [point](1_Sort_in_C++.cpp)
- defined in algorithm library
- internally used Introsort(Hybrid of quicksort, heap sort and insertion sort), worst case and avg case: ```O(nlogn)```

