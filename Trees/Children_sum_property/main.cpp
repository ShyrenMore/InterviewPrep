/*
Given a binary tree check whether the tree follows children-sum property 
The property is nothing but value of any node is sum of left and right child 

Check if root's data is sum of left, right
For each recursive step we check if 
- root's data == sum
- left child result returns true
- right child returns true 
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key)
    {
        data = key;
        left = NULL;
        right = NULL;
    }
};

bool isCheckChildrenSum(Node* root)
{
    // NOT a base case, if ip is NULL
    if(root == NULL)
        return true;

    // base case check for leaf node
    if(root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;

    if(root->left != NULL)
        sum += root->left->data;

    if(root->right != NULL)
        sum += root->right->data;

    return (root->data == sum && isCheckChildrenSum(root->left) && isCheckChildrenSum(root->right));
}

/*
Time: O(n)
Space: O(h) for recursion call stack
*/