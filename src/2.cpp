// FINDING MINIMUM AND MAXIMUM ELEMENTS IN A BINARY SEARCH TREE - ITERATIVE AND RECURSIVE APPROACHES

#include<iostream>

using namespace std;

class BSTNode
{
    public:
        int data;
        BSTNode* left;
        BSTNode* right;
};


BSTNode* Insert(BSTNode* root, int x)
{
    BSTNode* temp = new BSTNode();
    temp->data = x;
    temp->left = temp->right = NULL;

    if(root==NULL)
        root = temp;
    else if(x<=root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);

    return root;
}

int FindMin(BSTNode* root)
{
    if(root==NULL)
    {
        cout << "\nTree empty!" << endl;
        return -1;
    }

    while(root->left!=NULL)
    {
        root = root->left;
    }

    return root->data;
}

int FindMax(BSTNode* root)
{
    if(root==NULL)
    {
        cout << "\nTree empty!" << endl;
        return -1;
    }

    while(root->right!=NULL)
    {
        root = root->right;
    }

    return root->data;
}

int RecursiveFindMin(BSTNode* root)
{
    if(root==NULL)
    {
        cout << "\nTree empty!" << endl;
        return -1;
    }

    if(root->left==NULL)
    {
        return root->data;
    }

    return RecursiveFindMin(root->left);
}

int RecursiveFindMax(BSTNode* root)
{
    if(root==NULL)
    {
        cout << "\nTree empty!" << endl;
        return -1;
    }

    if(root->right==NULL)
    {
        return root->data;
    }

    return RecursiveFindMax(root->right);
}

int main()
{
    BSTNode* root = NULL;

    int n, num;

    cout << "How many elements do you wanna insert? ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cout << "\nEnter an element: ";
        cin >> num;

        root = Insert(root, num);
    }

    cout << "\nMinimum element, found iteratively: " << FindMin(root) << endl;
    cout << "\nMaximum element: found iteratively: " << FindMax(root) << endl;
    cout << "\nMinimum element, found recursively: " << RecursiveFindMin(root) << endl;
    cout << "\nMaximum element, found recursively: " << RecursiveFindMax(root) << endl;
}
