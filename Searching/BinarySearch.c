    #include <stdio.h>
     
    int main()
    {
       int c, first, last, middle, n, search, array[100];
     
       printf("Enter number of elements\n");
       scanf("%d",&n);
     
       printf("Enter %d integers\n", n);
     
       for (c = 0; c < n; c++)
          scanf("%d",&array[c]);
     
       printf("Enter value to find\n");
       scanf("%d", &search);
     
       first = 0;
       last = n - 1;
       middle = (first+last)/2;
     
       while (first <= last)//test condition
        {
          if (array[middle] < search)//search right half of the array
             first = middle + 1;    
          else if (array[middle] == search)// if element is in the middle
          {
             printf("%d found at location %d.\n", search, middle+1);
             break;
          }
          else //search in the left half of the array
             last = middle - 1;
     
          middle = (first + last)/2;
        }
       if (first > last)
          printf("Not found! %d isn't present in the list.\n", search);
     
       return 0;  
    }