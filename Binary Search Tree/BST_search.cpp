/*
Given root and key
return true if key is present in BST else false

Approach:
Let's recall BST property before starting out:
All the values to the left of root are smaller
All the values to the right of root are greater


Recursive approach:
so compare key with root
if (key == root)
    return true
else if (key < root)
    recursively call search funct with left child as root
else if (key > root)
    recursively call search funct with right child as root

if we hit a null while searching that means key is not present

Time: O(h)
Space: Function call stack space O(h)

Iterative Approach:
Take a ptr initially pointing to root
compare root's data with given key
if they match we return false
else if key < root's data, update the ptr to root.left
otherwise update it to root.right

Time: O(h)
Space: O(1)
*/

struct TreeNode{
    int key;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        key = x;
        left = right = NULL;
    }
};

bool recSearch(TreeNode *root, int key)
{
    // if empty tree and base case
    if(root == NULL)
        return false;
    else if(root->key == key)
        return true;
    else if(key < root->key)
        return recSearch(root->left, key);
    else
        return recSearch(root->right, key);
}

bool itrSearch(TreeNode *root, int key)
{
    TreeNode *curr = root;
    while(curr != NULL)
    {
        if(key == curr->key)
            return true;
        else if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return false;
}