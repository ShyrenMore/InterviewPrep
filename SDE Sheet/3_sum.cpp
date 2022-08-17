#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
link: https://leetcode.com/problems/3sum/

Video link: https://youtu.be/jzZsG8n2R9A
*/

class NaiveSolution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        for (int i = 0; i < n-2; i++)
        {
            for (int j = i+1; j < n-1; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    temp.clear();
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                    }

                    if(temp.size()!=0)
                        ans.push_back(temp);
                }
                
            }
            
        }
        return ans;
    }
};

/*

The above naive sol of generating all combinations doesn't work if input arr contains dupli els

eff: 
Sort the arr,
Skip duplicate els
Now if we fix first el
The remaining arr els are like two sum 
use left and right ptr

eg: -3, 3, 4, -3, 1, 2
after sort: -3, -3, 1, 2, 3, 4

-3 + L + R == 0
if our sum is > 0, decrease right ptr since ip arr is sorted
if sum < 0, increment left ptr 
now there could be duplicate values of L and R also

Time: O(nlogn + n^2) = O(n^2)
Space: O(1)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        vector<int> temp;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            if(i == 0 || (i>0 && nums[i] != nums[i-1]))
            {
                int l = i + 1;
                int r = n - 1;
                int threeSum = 0;

                while(l < r)
                {
                    threeSum = nums[i] + nums[l] + nums[r];
                    if(threeSum > 0)
                        r--;
                    else if (threeSum< 0)
                        l++;
                    else 
                    {
                        // pair found
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        
                        // for next itr
                        l++;

                        // also check for dupli
                        while(nums[l] == nums[l-1] and l < r)
                            l++;
                    }
                }
            }
        }

        return ans;
    }
};