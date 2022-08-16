#include <iostream>
#include <vector>
using namespace std;

/*
Link: https://leetcode.com/problems/maximum-subarray/
Naive Approach: Generate all subarray in two loops and then their sum in another loop 
return max of them

Time: O(n^3)
*/

class NaiveSolution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int n = nums.size();

        if(n == 1)
            return nums[0];
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                ans = max(ans, sum);
            }
            
        }
        return ans;
    }
};

/*
Best sol: Kadane's algo
Traverse the array
for every el, find the max sub-arr sum till that el
and overall res will be max of all values

eg:
consider arr: [-5, 1, -2, 3, -1, 2, -2]
for -5, max_sum = -5
for 1, max_sum = max(-4, 1) = 1
for -2, 3 choices: max(-5+1-2, 1-2, -2) = max(-6, -1, -2) = -1
for 3, max(-5+1-2+3, 1-2+3, -2+3, 3) = 3
for -1, it will have 5 choices, = 2
for 2, it will have 6 choices, = 4
for -2, it will have 7 choices, = 2

ans = max(-5, 1, -1, 3, 2, 4, 2) = 4

Time: O(N)
we do this by doing 

maxEnding at idx i = maximum of
- maxEnding(i-1) + curr_el
- curr_el

i.e maxEnding[i] = max(maxEnding[i-1] + arr[i], arr[i]);
*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        int maxEnding = nums[0];
        int n = nums.size();

        if (n == 1)
            return nums[0];

        for (int i = 1; i < n; i++)
        {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            ans = max(ans, maxEnding);
        }
        return ans;
    }
};