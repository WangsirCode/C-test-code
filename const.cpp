#include<iostream>

int main(int argc, char const *argv[])
{
    const int ci = 1;
    //int &a = ci;  error 
    int a = ci;
    // int *a = ci; error
    // int * const a = &ci;   a value of type "const int *" cannot be used to initialize an entity of type "int *const"
     const int *a = &ci;

    return 0;
}
