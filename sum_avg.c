#include<stdio.h>
float sum(float i,float j,float k,float l,float m);
float avg(float i,float j,float k,float l,float m);
int main()
    {
    float i,j,k,l,m;
    printf("Enter 5 values: \n");
    scanf("%f%f%f%f%f",&i,&j,&k,&l,&m);
    printf("The sum is: %.2f \n",sum(i,j,k,l,m));
    printf("The average is: %.2f \n",avg(i,j,k,l,m));
    }
    float sum(float i,float j,float k,float l,float m)
    {
        float sum1 = i+j+k+l+m;
        return(sum1);
    }
    float avg(float i,float j,float k,float l,float m)
    {
        float avg1 = (i+j+k+l+m)/5;
        return(avg1);
    }

