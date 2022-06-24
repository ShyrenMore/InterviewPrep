#include <iostream>
#include <cstring>  // for memset
#include <vector>
using namespace std;

// memoization sol
int f(int n, vector<int> &dp)
{
    if(n<=1)
        return n;
    if(dp[n]!=-1)
        return dp[n];

    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

// Space optimised
int getFibo(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    // int dp[n + 1];
    // memset(dp, -1, sizeof dp);
    vector<int> dp(n+1, -1);
    cout << f(n, dp);
}