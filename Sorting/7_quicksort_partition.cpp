/*

PS: Given an unsorted arr and index p (pivot)
Partition the array around a[p], i.e 
all elements before a[p] should be less or equal than it 
and all elements after a[p] should be greater 

eg:

ip: arr[] = {3, 8, 6, 12, 10, 7}    p=5
op: arr[] = {3, 6, 7, 8, 12, 10} 
                or 
            {6, 3, 7, 12, 8, 10}
                or 
                .
                .

Naive: 
For future efficient solution, let's maintain two pointers low and high
create auxilary arr
copy smaller or equal to elements in arr
after that put all the greater els

Copy temp array back to original array

Time: O(3n)
space: O(n)
*/

#include <iostream>
using namespace std;

void naive_partition(int arr[], int l, int h, int p)
{
    int temp[h - l + 1], idx = 0;

    for (int i = l; i <= h; i++)
    {
        if(arr[i] <= arr[p])
        {
            temp[idx] = arr[i];
            idx++;
        }
    }

    for (int i = l; i <= h; i++)
    {
        if (arr[i] > arr[p])
        {
            temp[idx] = arr[i];
            idx++;
        }
    }

    for (int i = l; i <= h; i++)
        arr[i] = temp[i];

    for (int i = l; i <= h; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int p;
    cin >> p;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    naive_partition(arr, 0, n-1, p);
}

/*
ip:
6 5
3 8 6 12 10 7

op:
3 6 7 8 12 10
*/