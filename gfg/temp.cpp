#include <bits/stdc++.h>
using namespace std;
void sort(int ar[], int n)
{
    int a = 0, b = 0, c = 0, i;
    for (i = 0; i < n; i++)
    {
        if (ar[i] == 0)
            a++;
        else if (ar[i] == 1)
            b++;
        else if (ar[i] == 2)
            c++;
    }
    for (i = 0; i < a; i++)
    {
        cout << 0 << " ";
    }
    for (i = 0; i < b; i++)
    {
        cout << 1 << " ";
    }
    for (i = 0; i < c; i++)
    {
        cout << 2 << " ";
    }
}
int main()
{
    int ar[]{1, 0, 0, 2, 1, 0, 1, 1};
    sort(ar, 8);
}