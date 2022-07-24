#include <iostream>
#include <vector>
using namespace std;

/*
eg: 
arr = [1, 2, 1] and sum = 2
ans: [1, 1], [2]

Thot process

For printing a subsequence, I need a DS to carry the multiple subseq
Whenver I carry a DS, I carry a variable sum
Whenever I am picking an el, and add it to variable sum
and if that sum matches with given sum it will be printed

*/

void f(int idx, vector<int> &ans, int sum, int given_sum, int arr[], int n)
{
    if (idx == n)
    {
        if (given_sum == sum)
            for (auto subsequence : ans)
                cout << subsequence << ' ';
        cout << "\n";
        return;
    }

    // take or pick the idx into the subseq
    ans.push_back(arr[idx]);
    sum += arr[idx];
    f(idx + 1, ans, sum, given_sum, arr, n);

    sum -= arr[idx];
    ans.pop_back();

    // element not added to subsequence
    f(idx + 1, ans, sum, given_sum, arr, n);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    vector<int> subseq;
    int given_sum = 2;
    f(0, subseq, 0, given_sum, arr, n);
}

