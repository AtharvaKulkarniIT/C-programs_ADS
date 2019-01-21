#include<stdio.h>
void passbyvalue(int j);
void passbyreference(int *j)
int main()
{
int i=9;
passbyvalue(i);
printf("Passing by value, i now is %d",i);
passbyreference(&i);
printf("Passing by reference, i now is %d",i);
}
void passbyvalue(int j)
{
j=99;
return;
}
void passbyreference(int *j)
{
*j=11;
return;
}
