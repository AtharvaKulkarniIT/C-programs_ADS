#include <stdio.h>

void swap(int *newmin,int *oldmin){
	int temp=*oldmin;
	*oldmin=*newmin;
	*newmin=temp;
	}
	
void sort(int a[],int size){
	for(int i=0;i<size-1;i++){
		int min=i;
		for(int j=i+1;j<size;j++){
			if(a[j]<a[min])
				min=j;
			}
			swap(&a[min],&a[i]);
		}
	}

void printarr(int arr[], int n){
	printf("\n The array after sorting: \n");
	for(int i=0;i<n;i++){
		printf("%d \n",arr[i]);
		}
	}

int main(){
	int i,n;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in the array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	printarr(arr,n);
	
	return 0;
}
