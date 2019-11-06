#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;

struct node *newnode(int item) //Used to add new node to the tree
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root,int value)
{
	if(root == NULL)
		return newnode(value);
	else if(value<root->data)
		root->left = insert(root->left,value);//recursion used
	else
		root->right = insert(root->right,value);//recursion used
}

void inorder(struct node *root)
{
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

	int ch=1,ch2,value;
	while(ch!=4)
	{
		printf("\n******************BINARY SEARCH TREE*************************\n1.Insertion\n2.Traversal with recursion\n3.Traversal without recursion\n4.Height of the tree\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter value to be inserted\n");
			scanf("%d",&value);
			insert(root,value);
			break;
			case 2:
			printf("1.Inorder Traversal\n2.Preorder Traversal\n3.Postorder Traversal\n");
			scanf("%d",&ch2);
			if(ch2==1)
			{
			inorder(root);
			break;
			}
			else if(ch2==2)
			{
			inorder(root);
			break;
			}
			else if(ch2==3)
			{
			inorder(root);
			}
			else
			break;
			case 3:

			break;
			case 4:
			exit(0);
			case 5:
			printf("You chose to exit.\n");
			exit(0);
			default:
			printf("Wrong value entered!\n");
	}
}
}