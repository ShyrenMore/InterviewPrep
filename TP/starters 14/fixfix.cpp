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

void ans(lli n, lli x)
{
    if (x == n)
    {
        for (lli i = 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
    }
    else if (x == n - 1)
        cout << "-1\n";
    else 
    {
        for (lli i = 1; i <= x; i++)
            cout << i << " ";
        
        for (lli i = x + 2; i <= n; i++)
            cout << i << " ";
        cout << x + 1 << "\n";
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
        lli n, x;
        cin >> n >> x;
        ans(n, x);
    }
    return 0;
}