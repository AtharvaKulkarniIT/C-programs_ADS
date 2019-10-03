#include <stdio.h>


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
    if (l < r) //test condition to end recursion
    { 
        int mid = (l+r)/2; 
        mergeSort(arr, l, mid); //split the left half of the array recursively
        mergeSort(arr, mid+1, r); //split the right half of the array recursively
        merge(arr, l, mid, r); //merge the left and right half in sorted order
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
        printf("\n1. Merge Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
            mergeSort(arr,0,size-1);
            printf("Array Sorted!\n");
            break;
            case 2:
            insertionSort(arr,size);
            printf("Array Sorted!\n");
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