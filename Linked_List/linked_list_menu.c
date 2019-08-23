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
       
       for (;;) {
          printf("1. Insert an element at beginning of linked list.\n");
          printf("2. Insert an element at end of linked list.\n");
          printf("3. Traverse linked list.\n");
          printf("4. Delete element from beginning.\n");
          printf("5. Delete element from end.\n");
          printf("6. Exit\n");
         
          scanf("%d", &input);
         
          if (input == 1) {
             printf("Enter value of element\n");
             scanf("%d", &data);
             insert_at_begin(data);
          }
          else if (input == 2) {
             printf("Enter value of element\n");
             scanf("%d", &data);
             insert_at_end(data);
          }
          else if (input == 3)
             traverse();
          else if (input == 4)
             delete_from_begin();  
          else if (input == 5)
             delete_from_end();
          else if (input == 6)
             break;
          else
             printf("Please enter valid input.\n");      
       }
       
       return 0;
    }
     
    void insert_at_begin(int x) {
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
     
    void insert_at_end(int x) {
       struct node *newnode, *temp;
       
       newnode = (struct node*)malloc(sizeof(struct node));
       count++;
       
       if (start == NULL) {
          start = newnode;
          start->data = newnode;
          start->next = NULL;
          return;
       }
       
       temp = start;
       
       while (temp->next != NULL)
          temp = temp->next;  
       
       temp->next = newnode;
       newnode->data    = x;
       newnode->next    = NULL;
    }
     
    void traverse() {
       struct node *newnode;
       
       newnode = start;
       
       if (newnode == NULL) {
          printf("Linked list is empty.\n");
          return;
       }
       
       printf("There are %d elements in linked list.\n", count);
       
       while (newnode->next != NULL) {
          printf("%d\n", newnode->data);
          newnode = newnode->next;
       }
       printf("%d\n", newnode->data);
    }
     
    void delete_from_begin() {
       struct node *newnode;
       int n;
       
       if (start == NULL) {
          printf("Linked list is already empty.\n");
          return;
       }
       
       n = start->data;
       newnode = start->next;
       free(start);
       start = newnode;
       count--;
       
       printf("%d deleted from beginning successfully.\n", n);
    }
     
    void delete_from_end() {
       struct node *newnode, *u;
       int n;
         
       if (start == NULL) {
          printf("Linked list is already empty.\n");
          return;
       }
       
       count--;
       
       if (start->next == NULL) {
          n = start->data;
          free(start);
          start = NULL;
          printf("%d deleted from end successfully.\n", n);
          return;
       }
       
       newnode = start;
       
       while (newnode->next != NULL) {
          u = newnode;
          newnode = newnode->next;
       }
       
       n = newnode->data;
       u->next = NULL;
       free(t);
       
       printf("%d deleted from end successfully.\n", n);
    }
