#include <bits/stdc++.h>
using namespace std;
void Insert(int A[], int n)
{
    int temp = A[n], i = n;
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
int main()
{
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for (i = 1; i <= 7; i++)
    {
        Insert(A, i);
    }
    for (i = 0; i <= 7; i++)
    {
        cout << A[i] << " ";
    }
}