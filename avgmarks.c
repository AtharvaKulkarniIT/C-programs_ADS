#include<stdio.h>
int main()
{
int avg,i,sum=0;
int marks[5];
printf("Enter your marks:\n");
for(i=0;i<5;i++)
{
scanf("%d",&marks[i]);
}
for(i=0;i<5;i++)
{
sum=sum+marks[i];
}
avg=sum/5;
printf("Your grades are:\n");
for(i=0;i<5;i++)
{
printf("%d\n",marks[i]);
}
printf("Avg marks= %d \n",avg);
return 0;
}
