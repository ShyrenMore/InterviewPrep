#include <iostream>
#include <queue>
using namespace std;

class Node {
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

void printLevel(Node *root)
{
    if(root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
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
    root->left = new Node(15);
    root->left->left = new Node(30);

    root->right = new Node(20);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    root->right->left->right = new Node(70);

    printLevel(root);
    return 0;
}

/*
  op: 10 15 20 30 40 50 60 70
  Time: theta(n)
  Space: O(n), sometimes it's going to be constant
  in queue, we will have one level at most at a time
  hence O(width)

  if tree is skewed, Aux space = O(1)
  if tree is balanced, Aux space = theta(n)
*/