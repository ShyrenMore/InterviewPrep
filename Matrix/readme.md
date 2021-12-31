## Important pts about matrix

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

## Ways of creating multi-dimensional array

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
- Time: θ(R*C) 
- Pseudo Code 
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

- Time: θ(2R+2C)
- Pseudo Code

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

## Transpose of a square matrix

- here we are actually suppose to change the matrix to it's transpose and not just print transpose
- transpose: rows become cols and vice-versa

```
ip:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
op:
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16

ip:
1 1
2 2
op:
1 2
1 2
```

- Approach: move ```mat[i][j] to mat[j][i]```
- Pseudo Code without inplace using aux array
```
void transpose(int mat[n][n])
{
    int temp[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = mat[j][i];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = temp[i][j];
}
```

- eff solution: one traversal, inplace
    - diagonal els remain as they are, swap ```mat[i][j] with mat[j][i]```

- Pseudo Code:
```
void transpose(int mat[n][n])
{
    // traversing upper diag
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
}
```

## Rotate a matrix by 90 deg anti-clockwise 

```
ip: 
1 2 3
4 5 6
7 8 9
op: 
3 6 9
2 5 8
1 4 7

ip: 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
op:
4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13
```

- Approach: 
    - find transpose 
    - reverse individual columns by simple array reversal

- eg:

```
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

after transpose:

1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16

reverse columns:
making last row -> first row
making second-last row -> second row

4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13
```

- Pseudo Code
```
void rotate90(int mat[n][n])
{
    // transpose
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    
    // reversing columns
    for(int i = 0; i < n; i++)
    {
        int low=0, high=n-1;
        while(low < high)
        {
            swap(mat[low][i], mat[high][i]);
            low++;
            high--;
        }
    }
}
```

- Time: θ(n^2)

## Spiral traversal of matrix

```
ip:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
op: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

ip: 
1 2 3
4 5 6
op: 1 2 3 6 5 4

ip: 10 20 30
op: 10 20 30

ip: 
10 
20 
30
op: 10 20 30
```

- approach: we remove outermost layers one by one, we do this by maintaining 4 ptrs
    - top for top row
    - right for rightmost col
    - left for leftmost col
    - bottom for bottom row
    <br>
- print top row, change top to point to next row, 
- then print rightmost col, change right to second last rightmost col
- similarly print bottom & change bottom to second-last row
- print left col, increment left ptr so it points to second column from left
- repeat the process until top crosses bottom or left crosses right
- code:
```
void printSpiral(int mat[][], int R, int C)
{
    int top=0, left=0, bottom=R-1, right=C-1;
    while(top<=bottom && left<=right)
    {
        // top row
        for(int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        ++top;

        //right col 
        for(int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        --right;

        //bottom row in reverse order 
        if(top<=bottom)
        {
            for(int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            --bottom;
        }

        // left col in reverse order
        if(left<=right)
        {
            for(int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            ++left;
        }
    }
}
```

```
dry run:

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

initially, top=0, bottom=3, left=0, right=3
op: 1 2 3 4     top=1
op: 1 2 3 4 8 12 16    right=2
op: 1 2 3 4 8 12 16 15 14 13   bottom=2
op: 1 2 3 4 8 12 16 15 14 13 9 5    left=1
op: 1 2 3 4 8 12 16 15 14 13 9 5 6 7    top=2
op: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11     right=1
op: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10      bottom=1

```

- Time: printing every cell: θ(R*C)

## Search in a row-wise & column-wise sorted matrix

- Given a matrix which is row-wise sorted & col-wise sorted and value x, if x is present print it's position 

```
ip:
mat[][] = {{10, 20, 30, 40},
           {15, 25, 35, 45}, 
           {27, 29, 37, 48},
           {32, 33, 39, 50}}
x=29
op: found at (2, 1)

ip:
mat[][] = {{10, 20}, 
           {12, 30}}
x=15
op: not found
```

- approach:  O(R+C)
- begin from top right corner, traverse the matrix
- while traversing cmp x with curr_el
    - if x is same, print position and return
    - if x is smaller, move left
    - if x is greater, move down
- DAMMMMNNNN, noice approach

```
void search(int mat[R][C], int x)
{
    int i = 0, j = C-1;
    while(i<R && j>=0)
    {
        if(mat[i][j]==x)
        {
            cout<<"Found at ( " << i << j << " )";
            return;
        }
        else if(mat[i][j]>x)
            --j;
        else 
            ++i;
    }

    cout<<"Not found";
}
```

## Median of a row-wise sorted matrix

- given an odd sized matrix containing distinct elements and every row is sorted in increasing order, find median of matrix

```
ip: 
1 10 20
15 25 35
5 30 40
op: 20  
exp: 1, 5, 10, 15, 20, 25, 30, 35, 40, total_el=9, 5th el is median

ip:
2   4   6   8   10
1   3   5   7   9
100 200 400 500 800
op: 8   // 1, 2, 3, 5, 6, 7, 8, 9, 10, 100, 200, 400, 500, 800
```

- Naive solution:
1) Put all el in array and sort it
2) return middle element 
3) Time: ```O(r*c*log(r*c))```

- efficient solution
```
1) find min and max el from matrix
minimum element will be from the first column
maximum element will be from the second column

2) find position of median el, (r*c+1)/2
i.e there will be (r*c+1)/2 elements smaller than or equal the median

3) do binary search in range [min, max]
upper_bound() function gives you idx(iterator) of first greater element
we don't update max=mid-1 in else, instead we do max=mid 

Time: ```O(r*log(max-min)*logc)```

```

- Code

```
int matMed(int mat[][MAX], int r, int c)
{
    int min = mat[0][0], max = mat[0][c-1];
    for(int i = 1; i<r; i++)
    {
        if(mat[i][0]<min)
            min = mat[i][0];
        if(mat[i][c-1]>max)
            max = mat[i][c-1];
    }

    int medPos = (r*c+1)/2;
    while(min<max)
    {
        int mid = (min+max)/2;
        int midPos = 0;

        for(int i = 0; i < r; i++)
            midPos += upper_bound(mat[i], mat[i]+c, mid) - mat[i];
        
        if(midPos < medPos) 
            min = mid + 1;
        else 
            max = mid;
    }
    return min;
}

```

- dry run

```
mat = 
5  10 20 30 40
1  2  3  4  6
11 13 15 17 19

actual ans should be 11 i.e 8th el(1, 2, 3, 4, 5, 6, 10, 11, 13, 15, 17, 19, 20, 30, 40)

r=3, c=5
min=1, max=40
medPos =  (3*5+1)/2 = 8

binary search begins 
min=1, max=40
mid=20, midPos = 3+5+5 = 13

min=1, max=20
mid=10
midPos = 2+5+0 = 7

min=11, max=20
mid=15
midPos=2+5+3=10

min=11, max=15
mid=13
midPos=2+5+2=9

min=11, max=13
mid=12
midPos=2+5+1=8

min=11, max=12
mid=11
midPos=2+5+1=8

min=11, max=11
```