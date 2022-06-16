# **Recursion**
When a function calls itself until base condition is met. 

- Printing numbers from 1 to n using recursion

```
int cnt = 0;
int n;
cin>>n;

void printSequence()
{
    if(cnt == n+1)
        return;
    print(cnt, \n)
    ++cnt;
    printSequence();
}

```  

Some more basic problems
- [Print name N times](Basic_Problems/print_name_N_times.cpp)
- [Print Linearly from 1 to N](Basic_Problems/print_1_to_N.cpp)
- [Print Linearly from N to 1](Basic_Problems/print_N_to_1.cpp)
- [Print Linearly from 1 to N but by backtracking](Basic_Problems/print_1_to_N_backtrack.cpp)
    - i.e i+1 is not allowed
- [Print Linearly from N to 1 but by backtracking](Basic_Problems/print_N_to_1_backtrack.cpp)
    - i.e i+1 is not allowed

## Parameterised and Functional Recursion 

- [Sum of first N numbers using parameterised recursion](sum_parameterised.cpp)
    - return type of void, everything stays inside function
- [Sum of first N numbers using functional recursion](sum_functional.cpp)
    - return the sum instead of printing , used in DP
    - ``f(n)`` is sum of first n nos
    - if n = 3: 3+f(2)

- [Factorial of N](n_factorial.cpp)
    - [parameterised way](para_factorial.cpp)
    - [Functional way](functional_factorial.cpp)

- [Reverse an array using recursion](reverse_array.cpp)
- [Check if given string is palindrome using recursion](isPalindrome.cpp)
- []

## Multiple Recursion calls

- General syntax

```
f()
{
    f()
    f()
    .
    .
}
```

- [Printing nth Fibonacci number](fibonacci.cpp)

## Recursion on Subsequences

- [Generate all Subsequences without recursion **(Power set)**](generate_power_set.cpp)
- [Generate all Subsequences with recursion ](generate_recursion.cpp)
- Dry run
![](TBD.jpg)

# **Backtracking**


- [NQueens](NQueens/)