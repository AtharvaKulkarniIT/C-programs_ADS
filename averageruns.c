#include <stdio.h>
#include <string.h>
struct stats 
{
char name[25];
int age,matches;
float average;
};
struct stats player[3];
int i,j,temp3,temp4;
float temp1;
char temp2[25];
int main()
{
for(i=0;i<3;i++)
{
printf("Enter player's name,age,matches,average:\n");
scanf("%s %d %d %f",player[i].name,&player[i].age,&player[i].matches,&player[i].average);
}
for(i=0;i<3;i++)
{
for(j=0;j<(3-i-1);j++)
{
if(player[j].average>player[j+1].average)
{
temp1=player[j].average;
player[j].average = player[j+1].average;
player[j+1].average = temp1;
strcpy(temp2,player[j].name);
strcpy(player[j].name,player[j+1].name);
strcpy(player[j+1].name,temp2);
temp3=player[j].age;
player[j].age = player[j+1].age;
player[j+1].age = temp3;
temp4=player[j].matches;
player[j].matches = player[j+1].matches;
player[j+1].matches = temp4;
}
}
}
printf("After arranging in ascending order acc to average:\n");
for(i=0;i<3;i++)
{
printf("%s %d %d %f \n",player[i].name,player[i].age,player[i].matches,player[i].average);
}
}

