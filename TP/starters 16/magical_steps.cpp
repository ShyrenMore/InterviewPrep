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

const int n = 1e7;


// prime array contains booleans values
// 1 represents no is prime
// 0 means non prime
bool prime[n + 2];

// total_prime[i] will be no of primes from range 0 to i
int total_prime[n + 2];

void sieve()
{
    fill(begin(prime), end(prime), true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        // initialise curr count of total prime
        total_prime[i] = total_prime[i - 1];

        // check if curr no is prime
        if(!prime[i])
            continue;

        total_prime[i]++;

        for (int j = 2 * i; j <= n; j+=i)
            prime[j] = false;
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
    sieve();

    int t;
    cin >> t;
    while (t--)
    {
        lli x, y, count = 0;
        cin >> x >> y;

        cout << y - x - (total_prime[y] - total_prime[x + 1])<<"\n";
    }
    return 0;
}