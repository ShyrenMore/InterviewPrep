#include <iostream>
#include <algorithm>
using namespace std;

// custom sorting
struct Point{
    int x, y;
};

// compare wrt increasing order of x-co-od
bool my_comp(Point p1, Point p2)
{
    return (p1.x < p2.x);
}

// simple example 
int main()
{
    int arr[] = {10, 20, 5, 7};
    sort(arr, arr + 4);

    for(int x: arr)
        cout << x << " ";
    cout << "\n";
    // sorting in  desc order
    sort(arr, arr + 4, greater<int>());
    for (int x : arr)
        cout << x << " ";

    // custom compartor eg
    // will sort the array of pairs such that x<y
    Point points[] = {{3, 10}, {2, 8}, {5, 4}};
    int n = sizeof(points) / sizeof(points[0]);
    cout << "\nPoint arr size :: " << n;

    sort(points, points + n, my_comp);
    cout << "\nPoint array after sorting :: \n";
    for (auto i : points)
        cout << i.x << " "<< i.y << "\n";
    return 0;
}

/*
op
5 7 10 20
20 10 7 5
Point arr size :: 3
Point array after sorting ::
2 8
3 10
5 4
*/