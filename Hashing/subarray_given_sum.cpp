#include <iostream>
#include <unordered_set>
using namespace std;

/*
Given an array
find if there exists a sub-array with sum of all elements as given sum

ip: arr[] = {5, 8, 6, 13, 3, -1}, sum = 22
op: Yes (6, 13, 3)

ip: arr[] = {15, 2, 8, 10, -5, -8, 6}
op: Yes (10, -5, -8, 6)

*/

/*
sol1: Time: O(n^2) and space: O(1)
for each el, consider it as starting el for that subarr
and find sum of all subarrays beginning with it 
*/

bool isGivenSumSubarr(int arr[], int n, int given_sum)
{
    for (int i = 0; i < n; i++)
    {
        int subarr_sum = 0;
        for (int j = i; j < n; j++)
        {
            subarr_sum += arr[j];
            if (subarr_sum == given_sum)
                return true;
        }
    }

    return false;
}

/*
sol2: O(n) time and space based on prefix sum and hashing 
search for (prefix_sum-given_sum) is present in prefix_sum array (hashtable)

eg:
arr = [5, 8, 6, 13, 3, -1], given_sum=22
op: yes

prefix_arr or hashtable = [5, 13, 19, 32, 35, 34]
now when I am at 35, 
prefix[i]-given_sum = 35-22 = 13 which is 2nd el of prefix sum

so, there is subarray after 13 till 35 which has sum=22
here since we needed searching opertion, so hashtable is most efficient: O(1) time

In the prev problem i.e zero sum subarray, 
we were searching for prefix_sum - 0
*/

// code gives false for input
bool isGivenSumSubarr_hashing(int arr[], int n, int given_sum)
{
    unordered_set<int> prefixHashTable;
    int prefixSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (prefixSum == given_sum)
            return true;

        if (prefixHashTable.find(prefixSum-given_sum) != prefixHashTable.end())
            return true;

        prefixHashTable.insert(prefixSum);
    }

    return false;
}

int main()
{
    int arr[] = {5, 8, 6, 13, 3, -1};
    int n = 6;
    int sum = 23;
    cout << isGivenSumSubarr(arr, n, sum) << "\n";
    cout << isGivenSumSubarr_hashing(arr, n, sum) << "\n";
}