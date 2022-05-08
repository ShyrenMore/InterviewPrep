/*
given two binary arrays
find longest common subarr, such that sum of els of subarr, is same in both arrays
You may assume both arr are of same size

arr1 = [0, 1, 0, 0, 0, 0]
arr2 = [1, 0, 1, 0, 0, 1]
op: 4
exp: indices 1 to 4 satisfy the criteria
sum = 1, arrangement can be random

arr1 = [0, 1, 0, 1, 1, 1, 1]
arr2 = [1, 1, 1, 1, 1, 0, 1]
op: 6
exp: indeices 1 to 6 with sum = 5 is longest

arr1 = [0, 0, 0]
arr2 = [1, 1, 1]
op: 0
*/

#include <iostream>
#include <unordered_map>
using namespace std;

/*
sol1: O(n*n) time, O(1) space
consider all els as first el of subarr for both arrays
for every subarr, we compute sum of both the subarrays 
at every moment, we compare both the sum
and maintain the maximum len
*/

int maxCommon(bool arr1[], bool arr2[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j < n; j++)
        {
            sum1 += arr1[j];
            sum2 += arr2[j];
            if(sum1 == sum2)
                res = max(res, j - i + 1);
        }
    }

    return res;
}

/*
sol2: O(n) time and space
This problem is going to reduce into the problem of finding length of largest subarray with 0 sum

we do this by subtracting one array from other array so we will have an array of -1, 1, 0
so we need to find len of longest subarr with 0 sum

*/

int getMaxLen_hashing(int arr[], int n)
{
    unordered_map<int, int> m;
    int prefixSum = 0, len = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == 0)
            len = i + 1;

        // store the first occurence
        if (m.find(prefixSum) == m.end())
            m.insert({prefixSum, i});

        if (m.find(prefixSum - 0) != m.end())
            len = max(len, i - m[prefixSum - 0]);
    }
    return len;
}

int main()
{
    int arr1[] = {0, 1, 0, 1, 1, 1, 1};
    int arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = 7;

    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr1[i] - arr2[i];

    cout << getMaxLen_hashing(temp, n);
}