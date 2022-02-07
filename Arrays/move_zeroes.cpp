#include <iostream>
using namespace std;

/*
Move zeros to the end while maintaing the order

ip: arr[] = {8, 5, 0, 10, 0, 20}
op: arr[] = {8, 5, 10, 20, 0, 0}

Naive Approach: 
Traverse the array
as soon as we find zero we go to right side from that el and swap non-zero element with zero
Time: O(n^2)

Eff Approach:
Traverse array from left to right
let's say we are at ith element, 
elements from 0 to a[i]-1 are in order 
i.e eg: 10, 12, 0, 0, arr[i]

now there are two possibilities:
a[i] == 0 --> ignore
a[i] != 0 --> swap a[i] with leftmost 0
for knowing index of 0, we keep track of count of non-zero els
first 0 = count of non-zero els

Time: O(n)
*/
void moveZerosToEnd(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                    swap(arr[i], arr[j]);
            }
        }
    }
}

void eff_moveZerosToEnd(int arr[], int n)
{
    int nonzero_count = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[nonzero_count]);
            ++nonzero_count;
        }
    }   
}

/*
Dry run:
{10, 8, 0, 0, 12, 0}
i=0: {10}, count=1
i=1: {10, 8}, count=2
i=2: {10, 8, 0}, count=2
i=3: {10, 8, 0, 0}, count=2
i=4: {10, 8, 0, 0, 12}, count=2
swap arr[2] with arr[4]
arr = [10, 8, 12, 0, 0], count=3

i=4: {10, 8, 12, 0, 0}, count=3

*/