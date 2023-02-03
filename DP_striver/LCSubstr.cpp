// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=youtube
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution{
    public:
    int ans = 0;
    
    int f(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(idx1 < 0 || idx2 < 0)
            return 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        int match = 0;
        if(s1[idx1] == s2[idx2])
            match = 1 + f(idx1-1, idx2-1, s1, s2, dp);

        return dp[idx1][idx2] = match;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, f(i, j, S1, S2, dp));
            }
        }
        return ans;
        // return ans;
    }
};
