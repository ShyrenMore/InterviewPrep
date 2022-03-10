#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_arr(n, arr)         \
    for (int i = 0; i < n; i++) \
    cout << arr[i]
#define op(n) cout << n << "\n"
#define lli long long int
#define here cout << "\nHERE\n"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

void solve()
{
    lli n, res = 0;
    cin >> n;
    string s;
    cin >> s;

    int low = 0, high = 1;
    if (n == 1)
        op(1);
    else
    {
        while (low < n && high < n)
        {
            if (s[low] == s[high])
                ++high;
            else
            {
                int len = high - low;
                if (len % 2)
                    res += len / 2 + 1;
                else
                    res += len / 2;

                low = high;
                high++;
            }
        }

        int len = high - low;
        if (len % 2)
            res += len / 2 + 1;
        else
            res += len / 2;

        op(res);
    }
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}