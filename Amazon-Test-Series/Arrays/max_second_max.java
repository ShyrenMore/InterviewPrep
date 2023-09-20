//{ Driver Code Starts
//Initial Template for Java

/*
https://practice.geeksforgeeks.org/batch/Amazon-Test-Series/track/amazon-arrays/problem/max-and-second-max
 */

import java.io.*;
import java.util.*;

class Solution{
    
    // Function to find largest and second largest element in the array
    public static ArrayList<Integer> largestAndSecondLargest(int sizeOfArray, int arr[])
    {
        int max = -1;
        int secondMax = -1;
        
        for(int num: arr)
        {
            if(num > max)
            {
                secondMax = max;
                max = num;
            }
            else if(num < max && num > secondMax)
                secondMax = num;
        }
        
        ArrayList<Integer> res = new ArrayList<Integer>();
        res.add(max);
        if(secondMax == -1)
            res.add(-1);
        res.add(secondMax);
        
        return res;
    }
}

//{ Driver Code Starts.

// Driver class
class Array {
    
    // Driver code
	public static void main (String[] args) throws IOException{
		// Taking input using buffered reader
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		
		// looping through all testcases
		while(testcases-- > 0){
		    int sizeOfArray = Integer.parseInt(br.readLine());
		    
		    int arr[] = new int[sizeOfArray];
		    
		    String line = br.readLine();
		    String[] elements = line.trim().split("\\s+");
		    
		    for(int index = 0;index < sizeOfArray; index++){
		        arr[index] = Integer.parseInt(elements[index]);
		    }
		    
		    Solution obj = new Solution();
		    ArrayList<Integer> res = new ArrayList<Integer>();
		    res = obj.largestAndSecondLargest(sizeOfArray, arr);
		    System.out.println(res.get(0) + " " + res.get(1) );
		}
	}
}
// } Driver Code Ends