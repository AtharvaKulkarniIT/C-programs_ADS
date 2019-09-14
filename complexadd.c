#include<stdio.h>
int addr(int a1,int a2);
int addi(int b1,int b2);
int main()
{
int a1,a2,b1,b2;
printf("\t Addition of 2 complex nos.\n");
printf("Enter the real part and imaginary part of 2 nos seperately:\n");
scanf("%d",&a1);
scanf("%d",&a2);
scanf("%d",&b1);
scanf("%d",&b2);
addr(a1,a2);
addi(b1,b2);
printf("The sum of the 2 nos is:%d+%di \n",addr(a1,a2),addi(b1,b2));
}
int addr(int a1,int a2)
{
int add = a1+a2;
return(add);
}
int addi(int b1,int b2)
{
int add = b1+b2;
return(add);
}



