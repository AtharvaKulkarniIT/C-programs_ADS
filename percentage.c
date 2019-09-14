#include<stdio.h>
float avg(int eng,int math,int comp);
int main()
{
int eng,math,comp;
printf("Enter your english, maths and computer marks: \n");
scanf("%d%d%d",&eng,&math,&comp);
printf("Your average marks are: %.2f \n",avg(eng,math,comp));
printf("Your percentage is: %.2f%% \n",avg(eng,math,comp));
}
float avg(int eng,int math,int comp)
{
float avg2 = (eng+math+comp)/3;
return(avg2);
}

