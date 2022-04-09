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

int getSize(Node* root)
{
    if(root == NULL)
        return 0;

    return 1 + getSize(root->left) + getSize(root->right);
}