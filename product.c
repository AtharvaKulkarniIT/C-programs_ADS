#include<stdio.h>
float prod(float i,int j);
int main()
{
float i;
int j;
printf("Enter a float value and an integer value:\n");
scanf("%f%d",&i,&j);
printf("The product of the 2 nos is: %.2f \n",prod(i,j));
}
float prod(float i,int j)
{
float prod2=i*j;
return(prod2);
}
