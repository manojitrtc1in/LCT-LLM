#include <bits/stdc++.h>

using namespace std;


















int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int64_t rc = count(s.begin(),s.end(),'R'),dc = count(s.begin(),s.end(),'D'),st = -1;
        for(int i = 0;i < s.size();++i)
        {
            if(i != 0 && s[i] != s[i-1])
            {
                st = i;
                break;
            }
        }
        if(st == -1)
        {
            cout << n << "\n";
            continue;
        }
        cout << st + (n-rc)*(n-dc) + (s[0] == 'R' ? (rc-st)*(n-dc) + (n-rc)*(dc) : (rc)*(n-dc) + (n-rc)*(dc-st)) << "\n";
    }
}