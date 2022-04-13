/*
Given a binary tree, find max width of tree

for empty binary tree, op is 0
We can use level order traversal line by line 
So we push the levels one by one in the queue 
and after pushing every level,
check if queue size is greater than current result 
if its greater, update result
finally we will have max width 
*/

#include <iostream>
#include <queue>
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

int maxWidth(Node *root)
{
    // tree is empty 
    if (root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {
        int count = q.size();
        res = max(res, count);
        // dont put q.size() in below line,
        // since queue size changes constantly
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            
            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

    }
    return res;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->right = new Node(30);

    cout<<maxWidth(root);
    return 0;
}

/*
op: 2
Time:
we are traversing each node exactly once
theta(N), N is no of nodes in the tree

Space: theta(width) or O(N/2) in case perfect binary tree 
*/