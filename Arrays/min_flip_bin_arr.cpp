#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Problem name: Minimum consecutive flips

Given a binary array or bool array, make all elements of th array same in minimum flips, you can flip 0s to 1s or vice versa.

when you are flipping a zero, you are allowed to do all consecutive flips for zero

ip: arr[] = {1, 1, 0, 0, 0, 1}
op: from 2 to 4

ip: arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1}
op: from 1 to 3 & 5 to 6

ip: arr[] = {1, 1, 1}
op: 

ip: arr[] = {0, 1}
op: flip 0 to 1, or vice versa

Approach: 
Naive: traverse the array, count groups of ones & zeroes
groups of zeroes < ones
we will flip groups of zeroes
we traverse again, we start from zero and stop at next one

O(2n)

Only one travesal solution:
note the observation that group counts differ by one
*/

