/*
Given an array of integers, the array may be sorted or unsorted
print leaders in the array
an element is called leader if there is nothing greater than or equal to the el on right of it


eg:
arr = [7, 10, 4, 3, 6, 5, 2]
op: 10 6 5 2

arr = [10, 20, 30]
op: 30

arr = [30, 20, 10]
op: 30 20 10

Naive sol:
Traverse through every el
For each el, we traverse on right side of it
If we find an el which is >= than curr el,
we say this number is not a leader
Time: O(n^2)

Eff sol:
This sol will print leaders from right to left
we traverse from the right side,
since last el will always be a leader
for each el we check if curr_el is > curr_leader
then curr element is also a leader
Time: theta(n)
Space: O(1) if reverse op is allowed
O(n) if normal op is allowed
*/

#include <iostream>
using namespace std;

void naive_leader(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] <= arr[j])
            {
                isLeader = true;
                break;
            }
        }

        if (isLeader == false)
            cout << arr[i] << " ";
    } 
}

void eff_leader(int arr[], int n)
{
    int curr_ldr = arr[n - 1];
    cout << curr_ldr << " ";

    for (int i = n - 2; i >= 0; i--)
    {
        if(curr_ldr < arr[i])
        {
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }
}