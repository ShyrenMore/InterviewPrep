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

/*

Hoare's partition: O(n) time, O(1) time
pivot is first element i.e pivot = arr[l]
initialise i=low-1, j=high+1 

maintain two windows:
0 to i : el < pivot

eg: arr[] = {5, 3, 8, 4, 2, 7, 1, 10}
l=0, h=7
pivot = arr[l] = 5

begin:
i=-1, j=8

we move i from l to h, and move j from h to l, until i and j cross each other 

for every iteration we ensure:
1) el from l to i < pivot
2) el from j to h > pivot 
*/


// returns index of partition
int hoare_partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while(true)
    {
        do{
            ++i;
        } while (arr[i] < pivot);

        do{
            --j;
        } while (arr[j] > pivot);

        if(i>=j)
            return j;

        swap(arr[i], arr[j]);
    }
}

/*

dry run:

initially
arr = 5, 3, 8, 4, 2, 7, 1, 10
i=-1, j=8, pivot=5

1st iter:
i=0, 5<5 stop i, 

j=7, 10>5
j=6, 1>5 stop j

swap(arr[0], arr[6])

arr = 1, 3, 8, 4, 2, 7, 5, 10
i=1, 3<5
i=2, 8<5 stop i 

j=5, 7>5
j=4, 2>5 stop j

swap arr[2] with arr[4]

arr = 1, 3, 2, 4, 8, 7, 5, 10
i=3, 4<5
i=4, 8<5 stop

j=3, 4>5 stop

i has cross j, return 3

which implies elements from 0 to 3 are smaller than elements from 4 to 7
*/

/*

Corner case: pivot is smallest
arr = 5, 10, 9, 12
i=0, 5<5 stop
j=3, 12>5
j=2,..
j=0, 5>5 stop j

i==j
return 0
arr is partitioned into 5 | 10, 9, 12

*/

/*

Hoare's partition is not stable
proof: arr = 5,5,5,5
i stop at 0 and j at 3, swapping happens, khatam tata bye bye

Do note, naive method is stable but requires O(n) extra space and 3 traversals
*/
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