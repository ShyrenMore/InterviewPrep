## 1. sort function in C++

- It is mainly used for data stored in containers which allow random access like normal arrays, vector, deque
- sort() expects two iterators/address
    - 1) address of first element
    - 2) address after last element 
    - 3) optional parameter: specifies order in which you want items to be sorted, mainly a comparison function that decides how array elements are to be compared. For eg: see [point](1_Sort_in_C++.cpp)
- defined in algorithm library
- internally used Introsort(Hybrid of quicksort, heap sort and insertion sort), worst case and avg case: ```O(nlogn)```

## 2. Stability of sorting algos

given an arr of students already sorted in alphabetic order of their names or lexicographically sorted

<br>

``` arr[] = {("Shyren", 50), ("Viknesh", 80), ("Piyush", 50), ("Ramesh", 80)} ```


<br>

We want to sort this in increasing order of their marks, if two students have same marks then they should appear alphabetically in op. 
This property is called stability, i.e if two items have same value then they should appear in same order as in original array
In the above eg, if we use stable sorting algo the op should be 
<br>

``` arr[] = {("Piyush", 50), ("Shyren", 50), ("Ramesh", 80), ("Viknesh", 80),  } ```

<br>

- Stable sort algos: Bubble sort, Insertion sort, Merge Sort
- Unstable sort algos: Selection sort, Quick sort, Heap Sort
