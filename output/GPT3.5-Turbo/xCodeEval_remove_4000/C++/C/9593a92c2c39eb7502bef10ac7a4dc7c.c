#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000100
#define MAXM 10010

char S[MAXN];
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

int Q[MAXM];
int Qs[MAXM];
int ans[MAXM];

int main()
{
    scanf("%s", S + 1);
    n = strlen(S + 1);
    for (int i = 1; i <= n; i++)
        S[i] -= 'a';
    S[n + 1] = 31;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        Qs[i] = Q[i] = getq();
    int stk[27], nn = 0;
    int vis[26];
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
            if (Qs[t])
                ans[t]++;
        }
    }

    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[Q[i]]);
    return 0;
}
