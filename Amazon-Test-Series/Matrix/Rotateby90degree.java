package Matrix;

import java.util.Scanner;

public class Rotateby90degree {
    public static void main(String[] args) 
	{ 
	    Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0)
        {
            int n = sc.nextInt();
            int[][] arr = new int[n][n];
            
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    arr[i][j] = sc.nextInt();
            
            GFG g = new GFG();
            g.rotate(arr);
            printMatrix (arr);
        }
	} 
	
	static void printMatrix(int arr[][]) 
	{ 
		for (int i = 0; i < arr.length; i++) { 
			for (int j = 0; j < arr[0].length; j++) 
				System.out.print(arr[i][j] + " "); 
			System.out.println(""); 
		} 
	} 
}

class GFG
{
    static void rotate(int matrix[][]) 
    {
        //1) transpose the matrix 
        int n = matrix.length;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //2) reverse the individual columns;
        for(int i=0;i<n;i++)
        {
            //logic of inplace revrerse
           int low=0,high=n-1;
           while(low<high)
           {
              
               int temp = matrix[low][i];
               matrix[low][i] =matrix[high][i];
               matrix[high][i]= temp;
               low++;
               high--;
           }
        }

    }
}
