// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1 
class Solution {
	public:
	int f(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(idx1 < 0 || idx2 < 0)
            return 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        int match = -1e9, not_match = -1e9;
        if(s1[idx1] == s2[idx2] && idx1 != idx2)
            match =  1 + f(idx1-1, idx2-1, s1, s2, dp);
        else 
        {
            not_match = 0 + max(
                f(idx1-1, idx2, s1, s2, dp),
                f(idx1, idx2-1,s1,s2, dp)
            );
        }
        
        return dp[idx1][idx2] = max(match, not_match);
    }
    
	int LongestRepeatingSubsequence(string str){
	    // Code here
	    int x = str.length();
        string B = str;
        vector<vector<int>> dp(x,vector<int>(x,-1));
        return f(x-1, x-1, str, B, dp);
	}

};
