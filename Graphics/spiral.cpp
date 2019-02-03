#include <simplecpp>
main_program
{
    turtleSim();
    left(90);
    double a[7]={6,4,3,2.5,2,1.7,1.5};
    for(int i=2;i<9;i++)
    {
        for(int j=0;j<15*i;j++)
        {
            forward(1);
            left(a[i-2]);
        }
    }
    wait(5);
}

