#include <iostream>
using namespace std;

/*
-----------------------------------------------------------------------
deletes an el (overwrites an el)
returns the size of new array
*/
int deleteEl(int arr[], int &n, int x)
{
    int i;

    // deleting last el
    if(arr[n-1] == x)
        return n - 1;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            break;
    }

    // element x was not present in arr
    if (i == n)
        return n;

    // shifting to left if x is found
    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }

    return (n - 1);

    // Time: theta(n)
}


/*
-----------------------------------------------------------------------
Finding index of largest el

returns index if element 
*/

int getLargest(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            return i;
    }

    // this is written to avoid warnings
    return -1;

    // Time: 
    // worst case: arr is sorted, Theta(n^2)
    // best case: arr is sorted in descending, Theta(n)
}

/*
-----------------------------------------------------------------------
Left rotate an array by d steps
or
Rotate an array in anti-clockwise direction by d steps

ip: arr[] = {1, 2, 3, 4, 5}, d=2
op: arr[] = {3, 4, 5, 1, 2} 

approach: LeftRotate the el d times

*/

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i-1] = arr[i];

    arr[n - 1] = temp;
}
void leftRotateBysteps(int arr[], int n, int steps)
{

    // in case steps>arr_size 
    if(steps>n)
        steps = n - steps;

    for (int i = 0; i < steps; i++)
        leftRotateByOne(arr, n);
    // Time: Theta(n x d)
}

void printArr(int arr[], int n)
{
    cout << "\nYour array is :: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int ip_del_el;
    // cin >> ip_del_el;
    // int x = deleteEl(arr, n, ip_del_el);
    // cout << "size of new arr :: " << x;
    printArr(arr, n);
    return 0;
}