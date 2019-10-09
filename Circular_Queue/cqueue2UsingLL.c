#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int info;
	struct Node *next;
}node;

node *front=NULL,*rear=NULL,*temp;

void display();
void enqueue();
void dequeue();

int main() {
	int ch;
	do {
 		printf("\n*****************Circular Linked List**********************\n\t   1. Enqueue : ");
		printf("\n\t   2. Dequeue : ");
		printf("\n\t   3. Display : ");
		printf("\n\t   4. Exit    : ");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch) {
			case 1:
			enqueue();
			break;
	 		case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
			case 4:
			return 1;
			default:
	 		printf("\nInvalid choice :");
		}
	} while(1);

	return 0;
}

void enqueue() {
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter the node value : ");
	scanf("%d",&newnode->info);
	newnode->next=NULL;
	if(front==NULL)
		front=rear=newnode;
	else {
		rear->next=newnode;
		rear=newnode;
	}
	rear->next=front;
}

void dequeue() {
	temp=front;
	if(front==NULL)
		printf("\nUnderflow :\n");
	else {
		if(front==rear) {
			printf("\nDeleted Element : %d\n",front->info);
			front=rear=NULL;
		}
		else {
			printf("\nDeleted Element : %d\n",front->info);
			front=front->next;
			rear->next=front;
		}

	temp->next=NULL;
	free(temp);
	}
}

void display() 
{
	temp=front;
	if(front==NULL)
		printf("\nQueue is Empty\n");
	else 
	{
		printf("\n");
		if(front == rear)
			printf("%d",temp->info);
		else 
		{
			do
			{
				printf(" %d",temp->info);
				temp=temp->next;
			} while(temp != front);
		}
		printf("\n");
	}
}
