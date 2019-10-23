#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
    
}*head=NULL;

void push(char input)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    if(head==NULL)
    {
        temp->data=input;
        temp->next=NULL;
        head=temp;
    //    printf("#%c\n",head->data);
    }
    else
    {
        temp->data = input;
        temp->next = head;
        head = temp;
    //    printf("#%c\n",head->data);
    }
}

char pop()
{
    char ch;
    if(head==NULL)
    {
        printf("\nStack is Empty!!\n");
        exit(0);
    }
    else
    {
        ch=head->data;
        head=head->next;
        return ch;
    }
}

int isOperator(char ch)
{
    if(ch=='+' ||  ch=='-' || ch=='*' || ch=='/' || ch=='^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return 0;
        
}

void Infix_to_Postfix(char infix[],char postfix[])
{
    push('(');
    strcat(infix,")");
    char x,item;
    int i=0,j=0;
    item=infix[0];
    while(item!='\0')
    {
        /*printf("Infix:%c",infix[j]);
        printf("%c\n",item); */
        if(item=='(')
            push(item);
        else if(isalnum(item))
        {
         //   printf("@,");
            postfix[j]=item;
            j++;
        }
        else if(isOperator(item)==1)
        {
      //      printf("@@%c,",head->data);
        //    x=pop();
            while(precedence(item)<=precedence(head->data))
            {
                postfix[j]=head->data;
                j++;
                pop();
            }
           // push(item);
   //         printf("\n%s",postfix);
            push(item);
        }
        
        else if(item==')')
        {
            //x=pop();
            while(head->data!='(')
            {
                postfix[j]=head->data;
                j++;
            //    printf("%c",x);
                
                pop();
            }
        }
        i++;
        item=infix[i];
    //    printf("%s\n",postfix);
        
    }
    pop();
    
    postfix[++j]='\0';
    int l=0;
  /*  for (int k=0;postfix[k]!='\0';k++)
        l++;
    printf("%c",postfix[l]);*/
    // if(head!=NULL)
    // {
    //     printf("Invalid Expression!!");
    // }
    
}


void Infix_to_Prefix(char infix[],char postfix[])
{
    char rev_Infix[50],prefix[50];
    int len=strlen(infix),j=0;
   // printf("%d",len);
    for(int i=len-1;i>=0;i--)
    {
        rev_Infix[j]=infix[i];j++;
    }
 //   printf("%s",rev_Infix);
    j=0;
    Infix_to_Postfix(rev_Infix,postfix);
    for(int i=strlen(postfix)-1;i>=0;i--)
    {
        prefix[j]=postfix[i];
        j++;
    }
    printf("Prefix Expression:%s",prefix);
    
}


int main()
{
    char postfix[50],infix[50];int choice=1;
    while(choice!=4)
    {
        printf("\n****Expression Conversion****\n1.Enter Expression\n2.Infix to Postfix\n3.Infix to Prefix\n4.Exit\nEnter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the Expression:");
                scanf("%s",infix);
                break;
            case 2:
                Infix_to_Postfix(infix,postfix);
                printf("Postfix Expression:%s",postfix);
                break;
            case 3:
                Infix_to_Prefix(infix,postfix);
                break;
            case 4:
                choice=4;
                break;
            default: 
                printf("Wrong Choice!!");
        }
        
    }
//    Infix_to_Postfix(infix,postfix);
    
    
    return 0;
}