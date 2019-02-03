#include<stdio.h>
int main()
{
int i,j,k;
char name[5][5];
int age[5];
for(i=0;i<5;i++)
{
printf("Enter your name:\n");
scanf("%s",name[i]);
printf("Enter your age:\n");
scanf("%d",&age[i]);
}
char temp1=' ';
int temp2=0;
for(j=0;j<5;j++)
{
for(k=0;k<5;k++)
{
if(name[k]>name[k+1])
{
temp1=name[k];
name[k]=name[k+1];
name[k+1]=temp1;
temp2=age[k];
age[k]=age[k+1];
age[k+1]=temp2;
}
}
}
printf("The info after sorting:\n");
for(i=0;i<5;i++)
{
printf("%s\t",name[i]);
printf("%d\n",age[i]);
}
}
