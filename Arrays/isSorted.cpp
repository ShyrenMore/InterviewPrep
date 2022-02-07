#include <iostream>
using namespace std;

/*

Check if an array is sorted in increasing order
ip: [8, 12, 15]
op: yes

ip: [100]
op: yes

ip: [100, 20, 200]
op: no

Naive Approach:
Traverse array from left to right
for each element check that
There should not be any smaller element on right side

Time:
worst case: arr is sorted, Theta(n^2)
best case: arr is sorted in descending, Theta(n)

Efficient Approach:
Traverse array from left to right
If elements are out of order we say array is sorted
i.e if I am at ith element, 
this means elements from 0 to ith index should be sorted 

Time: O(n)
*/

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                return false;
            }
        }
    }

    return true;
}

bool eff_isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1])
            return false;
    }

    return true;
}

int main()
{
    int arr[] = {5, 12, 30, 40};
    cout << eff_isSorted(arr, 4);
    return 0;
}