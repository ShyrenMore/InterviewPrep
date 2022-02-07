#include <iostream>
using namespace std;

/*
Given an array, find index of largest el
ip: arr[] = {10, 5, 20, 8}
op: 2

Naive approach: traverse the array, compare current element with every other element and maintain the largest index
Time: O(n^2)

Efficient approach: Traverse the array, 
let's say we are at ith index, so there are two cases
arr[i] <= alargest --> ignore
arr[i] > alargest --> update alargest
time: O(n)
*/

int getLargest(int arr[], int n)
{
    // until flag remains true, curr el is greatest el
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            return i;
    }
    return -1;
}

int getLargest_eff(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
        if(arr[i] > arr[res])
            res = i;
    return res;
}

int main()
{
    int arr[] = {5, 8, 20, 10};
    cout << getLargest(arr, 4);
    return 0;
}