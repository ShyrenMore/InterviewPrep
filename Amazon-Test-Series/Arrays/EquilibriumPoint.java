import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EquilibriumPoint {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {
            
            //taking input n
            int n = Integer.parseInt(br.readLine().trim());
            long arr[] = new long[n];
            String inputLine[] = br.readLine().trim().split(" ");
            
            //adding elements to the array
            for (int i = 0; i < n; i++) {
                arr[i] = Long.parseLong(inputLine[i]);
            }

            Solution ob = new Solution();
            
            //calling equilibriumPoint() function
            System.out.println(ob.equilibriumPoint(arr, n));
        }
    }
    
    class Solution {

        public static int equilibriumPoint(long arr[], int n) {
    
            // Your code here
            long totalSum = 0;
            for (int i = 0; i < n; i++) 
                totalSum += arr[i];
            
            long leftSum = 0;
            for (int i = 0; i < n; i++){
                long rightSum = totalSum - leftSum - arr[i];
                if(leftSum == rightSum)
                    return i+1;
                
                leftSum += arr[i];
            }
            
            return -1;
        }
    }
    
}
