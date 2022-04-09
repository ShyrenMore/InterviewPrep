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

int getMax(Node* root)
{
    if(root==NULL)
        return INT64_MIN;

    return max(root->data, max(getMax(root->left), getMax(root->right)));
}

int main()
{
    return 0;
}