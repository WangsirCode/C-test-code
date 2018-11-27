#include <iostream>
using namespace std;

// //基类
class BaseA{
public:
    BaseA(int a, int b);
    ~BaseA();
public:
    void show();
protected:
    int m_a;
    int m_b;
};
BaseA::BaseA(int a, int b): m_a(a), m_b(b){
    cout<<"BaseA constructor"<<endl;
}
BaseA::~BaseA(){
    cout<<"BaseA destructor"<<endl;
}
void BaseA::show(){
    cout<<"m_a = "<<m_a<<endl;
    cout<<"m_b = asdfsadf"<<m_b<<endl;
}

// //基类
class BaseB{
public:
    BaseB(int c, int d);
    ~BaseB();
    void show();
    void day();
protected:
    int m_c;
    int m_d;
};
BaseB::BaseB(int c, int d): m_c(c), m_d(d){
    cout<<"BaseB constructor"<<endl;
}
BaseB::~BaseB(){
    cout<<"BaseB destructor"<<endl;
}
void BaseB::show(){
    cout<<"m_c = "<<m_c<<endl;
    cout<<"m_d = "<<m_d<<endl;
}
void BaseB::day(){
    cout<<"day";
}
// //派生类
class Derived: public BaseA, public BaseB{
public:
    Derived(int a, int b, int c, int d, int e);
    ~Derived();
public:
    void display();
private:
    int m_e;
};
Derived::Derived(int a, int b, int c, int d, int e): BaseA(a, b), BaseB(c, d), m_e(e){
    cout<<"Derived constructor"<<endl;
}
Derived::~Derived(){
    cout<<"Derived destructor"<<endl;
}
void Derived::display(){
    // BaseA::show();  //调用BaseA类的show()函数
    day();
    // show();  "Derived::show" is ambiguous
    // BaseB::show();  //调用BaseB类的show()函数
    cout<<"m_e = "<<m_e<<endl;
}

class B
{
    public:
        int ib;
        char cb;
    public:
        B():ib(0),cb('B') {}
        virtual void f() { cout << "B::f()" << endl;}
        virtual void Bf() { cout << "B::Bf()" << endl;}
};
class B1 :  public B
{
    public:
        int ib1;
        char cb1;
    public:
        B1():ib1(11),cb1('1') {}
        virtual void f() { cout << "B1::f()" << endl;}
        virtual void f1() { cout << "B1::f1()" << endl;}
        virtual void Bf1() { cout << "B1::Bf1()" << endl;}
};
class B2:  public B
{
    public:
        int ib2;
        char cb2;
    public:
        B2():ib2(12),cb2('2') {}
        virtual void f() { cout << "B2::f()" << endl;}
        virtual void f2() { cout << "B2::f2()" << endl;}
        virtual void Bf2() { cout << "B2::Bf2()" << endl;}
};
class D : public B1, public B2
{
    public:
        int id;
        char cd;
    public:
        D():id(100),cd('D') {}
        virtual void f() { cout << "D::f()" << endl;}
        virtual void f1() { cout << "D::f1()" << endl;}
        virtual void f2() { cout << "D::f2()" << endl;}
        virtual void Df() { cout << "D::Df()" << endl;}
};

int main(){
    // Derived obj(1, 2, 3, 4, 5);
    // BaseA a = obj;
    // a.show();
    typedef void(*Fun)(void);
    long** pVtab = NULL;
    Fun pFun = NULL;
    D d;
    pVtab = (long**)&d;
    cout << "[0] D::B1::_vptr->" << endl;
    pFun = (Fun)pVtab[0][0];
    cout << "     [0] ";    pFun();
    pFun = (Fun)pVtab[0][1];
    cout << "     [1] ";    pFun();
    pFun = (Fun)pVtab[0][2];
    cout << "     [2] ";    pFun();
    pFun = (Fun)pVtab[0][3];
    cout << "     [3] ";    pFun();
    pFun = (Fun)pVtab[0][4];
    cout << "     [4] ";    pFun();
    pFun = (Fun)pVtab[0][5];
    cout << "     [5] 0x" << pFun << endl;

    int *pVtabToMember = (int *)&pVtab[1];
    cout << "[1] B::ib = " << (int)pVtabToMember[0] << endl;
    cout << "[2] B::cb = " << (char)pVtabToMember[1] << endl;
    cout << "[3] B1::ib1 = " << (int)pVtabToMember[2] << endl;
    cout << "[4] B1::cb1 = " << (char)pVtabToMember[3] << endl;

    cout << "[5] D::B2::_vptr->" << endl;
    long** pVtabToB2 = (long**)pVtab;
    pFun = (Fun)pVtabToB2[3][0];
    cout << "     [0] ";    pFun();
    pFun = (Fun)pVtabToB2[3][1];
    cout << "     [1] ";    pFun();
    pFun = (Fun)pVtabToB2[3][2];
    cout << "     [2] ";    pFun();
    pFun = (Fun)pVtabToB2[3][3];
    cout << "     [3] ";    pFun();
    pFun = (Fun)pVtabToB2[3][4];
    cout << "     [4] 0x" << pFun << endl;

    int * pMemberToB2 = (int*)&pVtabToB2[4];
    cout << "[6] B::ib = " << (int)pMemberToB2[0] << endl;
    cout << "[7] B::cb = " << (char)pMemberToB2[1] << endl;
    cout << "[8] B2::ib2 = " << (int)pMemberToB2[2] << endl;
    cout << "[9] B2::cb2 = " << (char)pMemberToB2[3] << endl;
    cout << "[10] D::id = " << (int)pMemberToB2[4] << endl;
    cout << "[11] D::cd = " << (char)pMemberToB2[5] << endl;
    return 0;
}