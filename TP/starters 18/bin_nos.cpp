#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out(n, arr)             \
    for (int i = 0; i < n; i++) \
    cout << arr[i]
#define lli long long int
using namespace std;

void solve(int n)
{
    vector<int> ans, din = {1, 3, 5, 9, 17, 33, 65, 129, 257, 513};

    // greedy traversing: largest to smallest
    for (int i = 9; i >= 0; i--)
    {
        if(din[i] <= n)
        {
            ans.push_back(din[i]);
            n -= din[i];
        }
    }

    // corner case
    if(n)
        ans.push_back(1);

    cout << ans.size() << "\n";
    for (int el: ans)
        cout << el << " ";
    cout << "\n";
}

int main()
{

    // /*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // since we want palindromic nos, we need to express it in sum of odd nos
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}