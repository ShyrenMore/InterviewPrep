/*

Given a binary tree, check if it's a height balanced or not 
Height balanced: the diff b/w height of left subtree and height of right subtree is at most 1 
This should be true for every node 

Naive sol: 
begin with root, compute height of left and right subtree
check if diff is <= 1, 
if these is true we do a recursive call for right subtree 
then a recursive call for left subtree 

Time: O(N^2)
Since height takes O(N-1) time
and you call height for each node 

Eff sol:
What if right and left child calls does two things
- if sub-tree is balanced
- height of sub-tree
we can do this by returning a pair where first will be a boolean var
and second will be int indicating height of sub-tree 
Or 
return only 1 int 
if func returns -1, we say tree is unbalanced
else return height  

Time: O(N)
traversing every node and doing constant amt of work

*/

#include <iostream>
#include <math.h>
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

int height(Node* root)
{

    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced_naive(Node* root)
{
    if(root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    return (fabs(lh - rh) <= 1 && isBalanced_naive(root->left) && isBalanced_naive(root->right));
}

int isBalanced_eff(Node* root)
{
    if(root == NULL)
        return 0;

    int lh = isBalanced_eff(root->left);
    if(lh == -1)
        return -1;

    int rh = isBalanced_eff(root->right);
    if(rh == -1)
        return -1;
    
    if(fabs(lh-rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

