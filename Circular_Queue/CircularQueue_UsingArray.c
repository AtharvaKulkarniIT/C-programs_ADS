#include <stdio.h>
#define size 5

void enqueue(int[], int);
void dequeue(int[]);
void display(int[]);

int front =  - 1;
int rear =  - 1;

int main()
{
    int n, ch;
    int queue[size];
    do
    {
        printf("\n Circular Queue:\n1. Insert \n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter Choice 0-3? : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                enqueue(queue, n);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                return(1);
            default:
                printf("Wrong Choice! Please enter again.\n");
        }
    }while (ch != 0);
}


void enqueue(int queue[], int item)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))//Queue full condition
    {
        printf("Queue is full");
        return;
    }
    else if (front ==  - 1)//resetting front and rear if queue was previously empty
    {
        rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)//if starting of queue is still empty despite rear pointing at last element
    {
        rear = 0;
    }
    else// normal condition just increment rear
    {
        rear++;
    }
    queue[rear] = item;
}

void display(int queue[])
{
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) //normally rear would be greater than front
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",queue[i]); 
    } 
    else // in cqueue rear can be in the starting thus less than front
    { 
        for (int i = front; i < size; i++) //printing all elements from front ptr to end of queue
            printf("%d ", queue[i]); 
  
        for (int i = 0; i <= rear; i++) //elements left out in the starting will be printed till rear
            printf("%d ", queue[i]); 
    } 
}

void dequeue(int queue[])
{
    if (front ==  - 1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)//to reset front and rear if only 1 element present
    {
        printf("\n %d deleted", queue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else if (front == size-1) //if we have reached end of queue then fron moves on to 0th element
        front = 0;
    else//normal condition
    {
        printf("\n %d deleted", queue[front]);
        front++;
    }
}
