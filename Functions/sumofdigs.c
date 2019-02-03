#include<stdio.h>
void sum(int num);
int main()
{
int num;
printf("Enter a number: \n");
scanf("%d",&num);
sum(num);
}
void sum(int num)
{
int temp = num;
int sum=0;
while(num>0)
{
int dig= num%10;
sum += dig;
num /= 10;
}
printf("The sum of digits of the no. %d is: %d \n",temp,sum);
}
