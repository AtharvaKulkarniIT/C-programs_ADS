//
//  spiral.c
//  
//
//  Created by ANGELO MATHAI on 17/10/18.
//

#include <stdio.h>
int main()
{
    int n,k,s=0;
    printf("enter the size of the array \n");
    scanf("%d",& n);
    int a[n];
    printf("enter the elements of the array \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",& a[i]);
    }
    for(int i=0;i<n;i++)
    {
            if(a[i]%2!=0)
            {
                s=s+a[i];
            }
    }
    printf("Sum=%d \n",s);
}
