#include <stdio.h>
int main()
{
    int b[3][3];
    int a[3][3];
    int s[3][3];
    printf("enter the values of 1st array\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",& a[i][j]);
        }
    }
    printf("enter the values of 2nd array\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",& b[i][j]);
        }
    }
    //addition
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
             s[i][j]=a[i][j]+b[i][j];
        }
    }printf("addition\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
    //substraction
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
             s[i][j]=a[i][j]-b[i][j];
        }
    }
    //printing
    printf("substraction\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }int sum=0;
    //multiplication
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int x=0;x<3;x++)
            {
                for(int y=0;y<3;y++)
                {
                    sum=sum+((a[x][y])*(b[y][i]));
                }
                s[i][x]=sum;
                sum=0;
            }
            
        }
    }
    printf("multiplication\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",s[j][i]);
        }
        printf("\n");
    }
}
