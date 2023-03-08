// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
class Solution{
	public:
	vector<int> longestSubsequence(int n, vector<int>arr)
    {
        // your code here
        vector<int> lis(n);
        lis[0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            lis[i] = 1;
            for(int j = 0; j < i; j++)
                if(arr[j] < arr[i])
                    lis[i] = max(lis[i], lis[j]+1);
        }
        return lis;
    }
    
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int> fromStart = longestSubsequence(n, nums);
	    reverse(nums.begin(), nums.end());
	    vector<int> fromEnd = longestSubsequence(n, nums);
	    int ans=0;
	    for(int i = 0; i < n; i++)
	        ans = max(ans, fromStart[i] + fromEnd[n-i-1] - 1);
	    return ans;
	}
};
