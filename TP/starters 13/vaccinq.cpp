#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 1; i <= n; i++) \
    cin >> arr[i]
#define out(n, arr)             \
    for (int i = 1; i <= n; i++) \
    cout << arr[i]
# define here cout<<"\nHERE\n"
#define lli long long int
using namespace std;

lli get_minutes(vector<int> &arr, lli n, lli x, lli y, lli p)
{
    lli i = 1, total_min=0;
    while(i<=n)
    {
        if(arr[i] == 0)
            total_min += x;
        else
            total_min += y;
        
        if(i==p)
            return total_min;

        i++;
    }
    return -1;
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
        lli n, p, x, y;
        cin >> n >> p >> x >> y;
        vector<int> arr(n+1);
        in(n, arr);
        // out(n, arr);
        // cout << "\n";

        cout << get_minutes(arr, n, x, y, p) << "\n";
    }
    return 0;
}