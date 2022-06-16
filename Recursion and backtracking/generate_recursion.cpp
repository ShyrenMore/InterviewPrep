/*
assume arr = [3, 1, 2]
recursive function will take index, list[],

base case: if we reach nth index
print array

otherwise
append arr[idx] to list
f(idx+1, list[])    // take 
list.remove(arr[i])
f(idx+1, list[])        // not taking an el

So basically we have two types of recursion
one where we add the curr element in subseq and expand it 
and other where curr element is absent  

This can be logically correlated to real-life scenario of buying clothes
say you take a couple of clothes for trying out 
You try out the first cloth
Now before trying out the second cloth, you remove the first  
*/ 

#include <iostream>
#include <vector>
using namespace std;

void f(int idx, vector<int> &ans, int arr[], int n)
{
    if(idx == n)
    {
        for(auto subsequence: ans)
            cout << subsequence << ' ';
        cout << "\n";
        return;
    }

    // take or pick the idx into the subseq
    ans.push_back(arr[idx]);
    f(idx + 1, ans, arr, n);
    ans.pop_back();

    // element not added to subsequence
    f(idx + 1, ans, arr, n);
}

int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> subseq;

    f(0, subseq, arr, n);
}

/*
op: Notice logical order
3 1 2
3 1
3 2
3
1 2
1
2
{}

*/

/*
Time:
every idx has 2 options: getting selected or rejected hence 2^n
for every subsequnece we are printing it ~~n
O(n*2^n) time

Space: O(n): depth of recursion tree is n 
*/