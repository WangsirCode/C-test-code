#include <iostream>

using namespace std;
// 1. 重载不支持返回值重载， 因为生成的函数签名里面不带有返回值信息
string GetValue(int value)
{
    return string("string");
}

int GetValue(int value)
{
    return 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
