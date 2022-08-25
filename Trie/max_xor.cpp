/**
 * Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Video: https://youtu.be/EIhAwfHubE8

Consider given an arr and an int x, find max (arr[i]^x)
 * Insert all numbers in binary form into trie
 Consider bin represntation as string where each bit will have it's own node
 The struct for trie will only have two sections/index for 0 and 1

 * Take x and find max no from arr where (no^x) is maximum
 Since we have each bit of every el in trie, we can greedily take the opposite bit to maximise xor 

Now we can say we have solved a major sub-problem for the given problem
we will have multiple max xor
arr2[0]^ trie
arr2[1]^ trie....

we take maximum of all these values 

Time: 
O(N*32) for insertion + 
O(M*32) for finding max_xor of each el in arr2

**/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[2];
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int n)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--){
            
            // check if ith bit is set
            int bit = (n >> i) & 1;
            if(!node->containsKey(bit)){
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
            if (node->containsKey(1-bit))
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
    int findMaximumXOR(vector<int> &nums)
    {
        Trie t;

        for(auto &it : nums)
            t.insert(it);

        int maxi = 0;
        for(auto &it: nums)
            maxi = max(maxi, t.getMax(it));
        return maxi;
    }
};
