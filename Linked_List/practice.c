#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
int value;

void insertend()
{
	printf("Enter value of the node:\n");
	scanf("%d",&value);
	struct node *newnode,*ptr;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head = newnode;
		newnode->data=value;
		newnode->next=NULL;
		return;
	}
	ptr = head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next = newnode;
	newnode->data = value;
	newnode->next = NULL;
}

void deleteend()
{
	struct node *temp,*ptr;
	temp=head;
	if(head==NULL)
	{
		printf("Linked List is already empty!\n");
		return;
	}

	while(temp->next!=NULL)
	{

		ptr = temp;
		temp = temp->next;
	}
	ptr->next = NULL;
	free(temp);		
	printf("Deleted element from end.\n");

}

void display()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("Linked List is empty!\n");
		return;
	}
	printf("Linked List is:\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main()
{
	int ch=1;
	while(ch!=4)
	{
		printf("\n1.Enter node at end\n2.Delete node from end\n3.Display\n4.Exit\nEnter your choice:\n");
		scanf("%d",&ch);
		if(ch==1)
			insertend();
		else if(ch==2)
			deleteend();
		else if(ch==3)
			display();
		else if(ch==4)
			printf("Quitting program.\n");
		else
			printf("Wrong key entered!\n");
	}
}