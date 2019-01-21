// File Copy program
#include <stdio.h>
#include <stdlib.h>//allocates memory for creation of new file
int main()
{
	FILE *fs,*ft;//declaring file pointers
	char ch;
	fs = fopen("hello.txt","r");//reading hello.txt info
	if(fs==NULL)//check if file exists
	{
		puts("Cannot open source file");
		fclose(fs);
		exit(1);//terminates program directly
	}
	ft = fopen("prac.txt","w");
	if(ft==NULL)
	{
		puts("Cannot open target file");
		fclose(ft);
		exit(1);
	}
	while(1)
	{
		ch = fgetc(fs);
		if(ch == EOF)//check for end of file
		{
			break;
		}
		
		else
		{
			fputc(ch,ft);
		}
	}
		fclose(fs);
		fclose(ft);
}


