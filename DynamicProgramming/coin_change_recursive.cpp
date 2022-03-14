/*
ip: coins[] = {1, 2, 3}     sum = 4
op: 4
explanation:
4 possible ways:
1 1 1 1
2 2
1 3
2 1 1

ip: coins[] = {2, 5, 3, 6}      sum = 10
op: 5
explanation:
5 possible ways:
5 5
2 2 2 2 2
6 2 2
5 3 2
3 3 2 2

Sol:
begin from last item or coin
there are two possibilities:
1) u include it, then reduce sum 
2) u don't include it then recursively call for n-1 remaining coins i.e reduce array size

at the end return the result

base case:
when sum is 0, you can achieve this by not picking any coin
i.e 1 way to achieve 0 sum
so return 1 

when 0 coins are left, and some sum is left to complete 
so you cannot achieve that with 0 coins,
hence return 0 
*/

int getCount(int coins[], int n, int sum)
{
    if(sum == 0)
        return 1;
    
    if(n==0)
        return 0;

    // not considering the coin
    int res = getCount(coins, n, sum - coins[n - 1]);

    // include last coin and reduce sum 
    if(coins[n-1] <= sum)
        res += getCount(coins, n, sum - coins[n - 1]);

    return res;
}

/*

Iterative sol/ DP sol
in the recursive sol, we saw there are two parameters that change
n and sum 
so we create a 2D array of size (sum+1)*(n+1) 
dp[i][j] will indicate no of combinations with sum i and considering coins from 1 to j

if sum is 0, ans will be 1, so fill first row with 1
if no of coins is 0, and sum > 0, then there are 0 ways of combinations, so fill first col with 0
*/

int getCount_dp(int coins[], int n, int sum)
{
    int dp[sum + 1][n + 1];

    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    
    for (int i = 1; i <= sum; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // take count of j-1 coins
            dp[i][j] = dp[i][j - 1];
            if(coins[j-1] <= i)
                dp[i][j] += dp[i - coins[j - 1]][i];
        }
    }

    return dp[sum][n];
}