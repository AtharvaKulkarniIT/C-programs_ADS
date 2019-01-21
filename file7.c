//reads string as input and writes them to a file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	FILE *fp;//declaring file pointers
	char s[150];
	fp = fopen("hello.txt","w");//reading hello.txt info
	if(fp==NULL)//check if file exists
	{
		puts("Cannot open source file");
		fclose(fp);
		exit(1);//terminates program directly
	}
	printf("Enter a few new lines of text \n");

	while(strlen(fgets(s,150,stdin))>0)
	{
		fputs(s,fp);
		fputs("\n",fp);
		break;
	}
	fclose(fp);
}