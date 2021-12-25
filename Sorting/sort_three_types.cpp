#include <iostream>
using namespace std;

/*

given an array that contains three types of elements

These can be asked in different forms
eg:
1) sort an array of 0s, 1s and 2s
ip: arr[] = {0, 1, 0, 2, 1, 2}
op: arr[] = {0, 0, 1, 1, 2, 2}

2) three way partitioning
given an array, partition the array around a pivot and there can be multiple occurences of pivot, all ocuurences should come together 

ip: arr[] = {2, 1, 2, 20, 10, 20, 1}    pivot=2
op: arr[] = {1, 1, 2, 2, 20, 10, 20}
note order of elements <20 and >20 need not be sorted 

3) partition around a range 
ip: arr[] = {10, 5, 6, 3, 20, 9, 40}    range = [5, 10]
op: arr[] = {3, 5, 6, 9, 10, 20, 40}

*/