//{ Driver Code Starts
import java.util.Scanner;
import java.util.*;
import java.io.*;

class ThirdLargestElement
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int n =sc.nextInt();
			int arr[] = new int[n];
			for(int i=0;i<n;i++)
				arr[i] = sc.nextInt();
			Solution g = new Solution();
			System.out.println(g.thirdLargest(arr,n));
		t--;
		}
	}
}
// } Driver Code Ends


class Solution
{
    int thirdLargest(int a[], int n)
    {
	    int firstMax = Integer.MIN_VALUE;
	    int secondMax = Integer.MIN_VALUE;
	    int thirdMax = Integer.MIN_VALUE;
	    
	    for(int num: a)
	    {
	        if (num > firstMax)
	        {
	            thirdMax = secondMax;
	            secondMax = firstMax;
	            firstMax = num;
	        }
	        else if(num > secondMax)
	        {
	            thirdMax = secondMax;
	            secondMax = num;
	        }
	        else if(num > thirdMax)
	            thirdMax = num;
	    }
	    
	    return thirdMax;
    }
}
