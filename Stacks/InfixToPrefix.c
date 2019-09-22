//Contains errors
#include <stdio.h>
#include <ctype.h>//used for alnum() operation
#include <string.h>
char stack[20];
int top = -1;

void push(char c)
{
	if(top==-1)
	{
		top=0;
		stack[top]=c;
	}
	else
	{
		stack[top]=c;
		top++;
	}
}

char pop()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		return(stack[top--]);
	}
}

int priority(char x)
{
    if(x == ')')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

int main()
{
    char exp[20];
    char revexp[20];
    char *e, x;
    int j=0;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    int len = strlen(exp);
    for(int i=len-1;i>=0;i--)
    {
    	revexp[j] = exp[i];
    	j++;
    }
    e=revexp;
    while(*e!='\0')
    {
    	if(*e==')')
    		push(*e);
    	else if(isalnum(*e))
    	{
    		printf("%c",*e);
    	}
    	else if(*e=='(')
    	{
    		while(x=pop()!=')')
    		{
    			printf("%c",x);
    		}
    	}
    	else
    	{
    		if(priority(*e)<=priority(stack[top]))
    		{
    			printf("%c",pop());
            push(*e);
        	}
        	e++;

    	}
    	while(top != -1)
    	{
        printf("%c",pop());
    	}
    	printf("\n");

    return 0;
}
}