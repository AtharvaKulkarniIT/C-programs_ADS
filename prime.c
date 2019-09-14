#include<stdio.h>
int main()
{
int i,j,n;
printf("The prime nos from 1-300:");
for(i=2;i<=300;i++)
{
for(j=2;j<=i;j++)
{
 if(i==j)
 printf(" %d \t",i);
 else if(i%j==0)
 break;
}
}
printf("\n");
}
