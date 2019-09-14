#include<stdio.h>
int main()
{
int i,count=0;
char str[20];
printf("Enter the string: \n");
scanf("%s",str);
for(i=0;i<str[i]!='\0';i++)
{
if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
{
count++;
}
}
printf("The number of consonants: %d \n",count);
}
