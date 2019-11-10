 #include <stdio.h>
  #include <stdlib.h>

  struct tnode
   {
        int data;
        struct tnode *left, *right;
  };

  struct tnode *root = NULL;

  /* creating node of the tree  and fill the given data */
  struct tnode * createNode(int data) {
        struct tnode *newNode;
        newNode  = (struct tnode *) malloc(sizeof(struct tnode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return (newNode);
  }

  /* inserting a new node into the tree */
  void insertion(struct tnode **node, int data) {
        if (!*node) {
                *node = createNode(data);
        } else if (data < (*node)->data) {
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) {
                insertion(&(*node)->right, data);
        }
  }

  /* inorder tree traversal */
  void inOrder(struct tnode *node) {
        if (node) {
                inOrder(node->left);
                printf("%d  ", node->data);
                inOrder(node->right);
        }
        return;
  }
  /* pre order tree traversal */
  void preOrder(struct tnode *node) {
        if (node) {
                printf("%d  ", node->data);
                preOrder(node->left);
                preOrder(node->right);
        }
        return;
  }
  /* post order tree traversal */
  void postOrder(struct tnode *node) {
        if (node) {
                postOrder(node->left);
                postOrder(node->right);
                printf("%d  ", node->data);
        }
        return;
  }



int height(struct tnode *node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = height(node->left); 
       int rDepth = height(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  

  int main() {
        int data, ch,h;
        while (1) {
                printf("*****************Binary Search Tree*************************\n");
                printf("\n1. Insertion\n2. Traversal(using recursion)\n");
                printf("3. Traversal(without recursion)\n");
                printf("4.Height\n5.Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter your data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                break;
                        case 2:
                                printf("Inorder: ");
                                inOrder(root);
                                printf("\n");
                                printf("Preorder: ");
                                preOrder(root);
                                printf("\n");
                                printf("Postorder: ");
                                postOrder(root);
                                printf("\n");
                                break;
                        case 3:
                                break;
                        case 4:
                                h= height(root);
                                printf("Height is: %d\n",h );
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("You have  entered a wrong option\n");
                                break;
                }
        }
        return 0;
  }