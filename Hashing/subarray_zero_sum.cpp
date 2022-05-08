#include <iostream>
#include <unordered_set>
using namespace std;

/*
Given an array
find if there exists a sub-array with sum of all elements as 0

ip: arr[] = {1, 4, 13, -3, -10, 5}
op: Yes (13, -3, -10)

ip: arr[] = {3, 1, -2, 5, 6}
op: No

*/

/*
sol1: Time: O(n^2) and space: O(1)
for each el, consider it as starting el for that subarr
and find sum of all subarrays beginning with it 

eg: arr[] = {4, -3, 2, 1}

when i=0: 
j = 0, sum = 4
j = 1, sum = -3
j = 2, sum = 3
j = 3, sum = 1

i=1:
j = 1, sum = -3
j = 2, sum = -1 (-3+2)
j = 3, sum = 0 (-3+2+1)
return true
*/

bool isZeroSumSubarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int subarr_sum = 0;
        for (int j = i; j < n; j++)
        {
            subarr_sum += arr[j];
            if(subarr_sum == 0)
                return true;
        }
    }

    return false;
}

/*
sol2: use prefix sum and hashing
O(n) space and time
Traverse the arr from L to R
keep on computing the prefix sum

now let's say array els 
are 
a0, a1, .... ai-1, ai, ai+1...aj...an-1
we know that subarray, ai to aj has zero sum
so in this scenario
prefix[a0 to ai] == prefix[a0 to aj] since sum of a[i] to a[j] is 0

how do we check if prefix is repeating?
i.e how do we know prefix[a0 to aj] has same value as prefix[a0 to ai]
for that purpose we use hashing 

So while computing the prefix sum for each el, we also insert the sum in hashtable 
When we find a prefix sum already present in hashtable, return true
eg:

arr[] = {-3, 4, -3, -1, 1}
prev_sum = 0
h = {}

i=0:
prefix_sum = -3
h={-3}

i=1:
prefix_sum = 1
h={-3, 1}

i=2:
prefix_sum = -2
h={-3, 1, -2}

i=3:
prefix_sum = -3
already present in hashtable 
return true
*/

bool isZeroSumSubarr_hashing(int arr[], int n)
{
    unordered_set<int> hashtable;

    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        
        if(prefixSum == 0)
            return true;

        if(hashtable.find(prefixSum)!= hashtable.end())
            return true;

        hashtable.insert(prefixSum);
    }

    return false;
}

int main()
{
    int arr[] = {3, 1, -2, 5, 6};
    int n = 5;
    cout << isZeroSumSubarr(arr, n) << "\n";
    cout << isZeroSumSubarr_hashing(arr, n) << "\n";
}