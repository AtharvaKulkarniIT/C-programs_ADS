#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int queue_array[MAX];
    int rear = - 1;
    int front = - 1;

void insert(int *add_item)
    {
    	int new_item = *add_item;
        if (rear == MAX - 1)
        printf("Sorry, there are too many orders at the moment. \n");
        else
        {
            if (front == - 1)
            /*If queue is initially empty */
            front = 0;
            rear = rear + 1;
            queue_array[rear] = new_item;
        }
    } /* End of insert() */
     
    void delete()
    {
        if (front == - 1 || front > rear)
        {
            printf("There are 0 orders remaining. \n");
            return;
        }
        else
        {
            printf("Delivery complete/cancelled! Order no. is : %d\n", queue_array[front]);
            front = front + 1;
        }
    } /* End of delete() */
     
    void display()
    {
        int i;
        if (front == - 1 || front > rear)
            printf("There are 0 orders remaining. \n");
        else
        {
            printf("The order nos remaining are : \n");
            for (i = front; i <= rear; i++)
                printf("%d ", queue_array[i]);
            printf("\n");
        }
    } /* End of display() */

int main()
{
	int ch=0,ordno;
	printf("*****************************PIZZA DELIVERY******************************\n");
	while(ch!=4)
	{	
		printf("\n1. Add an pizza order \n");
            printf("2. Delete a pizza order \n");
            printf("3. Display all pizza orders remaining \n");
            printf("4. Quit \n");
            printf(" Enter your choice : ");
            scanf("%d", &ch);
         switch (ch)
            {
                case 1:
                printf("Please enter your order no:");
				scanf("%d",&ordno);
                insert(&ordno);
                break;
                case 2:
                delete();
                break;
                case 3:
                display();
                break;
                case 4:
                exit(1);
                default:
                printf("Wrong choice! Please enter again. \n");
            } 
        }

	return 0;
	}
	