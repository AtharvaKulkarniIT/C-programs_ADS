    #include <stdio.h>
    #include <stdlib.h>
     
    struct node {
       int data;
       struct node *next;
    };
     
    struct node *start = NULL;
    void insert_at_begin(int);
    void insert_at_end(int);
    void traverse();
    void delete_from_begin();
    void delete_from_end();
    int count = 0;
     
    int main () {
       int input, data;
       
       while(1) {
          printf("\n1. Insert an element at beginning of linked list.\n");
          printf("2. Insert an element at end of linked list.\n");
          printf("3. Traverse linked list.\n");
          printf("4. Delete element from beginning.\n");
          printf("5. Delete element from end.\n");
          printf("6. Exit\n");
          printf("Enter your choice:\n");
          scanf("%d", &input);
         
         switch(input)
         {
          case 1:
             printf("Enter value of element\n");
             scanf("%d", &data);
             insert_at_begin(data);
          	 break;
          case 2:
             printf("Enter value of element\n");
             scanf("%d", &data);
             insert_at_end(data);
          	 break;
          case 3:
             traverse();
             break;
          case 4:
             delete_from_begin();  
             break;
          case 5:
             delete_from_end();
             break;
          case 6:
             exit(0);
          default:
             printf("Please enter valid input.\n");      
       }
       
       return 0;
    }
     
    void insert_at_begin(int x) 
    {
       struct node *newnode;
       newnode = (struct node*)malloc(sizeof(struct node));
       count++;
         //If the linked list is empty, check this condition
       if (start == NULL) {
          start = newnode;//start points towards the new node
          start->data = x;//store the data in x which is the new node data in start's data
          start->next = NULL;//set pointer of start to null as it is the only element present
          return;
       }
       
       newnode->data = x;//if linked list is not empty then take the data stored in x and store it in newnode's data
       newnode->next = start;//point the newnode's next to prev start
       start = newnode;//change the start to current newnode
    }
     
    void insert_at_end(int x) 
    {
       struct node *newnode, *temp;
       newnode = (struct node*)malloc(sizeof(struct node));
       count++;
       
       if (start == NULL) {
          start = newnode;
          start->data = x;
          start->next = NULL;
          return;
       }
       temp = start;
       while (temp->next != NULL)
       temp = temp->next;  
       temp->next = newnode;
       newnode->data = x;
       newnode->next = NULL;
    }
     
    void traverse() {
       struct node *newnode;
       
       newnode = start;
       
       if (newnode == NULL) {
          printf("Linked list is empty.\n");
          return;
       }
       
       printf("\nThere are %d elements in linked list.\n", count);
       
       while (newnode->next != NULL) {
          printf("%d\n", newnode->data);
          newnode = newnode->next;
       }
       printf("%d\n", newnode->data);
    }
     
    void delete_from_begin() {
       struct node *newnode;
       int temp;
       
       if (start == NULL) {
          printf("Linked list is already empty.\n");
          return;
       }
       
       temp = start->data;
       newnode = start->next;
       free(start);//used to free allocated memory
       start = newnode;
       count--;
       
       printf("%d deleted from beginning successfully.\n", temp);
    }
     
    void delete_from_end() {
       struct node *newnode, *u;
       int temp;
         
       if (start == NULL) {
          printf("Linked list is already empty.\n");
          return;
       }
       
       count--;
       
       if (start->next == NULL) {
          temp = start->data;
          free(start);
          start = NULL;
          printf("%d deleted from end successfully.\n", temp);
          return;
       }
       
       newnode = start;
       
       while (newnode->next != NULL) {
          u = newnode;
          newnode = newnode->next;
       }
       
       temp = newnode->data;
       u->next = NULL;
       free(newnode);
       
       printf("%d deleted from end successfully.\n", temp);
    }
