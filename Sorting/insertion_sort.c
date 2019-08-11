#include <stdio.h>

void sortarr(int arr[],int n)
{
	int j,key;
	for (int i = 0; i < n; ++i)
	{
		key = arr[i];
		j=i-1;
		while(key<arr[j] && j>=0){
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = key;
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
