#include <iostream>
#include <vector>
using namespace std;

// 转移语义可以将资源 ( 堆，系统对象等 ) 从一个对象转移到另一个对象，这样能够减少不必要的临时对象的创建、拷贝以及销毁，能够大幅度提高 C++ 应用程序的性能
// 对于值类型而言，引用类型不存在这个问题，因此对于python这样都是引用对象的语言而言，不存在这个问题

class MyString { 
private: 
 char* _data; 
 size_t   _len; 
 void _init_data(const char *s) { 
   _data = new char[_len+1]; 
   memcpy(_data, s, _len); 
   _data[_len] = '\0'; 
 } 
public: 
 MyString() { 
   _data = NULL; 
   _len = 0; 
 } 
 
 MyString(const char* p) { 
   _len = strlen (p); 
   _init_data(p); 
   std::cout << "init is called! source: " << _data << std::endl; 
 } 
 
 MyString(const MyString& str) { 
   _len = str._len; 
   _init_data(str._data); 
   std::cout << "Copy Constructor is called! source: " << str._data << std::endl; 
 } 
 
 MyString& operator=(const MyString& str) { 
   if (this != &str) { 
     _len = str._len; 
     _init_data(str._data); 
   } 
   std::cout << "Copy Assignment is called! source: " << str._data << std::endl; 
   return *this; 
 } 
 
 virtual ~MyString() { 
   if (_data) free(_data); 
 } 
}; 

void lvalue(int& a)
{
    cout << "lvalue" << endl;
}

void rvalue(int&& a)
{
    cout<< "rvalue" << endl;
}

int main(int argc, char const *argv[])
{
    int l_value = 1;
    lvalue(l_value);
   // rvalue(l_value); //candidate function not viable: no known conversion from 'int' to 'int &&' for 1st argument

    // lvalue(1); //candidate function not viable: expects an l-value for 1st argument
    rvalue(1);

    MyString a = MyString("Hello"); 
    a = MyString("Hello"); 
    std::vector<MyString> vec; 
    vec.push_back(MyString("World")); 

    return 0;
}
