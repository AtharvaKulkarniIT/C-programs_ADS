#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char name[50];int phy,chem,math,total;
}; struct student detail[100];
int main()
{
    FILE *fptr;
    
    char filename[100];
    
    printf("Enter the filename to open \n");
    scanf("%s", filename);
    
    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    else
    {
        char ch;
        int count = 0;
        do
        {
            ch = fgetc(fptr);
            if (ch == '\n') count++;
        } while (ch != EOF);
        rewind(fptr);
        int i;
        for (i = 0; i < count; i++)
        {
            fscanf(fptr, "%s %d %d %d\n", detail[i].name, &detail[i].phy,&detail[i].chem,&detail[i].math);
        }
        for (i = 0; i < count; i++)
        {
            printf("%s %d %d %d\n", detail[i].name, detail[i].phy,detail[i].chem,detail[i].math);
        }
        for(int i=0;i<count;i++)
        {
            detail[i].total=detail[i].phy+detail[i].chem+detail[i].math;
        }
        printf("total marks of students\n");
        for (i = 0; i < count; i++)
        {
            printf("%s %d \n", detail[i].name, detail[i].total);
        }
    }
    // Read contents from file
    fclose(fptr);
    return 0;
}

