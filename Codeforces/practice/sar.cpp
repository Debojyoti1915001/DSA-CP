#include <bits/stdc++.h>
using namespace std;
int rev(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
bool func(string N)
{
    int num = 0;
    for (int i = 0; i < N.size(); i++)
    {
        num = num * 10 + N[i] - '0';
    }
    for (int i = 1; i < num; i++)
    {
        if (i + rev(i) == num)
            return 1;
    }
    return 0;
}

// Driver code
int isspecial(string input1[], int input2)
{
    int cnt = 0;
    for (int i = 0; i < input2; i++)
        if (func(input1[i]))
            cnt++;
    return cnt;
}