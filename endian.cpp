#include<stdio.h>
int checkCPUendian()
{
    union
    {
    unsigned int a;
    unsigned char b;
    }c;
    c.a = 1;
    return (c.b == 1);
}

int main()
{
    printf("%d\n",checkCPUendian());
}