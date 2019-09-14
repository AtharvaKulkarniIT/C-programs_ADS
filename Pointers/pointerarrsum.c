#include <stdio.h>
void main()
{
int numArray[5];
int i,sum=0;
int *ptr;
printf(" Enter 5 elements: ");
for(i=0;i<5;i++)
scanf("%d",&numArray[i]);
ptr = numArray;
for(i=0;i<5;i++)
{
sum=sum + *ptr;
ptr++;
}
printf("The sum of array elements: %d \n", sum);
}
