#include <iostream>
#include <cstring>
using namespace std;

/*

Given a postfix exp as a string, find value of this exp
or evaluate a postfix exp
All tokens are seperated by space

ip: 10 2 * 3 +
op: 23
explanation: (10 2 * 3 +) => ((10 2 *) + 3) => ((10*2)+3)

ip: 10 2 + 3 *
op: 36
explanation: (10 2 + 3 *) => ((10 2 +) * 3) => ((10+2)*3)

ip: 10 2 3 ^ ^ ^
op: 100000000

Hint: postfix exp do not require associativity or precedence
nor do they require brackets
hence they can be evaluated in one pass in a linear fasion

Approach:
Traverse the string from left to right
whenever we see a operator, we take prev two operands
and evaluate value of this operator
now use this result as operand for futher traversal

Algorithm for evaluation of postfix
1) Create an empty stack st
2) Traverse through every symbol x of given postfix
    i) if x is an operand i.e a number, push to st
    ii) else if x is an operator
        a) pop stack two times for getting two operands
        b) compute operation with the popped operands
        c) push these result into stack

    return st.top()

Time: O(n)
Space: O(n)

*/

class Stack
{
public:
    int top;
    unsigned capacity;
    int *array;
};

// Stack Operations
Stack *createStack(unsigned capacity)
{
    Stack *stack = new Stack();

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];

    if (!stack->array)
        return NULL;

    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int peek(Stack *stack)
{
    return stack->array[stack->top];
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(Stack *stack, int op)
{
    stack->array[++stack->top] = op;
}

// The main function that returns value
// of a given postfix expression
int evaluatePostfix(char *exp)
{
    // Create a stack of capacity equal to expression size
    Stack *stack = createStack(strlen(exp));
    int i;

    // See if stack was created successfully
    if (!stack)
        return -1;

    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // if the character is blank space then continue
        if (exp[i] == ' ')
            continue;

        // If the scanned character is an
        // operand (number here),extract the full number
        // Push it to the stack.
        else if (isdigit(exp[i]))
        {
            int num = 0;

            // extract full number
            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            // push the element in the stack
            push(stack, num);
        }

        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}

// Driver code
int main()
{
    char exp[] = "10 2 * 3 +";
    cout << evaluatePostfix(exp);
    return 0;
}
