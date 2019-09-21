#include <stdio.h>

void swap(int *l,int *r)
{
	int temp = *l;
	*l = *r;
	*r = temp;
}

void sortarr(int arr[],int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size-i-1; ++j)
		{
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void printarr(int arr[],int n)
{
	printf("\nThe array after sorting: \n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i] );
	}

}

int main()
{
	int n;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements: \n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	sortarr(arr,n);
	printarr(arr,n);

	return 0;
}