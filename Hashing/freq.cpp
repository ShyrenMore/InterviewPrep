/*
ip: arr[] = {10, 12, 10, 15, 10, 20, 12, 12}
op: 
10  3
12  3
15  1
20  1

Array is unsorted
*/

#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

/*
sol1: O(n^2) time, O(1) space
Traverse elements from L to R
for every el, 
check if we have seen the element before
if yes, ignore the el
if no, count the freq of el by going to right side 
*/

void printFreq(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // check if el is seen before
        bool isProcessed = false;
        for (int j = 0; j < i; j++)
            if(arr[i] == arr[j])
            {
                isProcessed = true;
                break;
            }
        
        // if seen before do nothing
        if(isProcessed)
            continue;
        
        // else if it is new el, start counting the occurence on right side
        int freq = 1;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
                ++freq;
        }

        cout << arr[i] << " " << freq << "\n";
    }
}

/*
sol2: hashmap i.e unordered map, Time: O(n), space: O(n)
here key will be array elements 
values will be freq 

Traverse the array el and insert each el into hashmap
if that key is not present
    then after inserting it's value should be 1
else if it is present
    we just need to increase it's value 
*/

void countFreq_hashmap(int arr[], int n)
{
    // unordered_map<int, int> um;
    map<int, int> um;

    for (int i = 0; i < n; i++)
        um[arr[i]]++;

    /*
    um[arr[i]]++ means
    key = arr[i]
    and um[] will give access to the key's value
    so um[key] = +1;
    i.e when ever we insert the same key again, the value will be incremented by one 
    */

   for(auto x: um)
       cout << x.first << " " << x.second << "\n";
}

int main()
{
    int arr[] = {10, 12, 10, 15, 10, 20, 12, 12};
    int n = 8;
    countFreq_hashmap(arr, n);
}

/*
20 1
15 1
10 3
12 3

Note the order of keys is randomised
if we want the order according to the appearance of els  i..e
10 3
12 3
15 1
20 1

we need to use a map instead of unordered_map
BUTTT...
your time complexity of insert operation is O(logN)
so overall time will increase to O(NlogN)
*/