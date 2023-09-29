package Misc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class ReverseWithoutDupli{
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-->0)
            {
                String s = br.readLine();
                Solution ob = new Solution();
                System.out.println(ob.reverseString(s));
            }
    }
}

class Solution
{
    public String reverseString(String s)
    {
        StringBuilder ans = new StringBuilder();
        HashSet<Character> m = new HashSet<>();
        
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) == ' ')
                continue;
                
            if(!m.contains(s.charAt(i)))
            {
                ans.append(s.charAt(i));
                m.add(s.charAt(i));
            }
        }
        
        return ans.toString();
    }
}