/*

Problem statement : Given two sorted arrays, print all the elements of both the arrays in sorted order

sample ip & op

ip:
a[] = {10, 15, 20}
b[] = {5, 6, 6, 15}
op: 5 6 6 10 15 15 20

ip:
a[] = {1, 1, 2}
b[] = {3}
op: 1 1 2 3

idea: traverse both the arrays simultaneously, use two index variable i and j for accesiing array a and b
we compare a[i] and b[j]
case 1 : a[i] <= b[j]
    print a[i]
    i++
case 2 : a[i] > b[j]
    print b[j]
    j++
if (i<=n || j<=m)
    print remaining elements

dry run:
a[] = {10, 20, 35}
b[] = {5, 50, 50}

i=0, j=0 => a[i]>b[j]
op: 5
i=0, j=1 => a[i]<b[j]
op: 5 10
i=1, j=1 => a[i]<b[j]
op: 5 10 20
i=2, j=1 => a[i]<b[j]
op: 5 10 20 35

print remaning el of b
op: 5 10 20 35 50 50

Time complexity: θ(n+m)
*/

#include <iostream>
using namespace std;

void mergeSortedArrays(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(a[i] <= b[j])
        {
            cout << a[i] << " ";
            ++i;
        }
        else 
        {
            cout << b[i] << " ";
            ++j;
        }
    }

    while(i<m)
    {
        cout << a[i] << " ";
        ++i;
    }
    while(j<m)
    {
        cout << b[j] << " ";
        ++j;
    }
    
}

int main()
{
    int sz1, sz2;
    cin >> sz1 >> sz2;
    int a[sz1], b[sz2];
    for (int i = 0; i < sz1; i++)
        cin >> a[i];
    for (int i = 0; i < sz2; i++)
        cin >> b[i];

    mergeSortedArrays(a, b, sz1, sz2);
}

/*
3
3
10, 20, 35
5, 50, 50
*/