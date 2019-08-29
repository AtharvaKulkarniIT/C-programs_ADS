#include <stdio.h>
#include <stdlib.h>

int queue[5];
	int front = -1;
	int rear = -1;
	int size = 5;
	int key=99;
	int num;
int isFull()
{
	if(front==(size-1) && rear==(size-1))
		return 1;
}

int isEmpty()
{
	if(front==-1 && rear == -1)
		return 1;
}

void Enqueue(int num,int queue[])
{
	if(isFull())
	{
		printf("Queue is full!");
	}
	else
	{
		rear+=1;
		queue[rear] = num;
		if(front == -1)
			front = 0;
		printf(queue);
	}
}

void Dequeue()
{
	if(isEmpty())
		printf("The Queue is empty!");
	else
	{
		printf("The element removed is %d ",queue[front]);
		front+=1;
		if(front == (size-1))
			front =-1;

	}
}

int main()
{
	
	while(key!=0)
	{
	printf("Enter 1 to Enqueue, 2 to Dequeue, 0 to Quit \n");
	scanf("%d",&key);
	if(key==1)
		printf("Enter a no to be added\n");
		scanf("%d",&num);
		Enqueue(num,queue);
	if(key==2)
		Dequeue(queue);
	}

}