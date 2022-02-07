#include <iostream>
#include <vector>
using namespace std;

/*

Remove Duplicates from a sorted array
ip: arr[] = {10, 20, 20, 30, 30, 30, 30}
op: arr[] = {10, 20, 30, _, _, _, _}

Naive Approach: Create auxilary array of same size
copy only distinct elements
copy elements of distinct arrays into original arrays

return size of new array
Time: O(n)
Space: O(n)

Efficient Approach: 
initialise a res var as 1
start from second element 
we compare every el with last element that we include in our result

arr[] = {10, 20, 20, 30, 30, 30}
res=1
i=1: arr[] = {10, 20, 20, 30, 30, 30, 30} res=2
i=2: arr[] = {10, 20, 20, 30, 30, 30, 30} res=2
i=3: arr[] = {10, 20, 30, 30, 30, 30, 30} res=3
i=4: arr[] = {10, 20, 30, 30, 30, 30, 30} res=3
i=5: arr[] = {10, 20, 30, 30, 30, 30, 30} res=3

so basically we have same consecutive els, ignore
else copy new el to where res is pointing
at the end, res will have count of distinct els

Time: O(n)
*/

int removeDuplicates(vector<int> &arr)
{
    int n = arr.size();
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

int eff_removeDuplicates(vector<int> &arr)
{
    int res = 1, n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if(arr[i] != arr[res-1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main()
{
    vector<int> vect{10, 20, 20, 30, 30, 30, 30};
    int new_size = removeDuplicates(vect);

    for (int i = 0; i < new_size; i++)
        cout << vect[i] << " ";
    
    return 0;
}

/*
op: 10 20 30
*/