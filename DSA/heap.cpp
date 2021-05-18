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
int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
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
    for (i = 7; i > 1; i--)
    {
        Delete(A, i);
    }
    // Delete(A, 7);
    for (i = 1; i <= 7; i++)
    {
        cout << A[i] << " ";
    }
}