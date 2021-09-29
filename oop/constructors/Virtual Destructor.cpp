// CPP program without virtual destructor
// causing undefined behavior
#include<iostream>

using namespace std;

class base {
public:
	base()	
	{ cout<<"Constructing base \n"; }
	~base()
	{ cout<<"Destructing base \n"; }	
};

class derived: public base {
public:
	derived()	
	{ cout<<"Constructing derived \n"; }
	~derived()
	{ cout<<"Destructing derived \n"; }
};

int main(void)
{
derived *d = new derived();
base *b = d;
delete b;
getchar();
return 0;
}
