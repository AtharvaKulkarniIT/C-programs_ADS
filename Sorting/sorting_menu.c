#include <stdio.h>

void swap(int *newmin,int *oldmin){
	int temp=*oldmin;
	*oldmin=*newmin;
	*newmin=temp;
	}
	
void selectionSort(int a[],int size){
	for(int i=0;i<size-1;i++){
		int min=i;
		for(int j=i+1;j<size;j++){
			if(a[j]<a[min])
				min=j;
			}
			swap(&a[min],&a[i]);
		}
	}

void insertionSort(int arr[],int n)
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

void printarr(int arr[], int n){
	printf("\n The array after sorting: \n");
	for(int i=0;i<n;i++){
		printf("%d  ",arr[i]);
		}
	}

int main(){
	int i,size;
	printf("Enter the array size: ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements in the array:");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original aray:\n");
	for(i=0;i<size;i++){
		printf("%d  ",arr[i]);
	}
	int key=0;
    while(key!=4)
    {
        printf("\n1. Selection Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
            selectionSort(arr,size);
            break;
            case 2:
            insertionSort(arr,size);
            break;
            case 3:
            printarr(arr,size);
            break;
            case 4:
            return 0;
            default:
            printf("Wrong choice! Please enter again.\n");
        }
    } 
	return 0;
}