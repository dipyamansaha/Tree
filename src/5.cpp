// PREORDER, INORDER AND POSTORDER TRAVERSAL (DEPTH-FIRST) IN A BINARY TREE

#include<iostream>
#include<queue>

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

void PreOrder(BinaryNode* root)
{
    if(root==NULL)
        return;

    cout << root->data << endl;
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BinaryNode* root)
{
    if(root==NULL)
        return;

    InOrder(root->left);
    cout << root->data << endl;
    InOrder(root->right);
}

void PostOrder(BinaryNode* root)
{
    if(root==NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << endl;
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

    cout << "\nPreorder traversal of the binary tree: " << endl;
    PreOrder(root);

    cout << "\nInorder traversal of the binary tree: " << endl;
    InOrder(root);

    cout << "\nPostorder traversal of the binary tree: " << endl;
    PostOrder(root);
}
