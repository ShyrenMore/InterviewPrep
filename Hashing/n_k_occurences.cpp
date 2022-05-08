/*
Given an arr, and number k
print all the elements having more than n/k occurences

arr = [30, 10, 20, 20, 10, 20, 30, 30]  k=4
op: 20 30
exp: n=8, k=2
n/k = 2
count of 20 = 3 > n/k
count of 30 = 3 > n/k

arr = [30, 10, 20, 30, 30, 40, 30, 40, 30]  k=2
op: 30
exp: n=9, k=2
n/k = 4.5
all nos that appear 5 or more time
30 appears 5 times
*/

/*
sol1:
sort that array!
keep counting consecutive same elements
and check if count > n/k 
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void printNByK(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = 1, count = 1;
    while(i < n)
    {
        while(i < n && arr[i] == arr[i-1])
        {
            ++count;
            ++i;
        }

        if(count > n/k)
            cout << arr[i - 1] << " ";

        count = 1;
        i++;
    }
}

/*
sol2: O(n) time and space
use map lol
keys == arr els
values == freq 

but if k <<<< n, 
storing everything in a map might not be a good idea 
*/

void printNByK_hashing(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    
    for(auto e: m)
        if(e.second > n/k)
            cout << e.first << " ";
}

/*
sol3: O(nk) time

through observation we know that no of elements in op are at most k-1

find candidate elements: els which can be possible op
then it validates whether candidates are actually final sol
This idea is based on Murray's boating algo?

- Create empty map
-
for(i = 0; i < n; i++)
    - if m contains arr[i]
        m[arr[i]]++
    - else if m.size() < k-1
        m.put(arr[i], 1)
    - else
        decrease all values in m by one 
        IF value becomes 0, remove it

- FOR all elements in m
    print the elements that actually appear more than n/k times
*/