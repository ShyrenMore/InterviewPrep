//{ Driver Code Starts
import java.util.*;
import java.util.Scanner;

// https://practice.geeksforgeeks.org/batch/Amazon-Test-Series/track/amazon-arrays/problem/remove-duplicates-in-small-prime-array
class GFG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0; i<n; i++)
            {
                arr[i] = sc.nextInt();
            }
            Solution g = new Solution();
            ArrayList<Integer> result = new ArrayList<Integer>();
            result = g.removeDuplicate(arr,n);
            
            for(int i=0;i<result.size();i++)
                System.out.print(result.get(i) + " ");
            System.out.println();
        t--;
        }
    }
}



// } Driver Code Ends


class Solution
{
    ArrayList<Integer> removeDuplicate(int arr[], int n)
    {
        // code here 
        ArrayList<Integer> ans = new ArrayList<>(); 
        HashSet<Integer> set = new LinkedHashSet<>(); // ordered map
        for(int i = 0; i < n; i++)
            set.add(arr[i]);
        
        for(int x: set)
            ans.add(x);
        
        return ans;
    }
}
