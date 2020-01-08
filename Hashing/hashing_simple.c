#include <stdio.h>
#define SIZE 10
int hash(int key)
{
return key%SIZE;
}
int probe(int H[],int key,int index)
{
int i=0;
while(H[(index+i)%SIZE]!=0)
i++;
return (index+i)%SIZE;
}
void Insert(int H[],int key)
{
int index=hash(key);//returns hashed value

if(H[index]!=0)//if the place is already occupied
index=probe(H,key,index);//probe the array linearly to find an empty space
H[index]=key;//insert the key in the hashtable
}
int Search(int H[],int key)
{
int index=hash(key);
int i=0;
while(H[(index+i)%SIZE]!=key)
i++;

return (index+i)%SIZE;
}
int main()
{
int HT[10]={0};
Insert(HT,12);
Insert(HT,25);
Insert(HT,35);
Insert(HT,26);

printf("\nKey found at %d\n",Search(HT,26));
return 0;
}