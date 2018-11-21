#include<iostream>
#include<map>
int main(int argc, char const *argv[])
{
    std::map<int, std::string> map_a = {
        {1, "sdf"},
        {2, "adf"},
        {3,"saf"},
        {4,"dsaf"},
        {5,"fasdf"},
        {6,"dfaffd"}
    };
    for(auto &iter : map_a){
        std::cout<<iter.first<<std::endl;
    }
    return 0;
}
