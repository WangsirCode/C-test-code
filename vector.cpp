#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arr{1,2,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
    cout<< arr.size()<<endl;
    cout<< arr.capacity()<<endl;
    cout<< "shrink to fit"<<endl;
    arr.shrink_to_fit();
    cout<< arr.capacity()<<endl;
    cout<< "reserve to 100"<<endl;
    arr.reserve(100);
    cout<< arr.capacity()<<endl;
    return 0;
}
