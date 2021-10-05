#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given a sorted binary array, count how many ones are present in the binary array

arr[] = {0, 0, 0, 1, 1, 1, 1}
op: 4

arr[] = {1, 1, 1, 1, 1} 
op: 5

arr[] = {0, 0, 0, 0}
op: 0


Naive: start traversing from end, Time: theta(no of ones)
Using binary search: O(2logn) => O(logn)

we call binary search for first and last ocuurences, and return (last occur idx - first occur idx +1)
*/

int firstOccurence(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        // deb2(low, high);
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid]==x && mid > 0)
        {
            if (arr[mid] == arr[mid - 1])
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
    while(low <= high)
    {
        int mid = (low + high) / 2;
        // deb2(low, high);
        if(arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] == x && mid<n)
        {
            if (arr[mid] == arr[mid + 1])
                low = mid + 1;
            else
                return mid;
        }
    }

    return -1;
}

int countOnes(int arr[], int n)
{
    int first = firstOccurence(arr, n, 1);

    if (first==-1)
        return 0;
    return (lastOccurence(arr, n, 1) - first + 1);
}

int main()
{
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countOnes(arr, n);
    return 0;
}
