#include<stdio.h>
int main()
{
int temp=0;
int a[5]={2,4,1,8,5};
for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
if(a[j]>
a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("The array after sorting:\n");
for(int k=0;k<5;k++)
{
printf("%d\t",a[k]);
}
printf("\n");
}


