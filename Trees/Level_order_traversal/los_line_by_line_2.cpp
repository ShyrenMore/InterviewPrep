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
O(n) overall time
space: theta(width) i.e O(n) in case of complete bin tree
*/