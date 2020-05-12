// CHECKING IF A BINARY TREE IS A BINARY SEARCH TREE OR NOT - BRUTE FORCE APPROACH

#include<iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

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

bool IsSubtreeLesser(BinaryNode* root, int value)
{
    if(root==NULL)
        return true;

    if((root->data<=value)
       && IsSubtreeLesser(root->left, value)
       && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(BinaryNode* root, int value)
{
    if(root==NULL)
        return true;

    if((root->data>value)
       && IsSubtreeGreater(root->left, value)
       && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

bool IsBinarySearchTree(BinaryNode* root)
{
    if(root==NULL)
        return true;

    if(IsSubtreeLesser(root->left, root->data)
       && IsSubtreeGreater(root->right, root->data)
       && IsBinarySearchTree(root->left)
       && IsBinarySearchTree(root->right))
        return true;
    else
        return false;
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
