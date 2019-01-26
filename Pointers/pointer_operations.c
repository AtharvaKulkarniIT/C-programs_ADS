#include <stdio.h>
int main()
{
int a=5,b=10,*c,*d,sub=0,add=0,mult=0,div=0;
c=&a;
d=&b;
add = *d + *c;
sub = *d - *c;
mult = (*d) * (*c);
div = (*d) / (*c);
printf("Original value of a and b: %d,%d \n",a,b);
printf("Sum of a and b: %d \n",add);
printf("Difference between a and b: %d \n",sub);
printf("Product of a and b: %d \n",mult);
printf("Values after division: %d\n",div);
}

