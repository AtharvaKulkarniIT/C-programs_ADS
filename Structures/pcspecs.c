#include <stdio.h>
struct pc_specs
{
    int r,s;
    char bn[20];
    char p[20];
    char m[20];
    char os[20];
};struct pc_specs config;
int main()
{
    printf("enter the brand name\n");
    scanf("%s",config.bn);
    printf("enter the model name\n");
    scanf("%s",config.m);
    printf("enter the processor type\n");
    scanf("%s",config.p);
    printf("enter the ram\n");
    scanf("%d",& config.r);
    printf("enter the internal storage\n");
    scanf("%d",& config.s);
    printf("enter the name of the operating system\n");
    scanf("%s",config.os);
    printf("BRAND - %s\n",config.bn);
    printf("MODEL NAME - %s\n",config.m);
    printf("PROCESSOR - %s\n",config.p);
    printf("RAM - %d GB\n",config.r);
    printf("STORAGE - %d GB\n",config.s);
    printf("OPERATING SYSTEM - %s\n",config.os);
}

