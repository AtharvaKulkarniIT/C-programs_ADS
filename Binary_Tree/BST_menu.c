#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node *newnode(int item) //Used to add new node to the tree
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node *root,int value)
{
	if(root == NULL)
		return newnode(value);
	if(value<root->data)
		root->left = insert(root->left,value);//recursion used
	if(value>root->data)
		root->right = insert(root->right,value);//recursion used
}

void inorder(struct node *root)
{
	int ht=1;
	
	printf("\n");
}

int main()
{

	struct node *root;
	root = NULL;
	int ch=1,ch2,value;
	while(ch!=4)
	{
		printf("\n******************BINARY SEARCH TREE*************************\n1.Insertion\n2.Traversal with recursion\n3.Traversal without recursion\n3.Height of the tree\n4.Exit\n");
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
			inorder(root);
			break;
			else if(ch2==2)
			inorder(root);
			break;
			else if(ch2==3)
			inorder(root);
			else
				break;
			case 4:
			printf("You chose to exit.\n");
			exit(0);
			default:
			printf("Wrong value entered!\n");
	}
}
}