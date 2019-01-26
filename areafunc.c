#include<stdio.h>
float circle(float r);
float rectangle(float l,float b);
float square(float s);
float triangle(float ba,float h);
float area;
int main()
{
float r,l,br,s,ba,h;
printf("Enter radius of circle: \n");
scanf("%f",&r);
circle(r);
printf("Enter length and breadth of rectangle: \n");
scanf("%f%f",&l,&br);
rectangle(l,br);
printf("Enter side of square: \n");
scanf("%f",&s);
square(s);
printf("Enter base and heigth of triangle: \n");
scanf("%f%f",&ba,&h);
triangle(ba,h);
}
float circle(float r)
{
area=3.14*r*r;
printf("%f \n",area);
}
float rectangle(float l,float br)
{
area=l*br;
printf("%f \n",area);
}
float square(float s)
{
area=s*s;
printf("%f \n",area);
}
float triangle(float ba,float h)
{
area=0.5*(ba*h);
printf("%f \n",area);
}


