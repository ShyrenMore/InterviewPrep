#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given a sorted array, and element x, find index of last position

arr[] = {10, 15, 20, 20, 40, 40} x=20
op: 3

arr[] = {5, 8, 8, 10, 10} x=10
op: 4

arr[] = {8, 10, 10, 12} x=7
op: -1

Naive: start traversing from right to left and perform a linear search, Time: Theta(n-i)

Efficient: use binary search
once arr[mid] is found, check if it is the last occurence for that element by comparing arr[mid] with arr[mid+1], arr[mid+2]...

i.e we recursively call for right half until we see 
arr[mid] != arr[mid+1]

Time: O(log n)
*/

int naive_sol(int arr[], int n, int x)
{
    for (int i = n - 1; i >= 0; i--)
        if (arr[i] == x)
            return i;
    return -1;
}

int bin_recursive(int arr[], int low, int high, int x, int n)
{
    if (high < low)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == x && mid<n && arr[mid] == arr[mid+1])
        return bin_recursive(arr, mid + 1, high, x, n);
    else if (arr[mid] == x && mid < n && arr[mid] != arr[mid + 1])
        return mid;
    else if (arr[mid] > x)
        return bin_recursive(arr, low, mid - 1, x, n);
    else
        return bin_recursive(arr, mid + 1, high, x, n);
}

int bin_itr(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;
        else 
        {
            if (arr[mid] == x && mid < n && arr[mid] == arr[mid + 1])
                low = mid + 1;
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
    // cout << naive_sol(arr, n, x);
    // cout << bin_recursive(arr, 0, n-1, x, n);
    cout << bin_itr(arr, n, x);
    return 0;
}
