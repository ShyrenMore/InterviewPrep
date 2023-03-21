#include <bits/stdc++.h>
using namespace std;

/*
Given strings A, B, and C, find whether C is formed by an interleaving of A and B.
For example: A = "XYZ" B = "ABC"
so we can make multiple interleaving string C like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more 
Your task is to check whether you can create a string which can be equal to C.

Link: https://practice.geeksforgeeks.org/problems/interleaved-strings/1
*/

class Solution{
  public:
    /*You are required to complete this method */
    int f(int i, int j, int k, string A, string B, string C, vector<vector<int>> &dp)
    {
        if(i == A.size() && j == B.size() && k == C.size())
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans1 = 0, ans2 = 0;
        if(i < A.size() && A[i] == C[k])
            ans1 = f(i+1, j, k+1, A, B, C, dp);
        
        if(j < B.size() && B[j] == C[k])
            ans2 = f(i, j+1, k+1, A, B, C, dp);
        
        return dp[i][j] = (ans1+ans2);
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(0, 0, 0, A, B, C, dp);
    }

};
