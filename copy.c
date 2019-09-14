/*
 * C Program to Copy a File into Another File
 */
#include <stdio.h>
 
void main(int argc,char **argv)
{
    FILE *fp1, *fp2;
    char ch;
    int pos;
 
    if ((fp1 = fopen(argv[1],"r")) == NULL)    
    {    
        printf("\nFile cannot be opened");
        return;
    }
    else     
    {
        printf("\nFile opened for copy...\n ");    
    }
    fp2 = fopen(argv[2], "w");  
    fseek(fp1, 0L, SEEK_END); // file pointer at end of file
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET); // file pointer set at start
    while (pos--)
    {
        ch = fgetc(fp1);  // copying file character by character
        fputc(ch, fp2);
    }    
    fcloseall();    
}
