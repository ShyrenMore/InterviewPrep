/*
Count distinct elements in every window of size k
ip:
arr[] = {1, 2, 1, 3, 4, 3, 3}   k=4
op: 3 4 3 2
1,2,1,3 = 3 distinct els
2 1 3 4 = 4 distinct els
1 3 4 3 = 3 distinct els
3 4 3 3 = 2 distinct els 

Store elements of window in hashset/unordered set
and push the size of that unordered set into ans array

Time: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> getDistinctElementforWindow(int n, int k, int arr[])
{
    vector<int> ans;
    unordered_set<int> s;
    for (int i = 0; i < k; i++)
        s.insert(arr[i]);
    ans.push_back(s.size());

    for (int i = k; i < n; i++)
    {
        s.clear();
        
    }
}

int main()
{
    return 0;
}