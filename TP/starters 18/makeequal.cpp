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

lli ans(vector <int> &arr)
{
    lli maxi = *max_element(arr.begin(), arr.end());
    lli ans = 0;
    for (auto el: arr)
    {
        ans = max(maxi - el, ans);
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
        int n;
        cin>>n;
        vector<int> arr(n);
        in(n, arr);

        cout << ans(arr)<<"\n";
    }
    return 0;
}