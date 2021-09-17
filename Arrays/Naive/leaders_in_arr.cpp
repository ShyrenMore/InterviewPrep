#include <iostream>
using namespace std;

/*
Given an array of integers, whether be it sorted or unsorted, print leaders in an array
An element is called leader if there is nothing greater than the element from the right of it

ip: arr[] = {7, 10, 4, 3, 6, 5, 2}
op: 10, 6, 5, 2

ip: arr[] = {10, 20, 30}
op: 30

ip: arr[] = {30, 20, 10}
op: 30 20 10

Approach: Traverse the array, for every element traverse the right side of it, and if we find such element which is greater or equal we will break the loop

if we never break the loop, the element is leader 
*/

void leaders(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // found will be true when it finds an element smaller than curr_el
        bool found = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                found = true;
                break;
            }
        }
        if(!found)
            cout << "Leader found :: " << arr[i] << "\n";
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

    leaders(arr, n);
    // printArr(arr, n);
    return 0;
}