
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct rbtree
{
    int data;
    struct rbtree *left,*right,*parent;
    int color;  //RED-0   BLACK-1
};
typedef struct rbtree node;
node* accept(int data)//setting defaults for every new node
{
    node *n;
    n=(struct node*)malloc(sizeof(node)); // creating a new node
    n->data=data; // value to be stored in the new node
    n->color=0; // setting color of new node as red
    n->left=n->right=NULL;
    n->parent=NULL;
    return(n);
}
node *root=NULL;

void leftRotate(node *x)
{
    node *y;
    y = x->right;
    x->right = y->left;
    if(y->left!=NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL)
    {
        root = y;
    }
    else if( (x->parent->left != NULL) && (x->data == x->parent->left->data))
    {
        x->parent->left = y;
    }
    else x->parent->right = y;
    y->left = x;
    x->parent = y;

    return;
}

void rightRotate(node *y)
{
    node *x;
    x = y->left;
    y->left=x->right;
    if(x->right!=NULL)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if(y->parent==NULL)
    {
        root = x;
    }
    else if((y->parent->left!=NULL)&& (y->data==y->parent->left->data))
    {
        y->parent->left = x;
    }
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
    return;
}
void color(node *p)
{
    node *y=NULL;
    while ((p->parent != NULL) && (p->parent->color == 0))
    {
        if((p->parent->parent->left != NULL) && (p->parent->data == p->parent->parent->left->data))
        {
            if(p->parent->parent->right!=NULL)
            {
                y = p->parent->parent->right;
            }
            if ((y!=NULL) && (y->color ==0))
            {
                p->parent->color =1;
                y->color =1;
                p->parent->parent->color =0;
                if(p->parent->parent!=NULL)
                p = p->parent->parent;
            }
            else
            {
                if ((p->parent->right != NULL) && (p->data == p->parent->right->data))
                {
                    p = p->parent;                                  //LR
                    leftRotate(p);
                }
                p->parent->color =1;
                p->parent->parent->color =0;
                rightRotate(p->parent->parent);
            }
        }
        else
        {
            if(p->parent->parent->left!=NULL)
            {
            y = p->parent->parent->left;
            }
            if ((y!=NULL) && (y->color ==0))
            {
                p->parent->color =1;
                y->color =1;
                p->parent->parent->color =0;
                if(p->parent->parent!=NULL)
                p= p->parent->parent;
            }
            else
            {
                if ((p->parent->left != NULL) && (p->data == p->parent->left->data))
                {
                    p = p->parent;
                    rightRotate(p);
                }
                p->parent->color =1;
                p->parent->parent->color =0;
                leftRotate(p->parent->parent);
            }
        }
    }
    root->color =1;
}

void insert(int data)
{
    node *p,*q,*r;
    p=accept(data); // this function sets up a new node
    q=root;
    if(root==NULL) 
    {
        root=p; // setting the newnode as root if it doesnt exist
        root->color=1; // setting the root's color as black
    }
    else
    {
        while(q!=NULL) //finding suitable position to enter the new node
        {
            r=q; //keeps track of new node's parent
            if(p->data < q->data) 
            {
                q = q->left; 
            }
            else
            {
                q = q->right;
            }

        }
        p->parent=r; // assigning new node's parent
        if(r==NULL) // if root doesnt exist
        {
            root=p;
        }
        else if(p->data < r->data)
        {
            r->left = p;
        }
        else
            r->right = p;
    }
    color(p); //recoloring

}


void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        if(T->color==0)
        {
            printf("(%d---RED)  ",T->data);
        }
        else
        {
            printf("(%d--BLACK)  ",T->data);
        }
        inorder(T->right);
    }
}
void main()
{
    int c,val,n,i;
    node *p;
    while(1)
    {
        printf("\n1.create\n2.insert\n3.display\n4.exit\nEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:

                printf("Enter the no of nodes you want to insert in RB tree :");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("Enter the data ");
                    scanf("%d",&val);
                    insert(val);
                }
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d",&val);
                insert(val);
                break;
            case 3:
                printf("Root is: %d---BLACK\n",root->data);
                inorder(root);
                break;
            case 4:
                exit(1);
                break;
            default: printf("Invalid choice !");

        }
    }
}
