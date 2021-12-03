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

int ans(int a, int b, int p, int q)
{
    if(a==p && b==q)
        return 0;
    else if ((((a + b) & 1) && (p + q) % 2 == 0) || (((p + q) & 1) && (a + b) % 2 == 0))
        return 1;
    return 2;
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
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        cout << ans(a, b, p, q)<<"\n";
        // vector<lli> arr(n);
    }
    return 0;
}