//
//  odd_even.c
//  
//
//  Created by ANGELO MATHAI on 17/10/18.
//

#include <stdio.h>
int main()
{
    int ev=0,od=0;
    int s;
    printf("enter the size of the primary array\n");
    scanf("%d",& s);
    int arr[s];
    printf("enter the elements of the array\n");
    for(int i=0;i<s;i++)
    {
        scanf("%d",& arr[i]);
        if(arr[i]%2==0)
        {
            ev++;
        }
        else
        {
            od++;
        }
    }
    int odd[od];
    int even[ev];
    int e=0,o=0;
    for(int i=0;i<s;i++)
    {
        if(arr[i]%2==0)
        {
            even[e]=arr[i];
            e++;
        }
        else
        {
            odd[o]=arr[i];
            o++;
        }
    }
    printf("even array\n");
    for(int i=0;i<ev;i++)
    {
        printf("%d\n",even[i]);
    }
    printf("odd array\n");
    for(int i=0;i<od;i++)
    {
        printf("%d\n",odd[i]);
    }
}
