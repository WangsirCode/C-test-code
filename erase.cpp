#include<iostream>
#include<map>
#include <vector>
//测试代码
// erase 的 正确使用方式
// Return value : Iterator following the last removed element. If the iterator pos refers to the last element, the end() iterator is returned.
// 如果直接++ ， 当前iterator 已经失效了，会发生为为定义的行为
int main()
{
    std::map<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};
    // erase all odd numbers from c
    for(auto it = c.begin(); it != c.end(); )
        if(it->first % 2 == 1)
            it = c.erase(it);
        else
            ++it;
    for(auto& p : c)
        std::cout << p.second << ' ';

   std::cout << '\n';

    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it % 2 == 0) {
            it = vec.erase(it);
        } else {
            ++it;
        }
    }
 
    for (auto &i : vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}