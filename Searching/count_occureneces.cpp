#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given a sorted array, and element x, find no of occurences of X

arr[] = {10, 20, 20, 20, 30, 30} x=20
op: 3

arr[] = {10, 10, 10, 10, 10} x=10
op: 5

arr[] = {5, 8, 10} x=7
op: 0


Naive: Linear traversing - O(n)
Efficient:  
find first and last occurence of element using binary search - both will be O(log n)

both functions will return indices of first and last occurences, 
so if first occurence function return -1, that means there is no such el x present in array and op wil be 0
otherwise, 
the op will be (last-first+1)

Time: O(2logn) = O(logn)
*/

int naive(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if(arr[i] == x)
            ++count;

    return count;
}

int firstOccurence(int arr[], int n, int x)
{
    // 5 10 10 20 20
    int low = 0, high = n - 1;
    while (low <= high)
    {
        // deb2(low, high);
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;
        else
        {
            if (mid > 0 && arr[mid] == arr[mid - 1])
                high = mid - 1;
            else
                return mid;
        }
    }
    return -1;
}

int lastOccurence(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
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

int countOccurences(int arr[], int n, int x)
{
    int first = firstOccurence(arr, n, x);
    if (first == -1)
        return 0;
    return (lastOccurence(arr, n, x) - first + 1);
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
    // cout << naive(arr, n, x);
    cout << countOccurences(arr, n, x);
    return 0;
}
