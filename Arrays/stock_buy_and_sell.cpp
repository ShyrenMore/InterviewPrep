#include <iostream>
using namespace std;

/*

The problem assumes that we know price of a stock for
upcoming n days
we can buy the stock on any day
and sell it on any upcoming day
maximising profit is our target

ip: arr[] = {1, 5, 3, 8, 12}
op: 13
explanation:
you buy stock at day 1 for Rs 1 and
sell it on day 3 at Rs 5
profit = 5-1=4
you buy stock at day 3 for Rs 3 and
sell it on day 5 at Rs 12
profit = 5+(12-3) = 13

ip: arr[] = {30, 20, 10}
op: 0
explanation: you can't sell lower 

ip: arr[] = {10, 20, 30}
op: 20
explanation:
prices are sorted in increasing order
buy on first day and sell on last day
to maximise profit

ip: arr[] = {1, 5, 3, 1, 2, 8}
op: 11
explanation:
we buy it on day 1 for Rs 1
and sell it on day 2 for Rs 5
profit = 5-1 = 4
we then buy it on day 4 for Rs 1
and sell it on last day for Rs 8
profit = 4 + (8-1) = 11

-------------------------------------------------------------------

Approach 1: Naive

We will design a recursive function
where the arguments will be price arr, start and end
base condition would be if end<=start
i.e if in the range there is one or 0 element, there 
would be no profit for a single day
else 
we consider every pair i and j
such that i < j and price[i] < price[j] 
once we have found such a pair, 
we add the difference i.e 
price[j] - price[i] with curr profit
and recursively call same function for left of i 
and right of j
we consider curr_profit for every pair and find the max profit

dry run: 
Approach 2: below
*/

int maxProfit(int price[], int start, int end)
{
    if(end <= start)
        return 0;
    int profit = 0;

    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if(price[j] > price[i])
            {
                int curr_profit = (price[j] - price[i]) + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);

                profit = max(profit, curr_profit);
            }
        }
    }

    return profit;
}

/*

Approach 2: Efficient
We can use the fact that we know future prices
we will find bottom points and peak points
at every bottom point, we will buy the stock
and at every peak point, we will sell the stock
so Traverse the array starting from 2nd el

if curr el > prev el
    keep adding the difference to profit

Basically we are cummulating the profit
i.e ultimately we will get difference of bottom and top
*/

int maxProfit_eff(int price[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if(price[i] > price[i-1])
            profit += (price[i] - price[i - 1]);
    }

    return profit;
}

/*
dry run:
arr = [1 5 3 8 12]

profit = 0
i=1: profit = 0 + (5-1) = 4
i=2: 
i=3: profit = 4 + (8-3) = 9
i=4: profit = 9 + (12-8) = 13
*/