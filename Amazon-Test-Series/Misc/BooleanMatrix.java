package Misc;

import java.io.*;
import java.util.*;

/*
 * https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1?page=3&difficulty[]=1&status[]=unsolved&sortBy=submissions
 */

class BooleanMatrix
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            String str[] = read.readLine().trim().split("\\s+");
            int r = Integer.parseInt(str[0]);
            int c = Integer.parseInt(str[1]);
            int matrix[][] = new int[r][c];
            
            for(int i = 0; i < r; i++)
            {
                int k = 0;
                str = read.readLine().trim().split("\\s+");
                for(int j = 0; j < c; j++){
                  matrix[i][j] = Integer.parseInt(str[k]);
                  k++;
                }
            }
            new Solution().booleanMatrix(matrix);
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    sb.append(matrix[i][j] + " ");
                }
                sb.append("\n"); 
            }
            System.out.print(sb);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {

    public static void booleanMatrix(int[][] matrix) {
        int numRows = matrix.length;
        int numCols = matrix[0].length;
        boolean[] rowsWithOnes = new boolean[numRows];
        boolean[] colsWithOnes = new boolean[numCols];

        // Identify rows and columns with 1s
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (matrix[i][j] == 1) {
                    rowsWithOnes[i] = true;
                    colsWithOnes[j] = true;
                }
            }
        }

        // Modify matrix based on identified rows and columns
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (matrix[i][j] == 0 && (rowsWithOnes[i] || colsWithOnes[j])) {
                    matrix[i][j] = 1;
                }
            }
        }
    }

}
