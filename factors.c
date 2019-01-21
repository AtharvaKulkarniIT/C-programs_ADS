#include <stdio.h>
void factors(int n);
void main()
{
int n;
printf("Enter a number:\n");
scanf("%d",&n);
factors(n);
}
void factors(int n)
{
int num=n;
printf("The factors are :\n");
for (int i=1;i<=num;i++)
{
if((n%i)==0)
printf("%d\n",i);
}
}
