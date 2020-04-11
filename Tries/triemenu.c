#include<stdio.h>
#include<stdlib.h>

struct trie
{
 struct trie *alpha[26];
 int flag;
};

typedef struct trie trie;
trie * root;
trie * createnode()
{
  trie * node=(trie*) malloc(sizeof(trie));
  int i=0;
  for(i=0;i<26;i++)
  node->alpha[i]=NULL;
  node->flag=0;
  return node;
}

int search_insert_delete(trie *node, char *word, char mode)
{
  if(!node)
 {
   if(mode=='i')
  {
   printf("\nCreated root node.");
   node=createnode();
   root=node;
  }
  else if(mode=='s' || mode=='d')
  {
    printf("\nRoot node does not exist.");
    return 1;
  }
 }
 while(*word)
 {
   int index=(*word|('A'^'a'))-'a';
   if(!node->alpha[index])
   {
     if(mode=='i')
     {
       printf("\nCreating node for character '%c'...",*word);
       node->alpha[index]=createnode();
     }
     else if(mode=='s' || mode=='d')
    {
      printf("\nNo node found for character '%c'.",*word);
      return 1;
    }
   }
   node=node->alpha[index];
   word++;
 }
 if(!node->flag)
 {
   if(mode=='i')
  {
    printf("\nSetting flag...");
    node->flag=1;
    return 0;
  }
  else if(mode=='s' || mode=='d')
  {
    printf("\nFlag not set."); return 1;  }
  }
  else if(mode=='d')
  {
    printf("\nResetting flag...");
    node->flag=0;
    return 0;
  }
  else return 0;
}

int main()
{
 int ch;
 do
 {
  char word[10];
  int result;
  printf("*************************************TRIE MENU******************************************************\n");
  printf("\n\n1. Insert \n2. Search \n3. Delete \n4. Exit \n\nEnter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: 
    printf("\nEnter word to be inserted: ");
    scanf("%s",word);
    result=search_insert_delete(root,word,'i');
    if(!result)
		 printf("\nInserted Successfully!\n");
    break;
    case 2: 
    	printf("\nEnter the word to be searched: ");
        scanf("%s",word);
        result=search_insert_delete(root,word,'s');
        if(result==0)
   			 printf("\nSearch successful!\nThe word is present.\n");
        else
			printf("\nSearch unsuccessful!\nThe word is not present!\n");
        break;
    case 3 :
  	    printf("\nEnter the word to be deleted: ");
        scanf("%s",word);
        result=search_insert_delete(root,word,'d');
        if(result==0)
			 printf("\nDeleted successfully!\n");
        else
			printf("\nSearch unsuccessful!\nThe word is not present!\n");
        break;
    case 4 :
      	break;
    default: 
    	printf("Enter the correct value!\n");
  }
 }while(ch!=4);
}