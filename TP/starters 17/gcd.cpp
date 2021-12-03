#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out(n, arr)             \
    for (int i = 0; i < n; i++) \
    cout << arr[i] <<" "
#define lli long long int
using namespace std;

bool ans(vector <lli> &arr)
{
    lli i = 0;
    while(i+1 < arr.size())
    {
        if(arr[i] % arr[i+1] != 0)
            return 0;
        i++;
    }
    return 1;
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
        cin >> n;
        vector<lli> arr(n);
        in(n, arr);
        if(ans(arr))
        {
            out(n, arr);
            cout << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}