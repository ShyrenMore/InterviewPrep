## important pts about matrix

- elements are stored in row major order
- internal curly brackets are optional
    ``` int arr[3][2] = {10, 20, 30, 40, 50, 60} ```
- only first dimension can be omitted when we initialise
```
int arr[][2] = {{1, 2} {3, 4}}
int arr[][2][2] = {{{1, 2}, {3, 4}},
                   {{5, 6}, {7, 8}}}
```
- from C++14, variable size arrays are allowed

## ways of creating multi-dimensional array

1) Double pointer

we create a double pointer which will point to array of pointers 

```
// creating an arr of size m*n

int **arr;
arr = new int*[m];
for(int i = 0; i < m; i++)
    arr[i] = new int[n]
```
- Memory is allocated from heap

- advantage: we can have individual rows of different sizes
- disadvantage: not cache friendly

2) Array of pointers

```
// creating an arr of size m*n

int *arr[m];
for(int i = 0; i < m; i++)
    arr[i] = new int[n]
```

3) Array of vectors

```
// m - no of rows
vector <int> arr[m];
```

- advantage: individual rows are of "dynamic" sizes, easy to pass to function
- disadvantage: not cache friendly

4) Vector of vectors

- advantage: individual rows as well as no of rows are of "dynamic" sizes, easy to pass to function 

```
vector<vector<int>>arr;

//input
for(int i = 0; i < m; i++)
{
    vector<int> v;
    for(int j = 0; j < n; j++)
        v.push_back(10);
    arr.push_back(v);
}

//op
for(int i = 0; i < arr.size(); i++)
    for(int j = 0; j < arr[i].size(); j++)
        cout << arr[i][j] << " ";

op: 10 10 10 10 10 10
```

## Print a matrix in snake pattern 

```
ip:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
op: 1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13

ip:
1 2 3 4
5 6 7 8
9 10 11 12
op: 1 2 3 4 8 7 6 5 9 10 11 12
```

- Approach: if even row print l-r, else print r-l
- Time: theta(R*C) 
- Code 
```
void printSnake(int mat[R][C])
{
    for(int i = 0; i < R; i++)
    {
        if(i%2==0)
        {
            for(int j = 0; j < C; j++)
                cout << mat[i][j] <<" ";
        }
        else 
        {
            for(int j = C-1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
}
```

## Print boundary elements 

```
ip:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
op: 1 2 3 4 8 12 16 15 14 13 9 5

ip:
1 2 3 4
5 6 7 8
op: 1 2 3 4 8 7 6 5

ip: 1 2 3 4
op: 1 2 3 4

ip: 
1
2
3
op: 1 2 3
```

- Approach: R*C matrix, 
    - print first row, i = 0 to c-1
    - print last column, i = 1 to r-1
    - print last row from r-l, i = c-2 to 0
    - print first column, i = r-2 to 1
    - Corner cases: only one row or only one column

- Time: Theta(2R+2C)
- Code

```
void borderTraversal(int mat[R][C])
{
    if(R == 1)
        for(int i = 0; i < C; i++)
            cout << mat[0][i] << " ";
    else if(C == 1)
        for(int i = 0; i < R; i++)
            cout << mat[i][0] << " ";
    else
    {
        for(int i = 0; i < C; i++)
            cout << mat[0][i] << " ";
        for(int i = 1; i < R; i++)
            cout << mat[i][C-1] << " ";
        for(int i = C-2; i >= 0; i--)
            cout << mat[R-1][i] << " ";
        for(int i = R-2; i >= 1; i--)
            cout << mat[i][0] << " ";
    }
}
```