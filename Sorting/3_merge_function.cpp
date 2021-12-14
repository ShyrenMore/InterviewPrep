/*

Given an arr, and three indices low, mid, high
Given elements from low to mid are sorted and elements from mid+1 to high are sorted
we need to sort the array from low to high

ip: arr[] = {10, 15, 20, 11, 30}
low=0
mid=2
high=4
op: arr[] = {10, 11, 15, 20, 30}

ip: arr[] = {5, 8, 12, 14, 7}
low=0
mid=3
high=4
op: arr[] = {5, 7, 8, 12, 14}

Basically merge two subarrays and make a sorted array
low need not be 0
and high need not be last index
and low <= mid < high

Idea:
Create two auxilary arrays left and right,
size of left arr is chosen such that it can store elements from low to mid,
similarly  right arr will store elements from mid+1 to high

Now this problem is similar to merge sorted arr

Time: θ(N)
N - no of elements from low to high
*/

#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    /*** Setting up auxilary arrays ***/
    
    // getting size of left and right arr
    int n1 = mid - low + 1, n2=high-mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[n1 + i];

    /*** Setting up completed ***/

    
    /*** Standard merge logic starts ***/
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            ++i;
            ++k;
        }
        else 
        {
            arr[k] = right[j];
            ++k;
            ++j;
        }
    }

    while(i<n1)
    {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while(j<n2)
    {
        arr[k] = right[j];
        ++j;
        ++k;
    }
    /*** Standard merge logic ends ***/
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge(arr, 0, 2, 4);
    for (int i = 0; i < n; i++)
        cout << arr[i] <<" ";
    return 0;
}