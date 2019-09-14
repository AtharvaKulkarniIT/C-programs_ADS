//use of fscanf and fprintf functions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct emp
	{
		char name[40];
		int age;
		float bs;
	};
int main()
{
	char c='y';
	FILE *fp;
	struct emp e;
	fp =  fopen("Employee.dat","w");
	if(fp==NULL)
	{
		puts("Cannot open file");
		exit(1);
	}
	do
	{
		printf("Enter name,age,salary:\n");
		scanf("%s%d%f",e.name,&e.age,&e.bs);
		printf("%s\n%d\n%.2f\n",e.name,e.age,e.bs);
		fflush(stdin);
	}while(c=='y');
}