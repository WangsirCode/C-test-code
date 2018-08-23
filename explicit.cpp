#include<iostream>

using namespace std;
class CExplict
{
public:
	CExplict();
	explicit CExplict( bool _explicit)
	{
		this->is_explict = _explicit;
	}
	explicit CExplict(const CExplict& other)
	{
		this->is_explict = other.is_explict;
	}
	friend void printExplicit(const CExplict& cx);	
 
private:
	bool is_explict;
};
 
void printExplicit(const CExplict& cx)
{
	cout<<"is_explict="<<cx.is_explict<<endl;
}
 
int main( int argc, char* argv[])
{
	CExplict cx1 = true;
	CExplict cx2 = cx1;
	printExplicit(cx1);
	printExplicit(cx2);
	printExplicit(false);
	getchar();
	return 1;
}