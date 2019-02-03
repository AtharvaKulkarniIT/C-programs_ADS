#include <stdio.h>
int main()
{
int i=1,j=2;
int *ptr1, *ptr2;
ptr1=&i;
ptr2=&j;
int sum,dif,inc1=0,inc2=0,dec1=0,dec2=0;
printf("Enter 2 nos:");
scanf("%d%d",ptr1,ptr2);
sum = *ptr1 + *ptr2;
dif = *ptr1 - *ptr2;
printf("Sum of the 2 pointers is:%d \n",sum);
printf("Difference of the 2 pointers is:%d \n",dif);
inc1 = *ptr1 +1;
inc2 = *ptr2 +1;
dec1 = *ptr1 -1;
dec2 = *ptr2 -1;
printf("new pointer values after incrementing: %d %d \n",inc1,inc2);
printf("new pointer values after decrementing: %d %d \n",dec1,dec2);
}

