#include <iostream>
#include <vector>
using namespace std;

/*
link: https://leetcode.com/problems/rotate-array/
*/
class Solution
{
public:
    void myreverse(vector<int> &nums, int low, int high)
    {
        while (low < high)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        // Reverse the first n - k numbers.
        myreverse(nums, 0, n - k - 1);

        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        myreverse(nums, n - k, n - 1);

        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        myreverse(nums, 0, n - 1);
    }
};