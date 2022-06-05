#include <iostream>
using namespace std;

/*

consider a party that starts at 0:00 and goes till 23:59
you have list of guests, and you know when they are going to come in the party

ip: arr[] = {900, 940}
    dep[] = {1000, 1030}

first guest arrives at 9 AM and leaves at 10 AM
second guest arrives at 10 AM and leaves at 10:30 AM
0 <= arr[i], dep[] <= 2359

your target is to meet maximum guests

sample input:

ip: arr[] = {900, 940}
    dep[] = {1000, 1030}

op: 2 (you go from 9:40 to 10:00)

ip: arr[] = {800, 700, 600, 500}
    dep[] = {840, 820, 830, 530}
op: 3 (you go from 8:00 to 8:20 to meet idx 0,1,2)

ip: arr[] = {900, 940, 950, 1100, 1500, 1800}
    dep[] = {910, 1200, 1120, 1130, 1900, 2000}
op: 3 (you go from 11:00 to 11:20 to meet idx 1,2,3)
*/