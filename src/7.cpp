// CHECKING IF A BINARY TREE IS A BINARY SEARCH TREE OR NOT - OPTIMAL SOLUTION

#include<iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

#define MIN_INT -10000
#define MAX_INT 10000

class BinaryNode
{
    public:
        int data;
        BinaryNode* left;
        BinaryNode* right;
};

BinaryNode* InsertInBST(BinaryNode* root, int x)
{
    BinaryNode* temp = new BinaryNode();
    temp->data = x;
    temp->left = temp->right = NULL;

    if(root==NULL)
        root = temp;
    else if(x<=root->data)
        root->left = InsertInBST(root->left, x);
    else
        root->right = InsertInBST(root->right, x);

    return root;
}

void InOrder(BinaryNode* root)
{
    if(root==NULL)
        return;

    InOrder(root->left);
    cout << root->data << endl;
    InOrder(root->right);
}

bool IsBSTUtil(BinaryNode* root, int minValue, int maxValue)
{
    if(root==NULL)
        return true;

    if(root->data>minValue
       && root->data<maxValue
       && IsBSTUtil(root->left, minValue, root->data)
       && IsBSTUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

bool IsBinarySearchTree(BinaryNode* root)
{
    return IsBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    BinaryNode* root = NULL;

    int n, num;

    cout << "How many elements do you wanna insert? ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cout << "\nEnter an element: ";
        cin >> num;

        root = InsertInBST(root, num);
    }

    cout << "\nInorder traversal of the tree: " << endl;
    InOrder(root);

    if(IsBinarySearchTree(root))
        cout << "\nBINARY SEARCH TREE!" << endl;
    else
        cout << "\nNOT A BINARY SEARCH TREE!" << endl;
}
