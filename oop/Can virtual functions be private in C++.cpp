// In C++, virtual functions can be private and can be overridden by the derived class.

#include <iostream>

class base
{
public:
	
	// default base constructor
	base() { std::cout << "base class constructor\n"; }

	// virtual base destructor
	// always use virtual base
	// destructors when you know you
	// will inherit this class
	virtual ~base()
	{
		std::cout << "base class destructor\n";
	}
	// public method in base class
	void show()
	{
		std::cout << "show() called on base class\n";
	}
	
	// public virtual function in base class,
	// contents of this function are printed when called
	// with base class object when called with base class
	// pointer contents of derived class are printed on
	// screen
	virtual void print()
	{
		std::cout << "print() called on base class\n";
	}
};

class derived : public base {
public:
	// default derived constructor
	derived()
		: base()
	{
		std::cout << "derived class constructor\n";
	}
	// virtual derived destructor
	// always use virtual destructors
	// when inheriting from a
	// base class
	virtual ~derived()
	{
		std::cout << "derived class destructor\n";
	}

private:
	// private virtual function in derived class overwrites
	// base class virtual method contents of this function
	// are printed when called with base class pointer or
	// when called with derived class object
	virtual void print()
	{
		std::cout << "print() called on derived class\n";
	}
};

int main()
{
	std::cout << "printing with base class pointer\n";
	
	// construct base class pointer with derived class
	// memory
	base* b_ptr = new derived();
	
	// call base class show()
	b_ptr->show();
	
	// call virtual print in base class but it is overridden
	// in derived class also note that print() is private
	// member in derived class, still the contents of derived
	// class are printed this code works because base class
	// defines a public interface and drived class overrides
	// it in its implementation
	b_ptr->print();

	delete b_ptr;
}
