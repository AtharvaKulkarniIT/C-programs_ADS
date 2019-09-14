#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;
int count = 0;

inserthead()
{
	printf("Enter element to be inserted: \n");
	scanf("%d",&n);
	struct node *newnode = (struct node*)malloc(sizeof(struct node))
	count++;
	if(head == NULL && tail == NULL)
	{
		head = newnode;
		head->data = n;
		head->next = NULL;
		head->prev = NULL;
		return;
	}
	newnode->data = n;
	head->prev = newnode;
	newnode->next = head;
	head = newnode;

}

int main()
{
	while(key!=10)
	{
		printf("\n***********DOUBLY LINKED LIST*****************\n");
		printf("1. Insert at head\n");
		printf("2. Insert at tail\n");
		printf("3. Insert before position\n");
		printf("4. Insert after position\n");
		printf("5. Delete from head\n");
		printf("6. Delete from tail\n");
		printf("7. Delete before position\n");
		printf("8. Delete after position\n");
		printf("9. Display\n");
		printf("10. Exit\n");
		scanf("%d",&key);
	}
	switch(key)
	{
		case 1:
		inserthead();
		case 2:
		inserttail();
		case 3:
		insertbeforee();
		case 4:
		insertafter();
		case 5:
		deletehead();
		case 6:
		deletetail();
		case 7:
		deletebefore();
		case 8:
		deleteafter();
		case 9:
		display();
		case 10:
		exit(0);
		default:
		printf("Wrong value entered! Please enter a correct one.\n");
	}
}