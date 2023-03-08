// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1
class Solution{
	public:
	int longestSubsequence(int n, int arr[])
    {
        // your code here
        int lis[n];
        lis[0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            lis[i] = 1;
            for(int j = 0; j < i; j++)
                if(arr[j] < arr[i])
                    lis[i] = max(lis[i], lis[j]+1);
        }
        
        int res = lis[0];
        for(int i = 1; i < n; i++)
            res = max(res, lis[i]);
        return res;
    }
    
	int minDeletions(int arr[], int n) 
	{ 
	    // Your code goes here
	    return n - longestSubsequence(n, arr);
	} 
};
