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

int getMaxSum(vector<int> arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++)
    {
        if(arr[i] >= 0)
            break;
        arr[i] *= -1;
    }

    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            ans += arr[i];
    }
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        in(n, arr);
        op(getMaxSum(arr, n, k));
    }
    return 0;
}