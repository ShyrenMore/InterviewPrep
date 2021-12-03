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

bool cmp(string &s1, string &s2)
{
    return count(s1.begin(), s1.end(), '1') < count(s2.begin(), s2.end(), '1');
}

lli get_invs(string &s)
{
    lli invs = 0;
    lli ones = 0;
    for(char c: s){
        if(c == '1')
            ones++;
        else
            invs += ones;
    }
    return invs;
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
        int n, m;
        cin >> n >> m;
        vector<string> arr(n);

        for (string &s : arr)
            cin >> s;

        sort(arr.begin(), arr.end(), cmp);

        string mega_string;
        for (string s : arr)
            mega_string += s;

        cout << get_invs(mega_string) << "\n";
    }
    return 0;
}