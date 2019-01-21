#include <stdio.h>
void fact(int n);
void main()
{
int n;
printf("Enter a number:\n");
scanf("%d",&n);
fact(n);
}
void fact(int n)
{
int j=1;
for(int i=n;i>0;i--)
{
j=j*i;
}
printf("The factorial is: %d \n",j);
}
