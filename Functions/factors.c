#include <stdio.h>
void factors(int n);
void main()
{
int n;
printf("Enter a number:\n");
scanf("%d",&n);
factors(n);
}
void factors(int m)
{
int num=m;
printf("The factors are :\n");
for (int i=1;i<=num;i++)
{
if((m%i)==0)
printf("%d\n",i);
}
}
