#include <iostream>
using namespace std;

/*
Given an array of integers, find max(arr[j] - arr[i]) such that j>i

ip: arr[] = {2, 3, 10, 6, 4, 8, 1}
op: 8

ip: arr[] = {7, 9, 5, 6, 3, 2}
op: 2

ip: arr[] = {30, 10, 8, 2}
op: -2

ip: arr[] = {10, 20, 30}
op: 20

*/

int maxDiff(int arr[], int n)
{
    int ans = INT16_MIN;
    // int ans = arr[1] - arr[0];
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            ans = max(ans, arr[j] - arr[i]);
        }
    }
    return ans;
}

void printArr(int arr[], int n)
{
    cout << "\nYour array is :: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x = maxDiff(arr, n);
    cout << "x:" << x;
    // leaders(arr, n);
    // printArr(arr, n);
    return 0;
}