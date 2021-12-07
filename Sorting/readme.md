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

## 3. Bubble sort
- comparison based algo that takes O(n^2) time 
- The algorithm has various passes, in first pass we move largest element to last position, in second pass we move second largest el to second-last position and so on until all elements are in their correct position
- for moving elements to their respective position, we compare the el with its adjacent elements, we do swapping when adj el that are being compared are out of order 
- for an array of n els, we need to do n-1 passes, since n-1  largest elements will move n-1 correct position 

```
void bubbleSort(arr, n)
{
    // n-1 passes
    for(i = 0; i < n-1; i++)
        // bubbling largest els to correct pos
        for(j = 0; j < n-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}
```
Optimisation to above code: j=0 to n-1 runs every time for every pass, after we have run one pass, one el is fixed as largest element and so on... <br>
so if we are at ith iteration then i elements are already fixed to their correct positions 
so we run j=0 to n-i-1

```
void bubbleSort(arr, n)
{
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}
```
- [dry run](bubblesort.png)

- Time complexity
```
if(arr[j] > arr[j+1]) -------> for i=0, runs for n-1
                               for i=1, runs for n-2
                               ..
                               i=n-2 runs for 1 time

i.e (n-1) + (n-2) +...+ 2+1
= n*(n-1)/2
= theta(n^2) 
```

- Optimisation if array is sorted or becomes sorted in middle it does not do any more work
    - maintain a swapped variable
    - after every pass re-initalise it as False 
    - for current pass check if any el has been swapped, set swapped variable in this case
    - else swapped remains false indicating no swapping happened  i.e while comparing elements we did not find any element out of order i.e array is/has become sorted

    - Code
    ```
    void bubbleSort(arr, n)
    {
        for(i = 0; i < n-1; i++)
        {
            swapped = false;
            for(j = 0; j < n-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if(!swapped)
                break;
        }
    }
    ```
    - [dry run | does linear work ](opti-bubble-sort.png)
    - Time complexity: not theta (n^2)
        - worst case: O(n^2)
        - best case: O(n)
    - how to disrupt stability of bubble sort: ```arr[j] >= arr[j+1]```
    - in-place sorting: does not require any extra array to copy org elements