#include <stdio.h>
struct complex
{
    int real, img;
};struct complex a, b, add,sub,mul;

int main()
{
    printf("Enter a and b where a + ib is the first complex number.\n");
    scanf("%d%d", &a.real, &a.img);
    printf("Enter c and d where c + id is the second complex number.\n");
    scanf("%d%d", &b.real, &b.img);
    add.real = a.real + b.real;
    add.img = a.img + b.img;
    printf("Sum of the complex numbers: (%d) + (%di)\n",add.real, add.img);
    sub.real = a.real - b.real;
    sub.img = a.img - b.img;
    printf("Difference of the complex numbers: (%d) + (%di)\n", sub.real, sub.img);
    mul.real = (a.real*b.real)+(a.img*b.img*(-1));
    mul.img = (a.real*b.img)+(a.img*b.real);
    printf("product of the complex numbers: (%d) + (%di)\n", mul.real, mul.img);
}
