#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given a sorted array, and element x, find index of first position where x occurs 

arr[] = {1, 10, 10, 10, 20, 20, 40} x=20
op: 4

arr[] = {10, 20, 30} x=15
op: -1

arr[] = {15, 15 , 15} x=15
op: 0

Naive: linear search
Efficient: Binary search 
once arr[mid] is found, check if it is the last occurence for that element by comparing arr[mid] with arr[mid-1], arr[mid-2]...

i.e we recursively call for left half until we see 
arr[mid] != arr[mid-1]

*/

int bin_recursive(int arr[], int x, int low, int high)
{
    if(high < low)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x && mid >= 0 && arr[mid] == arr[mid - 1])
        return bin_recursive(arr, x, low, mid-1);
    else if (arr[mid] == x && mid >= 0 && arr[mid] != arr[mid - 1])
        return mid;
    else if (arr[mid] > x)
        return bin_recursive(arr, x, low, mid - 1);
    else
        return bin_recursive(arr, x, mid + 1, high);
}

int bin_itr(int arr[], int n, int x)
{
    // 5 10 10 20 20
    int low = 0, high = n - 1;
    while(low <= high)
    {
        // deb2(low, high);
        int mid = (low + high) / 2;
        if(arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;
        else 
        {
            if (mid > 0 && arr[mid] == arr[mid-1])
                high = mid - 1;
            else
                return mid;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << bin_recursive(arr,x, 0, n-1);
    cout << bin_itr(arr, n, x);
    return 0;
}
