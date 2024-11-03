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
        int64_t ostr = n,ostc = n;
        for(int i = 0;i < s.size();++i)
        {
            if(i != 0 && s[i] != s[i-1] && st == -1)
            {
                st = i;
            }
            if(s[i] == 'R')
                ostc--;
            else
                ostr--;
        }
        if(st == -1)
        {
            cout << n << "\n";
            continue;
        }
        int64_t ans = 0;
        for(int i = st;i < s.size();++i)
        {
            if(s[i] == 'R')
            {
                ans += ostr;
            }
            else
                ans += ostc;
        }
        ans += (ostr)*(ostc);
        cout << ans+st << "\n";
    }
}
