package Matrix;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;

public class BoundaryTraversal {
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine().trim());
        
        while(t-- > 0)
        {
            String s[] = in.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int a[][] = new int[n][m];
            s = in.readLine().trim().split(" ");
            int ind=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = Integer.parseInt(s[ind++]);
                }
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.boundaryTraversal(a, n, m);
            for (int i : ans) {
                out.print(i + " ");
            }
            out.println();
        }
        out.close();
    }
}

class Solution
{
    static ArrayList<Integer> boundaryTraversal(int matrix[][], int n, int m)
    {
        // code here 
        int R = n, C = m;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if(R == 1)
        {
            for(int i = 0; i < C; i++)
                ans.add(matrix[0][i]);
        }
        else if(C == 1)
            for(int i = 0; i < R; i++)
                ans.add(matrix[i][0]);
        else
        {
            for(int i = 0; i < C; i++)
                ans.add(matrix[0][i]);
            for(int i = 1; i < R; i++)
                ans.add(matrix[i][C-1]);
            for(int i = C-2; i >= 0; i--)
                ans.add(matrix[R-1][i]);
            for(int i = R-2; i >= 1; i--)
                ans.add(matrix[i][0]);
        }
        
        return ans;
    }
}