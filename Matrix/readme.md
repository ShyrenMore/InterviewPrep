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