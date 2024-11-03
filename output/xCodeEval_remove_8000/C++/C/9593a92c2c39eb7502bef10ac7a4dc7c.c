#include <stdio.h>
#include <string.h>

const double eps = 1e-8;
char S[1000100];
int n, m;
int getq()
{
    char buf[50];
    int ret = 0;
    scanf("%s", buf);
    for (int i = strlen(buf) - 1; i >= 0; i--)
        ret |= 1 << (buf[i] - 'a');
    return ret;
}
int Q[10010];
set<int> Qs;
map<int, int> ans;
int main()
{
    scanf("%s", S + 1);
    n = strlen(S + 1);
    for (int i = 1; i <= n; i++)
        S[i] -= 'a';
    S[n + 1] = 31;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        Qs.insert(Q[i] = getq());
    int stk[27], nn = 0;
    bool vis[26];
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++)
    {
        int x = S[i];
        if (!vis[x])
            stk[++nn] = x, vis[x] = 1;
        else
        {
            int j;
            for (j = 1;; j++)
                if (stk[j] == x)
                    break;
            for (; j < nn; j++)
                stk[j] = stk[j + 1];
            stk[nn] = x;
        }
        int t = 0;
        for (int j = nn; j; j--)
        {
            t |= 1 << stk[j];
            if ((t & (1 << S[i + 1])))
                break;
            if (Qs.count(t))
                ans[t]++;
        }
    }

    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[Q[i]]);
    return 0;
}
