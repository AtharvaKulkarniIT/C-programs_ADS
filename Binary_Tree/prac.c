 #include <stdio.h>
  #include <stdlib.h>

  struct tnode {
        int data;
        struct tnode *left, *right;
  };

  struct tnode *root = NULL;
  int height=0;

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
                height+=1;
                *node = createNode(data);
        } else if (data < (*node)->data) {
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) {
                insertion(&(*node)->right, data);
        }
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

  /* pre order tree traversal */
  void preOrder(struct tnode *node) {
        if (node) {
                printf("%d  ", node->data);
                preOrder(node->left);
                preOrder(node->right);
        }
        return;
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

  int main() {
        int data, ch;
        while (1) {
                printf("\n1. Insertion\n2. Pre-order\n");
                printf("3. Post-order\n4. In-order\n");
                printf("5. Height\n6.Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter your data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                break;
                        case 2:
                                preOrder(root);
                                break;
                        case 3:
                                postOrder(root);
                                break;
                        case 4:
                                inOrder(root);
                                break;
                        case 5:
                                printf("Height:%d\n", height);
                        case 6:
                                exit(0);
                        default:
                                printf("You have  entered a wrong option\n");
                                break;
                }
        }
        return 0;
  }