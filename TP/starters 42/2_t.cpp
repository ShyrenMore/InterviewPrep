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
// #pragma GCC optimize("O3,unrolli-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<lli> arr(n);
    in(n, arr);
    lli mn = INT_MAX;
    lli mx = INT_MIN;
    for (lli i = 0; i < n; i++)
    {
        if (i == 0)
        {
            mn = arr[i];
            mx = arr[i];
        }
        else
        {
            if (arr[i] > mn && arr[i] < mx)
            {
                op("NO");
                return;
            }
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
    }
    op("YES");
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

