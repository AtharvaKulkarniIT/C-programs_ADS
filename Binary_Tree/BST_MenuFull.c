#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* new_node(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
};

struct node* insert( struct node *root, int data){

    if(root == NULL)
        return new_node(data);

    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }

    return root;
}

void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);

}

 void iterativeInorder(struct node *root)
 {
   struct node *save[100];
   int top = 0;

   while(root != NULL)
   {
       while (root != NULL)
       {
            if (root->right != NULL)
            {
              save[top++] = root->right;
            }
            save[top++] = root;
            root = root->left;
       }

       root = save[--top];
       while(top != 0 && root->right == NULL)
       {
           printf("%d ", root->data);
           root = save[--top];
       }

       printf("%d ", root->data);
       root = (top != 0) ? save[--top] : (struct node *) NULL;
   }
 }


 void iterativePreorder(struct node *root)
 {
   struct node *save[100];
   int top = 0;

   if (root == NULL)
   {
     return;
   }

   save[top++] = root;
   while (top != 0)
   {
     root = save[--top];

     printf("[%d] ", root->data);

     if (root->right != NULL)
       save[top++] = root->right;
     if (root->left != NULL)
       save[top++] = root->left;
   }
 }


void iterativePostorder(struct node *root)
 {
   struct
   {
     struct node *node;
     unsigned vleft :1;   // Visited left?
     unsigned vright :1;  // Visited right?
   }save[100];

   int top = 0;

   save[top++].node = root;

   while ( top != 0 )
   {
       /* Move to the left subtree if present and not visited */
       if(root->left != NULL && !save[top].vleft)
       {
           save[top].vleft = 1;
           save[top++].node = root;
           root = root->left;
           continue;
       }

       /* Move to the right subtree if present and not visited */
       if(root->right != NULL && !save[top].vright )
       {
           save[top].vright = 1;
           save[top++].node = root;
           root = root->right;
           continue;
       }

       printf("%d ", root->data);

       /* Clean up the stack */
       save[top].vleft = 0;
       save[top].vright = 0;

       /* Move up */
       root = save[--top].node;
    }
 }


struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = height(node->left);
        int rDepth = height(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

int main()
{
    int choice, choice2, ele;
    struct node* root = NULL;
    while(1){
        printf("\nENTER YOUR CHOICE:\n1. Insert Element\n2. Traversal using recursion\n3. Traversal without using recursion\n4. Display height of tree\n5. Delete Node\n6. EXIT\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter element to insert:");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;

            case 2:
                 printf("\n\tENTER YOUR CHOICE:\n\t1. Display Inorder Traversal\n\t2. Display Preorder Traversal\n\t3. Display Postorder Traversal\n");
                 scanf("\t%d", &choice2);
                 switch(choice2){
                        case 1:
                            printf("\tInorder Traversal: ");
                            inorder(root);
                            break;

                        case 2:
                            printf("\tPreorder Traversal: ");
                            preorder(root);
                            break;

                        case 3:
                            printf("\tPostorder Traversal: ");
                            postorder(root);
                            break;
                        default:
                            printf("\nWRONG CHOICE ENTERED\n");
                 }

                 break;

            case 3:
                 printf("\n\tENTER YOUR CHOICE:\n\t1. Display Inorder Traversal\n\t2. Display Preorder Traversal\n\t3. Display Postorder Traversal\n");
                 scanf("%d", &choice2);
                 switch(choice2){
                        case 1:
                            printf("Inorder Traversal: ");
                            iterativeInorder(root);
                            break;

                        case 2:
                            printf("Preorder Traversal: ");
                            iterativePreorder(root);
                            break;

                        case 3:
                            printf("Postorder Traversal: ");
                            iterativePostorder(root);
                            break;
                        default:
                            printf("\nWRONG CHOICE ENTERED\n");
                 }

                 break;

            case 4:
                 ele = height(root);
                 printf("\n\nHeight of tree is: %d\n", ele);

            case 5:
                printf("\nEnter node to delete: ");
                scanf("%d", &ele);
                root = deleteNode(root, ele);
                break;

            case 6:
                return 0;

            default:
                printf("\nWRONG CHOICE ENTERED\n");
        }

    }
    return 0;
}