package Matrix;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class SpiralTraversal {
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int r = sc.nextInt();
            int c = sc.nextInt();
            
            int matrix[][] = new int[r][c];
            
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                 matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.spirallyTraverse(matrix, r, c);
            for (Integer val: ans) 
                System.out.print(val+" "); 
            System.out.println();
        }
    }
}

class Solution
{
    //Function to return a list of integers denoting spiral traversal of matrix.
    static ArrayList<Integer> spirallyTraverse(int matrix[][], int r, int c)
    {
        ArrayList<Integer> op = new ArrayList<Integer>();
        int row = 0, col = 0;
        
        while(row < r && col < c)
        {
            for(int i = col; i < c; i++)
                op.add(matrix[row][i]);
            ++row;
            
            for(int i = row; i < r; i++)
                op.add(matrix[i][c-1]);
            --c;
            
            if(row<r)
            {
                for(int i=c-1; i>=col; --i)
                    op.add( matrix[r-1][i]);
                r--;
            }
            
            if(col<c)
            {
                for(int i=r-1; i>=row; --i)
                    op.add( matrix[i][col]);
                col++;    
            }   
        }
        
        return op;
    }
}
