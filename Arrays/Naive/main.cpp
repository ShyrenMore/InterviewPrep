#include <iostream>
using namespace std;

/*
-----------------------------------------------------------------------
Check if an array is sorted in increasing order
Approach: There should not be any smaller element on right side

returns true if arr is sorted else false
*/

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                return false;
            }
        }
    }

    // this is written to avoid warnings
    return true;

    // Time:
    // worst case: arr is sorted, Theta(n^2)
    // best case: arr is sorted in descending, Theta(n)
}

/*
-----------------------------------------------------------------------
Reverse an array
ip: arr[] = {10, 5, 7, 30}
op: arr[] = {30, 7, 5, 10}

Approach: Maintain two idx var: low & high pointing to index of first and last els

Swap these els at both the indexes and then move low and high close to each other

*/
void reverseArr(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low<high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    
    // Time: O(n/2) => theta(n)
}

/*
-----------------------------------------------------------------------
Remove Duplicates from a sorted array
ip: arr[] = {10, 20, 20, 30, 30, 30, 30}
op: arr[] = {10, 20, 30, _, _, _, _}

Approach: Create auxilary array of same size
copy only distinct elements 
copy elements of distinct arrays into original arrays

returns distinct els
*/
int removeDuplicates(int arr[], int n)
{
    int temp[n];

    // first element will always be part of op
    temp[0] = arr[0];
    int distinct_els = 1;

    for (int i = 0; i < n; i++)
    {
        // check if curr el is same as last copied el in temp arr
        if (temp[distinct_els - 1] != arr[i])
        {
            temp[distinct_els] = arr[i];
            distinct_els++;
        }
    }

    for (int i = 0; i < distinct_els; i++)
        arr[i] = temp[i];

    return distinct_els;
}

/*
-----------------------------------------------------------------------
Move zeros to the end while maintaing the order

ip: arr[] = {8, 5, 0, 10, 0, 20}
op: arr[] = {8, 5, 10, 20, 0, 0}

Approach: Traverse the array 
as soon as we find zero we go to right side from that el and swap non-zero element with zero

*/
void moveZerosToEnd(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0)
        {
            for (int j = i+1; j < n; j++)
            {
                if(arr[j]!=0)
                    swap(arr[i], arr[j]);
            }
        }
    }

    // Time: O(n^2)
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

    // int ip_del_el;
    // cin >> ip_del_el;
    // int x = deleteEl(arr, n, ip_del_el);
    // cout << "size of new arr :: " << x;
    printArr(arr, n);
    return 0;
}