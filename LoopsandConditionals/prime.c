#include<stdio.h>
int main()
{
    int n,k=0,i;
    printf("enter the no.\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            k++;
        }
    }
    if(k==2)
    {
        printf("Its a prime no.\n");
    }
    else
    {
        printf("Not a prime no.\n");
    }
}
