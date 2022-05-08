#include <iostream>
#include <unordered_map>
// #include
using namespace std;

/*

given a binary array, find length of longest subarr, such that it has equal 0s and 1s

arr = [1, 0, 1, 1, 1, 0, 0]
op: 6

arr = [1, 1, 1, 1]
op: 0

*/

/*
sol1: O(n^2) time and O(1) space
consider every element as beginning of subarr
then an inner loop that considers every element to the right of it as ending element
we count of 0s and 1s
if they are equal we store the len in variable called res
*/

int longestSubArr(bool arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count0 = 0, count1 = 0;
        for (int j = i; j < n; j++)
        {
            if(arr[j] == 0)
                ++count0;
            else
                ++count1;

            if(count0 == count1)
                res = max(res, j - i + 1);
        }
    }

    return res;
}

/*
sol2: O(n) time and space
This problem is going to reduce into the problem of finding length of largest subarray with 0 sum
we can do this by replacing all 0 with -1s
so now question becomes finding longest subarr with 0 sum
*/

int getMaxLen_hashing(int arr[], int n)
{
    unordered_map<int, int> m;
    int prefixSum = 0, len = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i])
            prefixSum++;
        else
            --prefixSum;

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
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int n = 7;
    cout << getMaxLen_hashing(arr, n) << "\n";
    return 0;
}

/*
op: 6
*/