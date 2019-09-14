#include <stdio.h>
#include "ptrinfo.h"
int main()
{
struct student s1,*ptr;
ptr=&s1;
printf("Enter name:");
scanf("%s",s1.name);
printf("Enter roll no:");
scanf("%d",&s1.rno);
printf("Enter percentage:");
scanf("%lf",&s1.perc);
printf("Name: %s \n",ptr->name);
printf("Roll No: %d \n",ptr->rno);
printf("Percentage: %.2lf \n",ptr->perc);
}



