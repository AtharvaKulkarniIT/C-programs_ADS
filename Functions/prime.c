#include<stdio.h>
void check(int n);
int main()
{
    int n;
    printf("Enter the no.\n");
    scanf("%d",&n);
    check(n);
}
    void check(int n)
    {
    if (n==1)
    {
    printf("%d is neither prime nor a composite no. \n",n);
    return;
    }
    int k=0;
    for(int i=1;i<=n;i++)
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
