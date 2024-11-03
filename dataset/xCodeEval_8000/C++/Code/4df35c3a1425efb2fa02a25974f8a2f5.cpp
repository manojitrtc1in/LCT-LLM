
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
using namespace std;

const int N = 2e6;

char shit[N], fuck[N], s[N];
int len, n, nxt[N], snxt[N][27];

void solve()
{
    scanf("%s", fuck + n + 1);
    len = strlen(fuck + n + 1);
    for (int i = n + 1;i <= len + n;i++)
    {
        nxt[i] = 0;
        for (int j = 0;j <= 25;j++)
        snxt[i][j] = 0;
    }
    for (int j = 0;j <= 25;j++)
    snxt[n][j] = snxt[nxt[n]][j];
    snxt[n][fuck[n + 1] - 'a'] = n;
    for (int i = n + 1, j = nxt[n];i <= n + len;i++)
    {
        if (fuck[j + 1] != fuck[i])
        {
            j = snxt[j][fuck[i] - 'a'];
        }
        cout << (nxt[i] = j += fuck[j + 1] == fuck[i]) << ' ';
        for (int j = 0;j <= 25;j++)
        snxt[i][j] = snxt[nxt[i]][j];
        if (i != n + len)
        snxt[i][fuck[i + 1] - 'a'] = i;
    }
    cout << endl;
}

signed main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    nxt[1] = 0;
    for (int i = 2,j = 0;i <= n;i++)
    {
        while (j && s[j + 1] != s[i])
        {
            j = nxt[j];
        }
        nxt[i] = j += (s[j + 1] == s[i]);
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j <= 25;j++)
        snxt[i][j] = snxt[nxt[i]][j];
        snxt[i][s[i + 1] - 'a'] = i;
    }
    memcpy(fuck, s, sizeof(fuck));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}