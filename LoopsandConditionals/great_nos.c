#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter 3 nos\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a>b&&a>c)
    {
        printf("greatest no= %d \n",a);
    }
    else if(b>a&&b>c)
    {
        printf("greatest no= %d \n",b);
    }
    else
    {
        printf("greatest no= %d \n",c);
    }
}
