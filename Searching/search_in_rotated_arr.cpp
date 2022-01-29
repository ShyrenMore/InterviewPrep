#include <iostream>
using namespace std;

/*

Problem name: Search in a sorted rotated array

Given a sorted and rotated arr with distinct elements, 
and given x, 
if el x is present in arr, return idx else return -1;

ip: arr[] = {10, 20, 30, 40, 50, 8, 9} x=30
op: 2

ip: arr[] = {100, 200, 300, 10, 20} x=40
op: -1

Naive: Linear search, does not use the fact that arr is sorted and rotated
Efficient: use binary search

----- Observations and intuition

- in bin_search skip one half of the arr
- by observation we conclude that one half of the arr is always sorted
how do we know which half is sorted?
we compare middle element with leftmost el, 
if mid_el > leftmost_el, we conclude left half is sorted 
else right half of array will be sorted 

if our el x lies between leftmost el and mid_el, we conclude that x lies in left half of the arr

now we apply bin_search to left half

eg1: arr[] = {100, 200, 500, 1000, 2000, 10, 20}, x = 100

here leftmost_el = 100, mid_el = 1000
1000 > 100, hence left part of the arr is sorted
x lies b/w 100 and 1000

eg2: arr[] = {100, 200, 500, 1000, 2000, 10, 20}, x = 25
leftmost_el = 100, mid_el = 1000, rightmost_el = 20
1000 > 100, hence left part of the arr is sorted, 
100 < 25 < 1000 is not true, so x is not present in left half, 
so we go to right half & apply binary search  

eg3: arr[] = {100, 500, 10, 20, 30, 40, 50}
*/

int main()
{
    return 0;
}