/*
Given n and m
print first m n-bonaaci numbers

what is a n-bonacci number?
fib = two
so fibonacci means sum of two els
and n-bonacci number will be sum of previous n-elements

ip: n=3, m=8
op: 0 0 1 1 2 4 7 13
exp: 
13 = 2+4+7
7 = 4+2+1

ip: n=4, m=10
op: 0 0 0 1 1 2 4 8 15 29

Approach:
construct initial window of size n
the number next to window will be sum of current window
also for an n-bonacci series there are n-1 zeroes
this is visible in above eg
when n=4, 3 zeroes
when n=3, 2 zeroes

Time: O(m) 🤑
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> generateNbonacci(int n, int m)
{
    vector<int> ans(m);

    for (int i = 0; i < n-1; i++)
        ans[i] = 0;

    ans[n-1] = 1;
    int curr_sum = 1;

    for (int i = n, j = 0; i < m && j < m; i++, j++)
    {
        ans[i] = curr_sum;
        curr_sum += ans[i] - ans[j];
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> ans = generateNbonacci(n, m);
        for(auto x: ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

/*
ip:
3
2 10
3 8
4 10

op:
0 1 1 2 3 5 8 13 21 34
0 0 1 1 2 4 7 13
0 0 0 1 1 2 4 8 15 29

*/