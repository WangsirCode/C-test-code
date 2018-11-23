#include<vector>
using namespace std;

class Example {
public:
    // static double rate = 6.5; a member with an in-class initializer must be const
    static const int vecSize = 20;
    static vector<double> vec;
};
