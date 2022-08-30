/*
Given a key and root node of BST,
insert key in BST and return the root of this tree

Recursive Approach:
The concept is similar to search in a BST
compare root with the key
if(key < root)
    then recursively call insert to left subtree of root and assign it to root's left
else if(key > root)
    then recursively call insert to right subtree ahd assign it to root's right

Since this is a BST, insertion will always happen at leaf node
We do the assign operation to link the new leaf node with the prev leaf

Time: O(h)
Space: Function call stack space O(h)

Iterative Approach:
We need to maintain extra ptr parent to do linking in final part
and a ptr curr which will do the traversing
if(key < curr)
    point curr to left child i.e curr.left
else if(key > curr)
    point curr to right child

Before updating curr we store curr refernece in parent ptr

At the end of search, curr will be pointing to null
parent will be pointing to a leaf
We now simply need to decide whether new node will be inserted as left or right child based on comparing parent's data with key to be inserted

Time: O(h)
Space: O(1)
*/
#include <iostream>
using namespace std;
struct TreeNode
{
    int key;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        key = x;
        left = right = NULL;
    }
};

TreeNode* recInsert(TreeNode* root, int x)
{
    if(root == NULL)
        return new TreeNode(x);
    else if(x < root->key)
        root->left = recInsert(root->left, x);
    else if (x < root->key)
        root->left = recInsert(root->left, x);

    return root;
}

TreeNode *itrInsert(TreeNode *root, int x)
{
    TreeNode *newNode = new TreeNode(x);
    TreeNode *parent = NULL, *curr = root;

    while(curr != NULL)
    {
        parent = curr;
        if(x < curr->key)
            curr = curr->left;
        else if(x > curr->key)
            curr = curr->right;
        else if (x == curr->key)
            return root;
    }

    // empty tree
    if(parent == NULL)
        return newNode;
    
    if(x < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}