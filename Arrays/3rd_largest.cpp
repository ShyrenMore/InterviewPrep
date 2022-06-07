#include <iostream>
using namespace std;

/*

Input: arr[] = {1, 14, 2, 16, 10, 20}
Output: The third Largest element is 14

Approach:
- Create three variables, first, second, third, to store indices of three largest elements of the array
- traverse the array
- For every index
    check if the element is larger than first or not.
        Update the value of first, if the element is larger, and assign the value of first to second and second to third.
    Else if the element is larger than the second, then update the value of second,and the second largest element becomes third largest.
    Else If the previous two conditions fail, but the element is larger than the third, then update the third.
    
value of third will be answer
*/
int thirdLargest(int arr[], int sz)
{
    if(sz<3)
        return -1;

    int first = arr[0], second = INT16_MIN, third = INT16_MIN;

    for (int i = 1; i < sz; i++)
    {
        if(arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second)
        {
            third = second;
            second = arr[i];
        }
        else if(arr[i] > third)
            third = arr[i];
    }

    return third;
}