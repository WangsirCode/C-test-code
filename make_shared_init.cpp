#include<iostgream>
#include<string>
// 1. 对象初始化时，会调用默认的初始化函数，shared_ptr也会
// 反汇编：
// _main:
// 100000ef0:	55 	pushq	%rbp
// 100000ef1:	48 89 e5 	movq	%rsp, %rbp
// 100000ef4:	48 83 ec 10 	subq	$16, %rsp
// 100000ef8:	48 8d 7d f8 	leaq	-8(%rbp), %rdi
// 100000efc:	e8 1f 00 00 00 	callq	31 <__ZN8FileInfoC1Ev>
// 100000f01:	48 8d 7d f0 	leaq	-16(%rbp), %rdi
// 100000f05:	be 01 00 00 00 	movl	$1, %esi
// 100000f0a:	ba 02 00 00 00 	movl	$2, %edx
// 100000f0f:	e8 2c 00 00 00 	callq	44 <__ZN8FileInfoC1Eii>
// 100000f14:	31 c0 	xorl	%eax, %eax
// 100000f16:	48 83 c4 10 	addq	$16, %rsp
// 100000f1a:	5d 	popq	%rbp
// 100000f1b:	c3 	retq
// 100000f1c:	0f 1f 40 00 	nopl	(%rax)

// __ZN8FileInfoC1Ev:
// 100000f20:	55 	pushq	%rbp
// 100000f21:	48 89 e5 	movq	%rsp, %rbp
// 100000f24:	48 83 ec 10 	subq	$16, %rsp
// 100000f28:	48 89 7d f8 	movq	%rdi, -8(%rbp)
// 100000f2c:	48 8b 7d f8 	movq	-8(%rbp), %rdi
// 100000f30:	e8 3b 00 00 00 	callq	59 <__ZN8FileInfoC2Ev>
// 100000f35:	48 83 c4 10 	addq	$16, %rsp
// 100000f39:	5d 	popq	%rbp
// 100000f3a:	c3 	retq
// 100000f3b:	0f 1f 44 00 00 	nopl	(%rax,%rax)

// __ZN8FileInfoC1Eii:
// 100000f40:	55 	pushq	%rbp
// 100000f41:	48 89 e5 	movq	%rsp, %rbp
// 100000f44:	48 83 ec 10 	subq	$16, %rsp
// 100000f48:	48 89 7d f8 	movq	%rdi, -8(%rbp)
// 100000f4c:	89 75 f4 	movl	%esi, -12(%rbp)
// 100000f4f:	89 55 f0 	movl	%edx, -16(%rbp)
// 100000f52:	48 8b 7d f8 	movq	-8(%rbp), %rdi
// 100000f56:	8b 75 f4 	movl	-12(%rbp), %esi
// 100000f59:	8b 55 f0 	movl	-16(%rbp), %edx
// 100000f5c:	e8 2f 00 00 00 	callq	47 <__ZN8FileInfoC2Eii>
// 100000f61:	48 83 c4 10 	addq	$16, %rsp
// 100000f65:	5d 	popq	%rbp
// 100000f66:	c3 	retq
// 100000f67:	66 0f 1f 84 00 00 00 00 00 	nopw	(%rax,%rax)

// __ZN8FileInfoC2Ev:
// 100000f70:	55 	pushq	%rbp
// 100000f71:	48 89 e5 	movq	%rsp, %rbp
// 100000f74:	48 89 7d f8 	movq	%rdi, -8(%rbp)
// 100000f78:	48 8b 7d f8 	movq	-8(%rbp), %rdi
// 100000f7c:	c7 07 01 00 00 00 	movl	$1, (%rdi)
// 100000f82:	c7 47 04 00 00 00 00 	movl	$0, 4(%rdi)
// 100000f89:	5d 	popq	%rbp
// 100000f8a:	c3 	retq
// 100000f8b:	0f 1f 44 00 00 	nopl	(%rax,%rax)

// __ZN8FileInfoC2Eii:
// 100000f90:	55 	pushq	%rbp
// 100000f91:	48 89 e5 	movq	%rsp, %rbp
// 100000f94:	48 89 7d f8 	movq	%rdi, -8(%rbp)
// 100000f98:	89 75 f4 	movl	%esi, -12(%rbp)
// 100000f9b:	89 55 f0 	movl	%edx, -16(%rbp)
// 100000f9e:	48 8b 7d f8 	movq	-8(%rbp), %rdi
// 100000fa2:	8b 55 f4 	movl	-12(%rbp), %edx
// 100000fa5:	89 17 	movl	%edx, (%rdi)
// 100000fa7:	8b 55 f0 	movl	-16(%rbp), %edx
// 100000faa:	89 57 04 	movl	%edx, 4(%rdi)
// 100000fad:	5d 	popq	%rbp
// 100000fae:	c3 	retq
struct FileInfo
{
    int index;
    int subindex;
    // 如果不声明， index为随机值
    FileInfo()
    {
        index = 1;
        subindex = 0;
    }

    FileInfo(int index, int subIndex)
    {
        this->index = index;
        this->subindex = subIndex;
    }
};

int main()
{
    auto remote_file = std::make_shared<FileInfo>(2,1);
    std::cout<<remote_file->index<<"   "<< remote_file -> subindex << std::endl;

    FileInfo file;
    std::cout<<file.index<<"   "<< file.subindex << std::endl;
}
