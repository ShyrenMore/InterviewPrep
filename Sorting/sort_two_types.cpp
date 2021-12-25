#include <iostream>
using namespace std;

/*

Given an array with two types of els, we need to sort the array 

These can be asked in different forms
eg:

1) given an array of negatives and positive, you need to put negative first and then positives
ip: arr = [15, -3, -2, 18]
op: arr = [-3, -2, 15, 18]

2) Given an array of even and odd els, segregate even elements and then odd elements
ip: arr = [15, 14, 13, 12]
op: arr = [14, 12, 15, 13]

3) sort a binary array
ip: arr = [0, 1, 1, 1, 0]
op: arr = [0, 0, 1, 1, 1]

below will be solution of first problem
*/

/*

Create a temp array, initialise i = 0
put negative els in temp array,
then again traverse the array and put positive els after negative els in temp arr
finally copy temp array to original input array

time: θ(2n)     space: θ(n)

*/

void naive_segregatePosNeg(int arr[], int n)
{
    int temp[n], i = 0;

    for (int j = 0; j < n; j++)
    {
        if(arr[j] < 0)
        {
            temp[i] = arr[j];
            ++i;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if(arr[j] >= 0)
        {
            temp[i] = arr[j];
            ++i;
        }
    }

    for (int j = 0; j < n; j++)
        arr[j] = temp[j];
}

/*

Efficient: variation of partition function of quicksort
time: θ(n)     space: θ(1)

using hoarse's partition scheme
we consider 0 as our pivot,
we initialise i = -1 and j=n

arr[] = {-12, 18, -10, 15}
i=-1, j=4

1st iteration: i=1, j=2
arr[] = {-12, -10, 18, 15}

2nd iteration: i=2, j=1

*/

void eff_segregatePosNeg(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            ++i;
        } while (arr[i] < 0);

        do
        {
            --j;
        } while (arr[j] >= 0);

        if (i >= j)
            return;

        swap(arr[i], arr[j]);
    }
}

void eff_segregateEvenOdd(int arr[], int n) 
{
    int i = -1, j = n;
    while(true)
    {
        do{
            ++i;
        } while (arr[i] % 2 == 0);
        do
        {
            --j;
        } while (arr[j] % 2 != 0);

        if(i>=j)
            return;

        swap(arr[i], arr[j]);
    }
}    

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // naive_segregatePosNeg(arr, n);
    // eff_segregatePosNeg(arr, n);
    eff_segregateEvenOdd(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

/*

for pos and neg

ip:
4
15 -3 -2 18

op:
-2 -3 15 18
*/

/*

for even odd

ip:
6
2 7 9 3 12 8

op:
2 8 12 3 9 7

*/