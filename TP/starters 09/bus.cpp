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
        int m, n, q;
        cin >> n >> m >> q;
        vector<int> boarded(n, -1);
        bool isConsitent = true;
        int count = 0;
        while(q--)
        {
            char sign;
            cin >> sign;
            int i;
            cin >> i;
            i--;

            if(sign == '+' && boarded[i] != -1 || (sign == '-' && boarded[i] != 1) || (sign=='+' && count == m))
                isConsitent = false;

            if(sign == '+')
            {
                boarded[i] = 1;
                count++;
            }
            else if (sign == '-')
            {
                boarded[i] = 0;
                count--;
            }
        }
        cout << (isConsitent ? "Consistent" : "Inconsistent")<<"\n";
    }
    return 0;
}