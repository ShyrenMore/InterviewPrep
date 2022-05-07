#include <iostream>
#include <unordered_set>
using namespace std;

/*

Given two unsorted arrays els, find count of only DISTINCT intersecting elements
ip:
a[] = {10, 15, 20, 15, 30, 30, 5}
b[] = {30, 5, 30, 80}

op: 2 (common els: 30, 30, 5)

---

ip:
a[] = {10, 20}
b[] = {20, 30}
op: 1 (common el: 20)

---

ip:
a[] = {10, 10, 10}
b[] = {10, 10, 10}
op: 1 (common el: 10, 10, 10)
*/


/*
sol1: O(m*(m+n)) time and O(1) space
Traverse all els of first array
for every el, check if it appeared on the left for handling duplicate 
if it has, skip this element 
if not appeared before
    look for this element in other array

if we find it, we increment the res variable and break the loop
*/


int intersection_naive(int a[], int b[], int m, int n)
{
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        bool isDuplicate = false;

        for (int j = 0; j < i - 1; j++)
            if(a[i] == a[j])
            {
                isDuplicate = true;
                break;
            }
        
        if(isDuplicate)
            continue;

        for (int j = 0; j < n; j++)
            if(a[i] == b[j])
            {
                ++res;
                break;
            }
    }

    return res; 
}

/*
sol2: O(m+n) time and O(m) space
create hashtable (unordered set) and insert all items of first arr
traverse the second array, 
    search each el in set,
        if found, 
        - we found intersection el hence increement res 
        - erase that el from set, since the same el might occur again in second array, and result will get increment again if we don't erase it 
*/

int interesection_hashtable(int a[], int b[], int m, int n)
{
    unordered_set<int> us;
    for (int i = 0; i < m; i++)
        us.insert(a[i]);

    int res = 0;
    for (int j = 0; j < n; j++)
    {
        if(us.find(b[j]) != us.end())
        {
            ++res;
            us.erase(b[j]);
        }
    }

    return res;
}