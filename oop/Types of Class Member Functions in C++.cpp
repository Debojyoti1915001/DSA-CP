//1
class WithFriend
{
    int i;
    public:
    friend void fun(); // global function as friend
};

void fun()
{
    WithFriend wf;
    wf.i=10;  // access to private data member
    cout << wf.i;
}

int main()
{
    fun(); //Can be called directly
}

//2
class Other
{
    void fun();
};

class WithFriend
{
    private:
    int i;
    public:
    void getdata();  // Member function of class WithFriend
    
    // making function of class Other as friend here
    friend void Other::fun();   
    
    // making the complete class as friend
    friend class Other;  //the whole class with friend is made accesible to class other
};
