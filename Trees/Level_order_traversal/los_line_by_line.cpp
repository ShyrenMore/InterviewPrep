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

void printLevelOrderLineByLine(Node *root)
{
    if(root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // here q.empty() is invalid
    // since at least there should be NULL in queue at any stage
    while(q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        
        if(curr == NULL){
            cout << "\n";
            q.push(NULL);
            /*
                lines 45 - 51 will not execute
            */
            continue;
        }

        cout << curr->data << " ";

        if(curr->left != NULL)
            q.push(curr->left);

        if(curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->right = new Node(30);

    printLevelOrderLineByLine(root);
    return 0;
}

/*
op:
10
20 30
40

time:
We are printing node exactly once
it goes and comes out of the queue exactly once 
there will O(h) extra nulls for every level
O(n + h) overall time
space: theta(width) i.e O(n) in case of complete bin tree 
*/