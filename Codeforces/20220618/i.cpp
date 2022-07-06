#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int Test; 
    cin >> Test;
    for(int t = 0; t < Test; t++)
    {
        int n, q; 
        cin >> n>>q;
        
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
            
        for(int i = 0; i < q; i++)
        {
            int c; 
            cin >> c;
            if(c == 1)
            {
                int x1, x2;
                cin >> x1 >> x2;
                x1--;
                a[x1] = x2;
            }
            else
            {
                int l, r;
                cin >> l >> r;
                l--; r--;
                
                int c[1001] = {0};
                for(int i = l; i <= r; i++) c[a[i]]++;
                
                int ans = 0;
                for(int i = 0; i <= 1000; i++) 
                {
                    if(c[i] % 2 == 1)
                        ans++;
                }
                cout << ans << "\n";
            }
        }
        
    }
}