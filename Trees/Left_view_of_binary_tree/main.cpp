/*

Printr left view of binary tree
Left view is nothing but printing leftmost node for every level 

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

/*
Sol1: recursive 
If you are going to do a pre-order traversal of binary tree
we always visit the leftmost node first
While doing pre-order traversal, we maintain two variables
first called maxLevel initialised to 0
and other  is level variable which indicated level of current node 
so level will be initialised to 1 for root node 

At any node we check if curr level is greater than the maxLevel we have seen so far, 
if yes, we print this node 
and after printing the node, we update maxLevel variable 

Time: theta(n)
Space: theta(h)
*/

int maxLevel = 0;

void printLeftView_rec(Node* root, int level)
{
    if(root == NULL)
        return;

    if(maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    printLeftView_rec(root->left, level + 1);
    printLeftView_rec(root->right, level + 1);
}

void helper(Node *root)
{
    printLeftView_rec(root, 1);
}

/*
Iterative solution:
We do something similar to level order traversal line by line method 2
the only change is we print cuurnt node only if i==0

- we break the logic into two loops
- the outer loop calls the inner loop for every loop
- the inner loop prints one level at a time
- after completion of inner loop we print new line
- The outer loops runs till queue is empty
- the inner loop runs for how many items are present in queue which is actually the no of nodes present at that level
*/

void printLeftView(Node* root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        // dont put q.size() in below line,
        // since queue szie changes constantly
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();

            if(i==0)
                cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        cout << "\n";
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    printLeftView(root);
    return 0;
}

/*
op: 10 20 40 
*/