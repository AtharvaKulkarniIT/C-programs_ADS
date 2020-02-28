#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *l;
	struct Node *r;
	struct Node *p;
	int v;
};
struct Node *root;
void rightRotate(struct Node *P)
{
	struct Node *T=P->l;
	struct Node *B=T->r;
	struct Node *D=P->p;
	if(D)
	{
		if(D->r==P) D->r=T;
		else D->l=T;
	}
	if(B)
		B->p=P;
	T->p=D;
	T->r=P;
	
	P->p=T;
	P->l=B;
}
void leftRotate(struct Node *P)
{
	struct Node *T=P->r;
	struct Node *B=T->l;
	struct Node *D=P->p;
	if(D)
	{
		if(D->r==P) D->r=T;
		else D->l=T;
	}
	if(B)
		B->p=P;
	T->p=D;
	T->l=P;
	
	P->p=T;
	P->r=B;
}

void Splay(struct Node *T)
{
	while(1)
	{
		struct Node *p=T->p;
		if(!p) break;
		struct Node *pp=p->p;
		if(!pp)//Zig
		{
			if(p->l==T)
				rightRotate(p);
			else
				leftRotate(p);
			break;
		}
		if(pp->l==p)
		{
			if(p->l==T)
			{//ZigZig
				rightRotate(pp);
				rightRotate(p);
			}
			else
			{//ZigZag
				leftRotate(p);
				rightRotate(pp);
			}
		}
		else
		{
			if(p->l==T)
			{//ZigZag
				rightRotate(p);
				leftRotate(pp);
			}
			else
			{//ZigZig
				leftRotate(pp);
				leftRotate(p);
			}
		}
	}
	root=T;
}
void Insert(int v)
{
	if(!root)
	{
		root=(struct Node *)malloc(sizeof(struct Node));
		root->l=NULL;
		root->r=NULL;
		root->p=NULL;
		root->v=v;
		return;
	}
	struct Node *P=root;
	while(1)
	{
		if(P->v==v) break; // not multiset
		if(v < (P->v) )
		{
			if(P->l) P=P->l;
			else
			{
				P->l=(struct Node *)malloc(sizeof(struct Node));
				P->l->p=P;
				P->l->r=NULL;
				P->l->l=NULL;
				P->l->v=v;
				P=P->l;
				break;
			}
		}
		else
		{
			if(P->r) P=P->r;
			else
			{
				P->r=(struct Node *)malloc(sizeof(struct Node));
				P->r->p=P;
				P->r->r=NULL;
				P->r->l=NULL;
				P->r->v=v;
				P=P->r;
				break;
			}
		}
	}
	Splay(P);
}
void Inorder(struct Node *R)
{
	if(!R) return;
	Inorder(R->l);
	printf("v: %d ",R->v);
	if(R->l) printf("l: %d ",R->l->v);
	if(R->r) printf("r: %d ",R->r->v);
	puts("");
	Inorder(R->r);
}
struct Node* Find(int v)
{
	if(!root) return NULL;
	struct Node *P=root;
	while(P)
	{
		if(P->v==v)
			break;
		if(v<(P->v))
		{
			if(P->l)
				P=P->l;
			else
				break;
		}
		else
		{
			if(P->r)
				P=P->r;
			else
				break;
		}
	}
	Splay(P);
	if(P->v==v) return P;
	else return NULL;
}
int Delete(int v)
{
	struct Node *N=Find(v);
	if(!N) return 0;
	Splay(N); //check once more;
	struct Node *P=N->l;
	if(!P)
	{
		root=N->r;
		root->p=NULL;
		free(N);
		return 1;
	}
	while(P->r) P=P->r;
	if(N->r)
	{
		P->r=N->r;
		N->r->p=P;
	}
	root=N->l;
	root->p=NULL;
	free(N);
	return 1;
}
int main()
{
int choice,data;

	do
	{
	printf("Enter your choice\n");
	printf("1.Insert 2.Find 3.Delete 4.Display 5.Exit\n");
	scanf("%d",&choice);	
		switch(choice)
		{
		case 1:
		{
		printf("Enter the data\n");
		scanf("%d",&data);
		Insert(data);
		break;
		}
		case 2:
		{
		printf("Enter the data to be searched\n");
		scanf("%d",&data);
		if(!Find(data))
			printf("Couldn't Find %d!\n",data);
		else
			printf("Found %d!\n",data);
				
		break;
		}
		case 3:
		{
		printf("Enter the data to be deleted\n");
		scanf("%d",&data);
		if(Delete(data))
			printf("Deleted.... %d\n",data);
		else
			printf("Couldn't Find.... %d\n",data);
		break;		
		}
		case 4:
		{
		printf("The resulted splay tree is: \n");
		if(root) printf("root: %d\n",root->v);
		Inorder(root);
		break;
		}
		
		}
	}while(choice!=5);
}