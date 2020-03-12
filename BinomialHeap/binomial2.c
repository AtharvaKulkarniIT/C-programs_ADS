#include<stdio.h>
#include<malloc.h>
 
struct node {
    int n;
    int degree;
    struct node* parent;
    struct node* child;
    struct node* sibling;
};

 
struct node* MAKE_bin_HEAP();
int bin_LINK(struct node*, struct node*);
struct node* create_node(int);
struct node* bin_HEAP_UNION(struct node*, struct node*);
struct node* bin_HEAP_INSERT(struct node*, struct node*);
struct node* bin_HEAP_MERGE(struct node*, struct node*);
int REVERT_LIST(struct node*);
int display(struct node*);
struct node* FIND_NODE(struct node*, int);
int count = 1;
 
struct node* MAKE_bin_HEAP() {
    struct node* np;
    np = NULL;
    return np;
}

struct node * H = NULL;
struct node *Hr = NULL;

int bin_LINK(struct node* y, struct node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

struct node* create_node(int k) {
    struct node* p;//new node;
    p = (struct node*) malloc(sizeof(struct node));
    p->n = k;
    return p;
}

struct node* bin_HEAP_UNION(struct node* H1, struct node* H2) {
    struct node* prev_x;
    struct node* next_x;
    struct node* x;
    struct node* H = MAKE_bin_HEAP();
    H = bin_HEAP_MERGE(H1, H2);
    if (H == NULL)
        return H;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL) {
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL)
                && (next_x->sibling)->degree == x->degree)) 
        {
            prev_x = x;
            x = next_x;
        }
         else
          {
            if (x->n <= next_x->n) {
               x->sibling = next_x->sibling;
                bin_LINK(next_x, x);
            }
             else
              {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                bin_LINK(x, next_x);
                x = next_x;
            }
        }
        next_x = x->sibling;
    }
    return H;
}

struct node* bin_HEAP_INSERT(struct node* H, struct node* x) 
{
    struct node* H1 = MAKE_bin_HEAP();
    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = bin_HEAP_UNION(H, H1);
    return H;
}

struct node* bin_HEAP_MERGE(struct node* H1, struct node* H2) 
{
    struct node* H = MAKE_bin_HEAP();
    struct node* y;
    struct node* z;
    struct node* a;
    struct node* b;
    y = H1;
    z = H2;
    if (y != NULL)
    {

        if (z != NULL && y->degree <= z->degree)
            H = y;
        else if (z != NULL && y->degree > z->degree)
            /* need some modifications here;the first and the else conditions can be merged together!!!! */
            H = z;
        else
            H = y;
    } 
    else
        H = z;
    while (y != NULL && z != NULL) 
    {
        if (y->degree < z->degree) 
        {
            y = y->sibling;
        } 
        else if (y->degree == z->degree) 
        {
            a = y->sibling;
            y->sibling = z;
            y = a;
        } 
        else 
        {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
    }
    return H;
}

int display(struct node* H) {
    struct node* p;
    if (H == NULL) 
    {
        printf("\nHeap Empty!");
        return 0;
    }
    printf("\nThe root nodes are:-\n");
    p = H;
    while (p != NULL) 
    {
        printf("%d", p->n);
        if (p->sibling != NULL)
            printf("-->");
        p = p->sibling;
    }
    printf("\n");
}


int REVERT_LIST(struct node* y) 
{
    if (y->sibling != NULL) 
    {
        REVERT_LIST(y->sibling);
        (y->sibling)->sibling = y;
    } 
    else 
    {
        Hr = y;
    }
}

struct node* FIND_NODE(struct node* H, int k) 
{
    struct node* x = H;
    struct node* p = NULL;
    if (x->n == k) 
    {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL) 
    {
        p = FIND_NODE(x->child, k);
    }
    if (x->sibling != NULL && p == NULL) 
    {
        p = FIND_NODE(x->sibling, k);
    }
    return p;
}

int main() 
{
    int i, n, m, key;
    struct node* p;
    struct node* np;
    char ch;
    printf("\nEnter no of elements:");
    scanf("%d", &n);
    printf("\nEnter the elements:\n");
    for (i = 1; i <= n; i++) 
    {
        scanf("%d", &m);
        np = create_node(m);
        H = bin_HEAP_INSERT(H, np);
    }
    display(H);
    do 
    {
        printf("\n*******************************BINOMIAL HEAP***********************:-\n");
        printf("\n1)Insert\n2)display\n3)Exit\n");
        scanf("%d", &key);
        switch (key) 
        {
        case 1:
                printf("\nEnter element to be inserted:");
                scanf("%d", &m);
                p = create_node(m);
                H = bin_HEAP_INSERT(H, p);
                printf("\nNow heap is:\n");
                display(H);
                fflush(stdin);
                scanf("%c", &ch);
            break;
            case 2:
                display(H);
            break;
        case 3:
            printf("\nYou chose to quit!\n");
            break;
        default:
            printf("\nInvalid Entry...Try Again!....\n");
        }
    } while (key != 3);
}