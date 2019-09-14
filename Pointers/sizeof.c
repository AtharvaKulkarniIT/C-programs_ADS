#include<stdio.h>
void integer();
void doub();
void character();
void float_type();
int main()
{
integer();
doub();
character();
float_type();
}
void integer()
{
int *a,*b,c=10,d;
a=&c;
printf("address=%p \n",a);
printf("value=%d \n",*a);
b=a;
a++;
d=(int)a-(int)b;
printf("size of integer data type=%d\n",d);
}
void doub()
{
double *a,*b,c=10;int d;
a=&c;
printf("address=%p\n",a);
printf("value=%If\n",*a);
b=a;
a++;
d=(int)a-(int)b;
printf("size of double data type=%d\n",d);
}
void character()
{
char *a,*b,c='a';int d;
a=&c;
printf("address=%p \n",a);
printf("value=%c \n",*a);
b=a;
a++;
d=(int)a-(int)b;
printf("size of integer data type=%d\n",d);
}
void float_type()
{
float *a,*b,l=10.0;int d;
a=&l;
printf("address=%p \n",a);
printf("value=%f \n",*a);
b=a;
a++;
d=(int)a-(int)b;
printf("size of integer data type=%d\n",d);
}
