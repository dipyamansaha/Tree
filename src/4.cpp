// LEVEL ORDER TRAVERSAL (BREADTH-FIRST) IN A BINARY TREE

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

void LevelOrder(BinaryNode* root)
{
    if(root==NULL)
        return;

    queue<BinaryNode*> Q;
    Q.push(root);

    cout << "\nLevel order traversal of the binary tree: " << endl;
    while(!Q.empty())
    {
        BinaryNode* current = Q.front();
        cout << current->data << endl;

        if(current->left!=NULL)
            Q.push(current->left);
        if(current->right!=NULL)
            Q.push(current->right);

        Q.pop();
    }
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

    LevelOrder(root);
}
