#include<stdio.h>
struct dob
{
int date;
int month;
int year;
};
struct student
{
char name[50];
int id;
struct dob d1;
};
struct student s1;
int main()
{
printf("Enter name: ");
scanf("%s",s1.name);
printf("Enter id: ");
scanf("%d",&s1.id);
printf("Enter dob: ");
scanf("%d",&s1.d1.date);
scanf("%d",&s1.d1.month);
scanf("%d",&s1.d1.year);
printf("Name: %s \n",s1.name);
printf("ID: %d \n",s1.id);
printf("Date of birth: %d/%d/%d \n",s1.d1.date,s1.d1.month,s1.d1.year);
} 



