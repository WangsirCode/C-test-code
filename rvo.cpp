#include <iostream>
using namespace std;
class A
{
    public:
        int a;
        A()
        {
            cout << "A() " <<endl;
        }
        A(int i):a(i)
        {
            cout << "A() :" << a << endl;
        }
        ~A()
        {
            cout << "~A()" << a << endl;
        }
        A(const A& x):a(x.a)
        {
            cout << "copy A()" << a << endl;
        }
        A(const A&& x):a(x.a)
        {
            cout << "move A()" << a << endl;
        }
        A& operator=(const A& rhs){
            cout << "operator= A()" << a << endl;
            this->a = rhs.a;
            return *this;
        }
         A& operator=(A&& rhs) {
            cout << "operator= A() move" << endl;
            this->a = rhs.a;
            return *this;
        }
};
A test1()
{
    return A(1);   
}
A test2()
{
    A tmp(2);
    return tmp;
}

A test3(bool condition)
{
    A tmp1(3), tmp2(4);
    if (condition) {
        return tmp1;
    }
    else
    {
        return tmp2;
    }
}

int main()
{
    cout << "test1" << endl;
    A a ;
    a = test1();

    cout << endl;
    cout << "test2" << endl;
    A b = test2();
    
    cout << endl;
    cout << "test3" << endl;
    A c;
    c = test3(1);
    A d = test3(0);
    return 0;
}
// 1. 对于非RVO， 对象会有两次拷贝，一次从被调用函数拷贝到临时区， 一次从临时区拷贝到调用函数
// 2. 对于RVO，有两种情况， 1. A a = test(), 这种情况test里面直接操作a 的地址 2. A a; a = test(); 这种情况test 里面直接操作临时区的地址
// 3. 如果函数里面有分支语句，不会触发RVO

// RVO 
// g++ rvo.cpp -std=c++11
// test1
// A() 
// A() :1
// operator= A() move
// ~A()1

// test2
// A() :2

// test3
// A() 
// A() :3
// A() :4
// copy A()3
// ~A()4
// ~A()3
// operator= A() move
// ~A()3
// A() :3
// A() :4
// copy A()4
// ~A()4
// ~A()3
// ~A()4
// ~A()3
// ~A()2
// ~A()1

// no RVO  g++ rvo.cpp -std=c++11 -fno-elide-constructors
// test1
// A() 
// A() :1
// copy A()1
// ~A()1
// operator= A() move
// ~A()1

// test2
// A() :2
// copy A()2
// ~A()2
// copy A()2
// ~A()2

// test3
// A() 
// A() :3
// A() :4
// copy A()3
// ~A()4
// ~A()3
// operator= A() move
// ~A()3
// A() :3
// A() :4
// copy A()4
// ~A()4
// ~A()3
// copy A()4
// ~A()4
// ~A()4
// ~A()3
// ~A()2
// ~A()1