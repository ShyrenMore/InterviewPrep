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

bool ans(string s)
{
    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] == 'L' && s[i + 1] == 'L')
            return true;
        else if (s[i] == 'R' && s[i+1] == 'R')
            return true;

    return false;
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
        lli n, count = 0;
        cin >> n;
        string s;
        cin >> s;
        
        // vector<lli> arr(n);
        if(ans(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }   
    return 0;
}