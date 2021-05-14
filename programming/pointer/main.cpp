#include <iostream>

using namespace std;

int main()
{
    int score{100};
    int *p{&score};
    cout<<*p;
}
