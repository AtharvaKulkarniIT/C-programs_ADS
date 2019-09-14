#include <stdio.h>
#include <math.h>
struct complexno
{
double realpart,imaginarypart;
};
struct complexno cmp;
int main()
{
int a,b,c;
double d,root1,root2;
printf("Enter coeff. a,b,c: ");
scanf("%d %d %d",&a,&b,&c);
d=((b*b)-(4*a*c));
if (d > 0)
    {
    // sqrt() function returns square root
        root1 = (-b+sqrt(d))/(2*a);
        root2 = (-b-sqrt(d))/(2*a);

        printf("root1 = %lf and root2 = %lf",root1 , root2);
    }

    //condition for real and equal roots
    else if (d == 0)
    {
        root1 = root2 = -b/(2*a);

        printf("root1 = root2 = %lf;", root1);
    }

    // if roots are not real 
    else
    {
        realpart = -b/(2*a);
        imaginarypart = sqrt(-d)/(2*a);
        printf("root1 = %lf+%lfi and root2 = %lf-%lfi", cmp.realpart, cmp.imaginarypart);
    }

    return 0;
}   

