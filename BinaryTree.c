//Binary Tree implementation

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
} node;

node *create()
{
	node *p;
	int x;
	printf("\nEnter data(-1 for no data):");
	scanf("%d", &x);
	if (x == -1)
	{
		return NULL;
	}
	p = (node *)malloc(sizeof(node));
	p->data = x;
	printf("\nEnter left of %d : ", x);
	p->left = create();
	printf("\nEnter right of %d : ", x);
	p->right = create();
	return p;
}
void InOrder(node *root)
{
	if(root != NULL)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}
void preOrder(node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(node *root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}
void print_leaf(node * root)
{
	if(root!=NULL)
	{
		if(root->left == NULL && root->right == NULL)
		{
			printf("%d ", root->data);
		}
		print_leaf(root->left);
		print_leaf(root->right);
	}
}
int max(int x, int y)
{
	return x>y?x:y;
}
int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return 0;
	}
	else
	{
		return(1+max(height(root->left), height(root->right)));
	}	
}

int main()
{
	node *root;
	root = create();
	printf("\nPreorder Travesal of tree: ");
	preOrder(root);
	printf("\nPostorder Traversal of tree: ");
	postOrder(root);
	printf("\nInOrder Traversal of tree: ");
	InOrder(root);
	printf("\nLeaf nodes of tree: ");
	print_leaf(root);
	printf("\nHeight of tree is %d ", height(root));

	return 0;
}