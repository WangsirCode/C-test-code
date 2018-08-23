#include <iostream>
using namespace std;
class Data
{
    char c;
    int a;
};

struct A
{
    char a;　　　//内存位置:  [0]
    double b;　  // 内存位置: [8]...[15]
    char d;
    int c;　　　　// 内存位置: [16]...[19]　　----　　规则1
};

struct B
{
    int a;　　　　// 内存位置: [0]...[3]
    A b;　    　　// 内存位置: [8]...[31]　　----　　规则2
    char c;　　　// 内存位置: [32]
};

int main()
{
    cout << sizeof(Data) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
}
