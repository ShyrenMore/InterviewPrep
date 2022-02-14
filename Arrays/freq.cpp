/*
Given a sorted array, find frequencies of all elements in the given array

ip: arr[] = {10, 10, 10, 25, 30, 30}
op:
10 3
25 1
30 2

ip: arr[] = {10, 10, 10, 10}
op:
10 4

ip: arr[] = {10, 20, 30}
op:
10 1
20 1
30 1

Approach: Traverse the array, check if it is same as previous element then increment the count
if curr element is not same as prev element then that means we can print the freq of curr element can again count freq of next element

Time: theta(n)

Dry run
arr[] = {10, 10, 10, 30, 30, 40}
Initially: freq = 1
i=1: freq = 2
i=2: freq = 3
i=3: print(10 3), freq = 3
i=4: freq = 2
i=5: print(30 2), freq = 1
After loops:
    print(40 1)
2nd testvase
arr[] = {40, 50, 50, 50}
40 1
50 3
*/

#include <iostream>
using namespace std;

void printFreq(int arr[], int n)
{
    int freq = 1, i = 1;
    while(i < n)
    {
        while (i < n && arr[i] == arr[i-1])
        {
            ++freq;
            ++i;
        }

        cout << arr[i - 1] << " " << freq << "\n";
        ++i;
        freq = 1;
    }

    // if last two el are different
    if (n == 1 || arr[n - 1] != arr[n - 2])
        cout << arr[n - 1] << " 1";
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
    printFreq(arr, n);
    return 0;
}

/*
op:
5
1 2 2 3 3 3
1 1
2 2
3 2
*/