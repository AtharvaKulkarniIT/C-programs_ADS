#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*newnode;
int value;

void insertbeg()
{
	printf("Enter element to be inserted:\n");
	scanf("%d",&value);
	if(head == NULL)
	{
		head = newnode;
		head->next = NULL;
		head->data = value;
		return;
	}
	newnode->data = value;
	newnode->next = head;
	head = newnode;
}

void insertend()
{
	printf("Enter element to be inserted:\n");
	scanf("%d",&newnode->data);
	if(head == NULL)
	{
		head->next = NULL;
		head = newnode;
		return;
	}
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
	newnode->next = NULL;
}

void deletebeg()
{
	if(head == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	printf("Deleted element is: %d\n",head->data);
	struct node *temp;
	temp = head->next;
	free(head);
	head = temp;
}

void deleteend()
{
	if(head == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	printf("Deleted element is: %d\n",temp->data );
	temp = temp->next;
}

void traverse()
{
	if(head == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while(temp->next != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	printf("%d---->NULL\n",temp->data );
}

int main()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	int key = 1;
	while(key!=6)
	{
		printf("1.Insert at front\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Traverse\n6.Exit\n");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
			insertbeg();
			break;
			case 2:
			insertend();
			break;
			case 3:
			deletebeg();
			break;
			case 4:
			deleteend();
			break;
			case 5:
			traverse();
			break;
			case 6:
			exit(0);
			default:
			printf("Wrong value entered!\n");
		}
	}
	return 0;

}