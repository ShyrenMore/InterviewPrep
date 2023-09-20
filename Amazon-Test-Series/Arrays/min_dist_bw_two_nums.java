// https://practice.geeksforgeeks.org/batch/Amazon-Test-Series/track/amazon-arrays/problem/minimum-distance-between-two-numbers

import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) 
                a[i] = Integer.parseInt(str[i]);
            String[] xy = br.readLine().trim().split(" ");
            int x = Integer.parseInt(xy[0]);
            int y = Integer.parseInt(xy[1]);
            Solution g = new Solution();
            System.out.println(g.minDist(a, n, x, y));
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    int minDist(int a[], int n, int x, int y) {
        // code here
        int minDist = Integer.MAX_VALUE;
        int prevIndex = -1;
        
        for(int i = 0; i < n; i++){
            if (a[i] == x || a[i] == y) {
                if (prevIndex != -1 && a[i] != a[prevIndex]) 
                    minDist = Math.min(minDist, i - prevIndex);

                prevIndex = i;
            }
        }
        
        if (minDist == Integer.MAX_VALUE)
            return -1;
        return minDist;
    }
}