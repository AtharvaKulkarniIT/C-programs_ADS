#include <stdio.h>
#include "info.h"
int main()
{
struct user a;
printf("Enter your name, roll no, and grno.\n");
scanf("%s %d %d",a.name,&a.age,&a.grno);
printf("%s  %d  %d \n",a.name,a.age,a.grno);
}
