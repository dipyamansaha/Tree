// BINARY SEARCH TREE - LINKED LIST IMPLEMENTATION

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

bool Search(BSTNode* root, int x)
{
    if(root==NULL)
        return false;
    if(x==root->data)
        return true;
    if(x<=root->data)
        return Search(root->left, x);
    return Search(root->right, x);
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

    if(Search(root, 2))
        cout << "\nFound 2!" << endl;
    else
        cout << "\nCouldn't find 2!" << endl;

    if(Search(root, 3))
        cout << "\nFound 3!" << endl;
    else
        cout << "\nCouldn't find 3!" << endl;

    if(Search(root, 5))
        cout << "\nFound 5!" << endl;
    else
        cout << "\nCouldn't find 5!" << endl;

    if(Search(root, 7))
        cout << "\nFound 7!" << endl;
    else
        cout << "\nCouldn't find 7!" << endl;
}
