#include<stdio.h>
int main()
{
int *a;int *b;
int c=5;
a=&c;
 int b=&a;
printf("\n");
printf("\t\t  memory map \n");
printf("\n");
printf("     _________      __________\n");
printf("value:  |  %d   |   ->  |%p|\n",*a,b);
printf("address: |%p|     |%p|\n",b,&b);
printf("    _______     _________\n");
}
