#include <vector> 
#include <iostream> 
#include<map>
using namespace std;
int main()
{
    
    vector<int> test_vec = {1,23,4,5,6,7,8};
    test_vec.reserve(100);
    for(auto iter = test_vec.begin(); iter != test_vec.end(); )
    {
        if (*iter> 10) {
            auto temp = {1,1,1};
            test_vec.insert(test_vec.end(), temp.begin(), temp.end());
        }
        iter ++;
    }

    for(auto iter:test_vec)
    {
        cout<< iter<< endl;
    }
}

// insert 时， 可能会因为扩容导致iter失效。