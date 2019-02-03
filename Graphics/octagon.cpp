#include <simplecpp>
main_program
{
    turtleSim();
    repeat(8)
    {
        forward(100);
        right(360/8);
    }
    wait(5);
}
