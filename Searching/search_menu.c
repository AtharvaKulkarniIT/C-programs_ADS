#include <stdio.h> 
  
int linearSearch(int arr[], int n, int x) 
{ 
    int result = 0;
    int count = 0;
    for (int i = 0; i < n; i++) 
        if (arr[i] == x)
        {
            result++;
            count = i; 
        }
    (result == 0) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n",count);                        
} 

int binarySearch(int arr[], int l, int r, int x) 
{ 
    int count = 0;
    int result = 0;
    while (l <= r) 
    { 
        int m = l + (r - l) / 2; 
        if (arr[m] == x) 
        {
            result++;
            count = m;
            break; 
        }
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    } 
    (result == 0) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n",count);                        
} 

  
int main() 
{
    int size=0,x=0;
    printf("Enter size of the array:");
    scanf("%d",&size); 
    int arr[size];
    printf("Enter the elements in the array:");
    for (int i=0;i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int key=0;
    while(key!=3)
    {
        printf("\n1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
            printf("Enter element to be searched:\n");
            scanf("%d",&x);
            linearSearch(arr,size,x);
            break;
            case 2:
            printf("Enter element to be searched:\n");
            scanf("%d",&x);
            binarySearch(arr,0,size,x);
            break;
            case 3:
            return 0;
            default:
            printf("Wrong choice! Please enter again.\n");
        }
    } 
    return 0; 
} 