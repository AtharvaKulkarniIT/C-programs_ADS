#include <stdio.h>

struct dob
{
    int d;
    int m;
    int y;
};

struct player
{
    char name[25];
    int jno;
    struct dob d1;
};

int main()
{
    struct player p1[3];
    for(int i=0;i<3;i++)
    {
    printf("Enter name,jersey no,dob(day,month,year): \n");
    scanf("%s %d %d %d %d",p1[i].name,&p1[i].jno,&p1[i].d1.d,&p1[i].d1.m,&p1[i].d1.y);
    }
    for(int i=0;i<3;i++)
    {
    printf("Name: %s\nJersey no: %d\nDob:%d/%d/%d\n",p1[i].name,p1[i].jno,p1[i].d1.d,p1[i].d1.m,p1[i].d1.y);
    }
}