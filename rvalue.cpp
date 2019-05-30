#include <iostream>
#include <utility>
#include <type_traits>
using namespace std;

// 转移语义可以将资源 ( 堆，系统对象等 ) 从一个对象转移到另一个对象，这样能够减少不必要的临时对象的创建、拷贝以及销毁，能够大幅度提高 C++ 应用程序的性能
// 对于值类型而言，引用类型不存在这个问题，因此对于python这样都是引用对象的语言而言，不存在这个问题

// 1. 右值引用是什么 。 和左值引用一样，同样是引用， 实现方式是存了一个地址。不过对于 int&& a = 1; 必须先将“1”存在内存中，然后另a指向他
// 2. 对于已右值引用为参数的函数而言，寄存器传的是地址。实现方式和左右引用完全一样。
// 3. 左右引用和右值引用的唯一区别是右值引用只能绑定到右值上，左右引用只能绑定到左值上。 两个的存取方式完全一样
// 4. 左值引用和右值引用都是引用， 属于左值。 只有临时变量属于右值。
// 5. std::move可以将任何左值变为右值(包括int, int&, int&&)
// 6. 函数的返回值int和int&&也可以被Bind到 int&& ， int&不可以
// 7. funcC(int a)和funcC(int& a) 会冲突
// 8. T可以bind到T, T&, T&&
// 9. T&可以Bind到T, T&, T&&
// 10. T&& 可以Bind到 (T，T&&)右值
int funcA(int& a)
{
    int b = a;
    return 1;
}

int funcB(int&& a)
{
    int b = a;
    return 1;
}

int funcC(int a)
{
    int b = a;
    return 1;
}

int funcC(int& a)
{
    return 1;
}

int&&  funcD(int a)
{   
     using ReturnType =                       // alias declaration;
    typename remove_reference<int>::type&&;
    auto test = static_cast<ReturnType>(a);
    return static_cast<ReturnType>(a);
}

int& funcE(int a)
{
    int& ref = a;
    return ref;
}

int main()
{
    int value = 1;
    int& l_value_ref = value;
    int&& r_value_ref = 1;

//T可以bind到T, T&, T&&
    int value_test = 1;
    int value_test = l_value_ref;
    int value_test = r_value_ref;

//T&可以Bind到T, T&, T&&
    int& l_value_ref_test = l_value_ref;
    int& l_value_ref_test2 = r_value_ref;
    // int& l_value_ref_test3 = 1;  wrong

//T&& 可以Bind到 (T，T&&)右值
    int&& r_value_ref_test = 1;
    // int&& r_value_ref_test2 = value;  an rvalue reference cannot be bound to an lvalue
    int&& r_value_ref_test2 = std::move(value);
    // int&& r_value_ref_test3 = l_value_ref; an rvalue reference cannot be bound to an lvalue
    int&& r_value_ref_test3 = std::move(l_value_ref);
    // int&& r_value_ref_test = r_value_ref; an rvalue reference cannot be bound to an lvalue
    int&& r_value_ref_test4 = std::move(r_value_ref);
    int&& r_value_ref_test5 = funcD(1);
    int&& r_value_ref_test6 = funcA(value);
    // static_cast 可以理解为一个函数
    int&& r_value_ref_test7 = static_cast<int>(value);
    int&& r_value_ref_test8 = static_cast<int&&>(value);
    // int&& r_value_ref_test9 = static_cast<int&>(value); wrong
    int&& r_value_ref_test9 = std::forward<int>(l_value_ref);
    // int&& r_value_ref_test9 = std::forward<int&>(l_value_ref); wrong
    int&& r_value_ref_test10 = std::forward<int&&>(l_value_ref);
}