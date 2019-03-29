#include "template.h"
// 1. 静态符号只在本文件中有.在符号表中有一个字段表明是全剧符号还是局部符号
// 2.模版在每个文件中都会实例化， 最终由链接器负责去重
// 3. 模板函数实例化之后的签名和普通函数不一样， c++filt 可以用来还原修饰之前的函数
// 4. 模板特例化放在头文件会导致重复定义， 解决方式： inline , static, extern 声明然后放在.cpp文件实现
static int test;
void test2()
{
    compare(1,2);
}

bool compare2(int t1, int t2)
{
    return t1 > t2;
}

int main()
{
    test2();
    return 1;
}