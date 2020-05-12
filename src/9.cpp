// FINDING THE INORDER SUCCESSOR IN A BINARY SEARCH TREE

#include<iostream>

using namespace std;

class BSTNode
{
    public:
        int data;
        struct BSTNode *left;
        struct BSTNode *right;
};

BSTNode* Find(BSTNode*root, int data)
{
	if(root == NULL)
        return NULL;
	if(root->data == data)
        return root;
	if(root->data < data)
        return Find(root->right,data);
	else
        return Find(root->left,data);
}

struct BSTNode* FindMin(struct BSTNode* root)
{
	if(root == NULL) return NULL;

	while(root->left != NULL)
		root = root->left;
	return root;
}

struct BSTNode* Getsuccessor(struct BSTNode* root,int data)
{
	struct BSTNode* current = Find(root,data);

	if(current == NULL) return NULL;

	if(current->right != NULL)
    {  //Case 1: BSTNode has right subtree.
		return FindMin(current->right);
	}
	else
    {   //Case 2: No right subtree.
        struct BSTNode* successor = NULL;
		struct BSTNode* ancestor = root;
		while(ancestor != current)
		{
			if(current->data < ancestor->data)
			{
				successor = ancestor; // So far this is the deepest BSTNode for which current BSTNode is in left.
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

void Inorder(BSTNode *root)
{
	if(root == NULL) return;

	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

BSTNode* Insert(BSTNode *root,char data)
{
	if(root == NULL)
    {
        root = new BSTNode();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
	return root;
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

	cout<<"\nInorder Traversal of the tree:" << endl;
	Inorder(root);

	int val;

	cout << "\nEnter the value of the node whose inorder successor you want to find: ";
	cin >> val;

	struct BSTNode* successor = Getsuccessor(root, val);
	if(successor == NULL)
        cout<< "\nSuccessor NOT found." << endl;
	else
        cout<< "\nSuccessor found! It is: " << successor->data << endl;
}
