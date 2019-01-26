#include <stdio.h>
int main()
{
    int s=0;
    int a[10];
    printf("enter the elements of the array\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",& a[i]);
        s=s+a[i];
    }
    float avg=s/10;
    int max=0;
    for(int i=0;i<10;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    int min=a[0];
    for(int i=1;i<10;i++)
    {
        if(min>a[i])
        {
            min=a[i];
        }
    }
    printf("minimum=%d\n",min);
    printf("maximum=%d\n",max);
    printf("average=%f\n",avg);
}
