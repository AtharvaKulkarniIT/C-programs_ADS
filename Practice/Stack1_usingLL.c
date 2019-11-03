#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *top;

void push(int *value)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		top = newnode;
		top->data = *value; 
		top->next = NULL;
		return;
	}
	newnode->data = *value;
	newnode->next = top;
	top = newnode;
}

void pop()
{
	if(top==NULL)
	{
		printf("Stack is empty!\n");
		return;
	}
	struct node *temp = top;
	free(top);
	top = temp->next;
	printf("Stack top element deleted\n");
}

void display()
{
	if(top == NULL)
	{
		printf("Stack is empty!\n");
		return;
	}
	struct node *temp =top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data );
		temp = temp->next;
	}
	printf("\n");
}


int main()
{
	int value,key;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
			printf("Enter value to be pushed:\n");
			scanf("%d",&value);
			push(&value);
			break;
			case 2:
			pop();
			break;
			case 3:
			display();
			break;
			case 4:
			exit(0);
			default:
			printf("Wrong value entered!\n");
		}
	}
}