#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

given x, return root x if x is perfect square
if x is not perfect square, return floor of it's square root

ip: x=4
op: 2

ip: x=14
op: 3 (3.something)

ip: x=25
op: 5

So basically for any x between 4 and 9, it's square root will be 2
similarly, for any x between 9 and 16, it's square root will be 3

Naive solution: check every no one by one starting from 1, if it is square root we return the number

Time: theta (root(x)) or theta (x ^ 1/2) 

Efficient: use binary search on range 1 to x, we check if x/2 is sq root i.e if x/2*x/2 = x, 
if is more than x, we try x/4...

*/

int sq_root_naive(int x)
{
    /*
        Dry run: x=9
        i=1, 2, 3, 4 
        result = i-1 = 3
    */
    int i = 1;
    while(i*i <= x)
        ++i;
    return (i - 1);
}

int sq_root_efficient(int x)
{
    // x=10
    int low = 1, high = x, ans=-1;
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(mid*mid == x)
            return mid;
        else if(mid*mid > x)
            high = mid - 1;
        else 
        {
            // not breaking here, since x=10, 4 would be ans if we apply a break statement here
            // but it is 3
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    int x;
    cin >> x;
    // cout << sq_root_naive(x);
    cout << sq_root_efficient(x);
    return 0;
}
