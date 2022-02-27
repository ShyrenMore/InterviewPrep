/*
given an infix exp as a string, convert it to postfix

operator | associativity    ^   
^ (power)| R to L           |   precedence
*, /     | L to R           |
+, -     | L to R           |

precendence wise: ^ > *, / > +, -

ip: a+b*c
op: bc*a+

ip: (a+b)*c
op: ab+c*

ip: a^b^c
op: abc^^

ip: (a+b)*(c+d)
op: ab+cd+*

1) Create an empty stack st
2) Do foll for each char x in string from L to R
3) If x is:
    - operand: op it
    - left parenthesis: push to st
    - right parenthesis: pop from st until left parenthesis is found
    op the popped operators
    - operator: if st is empty, push x to st
                else compare with st top
    i) Higher precedence than top, push
    ii) Lower precedence than top, pop top and output until
        higher precedence operator is found, then push x in st
    iii) equal precedence: use associativity 

    basically our main aim is at the top of the stack,
    there should be always higher precedence operator  
4) pop and op everything from st

Dry run:
ip: a+b*c

see img folder 

theta(n) time
*/

#include <iostream>
#include <stack>
using namespace std;

int getPrecedence(char c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // if operand
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // '('
        else if(c=='(')
            st.push(s[i]);
        
        // ')' 
        else if(c==')')
        {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        // operators
        else 
        {
            while(!st.empty() && getPrecedence(c) <= getPrecedence(st.top()))
            {
                result += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    // popping remaining items
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << "\n";
}

int main()
{
    string ip;
    cin >> ip;
    infixToPostfix(ip);
    return 0;
}