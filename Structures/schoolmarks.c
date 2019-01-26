#include <stdio.h>
struct school
{
    int roll_no;
    char name[15];
    float marks[3];
};
void disp();
struct school student[25];
int main()
{
    printf("\t\tSTUDENT DETAILS\n\n");
    for(int i=0;i<2;i++)
    {
        printf("enter the student name\n");
        scanf("%s",student[i].name);
        printf("enter the student roll_no\n");
        scanf("%d",& student[i].roll_no);
        printf("enter the student marks in three subjects\n");
        for(int j=0;j<3;j++)
        {
            scanf("%f",& student[i].marks[j]);
        }
    }
    disp();
}
void disp()
{
int count=0;
    printf("students who failed in more than one subject:\n");
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(student[i].marks[j]<40.0)
            {
                count++;
            }
        }
     if(count==2)
    {
    printf("%s\n",student[i].name);
    count=0;
    }   
    }
}

