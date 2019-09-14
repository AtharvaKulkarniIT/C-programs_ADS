#include<stdio.h>
int a,b;
void swap(int*,int*);
int main()
{
printf("Enter 2 nos ");
scanf("%d %d",&a,&b);
swap(&a,&b);
}
void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
printf("Values of a and b after swapping: %d %d",a,b);
}
