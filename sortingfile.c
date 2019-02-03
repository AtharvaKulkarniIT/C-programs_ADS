#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
char name[50];int age;
};struct student detail[100];
int main()
{
int count = 0;
FILE *fptr;
char filename[100];
printf("Enter the filename to pen \n");
scanf("%s",filename);
//open file
fptr = fopen(filename,"r");
if(fptr == NULL)
{
printf("Cannot open file \n");
exit(0);
}
else
{
char ch;
do
{
ch = fgetc(fptr);
if(ch == '\n')
count++;
} while(ch !=EOF);
rewind(fptr);
int i,j;
for(i=0;i<count;i++)
{
fscanf(fptr,"%s %d \n",detail[i].name,&detail[i].age);
}
for(i=0;i<count;i++)
{
printf("%s %d \n",detail[i].name,detail[i].age);
}
printf("after sorting in alphabetical order\n");
for(int i=0;i<count-1;i++)
{
for(int j=0;j<count-1-i;j++)
if(strcmp(detail[j].name,detail[j+1].name)>0)
{
int temp = detail[j].age;
detail[j].age=detail[j+1].age;
detail[j+1].age=temp;
char temp1[50];
strcpy(temp1,detail[j].name);
strcpy(detail[j].name,detail[j+1].name);
strcpy(detail[j+1].name,temp1);
}
}
}
for(int k=0;k<count;k++)
{
printf("%s %d \n", detail[k].name,detail[k].age);
}
//Read contents from file
fclose(fptr);
return 0;
}

