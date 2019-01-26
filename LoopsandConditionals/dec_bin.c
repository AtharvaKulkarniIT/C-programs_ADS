#include <stdio.h>
int main()
{
    int n,k=0;
    printf("enter the no\n");
    scanf("%d",& n);
    int t=n;
    while(t!=0)
    {
        k++;
        t=t/2;
    }
    int a[k];
    t=n;
    int j=0;
    while(t!=0)
    {
        int r=t%2;
        a[j]=r;
        t=t/2;
        j++;
    }
    printf("binary=");
    for (int i=k-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    fflush(stdin);
    int p=1,s=0,m=0,n_p;
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=i;j++)
        {
            p=p*2;
        }
        n_p=a[m]*p;
        s=s+n_p;
        p=1;
        m++;
    }
    printf("decimal=%d\n",s);
}
