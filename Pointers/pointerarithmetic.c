#include<stdio.h>
int main()
{
int i=12,*ip=&i;
double d =2.3,*dp=&d;
char ch='a',*cp=&ch;
printf("Value of ip= %p \n",ip);
printf("Value of dp= %p \n",dp);
printf("Value of cp= %p \n\n",cp);
printf("Value of ip+1= %p \n",ip+1);
printf("Value of dp+1= %p \n",dp+1);
printf("Value of cp+1= %p \n\n",cp+1);
printf("Value of ip+2= %p \n",ip+2);
printf("Value of dp+2= %p \n",dp+2);
printf("Value of cp+2= %p \n",cp+2);
return(0);
}
