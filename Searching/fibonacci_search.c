#include <stdio.h> 
  
int min(int x, int y) 
{
 return (x<=y)? x : y; 
} 
  
int fibonacciSearch(int arr[], int x, int n) 
{ 
    int fib2 = 0;    
    int fib1 = 1;    
    int fib = fib2 + fib1;   
  
    
    while (fib < n) 
    { 
        fib2 = fib1; 
        fib1 = fib; 
        fib  = fib2 + fib1; 
    } 
  
    int offset = -1; 
  
    while (fib > 1) 
    { 
        int i = min(offset+fib2, n-1); 
        if (arr[i] < x) 
        { 
            fib = fib1; 
            fib1 = fib2; 
            fib2 = fib - fib1; 
            offset = i; 
        } 
        else if (arr[i] > x) 
        { 
            fib  = fib2; 
            fib1 = fib1 - fib2; 
            fib2 = fib - fib1; 
        } 
        else return i; 
    } 
    if(fib1 && arr[offset+1]==x)return offset+1; 
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = {10, 12, 18, 20, 55, 50, 67, 82, 9, 84, 70}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int x = 50; 
    printf("Found at index: %d", fibonacciSearch(arr, x, size)); 
    return 0; 
} 