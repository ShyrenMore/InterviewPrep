#include <iostream>
#include <algorithm>
using namespace std;

/*

Problem statement: Given two sorted arrays, print union
op should also be sorted, should not contain any duplicate elements

ip: a[] = {3, 5, 8}
    b[] = {2, 8, 9, 10, 15}
op: 2 3 5 8 9 10 15

ip: a[] = {2, 3, 3, 3, 4, 4}
    b[] = {4, 4}
op: 2 3 4

Naive: Create an auxilary array 'c'
Copy elements of a and b in arr c
now sort arr c
while printing arr c, don't print duplicate elements

Time: O((m+n)*log(m+n))
space: θ(m+n)
*/

void naive_union(int a[], int m, int b[], int n)
{
    int c[m + n], i, j;
    for (i = 0; i < m; i++)
        c[i] = a[i];
    for (j = 0; j < n; j++)
        c[m + j] = b[j];

    sort(c, c + m + n);
    for (int k = 0; k < m + n; k++)
        if(k==0 || c[k] != c[k-1])
            cout << c[i] << " ";
}
/*

Efficient : -We traverse simultaneously through both the arrays
- three cases
    a[i]<b[j] : print a[i], move to i + 1
    a[i]> b[j] : print b[j] move to j + 1
    a[i] == b[j] : print any a[i] or b[j], move to i + 1 & j + 1
- handling duplicates : 
    if (i>0 && a[i] == a[i - 1]) 
        i++;
        continue;
    if (j>0 && b[j] == b[j - 1]) 
        j++;
        continue;
- process remanining elements of other arrays
Time : O(n+m)
Space: O(1)
*/

void eff_union(int a[], int m, int b[], int n)
{
    int i = 0, j = 0;
    while(i<m && j<n)
    {
        if(i>0 && a[i] == a[i-1])
        {
            ++i;
            continue;
        }

        if(j>0 && b[j]==b[j-1])
        {
            ++j;
            continue;
        }

        if(a[i] < b[j])
        {
            cout << a[i] << " ";
            ++i;
        }
        else if(a[i] > b[j])
        {
            cout << b[j] << " ";
            ++j;
        }
        else 
        {
            cout << a[i] << " ";
            ++i;
            ++j;
        }
    }

    while(i<m)
        if(i>0 && a[i] != a[i-1])
        {
            cout << a[i] << " ";
            ++i;
        }
        
    while(j<n)
        if(j>0 && b[j] != b[j-1])
        {
            cout << b[j] << " ";
            ++j;
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

    eff_union(a, m, b, n);
    return 0;
}

/*
ip:
3 5
3 5 8
2 8 9 10 15

op:
2 3 5 8 9 10 15
*/