//
//  interest.c
//  
//
//  Created by ANGELO MATHAI on 18/10/18.
//

#include <stdio.h>
int main()
{
    int p,t;float r;
    printf("enter the pricipal amount\n");
    scanf("%d",& p);
    printf("enter the rate of interest\n");
    scanf("%f",& r);
    printf("enter the time\n");
    scanf("%d",& t);
    float i=(p*r*t)/100;
    float amt=p+i;
    printf("interest=%f\n",i);
    printf("amount=%f\n",amt);
}
