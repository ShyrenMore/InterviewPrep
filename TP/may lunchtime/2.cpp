#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_arr(n, arr)         \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << " "
#define op(n) cout << n << "\n"
#define lli long long int
#define here cout << "\nHERE\n"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

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
        lli n, m;
        cin >> n >> m;
        set<lli> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        vector<lli> arr;
        // in(n, arr);
        for(auto x: s)
            arr.push_back(x);

        sort(arr.begin(), arr.end());
        // out_arr(arr.size(), arr);
        int n2 = arr.size();
        int diff1 = (arr[n2 - 1] - arr[n2 - 2]);
        int diff2 = m - abs(arr[n2 - 2] - arr[n2 - 1]);
        // deb2(diff1, diff2);
        int diff = max(diff1, diff2);
        // int diff = diff;
        // deb(diff2);
        // int ans = arr[n - 2] + arr[n - 1] + (abs(arr[n - 1] - arr[n - 2]) % m);
        int ans = arr[n2 - 2] + arr[n2 - 1] + diff;
        op(ans);
    }
    return 0;
}