#include <bits/stdc++.h>

using namespace std;


















const int mod = 998244353;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int64_t n;
        cin >> n;
        string s;
        cin >> s;
        int64_t st = -1;
        int64_t rc = 0,dc = 0;
        for(int i = 0;i < s.size();++i)
        {
            if(i != 0 && s[i] != s[i-1] && st == -1)
            {
                st = i;
            }
            if(s[i] == 'R')
                rc++;
            else
                dc++;
        }
        if(st == -1)
        {
            cout << n << "\n";
            continue;
        }
        if(s[0] == 'R')
            cout << st + (rc-st)*(n-dc) + (n-rc)*(dc) + (n-rc)*(n-dc) << "\n";
        else
            cout << st + (rc)*(n-dc) + (n-rc)*(dc-st) + (n-rc)*(n-dc) << "\n";
    }
}
