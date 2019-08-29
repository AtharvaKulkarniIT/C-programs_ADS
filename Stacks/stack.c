#include <stdio.h>
#include <stdlib.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() 
{
   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() 
{
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek()
{
    printf("\nElement on the top: %d \n",stack[top]);
}

int pop()
 {
   int data;	
   if(!isempty()) 
   {
      data = stack[top];
      top = top - 1;   
      printf("\nElement deleted %d\n",data );
   }
   else 
   {
      printf("\nCould not retrieve data, Stack is empty.\n");
   }
}

int push()
{
   int data;
   printf("Enter element: ");
   scanf("%d",&data);
   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } 
   else 
   {
      printf("\nCould not insert data, Stack is full.\n");
   }
}

int main() 
{
   int key;
   while(1)
   {
      printf("\n1. Push element in the stack \n");
      printf("2. Pop element from the stack \n");
      printf("3. Peek \n");
      printf("4. Exit \n");
      printf("Enter your choice: \n");
      scanf("%d",&key);
   switch(key)
   {
      case 1:
         push();
         break;
      case 2:
         pop();
         break;
      case 3:
         peek();
         break;
      case 4:
      exit(1);
      default:
      printf("Wrong input!\n\n");
   }
   }
   
   return 0;
}