/*
Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].

eg1:
ip: N = 2, arr[] = {1,0}
op: 0 1
exp:
arr[arr[0]] = arr[1] = 0.
arr[arr[1]] = arr[0] = 1.

eg2:
ip:
N = 5 arr[] = {4,0,2,1,3}
op: 3 4 2 0 1
Explanation:
arr[arr[0]] = arr[4] = 3.
arr[arr[1]] = arr[0] = 4.
and so on.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Approach: The array elements of the given array lies from 0 to n-1. Now an array element is needed that can store two different values at the same time.

To achieve this, every element at ith index is incremented by (arr[arr[i]] % n)*n

Old value can be obtained by new-arr[i]%n and a new value can be obtained by new-arr[i]/n.

How this can be achieved?
Let's assume an element is a and another element is b, both the elements are less than n. So if an element a is incremented by b*n. So the element becomes a + b*n so when a + b*n is divided by n then the value is b and a + b*n % n is a.
*/

class Solution{
    public:

    void rearrange(int arr[], int n)
    {
        // First step: Increase all values by (arr[arr[i]]%n)*n
        for (int i = 0; i < n; i++)
            arr[i] += (arr[arr[i]] % n) * n;

        // Second Step: Divide all values by n
        for (int i = 0; i < n; i++)
            arr[i] /= n;
    }
};

