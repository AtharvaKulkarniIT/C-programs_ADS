#include <stdio.h>
 
int to_upper_file(FILE *);
 
int main(int argc,char *argv[])
{
    FILE *fp;
    int status;
 
    if (argc == 1)
    {
        printf("Insufficient Arguments:");
        printf("No File name is provided at command line");
        return;
    }
    if (argc > 1)
    {
        fp = fopen(argv[1],"r+");
        status = to_upper_file(fp);
 
        /* 
          *If the status returned is 0 then the coversion of file content was completed successfully
         */
 
        if (status == 0)
        {
            printf("\n The content of \"%s\" file was successfully converted to upper case\n",argv[1]);
            return;
        }
        /*
          * If the status returnes is -1 then the conversion of file content was not done
          */
        if (status == -1)
        {
            printf("\n Failed to convert");
            return;
        } 
   }
}
 
/*
 * convert the file content to uppercase
 */
int to_upper_file(FILE *fp)
{
    char ch;
 
    if (fp == NULL)
    {
        perror("Unable to open file");
        return -1;
    }
    else
    {
        /*
          * Read the file content and convert to uppercase
          */
        while (ch != EOF)
        {
            ch = fgetc(fp);
            if ((ch >= 'a') && (ch <= 'z'))
            {
                ch = ch - 32;
                fseek(fp,-1,SEEK_CUR);
                fputc(ch,fp);
            }    
        }
        return 0;
    }
}
