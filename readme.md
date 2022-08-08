### A new visitor?
you can refer readmes of
- [LinkedList](LinkedList/)
    <br>
    **Corner cases**
    - empty LL
    - LL with one node 
- [Arrays](Arrays/)
    <br>
    for every array quest, **you should ask the interviewer** if not already specified:
    - is the array sorted?
    - minimum no of elements in array?
    - does the array contain negative elements
    <br>
    **Corner cases**
    - would the code run properly if n=1?
- [Matrix](Matrix/)
- [Sorting](Sorting/)
- [Stack](Stack/)
- [Queue](Queue/)
- [Hashing](Hashing/)
- [Dynamic Programming](DP_striver/)

### What is this repo about?
- Interview prep 

### Some resources and hacks 

- Cheatsheet for time and space complexity:
https://www.bigocheatsheet.com/


- The below tips are taken from [here](https://github.com/SeanPrashad/leetcode-patterns)

``` 

If input array is sorted then
    - Binary search
    - Two pointers

If asked for all permutations/subsets then
    - Backtracking

If given a tree then
    - DFS
    - BFS

If given a graph then
    - DFS
    - BFS

If given a linked list then
    - Two pointers

If recursion is banned then
    - Stack

If must solve in-place then
    - Swap corresponding values
    - Store one or more different values in the same pointer

If asked for maximum/minumum subarray/subset/options then
    - Dynamic programming

If asked for top/least K items then
    - Heap

If asked for common strings then
    - Map
    - Trie

Else
    - Map/Set for O(1) time & O(n) space
    - Sort input for O(nlogn) time and O(1) space

```

- Identifying the solution methodology by looking at constraints 
- upto n<=10^3 naive sols will work most of the times

n-value | Maximum time it can take |
------- | :----------------: |
n <= 12 | O(n!)
n <= 25 | O(2^n)
n <= 100 | O(n^4)
n <= 500 | O(n^3)
n <= 10^4 | O(n^2)
n <= 10^6 | O(nlogn) - sorting 
n <= 10^8 | O(n) - hashing
n > 10^8 | O(logn) or O(1) - binary search


