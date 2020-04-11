#include<stdio.h>
#include<malloc.h>
 
struct node {
    int n;
    int degree;
    struct node* parent;
    struct node* child;
    struct node* sibling;
};

 
struct node* create_heap();
int link(struct node*, struct node*);
struct node* create_node(int);
struct node* bin_union(struct node*, struct node*);
struct node* insert(struct node*, struct node*);
struct node* merge(struct node*, struct node*);
struct node* extract_min(struct node*);
int revert_list(struct node*);
int display(struct node*);
struct node* find(struct node*, int);
int decrease_key(struct node*, int, int);
int delete(struct node*, int);

int count = 1;
 
struct node* create_heap() {
    struct node* np;
    np = NULL;
    return np;
}

struct node * H = NULL;
struct node *Hr = NULL;

int link(struct node* y, struct node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

struct node* create_node(int k) {
    struct node* p;
    p = (struct node*) malloc(sizeof(struct node));
    p->n = k;
    return p;
}

struct node* bin_union(struct node* H1, struct node* H2) {
    struct node* prev_x;
    struct node* next_x;
    struct node* x;
    struct node* H = create_heap();
    H = merge(H1, H2);
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
                link(next_x, x);
            }
             else
              {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                link(x, next_x);
                x = next_x;
            }
        }
        next_x = x->sibling;
    }
    return H;
}

struct node* insert(struct node* H, struct node* x) 
{
    struct node* H1 = create_heap();
    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = bin_union(H, H1);
    return H;
}

struct node* merge(struct node* H1, struct node* H2) 
{
    struct node* H = create_heap();
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

struct node* extract_min(struct node* H1) 
{
    int min;
    struct node* t = NULL;
    struct node* x = H1;
    struct node *Hr;
    struct node* p;
    Hr = NULL;
    if (x == NULL) 
    {
        printf("\nNothing to extract");
        return x;
    }
    
    p = x;
    while (p->sibling != NULL) 
    {
        if ((p->sibling)->n < min) 
        {
            min = (p->sibling)->n;
            t = p;
            x = p->sibling;
        }
        p = p->sibling;
    }
    if (t == NULL && x->sibling == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->sibling;
    else if (t->sibling == NULL)
        t = NULL;
    else
        t->sibling = x->sibling;
    if (x->child != NULL) 
    {
        revert_list(x->child);
        (x->child)->sibling = NULL;
    }
    H = bin_union(H1, Hr);
    return x;
}

int revert_list(struct node* y) 
{
    if (y->sibling != NULL) 
    {
        revert_list(y->sibling);
        (y->sibling)->sibling = y;
    } 
    else 
    {
        Hr = y;
    }
}

struct node* find(struct node* H, int k) 
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
        p = find(x->child, k);
    }
    if (x->sibling != NULL && p == NULL) 
    {
        p = find(x->sibling, k);
    }
    return p;
}

int decrease_key(struct node* H, int i, int k) 
{
    int temp;
    struct node* p;
    struct node* y;
    struct node* z;
    p = find(H, i);
    if (p == NULL) 
    {
        printf("\nInvalid Choice of key to be reduced");
        return 0;
    }
    if (k > p->n) 
    {
        printf("\nThe new key entered is greater than the current one!");
        return 0;
    }
    p->n = k;
    y = p;
    z = p->parent;
    while (z != NULL && y->n < z->n) 
    {
        temp = y->n;
        y->n = z->n;
        z->n = temp;
        y = z;
        z = z->parent;
    }
}

int delete(struct node* H, int k) 
{
    struct node* np;
    if (H == NULL) 
    {
        printf("\nHeap Empty!");
        return 0;
    }
    decrease_key(H, k, -1000);
    np = extract_min(H);
    if (np != NULL)
        printf("\nNode deleted successfully");
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
        H = insert(H, np);
    }
    display(H);
    do 
    {
        printf("\n*******************************BINOMIAL HEAP***********************:-\n");
        printf("Insert\n2)Delete\n3)Display\n4)Exit\n");
        scanf("%d", &key);
        switch (key) 
        {
        case 1:
                printf("\nEnter element inserted:");
                scanf("%d", &m);
                p = create_node(m);
                H = insert(H, p);
                printf("\nNow heap is:\n");
                display(H);
                fflush(stdin);
                scanf("%c", &ch);
            break;
        case 2:
                printf("\nEnter key to be deleted: ");
                scanf("%d", &m);
                delete(H, m);
                fflush(stdin);
                scanf("%c", &ch);
            break;
            case 3:
                display(H);
            break;
        case 4:
            printf("\nYou chose to quit!\n");
            break;
        default:
            printf("\nInvalid Entry...Try Again!....\n");
        }
    } while (key != 4);
}