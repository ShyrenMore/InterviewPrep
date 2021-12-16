#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*
EFFICIENT SOLUTION 
Problem name: Maximum consecutive ones

Given a binary array, count max consecutive ones

ip: arr[] = {0, 1, 1, 0, 1, 0}
op: 2 (index 1 and 2)

ip: arr[] = {1, 1, 1, 1, 1, 1}
op: 6 (all indices)

ip: arr[] = {0, 0, 0, 0}
op: 0

ip: arr[] = {1, 0, 1, 1, 1, 1, 0, 1, 1}
op: 4 (index: 2-5)

Approach: Traverse every element, count consecutive ones begining with the element, and if this current count is greater than result we update the result

Time: O(n)

*/

int count_cons_ones(bool arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;

        /*
            if you don't put i < n, for case [1, 1, 1, 1],
            code will give WA, since we are passing arr by ref, so garbage values will be considered beyond index n
        */
        while(arr[i]!=0 && i < n)
        {
            // deb2(count, res);
            count++;
            // deb2(i, arr[i]);
            i++;
        }

        res = max(res, count);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    bool arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << count_cons_ones(arr, n);

    return 0;
}