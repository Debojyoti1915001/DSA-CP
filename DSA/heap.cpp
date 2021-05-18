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
void Delete(int A[], int n)
{
    int x, i, j;
    x = A[n];
    A[1] = A[n];
    i = 1, j = 2 * i;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    A[n] = x;
}
int main()
{
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for (i = 2; i <= 7; i++)
    {
        Insert(A, i);
    }
    for (i = 1; i <= 7; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    for (i = 7; i >= 1; i--)
    {
        Delete(A, i);
    }
    // Delete(A, 7);
    for (i = 1; i <= 7; i++)
    {
        cout << A[i] << " ";
    }
}