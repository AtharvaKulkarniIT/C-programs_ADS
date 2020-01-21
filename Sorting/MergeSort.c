#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int mid, int r) 
{  
    int n1 = mid - l + 1; 
    int n2 =  r - mid; 
    int L[n1], R[n2]; 
    for (int i = 0; i < n1; i++) //putting first half into a new array
        L[i] = arr[l + i]; 
    for (int j = 0; j < n2; j++) // putting second half into a new array
        R[j] = arr[mid + 1+ j]; 
    int p = 0; 
    int q = 0; 
    int k = l; //k set to first element in the array
    while (p < n1 && q < n2)
    { 
        if (L[p] <= R[q]) //compare left and right array elements
        { 
            arr[k] = L[p]; //if left is smaller
            p++; 
        } 
        else
        { 
            arr[k] = R[q]; //else right is inserted
            q++; 
        } 
        k++; //original array size incremented
    } 
    //for any left over elements
    while (p < n1) 
    { 
        arr[k] = L[p]; 
        p++; 
        k++; 
    } 
    while (q < n2) 
    { 
        arr[k] = R[q]; 
        q++; 
        k++; 
    } 
} 


void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) //do this till l and r are the same element
    { 
        int mid = (l+r)/2; 
        mergeSort(arr, l, mid); 
        mergeSort(arr, mid+1, r); 
        merge(arr, l, mid, r); 
    } 
} 

		

int main()
{
	int size;
	printf("Enter the size of the array: \n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the array elements: \n");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,size-1);
	printf("\nSorted array is :");
	for(int i=0;i<size;i++)
	printf("%d ",arr[i]);
	printf("\n");	

	return 0;
}