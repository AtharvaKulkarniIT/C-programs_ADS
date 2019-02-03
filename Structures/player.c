#include <stdio.h>
#include <string.h>
struct PLAYER
{
char name[25];
int age,matches;
float average;
};
struct PLAYER info;
int i,j;
int main()
{
printf("Enter player's name,age,matches,average:\n");
scanf("%s %d %d %f",info.name,&info.age,&info.matches,&info.average);
printf("NAME-%s\nAGE-%d\nMATCHES-%d\nAVERAGE-%f\n",info.name,info.age,info.matches,info.average);
}
