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

# **Backtracking**


- [NQueens](NQueens/)