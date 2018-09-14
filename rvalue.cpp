#include <iostream>
using namespace std;
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
    int a = 1;
    lvalue(a);
   // rvalue(a); //candidate function not viable: no known conversion from 'int' to 'int &&' for 1st argument

   // lvalue(1); //candidate function not viable: expects an l-value for 1st argument
    rvalue(1);

    return 0;
}
