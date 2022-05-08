#include <iostream>
#include <unordered_set>
using namespace std;
/*
ip:
a = [15, 20, 5, 15]
b = [15, 15, 15, 20, 10]

op: 4 [15, 20, 5, 10]

ip: 
a = [10, 12, 15]
b = [18, 12]
op: 4 [10, 12, 15, 18]

ip: 
a = [3, 3, 3]
b = [3, 3]
op: 1 [3]
*/

/*
naive sol: O((m+n)^2) time, O(m+n) space
copy contents of both arrays in another array 
count distinct els in new array 
*/

int countDistinctUnion(int a[], int b[], int m, int n)
{
    int c[m + n];
    for (int i = 0; i < m; i++)
        c[i] = a[i];
    for (int i = 0; i < n; i++)
        c[m + i] = b[i];

    int res = 0;
    for (int i = 0; i < m + n; i++)
    {
        bool isPresentOnLeftSide = false;
        for (int j = 0; j < i; j++)
        {
            if(c[j] == c[i])
            {
                isPresentOnLeftSide = true;
                break;
            }
        }

        if(!isPresentOnLeftSide)
            ++res;
    }

    return res;
}

/*
sol2: O(m+n) time and space
nothing much, just insert both arr els into unordered_set and size of set will be ans
*/

int countDistinctUnion_hashing(int a[], int b[], int m, int n)
{
    unordered_set<int> us;
    for (int i = 0; i < m; i++)
        us.insert(a[i]);
    for (int i = 0; i < n; i++)
        us.insert( b[i]);

    return us.size();
}

int main()
{
    int a[] = {15, 20, 5, 15};
    int b[] = {15, 15, 15, 20, 10};
    int m = 4;
    int n = 5;

    cout << countDistinctUnion(a, b, m, n);
    // cout << countDistinctUnion_hashing(a, b, m, n);
}