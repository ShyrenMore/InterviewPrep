// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1 

class Solution{
	public:
	
	int maxSumIS(int arr[], int n)  
	{  
	      int lis[n];
        
        for(int i = 0; i < n; i++)
        {
            lis[i] = arr[i];
            for(int j = 0; j < i; j++)
                if(arr[j] < arr[i])
                    lis[i] = max(lis[i], arr[i]+lis[j]);
        }
        
        int res = lis[0];
        for(int i = 1; i < n; i++)
            res = max(res, lis[i]);
        return res;
	}  
};
