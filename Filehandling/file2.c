#include <stdio.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char s[100];
};
int main()
{
    int count=0;
    char ch;
    char fname[50],fname1[50];
    FILE *fp,*fp1;
    printf("enter the file name\n");
    scanf("%s", fname);
    fp=fopen(fname,"r");
    printf("enter the file name\n");
    scanf("%s", fname1);
    fp1=fopen(fname1,"w");
    if(fp==NULL&&fp1==NULL)
    {
        printf("file does not exist\n");
        exit(1);
    }
    do
    {
        ch = fgetc(fp);
        if (ch == '\n') count++;
    } while (ch != EOF);
    struct student line[count];
    rewind(fp);
    for(int i=0;i<count;i++)
    {
        fscanf(fp,"%s\n",line[i].s);
    }
    for(int i=0;i<count;i++)
    {
        printf("%s\n",line[i].s);
    }
    for(int i=0;i<count;i++)
    {
        fprintf(fp1,"%s\n",line[i].s);
    }
    fclose(fp);
    fclose(fp1);
}
