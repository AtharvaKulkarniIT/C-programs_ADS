//code for checking no of characters,lines,spaces,tabs
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int nol=0,not=0,noc=0,nob=0;
    fp=fopen("hello.txt","r");
    while(1)
    {
    	ch = fgetc(fp);
    	if(ch==EOF)
    	break;
    		noc++;
    	if(ch==' ')
    		nob++;
    	if(ch=='\n')
    		nol++;
    	if(ch=='\t')
    		not++;
    }	
    fclose(fp);
    printf("No of characters=%d\n",noc);
    printf("No of lines=%d\n",nol);
    printf("No of blank spaces=%d\n",nob);
    printf("No of tabs=%d\n",not);
    fclose(fp);
	return 0;
}