#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	fp = fopen("hello.txt","r");
	char ch;
	while(ch!=EOF)//or use while(!feof(fp)),use fgets and puts then.
	{
		ch= fgetc(fp);
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}