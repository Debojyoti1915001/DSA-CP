// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
class Test{
    private:
    int num;
    public:
    Test():num(8){};
    void operator ++(){
        num+=2;
    }
    void Print(){
        cout<<"The count"<<num;
    }
};
int main()
{
    Test t;
    ++t;
    t.Print();
    return 0;
}
