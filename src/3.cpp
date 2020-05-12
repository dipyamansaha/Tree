// FINDING THE HEIGHT OF A BINARY TREE

#include<iostream>

using namespace std;

class BinaryNode
{
    public:
        int data;
        BinaryNode* left;
        BinaryNode* right;
};

BinaryNode* Insert(BinaryNode* root, int x)
{
    BinaryNode* temp = new BinaryNode();
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

int FindHeight(BinaryNode* root)
{
    if(root==NULL)
        return -1;

    return (max(FindHeight(root->left), FindHeight(root->right)) + 1);
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

        root = Insert(root, num);
    }

    cout << "\nHeight of the binary tree: " << FindHeight(root) << endl;
}
