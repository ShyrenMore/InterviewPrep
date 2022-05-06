/*

given an arr, find count of distinct els lol
arr[] = {15, 12, 13, 12, 13, 13, 18}
op: 4

sol:
hashing use karo bc unless u are stupid and you want O(n^2) sol
*/

/* 
naive sol: time: O(n^2), space: O(1)
initialise res = 0
traverse the array 
for every el, check if it is present on left side 
by maintaining a bool variable isDuplicate
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int countDist(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }

        if(!isDuplicate)
            ++res;
    }

    return res;
}

/*
sol 2: time: O(n), space: O(n)
Create unordered_set
and insert in the set

*/

int countDist_hashing(int arr[], int n)
{
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
        us.insert(arr[i]);
    return us.size();
}

/*
Less line of code implementations 
*/

int countDist_hashing_eff(int arr[], int n)
{
    unordered_set<int> us(arr, arr + n);
    return us.size();
}