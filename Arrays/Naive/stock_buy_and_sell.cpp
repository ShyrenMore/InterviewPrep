#include <iostream>
using namespace std;

/*

We assume that we know prices of stock for upcoming n days 
we can buy anyday and sell the stock in any upcoming day
we have to maximize the profit 

ip: arr[] = {1, 5, 3, 8, 12}
op: 13
explain: 1->5 & 3->12

ip: arr[] = {30, 20, 10}
op: 0 
explain: loss condition

ip: arr[] = {10, 20, 30}
op: 20 
explain: 10->30

ip: arr[] = {1, 5, 3, 1, 2, 8}
op: 11
explain: 1->5 & 1->8

Approach: 

we write a recursive function using start index and end index 

if arr has two or more elements we consider every such pair i & j, such that i<j & arr[i]<arr[j]

Once we find such a pair, we add the difference of the pair to profit and recusively call the function for left of i and right of j 

*/

int maxProfit(int price[], int start, int end)
{
    if(end<=start)
        return 0;

    int profit = 0;

    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if(price[i]<price[j])
            {
                int curr_profit = (price[j] - price[i]) + maxProfit(price, start, i - 1) + maxProfit(price, j+1, end);

                profit = max(profit, curr_profit);
            }
        }
    }

    return profit;
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0, end = n - 1;
    cout<< maxProfit(arr, start, end);
}