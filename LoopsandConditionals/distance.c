#include <stdio.h>
int main()
{
    float u,a,t;
    int c;
    do
    {
        printf("enter the initial speed\n");
        scanf("%f",& u);
        printf("enter the acceleration\n");
        scanf("%f",& a);
        printf("enter the time\n");
        scanf("%f",& t);
        float s=(u*t)+(a*t*t)/2;
        printf("the distance travelled is=%f\n",s);
        printf("do you wish to continue?(1/2)\n");
        scanf("%d",& c);
    }while(c==1);
}
