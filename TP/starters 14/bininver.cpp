#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define here cout << "I am here\n";
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out(n, arr)             \
    for (int i = 0; i < n; i++) \
    cout << arr[i]
#define lli long long int
using namespace std;

lli ans(vector <lli> &arr, int n)
{
    for(auto el : arr)
        if(el & 1)
            return 0;
    
    // if it reaches here all el are even
    for (auto el: arr)
        if (el % 4 != 0)
        {
            // here;
            return 1;
        }

    // if it reaches here all el are even and mutiples of 4
    // lli min_el = *min_element(arr.begin(), arr.end());
    vector<lli> possible_ans;
    for(auto x: arr)
    {
        lli count = 0;
        while (!(x & 1))
        {
            ++count;
            x /= 2;
        }
        possible_ans.push_back(count);
    }
    
    return *min_element(possible_ans.begin(), possible_ans.end());
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
        cout << ans(arr, n) <<"\n";
    }
    return 0;
}