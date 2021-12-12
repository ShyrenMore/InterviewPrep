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
#define INF INT_MAX
#define MOD 1000000007
#define here cout << "\nHERE\n"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

lli solve(vector<lli> arr)
{
    map<lli, lli> freq;
    lli ans = 1;

    for (lli i : arr)
        freq[i]++;

    for (auto x : freq)
    {
        lli freqEl = x.second;
        ans *= (freqEl + 1);
        ans %= MOD;
    }
    ans--;
    return ans;
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
        lli n;
        cin >> n;
        vector<lli> arr(n);
        in(n, arr);
        
        op(solve(arr));
    }
    return 0;
}