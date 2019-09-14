#include <stdio.h>
int main()
{
    float cp,sp;
    printf("enter the cost price\n");
    scanf("%f",& cp);
    printf("enter the selling price\n");
    scanf("%f",& sp);
    float p=((sp-cp)*100)/cp;
    printf("profit=%f",p);
    printf("%%");
    printf("\n");
}
