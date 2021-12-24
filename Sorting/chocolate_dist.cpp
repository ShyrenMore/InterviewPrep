#include <iostream>
#include <algorithm>
using namespace std;

/*

Given an array, each arr element represent no of chocalates in a packet
we want to distribute packets to m children foll some rules
1) every child get 1 packet
2) minimise the difference between minimum chocalates that a child gets, and the max chocalates  that another child gets

Formally, pick m packets such that max-min is minimum 

ip: arr = [7, 3, 2, 4, 9, 12, 56]       m=3
op: 2
explanation: we need to distribute 3 packets, 
consider we pick 7, 3, 2. 
diff b/w max and min = 7-2=5

consider we pick 7, 3, 4. 
diff b/w max and min = 7-4=3

consider we pick 3, 2, 4. 
diff b/w max and min = 4-2=2
... etc

out of all differneces, we have minimum diff = 2

ip: arr = [3, 4, 1, 9, 56, 7, 9, 12]    m=5
op: 6 (if we pick 3, 4, 7, 9, 9)

*/

/*

Solution: Consider each element as minimum of m elements, the find remaning m-1 elements 
then we find, what will be the set where this element is minimum

arr = 7 3 2 4 9 12 56

For every element we need m-1 greater elements
sort array, traverse it 
2 3 4 7 9 12 56 and m=3

arr[2] - arr[0] = 2
arr[3] - arr[1] = 3, min(2, 3) = 2
arr[4] - arr[2] = 5, min(2, 5) = 2
arr[5] - arr[3] = 5, min(2, 5) = 2
arr[6] - arr[4] = 56-9 = 47, min(2, 47) = 2

op: res=2

time: O(nlogn)
*/

int minDiff(int arr[], int n, int m)
{
    if(m>n)
        return -1;

    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    for (int i = 1; (i + m - 1) < n; i++)
        res = min(res, arr[i + m - 1] - arr[i]);

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << minDiff(arr, n, m);
}