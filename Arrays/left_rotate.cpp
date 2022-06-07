#include <iostream>
using namespace std;
/*

Left rotate an array by d steps
or
Rotate an array in anti-clockwise direction by d steps

ip: arr[] = {1, 2, 3, 4, 5}, d=2
op: arr[] = {3, 4, 5, 1, 2}

Naive approach: LeftRotate the el d times
Time: Theta(n x d)

Efficient approach (method2):
copy first d elements in temp arr
in original array, from index d+1 to n-1,
shift all elements d positions back
then copy elemnts from temp to arr,
arr[n-d+i] = temp[i]
Time: theta(d) + theta(n-d) + theta(d)
i.e theta(n)
Space: theta(d)

eg: arr = [1, 2, 3, 4, 5], d = 2
copy els to temp
temp = [1, 2]

shift n-d els
arr = [3, 4, 5, 4, 5]

put els back to og array
arr = [3, 4, 5, 1, 2]

Efficient approach (method3):
Step 1) reverse first d els i.e from 0 to d-1
Step 2) reverse n-d els i.e from d to n-1
Step 3) reverse the entire array

eg: arr = [1, 2, 3, 4, 5], d=2

after first reverse
arr = [2, 1, 3, 4, 5]

after second reverse
arr = [2, 1, 5, 4, 3]

after third reverse 
arr = [3, 4, 5, 1, 2]

Time: O(d+n-d+n) = O(2n) = O(n)
Space: O(1)
*/

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i - 1] = arr[i];

    arr[n - 1] = temp;
}
void leftRotateBysteps(int arr[], int n, int steps)
{

    // in case steps>arr_size
    if (steps > n)
        steps = n - steps;

    for (int i = 0; i < steps; i++)
        leftRotateByOne(arr, n);
}

void leftRotateBysteps_method2(int arr[], int n, int d)
{
    int temp[d];
    // copy first d els into temp
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];

    // shift the remanining n-d els
    for (int i = d; i < n; i++)
        arr[i - d] = arr[i];
    
    // copy element back to og arr
    for (int i = 0; i < d; i++)
        arr[n - d + i] = temp[i];
}

void reverse_method3(int arr[], int low, int high)
{
    while(low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotateBysteps_method3(int arr[], int n, int d)
{
    // in case d>n
    d = d % n;

    reverse_method3(arr, 0, d - 1);
    reverse_method3(arr, d, n - 1);
    reverse_method3(arr, 0, n - 1);
}