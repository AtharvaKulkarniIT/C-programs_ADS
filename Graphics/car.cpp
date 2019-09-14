#include <simplecpp>
main_program
{
    int j=1;
    initCanvas("car",1440,900);
    Rectangle r1(70,50,100,50);
    Circle c1(45,85,10),c2(95,85,10);
    for(int i=1;i<=70;i++)
    {
        r1.moveTo(70+j,50);
        c1.moveTo(45+j,85);
        c2.moveTo(95+j,85);
        j=j+5;
    }
    wait(5);
}
