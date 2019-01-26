#include <stdio.h>
#include<stdlib.h>
int main()
{
    char s2[100],s1[100],ch,ch1;
    char fname[50],fname1[50];
    FILE *fp,*fp1;
    printf("enter the file name\n");
    scanf("%s", fname);
    fp=fopen(fname,"r");
    printf("enter the file name\n");
    scanf("%s", fname1);
    fp1=fopen(fname1,"r");
    if(fp==NULL&&fp1==NULL)
    {
        printf("file does not exist\n");
        exit(1);
    }
    do
    {
        fscanf(fp,"%s",s1);
        printf("%s\n",s1);
        fscanf(fp1,"%s",s2);
        printf("%s\n",s2);
        ch=fgetc(fp);
        ch1=fgetc(fp1);
    }while(ch!=EOF||ch1!=EOF);
    fclose(fp);
    fclose(fp);
}
