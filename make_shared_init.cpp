#include<iostream>
#include<string>
struct FileInfo
{
    int index;
    int subindex;
};

class A
{
    public:
     int a;
    A()
    {
        std::cout<< "init call"<<std::endl;
        
    };

    private:
        int b;
        void test(){
            A *a = new A();
            a->b;
        }
};

int main()
{
    auto remote_file = std::make_shared<FileInfo>();
    std::cout<<remote_file->index<<"   "<< remote_file -> subindex << std::endl;

    FileInfo file;
    std::cout<<file.index<<"   "<< file.subindex << std::endl;

    A a;
    std::cout<< a.a << std::endl;

    auto p_a = std::make_shared<A>();

    std::cout<< p_a->a << std::endl;

    char test_a[16] = "fadsaf";
    char char_test = 0x1a;
    std::cout<< std::hex<< std::uppercase << (int)char_test << std::endl;
    std::string test_b = test_a;
    std::cout<< test_b << std::endl;
}
