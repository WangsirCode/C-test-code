#include<iostream>
using namespace std;

class Parent {
public:
    int iparent;
    Parent ():iparent (10) {}
    virtual void f() { cout << " Parent::f()" << endl; }
    virtual void g() { cout << " Parent::g()" << endl; }
    virtual void h() { cout << " Parent::h()" << endl; }
 
};
 
class Child : public Parent {
public:
    int ichild;
    Child():ichild(100) {}
    virtual void f() { cout << "Child::f()" << endl; }
    virtual void g_child() { cout << "Child::g_child()" << endl; }
    virtual void h_child() { cout << "Child::h_child()" << endl; }
};
 
class GrandChild : public Child{
public:
    int igrandchild;
    GrandChild():igrandchild(1000) {}
    virtual void f() { cout << "GrandChild::f()" << endl; }
    virtual void g_child() { cout << "GrandChild::g_child()" << endl; }
    virtual void h_grandchild() { cout << "GrandChild::h_grandchild()" << endl; }
};

typedef void(*Fun)(void);

int main()
{
    GrandChild gc;
    Fun pFun;
    long** pVtab = (long**)&gc;
    
    cout << "[0] GrandChild::_vptr->" << endl;
    for (int i=0; (long)pVtab[0][i]!=1; i++){
        pFun = (Fun)pVtab[0][i];
        cout << "    ["<<i<<"] ";
        pFun();
    }
    cout << "[1] Parent.iparent = " << (int)pVtab[1] << endl;
    cout << "[2] Child.ichild = " << (int)pVtab[2] << endl;
    cout << "[3] GrandChild.igrandchild = " << (int)pVtab[3] << endl;
}