#include <iostream>
using namespace std;

/*

Problem statement: Given two sorted arrays, print intersection or common elements.
Both arrays might contain duplicates
If a element appears multiple times in both arrays, it should be only printed once

ip: a[] = {3, 5, 10, 10, 10, 15, 15, 20}
    b[] = {5, 10, 10, 15, 30}
op: 5 10 15

ip: a[] = {1, 1, 3, 3, 3}
    b[] = {1, 1, 1, 1, 3, 5, 7}
op: 1 3

Naive: Traverse every element of array a, we look for it in array b, if we find, we print the el, and move to next element 
Time: O(n x m)

*/
void naive_intersection(int a[], int m, int b[], int n)
{
    for (int i = 0; i < m; i++)
    {
        if(i > 0 && a[i] == a[i-1])
            continue;
        for (int j = 0; j < n; j++)
        {
            if(a[i] == b[j])
            {
                cout << a[i] << " ";
                // break the loop to avoid duplicates
                break;
            }
        }
    }
}

/*
Dry run of above approach:
a[] = {1, 20, 20, 40, 60}
b[] = {2, 20, 20, 40}

i=0: j=0,1,2,3
i=1: j=0,1
    print(20)
i=2:
i=3: j=0,1,2,3
i=4: j=0,1,2,3
    print(40)

op: 20 40
*/

/*

Efficient:
- We traverse simultaneously through both the arrays
- three cases
    a[i]<b[j]: move to i+1
    a[i]>b[j]: move to j+1
    a[i]==b[j]: print any a[i] or b[j], move to i+1 & j+1
- handling duplicates:
if(i>0 && a[i] == a[i-1])
    i++; continue;

Time: θ(n+m)
*/

void eff_intersection(int a[], int m, int b[], int n)
{
    int i = 0, j = 0;
    while(i<m && j<n)
    {
        if(i>0 && a[i] == a[i-1])
        {
            ++i;
            continue;
        }
        if(a[i] < b[j])
            ++i;
        else if(a[i] > b[j])
            ++j;
        else 
        {
            cout << b[j] << " ";
            ++i;
            ++j;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    eff_intersection(a, m, b, n);
    return 0;
}

/*
ip:
5 4
1 20 20 40 60
2 20 20 40

op: 20 40
*/