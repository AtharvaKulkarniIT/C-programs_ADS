#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
FILE *fp1,*fp2;
char ch;
fp1=fopen("source.txt","r");
if(fp1 == NULL)
{
puts("File does not exist");
fp2=fopen("target.txt","n");
if(fp2 == NULL)
{
puts("File does not exist");
fclose(fp1);
exit(1);
}
while((ch=fgetc(fp1))!=EOF)
{
ch=toupper(ch);
fputc(ch,fp2);
}
printf("\n File successfully copied");
return 0;
}
}
