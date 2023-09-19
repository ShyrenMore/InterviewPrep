import java.util.Scanner;
import java.lang.Math;

class Convert_To_Five {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int N = sc.nextInt();
            System.out.println(new GfG().convertfive(N));
            T--;
        }
    }
}


class GfG {
    int convertfive(int num) {
        // Your code here
        int ans = 0;
        int position_multiplier = 1;

        while(num > 0)
        {
            int digit = num % 10;
            if(digit == 0)
                digit = 5;
            
            ans += digit*position_multiplier;
            position_multiplier *= 10;
            num /= 10;
        }
        
        return ans;
    }
}