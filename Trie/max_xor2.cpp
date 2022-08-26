/**
 * Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

Given queries in form [xi, mi]
The answer to a query i.e 
query[i] = max xor value of xi with any integer in arr but it should be less 'mi'

Naive approach: Do as the problem says
Time: O(no_of_query * arr_size)
*/

#include <bits/stdc++.h>
using namespace std;

class NaiveSolution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int no_of_queries = queries.size();
        vector<int> ans;

        for (int i = 0; i < no_of_queries; i++)
        {
            int xi = queries[i][0];
            int mi = queries[i][1];

            int maxXOR = -1;
            for (int j = 0; j < nums.size(); j++)
            {
                if(nums[j] <= mi)
                    maxXOR = max(maxXOR, xi ^ nums[j]);
            }
            ans.push_back(maxXOR);
        }

        return ans;
    }
};

/*
Efficient approach: Use Trie

We want (arr[i]^xi) to be max given arr[i]<=mi
The trie will only contain elements <= mi
Now it boils down to prev problem i.e just finding
max (arr[i]^x)

Now I will pre-process the queries rather than processing them when their turn comes
but before pre-processing I need to sort them wrt mi
since now we can add els in trie properly
We also need to sort input arr

But the ans vector should contain answers in the given order of queries, how do we tackle this?

we maintain an auxilary array, in the queries vector we assign a query number to each of query

Video link: https://youtu.be/Q8LhG9Pi5KM
Dry run starts at 11:30 = he has already given number to query

Time: 
O(q): for giving query no
+ 
O(qlogq): for sorting
+
O(n) for while loop
+
O(q*32) for 
+ 
O(n*32) for travering processed querie
*/

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int n)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {

            // check if ith bit is set
            int bit = (n >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int n)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            // check if ith bit is set / get the bit
            int bit = (n >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> preprocessQ;
        int q = queries.size(); // q: no of queries
        for (int i = 0; i < q; i++)
        {
            // storing in form (mi, {xi, query_no})
            preprocessQ.push_back({queries[i][1], {queries[i][0], i}});
        }

        // sort wrt mi
        sort(preprocessQ.begin(), preprocessQ.end());
        vector<int> ans(q, 0);
        int n = nums.size();
        int idx = 0;
        Trie t;
        for (int i = 0; i < q; i++)
        {
            int mi = preprocessQ[i].first;
            int xi = preprocessQ[i].second.first;
            int qIdx = preprocessQ[i].second.second;

            while(idx < n && nums[idx] <= mi)
            {
                t.insert(nums[idx]);
                idx++;
            }

            if(idx == 0)
                ans[qIdx] = -1;
            else
                ans[qIdx] = t.getMax(xi);
        }
        return ans;
    }
};