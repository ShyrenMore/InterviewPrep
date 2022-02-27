#include <iostream>
using namespace std;

/*

ip: infix = x+y*z
op: prefix = +x*yz

ip: (x+y)*z
op: *+xyz

ip: x^y^z
op: ^x^yz
explanation: R to L for ^
so x^(y^z)

ip: (x+y)*(z+w)
op: *+xy+zw

ip: x+y*(z-w)
op:
understand by parenthesing the expression
exp: (x+(y*(z-w))) = (x+(y*(-zw))) = (x+(*y-zw)) = +x*y-zw

ip: x+y*z/w+u
op:
exp: ((x+((y*z)/w))+u) = ((x+((*yz)/w))+u)
 = (x+(/*yzw)+u)
 = +x/*yzw + u
 = ++x/*yzwu

Algorithm:

1) Create an empty stack
2) Create an empty ans string prefix
3) Traverse the ip string FROM R to L
   for each char do the foll:
4) if c is:
   a) operand: push it to prefix string
   b) right parentheses(')'): push to stack
   c) left parentheses('('): pop from st, until right parenthesis is found. Append the popped chars to prefix string
   d) operator: if stack is empty, push it to st
   else
        compare the operator with top
        threee cases:
        i) Higher precedence(than st top): push char to st
        ii) Lower prec than st top: pop st top and append the popped item to prefix string until a higher precedence operator is found. Push char to stack
        iii) Equal precedence: use associativity
   e) pop everything from st and append it to prefix
   f) return reverse of prefix str
*/