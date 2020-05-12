// DELETION OF A NODE IN A BINARY SEARCH TREE

#include<iostream>
using namespace std;

class BSTNode
{
    public:
        int data;
        BSTNode *left;
        BSTNode *right;
};

BSTNode* FindMin(BSTNode* root)
{
	while(root->left != NULL)
        root = root->left;

	return root;
}

BSTNode* Delete(BSTNode *root, int data)
{
	if(root == NULL)
        return root;
	else if(data < root->data)
        root->left = Delete(root->left,data);
	else if (data > root->data)
        root->right = Delete(root->right,data);

	// Node to be deleted found.
	else
	{
        // Case 1:  No child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL)
		{
			BSTNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
        {
			BSTNode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else
		{
			BSTNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}

	return root;
}

void Inorder(BSTNode *root)
{
	if(root == NULL) return;

	Inorder(root->left);
    cout << root->data << endl;
	Inorder(root->right);
}

BSTNode* Insert(BSTNode *root, int data)
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

    cout<<"\nInorder traversal of the tree: " << endl;
	Inorder(root);

	int delNum;

	cout << "\nThe node with which value do you want to be deleted? ";
	cin >> delNum;
	root = Delete(root, delNum);

	cout<<"\nInorder traversal of the tree after deletion: " << endl;
	Inorder(root);
}
