#include <iostream>
#include <unordered_set>
using namespace std;

/*
given unsorted array and a sum
find if there exists a pair of two array element such that their sum is equal to given sum

ip: arr[] = {3, 2, 15, -8, 8} sum = 17
op: Yes (2, 15)

ip: arr[] = {2, 4, 6, 3} sum = 11
op: No

ip: arr[] = {5, 8, -3, 6} sum = 3
op: Yes

sol 2: If array was sorted, we could have used two pointer approach which could be a O(nlogn)+O(n) sol
*/

/*
sol1: O(n^2) time, O(1) time
Traverse all els from L to R
for every el, traverse the els after it 
    check if sum of curr_el + anyother el == given sum
        if it is return true

at the end if loop is over, return false 

worst case: all subarrays are traversed, so n-1 + n-2...1
*/

bool hasPair(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(arr[i] + arr[j] == sum)
                return true;
    return false;
}

/*
sol3: O(n) time and space
traverse from L to R
at ith element, elements from 0 to i-1 will be in hashtable, not the complete array but only els from 0 to i-1
check if ith element, is forming a valid pair with any of the elements present in hashtable
we do this by searching for sum-arr[i] in hashtable 
if it does not form a pair, insert the element in hashtable
*/

bool hasPair_hashing(int arr[], int n, int sum)
{
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        if(us.find(sum-arr[i]) != us.end())
            return true;

        us.insert(arr[i]);
    }
    return false;
}

int main()
{
    int a[] = {3, 2, 15, -8, 8};
    int n = 5;
    int sum = 17;
    cout << hasPair(a, n, sum);
    cout << hasPair_hashing(a, n, sum);
}

/*
op:
1 (true)
1 (true)
*/

/*
if asked to print indices of the pair
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> ans(2);
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            if(um.find(target-arr[i]) != um.end())
            {
                ans[0] = um[target-arr[i]];
                ans[1] = i;
                
            }

            um.insert({arr[i], i});
        }    
        
        return ans;
    }
};