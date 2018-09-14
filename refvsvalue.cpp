#include <iostream>
using namespace std;

void ref(int a)
{
    cout<<"value version"<<endl;
}

void ref(int& a)
{
    cout<< "ref version" << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = 1;
    int &refen= a;
    int value = 1;
    // ref(refen); //call to 'ref' is ambiguous
    // ref(value); //call to 'ref' is ambiguous
    return 0;
}
