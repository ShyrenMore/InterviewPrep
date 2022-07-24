#include <iostream>
using namespace std;

/*
logically maintain two vars left and right
we swap left and right and call for l+1 and r-1

if interviewer asks can you do this using only single pointer 
yes, swap(arr[l], arr[n-l-1])
and base case would be i>=n/2
and recursive call will be f(l+1)

By default arrays are passed as reference
*/

void reverse(int l, int r, int arr[])
{
    if(l>=r)
        return;
    swap(arr[l], arr[r]);
    reverse(l + 1, r - 1, arr);
}

int main()
{
    int n=5;
    int arr[] = {5, 4, 3, 2, 1};
    reverse(0, n - 1, arr);
    for(auto x: arr)
        cout << x << " ";
    return 0;
}