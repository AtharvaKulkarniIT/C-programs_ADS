#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void printlist(struct Node *n)
{
	struct Node *temp;
	temp = n;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL;
	printf("Enter a no: ");
	scanf("%d",&n);
	
	printlist(head);
}