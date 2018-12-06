#include<iostream>
using namespace std;
class A
{
  int value;
public:
  A(int n = 0) : value(n) {}
  int GetValue()
  {
    return value;
  }
  void PrintMessage()
  {
      cout<< value << endl;
  }
};

int main(int argc, char const *argv[])
{
    A a;
    a.PrintMessage();
    *((int *)&a) = 5;
    a.PrintMessage();
    return 0;
}


// C++ 的访问控制是在编译时实现的，在运行时仍然可以通过访问内存访问私有变量