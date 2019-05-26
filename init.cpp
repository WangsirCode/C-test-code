#include<iostream>
using namespace std;
// 1. 构造函数必须声明为public
// 2. 可以使用delete 或者default(使用default的意义：某些情况下系统不会生产默认的构造函数)
// 3. 使用explicit 避免隐式转换
// 4. 只要有构造函数声明，则不再生产默认的构造函数
// 5. A a 和 A a{} 会调用默认构造函数
// 6. A a = A(); 会调用默认构造函数，然后执行一次move(如果禁止返回值优化则不会调用Move)
class A
{
    public: // 如果不声明为public, 则默认为private, 则无法调用
    A(){
        cout<<"default cstor"<< endl;
    }

    A(const A& x)
    {
        cout<<"copy cstor"<< endl;
    }

    A(const A&& x)
    {
        cout<<"move cstor"<< endl;
    }
};

int main()
{
    A a{};
    A a2; // 调用默认构造函数

    A a3 = A(); // 调用默认构造函数，再调用move, 如果禁止返回值优化则不会调用Move
}