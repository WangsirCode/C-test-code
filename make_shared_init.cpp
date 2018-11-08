#include<iostream>
struct FileInfo
{
    int index;
    int subindex;
};

int main()
{
    auto remote_file = std::make_shared<FileInfo>();
    std::cout<<remote_file->index<<"   "<< remote_file -> subindex << std::endl;
}
