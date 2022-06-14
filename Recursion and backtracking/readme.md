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



# **Backtracking**


- [NQueens](NQueens/)