#include <iostream>
using namespace std;
// initializer_list 是接收可变长度参数的方式
class Foo
{
    public:
	int x;
	int y;
	int z;
    public:
	Foo(std::initializer_list<int> list)
	{
		auto it= list.begin();
		x = *it++;
		y = *it++;
		z = *it++;
	}
};
 
int main(int argc, char* argv[])
{
	Foo foo1 {1,2,3};
	Foo foo2 { 4, 5};
	Foo foo3{ 6};
	Foo foo4{ 7, 8, 9 };
	cout << foo1.x << " " << foo1.y << " " << foo1.z<<endl;
	cout << foo2.x << " " << foo2.y << " " << foo2.z << endl;
	cout << foo3.x << " " << foo3.y << " " << foo3.z << endl;
	cout << foo4.x << " " << foo4.y << " " << foo4.z << endl;
	return 0;
}

