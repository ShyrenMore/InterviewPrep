/*
s="abc"
subseq : "", a, b, c, ab, bc, ac, abc i.e 8 subseq

we do this by bit manip
Pre-req:
1) check if ith bit i set
we do this by performing & operation with ..0i00..
If result is non-zero that means ith bit is set, else not set 

for bits indexing goes from right to left
eg 101, check if bit 2 is set
101 & 100 = 100 i.e non-zero res, hence bit 1 is set 

for producing i000, we do left shift 
i.e left shift i times i.e 1<<i
eg: 
in above case we wanted 100
1<<2 will produce 100

hence if we do 101 & (1<<2) we can check if bit 2 is set or not

generalised: n & (1<<i)
if res != 0, bit is set
else bit is not set 

Actual logic:

210: position of bits

000 -> ""
001 -> a
010 -> b
011 -> ab
100 -> c
101 -> ac
110 -> bc 
111 -> abc

i.e we iterate number from 0 to 2^n-1 and checks for each bits 

2^n-1 can be written as (1<<n)-1

*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> AllPossibleStrings(string s)
{
    int n = s.length();
    vector<string> ans;

    // empty string is also a subseq
    ans.push_back("");
    
    // 1 to 2^n (rows)
    for (int i = 1; i < (1 << n) ; i++)
    {
        string tmp;
        // checking bits (cols)
        for (int j = 0; j < n; j++)
            if(i&(1<<j))
                tmp += s[j];
        ans.push_back(tmp);
    }

    return ans;
}

int main()
{
    string s = "abc";
    vector<string> ans = AllPossibleStrings(s);
    cout << "Substrings are :: \n";
    for(auto subseq: ans)
        cout<<subseq<<"\n";
    return 0;
}

/*
Time: outer loop runs for 2^n 
inner loop runs n time
Time = O(n*2^n)
Space = O(1)
*/