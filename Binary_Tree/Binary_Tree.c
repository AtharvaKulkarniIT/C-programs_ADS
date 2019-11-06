#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};
struct node *root = NULL;
int height=0;

struct node *create() 
{
	int x;
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data(-1 for no node)\n");
	scanf("%d",&x);
	if(root==NULL)
	{
		root->data = x;
	}
	if(x==-1)
		return 0;
	newnode->data = x;
	printf("Enter left child of %d\n", x);
	newnode->left = create();
	printf("Enter right child of %d\n", x);
	newnode->right = create();
	return newnode;
}

void inorder(struct node *root)
{
	height+=1;
	struct node *temp;
	temp = root;
	if(root==NULL)
		return;
	inorder(temp->left);
	printf("%d->",temp->data);
	inorder(temp->right);
}

void preorder(struct node *root)
{
	struct node *temp;
	temp = root;
	if(root==NULL)
		return;
	printf("%d->",temp->data);
	preorder(temp->left);
	preorder(temp->right);
}

void postorder(struct node *root)
{
	struct node *temp;
	temp = root;
	if(root==NULL)
		return;
	postorder(temp->left);
	postorder(temp->right);
	printf("%d->",temp->data);
}


int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Create a node\n2.Inorder\n3.Preorder\n4.Postorder\n5.Height\n6.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			create();
			case 2:
			inorder(root);
			case 3:
			preorder(root);
			case 4:
			postorder(root);
			case 5:
			printf("Height:%d\n",height);
			case 6:
			exit(0);
			default:
			printf("Wrong value entered!\n");
		}
	}
}