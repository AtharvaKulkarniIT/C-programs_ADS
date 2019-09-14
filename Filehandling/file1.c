
#include <stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    int s=0,l=0,t=0,c=0;
    char fname[50];
    FILE *fp;
    printf("enter the file name\n");
    scanf("%s", fname);
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("file does not exist\n");
        exit(1);
    }
    do
    {
        ch=fgetc(fp);
        if(ch==' ')
        {
            s++;
        }
        else if(ch=='\n')
        {
            l++;
        }
        else if(ch=='\t')
        {
            t++;
        }
        else
        {
            c++;
        }
    }while(ch!=EOF);
    printf("no. of spaces=%d\n",s);
    printf("no. of lines=%d\n",l);
    printf("no. of tabs=%d\n",t);
    printf("no. of characters=%d\n",c);
    
}
