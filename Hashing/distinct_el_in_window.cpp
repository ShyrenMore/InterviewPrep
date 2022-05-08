/*
Given array and a number k, k<=n
find count of distinct elements in every window of size k

arr = [10, 20, 20, 10, 30, 40, 10]  k=4
op: 2 3 4 3

arr = [10, 10, 10, 10]  k=3
op: 1   1

arr = [10, 20, 30, 40]  k=3
op: 3   3
*/

/*
sol1: O(n-k * k * k) time
Consider starting point of every window 
There are total n-k+1 windows 
so traverse all windows 
for each window, count distinct els 
We can see if an element is distinct or not 
by having two loops
the outer loop picks and element one by one and the 
inner loop checks if same element has ocuured before
*/

#include <iostream>
using namespace std;

void printDistinct(int arr[], int n, int k)
{
    for (int i = 0; i <= n - k; i++)
    {
        int count = 0;
        for (int j = 0; j < k; j++)
        {
            bool flag = false;
            for (int p = 0; p < j; p++)
                if(arr[i+j] == arr[i+p])
                {
                    flag = true;
                    break;
                }
        }

        cout << count << '\t';
    }
}

/*
sol2: O(n-k + k) = O(n) time, O(k) space
Maintain frequency map of elements present in first window
print siz of freq map
Then traverse the windows,
compute freq map of curr window using freq map of prev window

for(int i = k; i < n; i++)
{
    - decrease frequency of arr[i-k]
    - if freq of arr[i-k] becomes 0
        remove it from map

    - if arr[i] is absent in map
        insert it
      else 
        increase it's frequency in map

    - print size of map   
}
*/