#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ul;

int cntd(unsigned x)
{
    int ans = 0;
    while (x)
    {
        if (x & 1)
            ++ans;
        x >>= 1;
    }
    return ans;
}

ll cntdll(ul x)
{
    ll ans = 0;
    while (x)
    {
        if (x & 1)
            ++ans;
        x >>= 1;
    }
    return ans;
}

int clzd(unsigned x)
{
    int ans = 32;
    while (x)
    {
        --ans;
        x >>= 1;
    }
    return ans;
}

ll id9(ul x)
{
    ll ans = 64;
    while (x)
    {
        --ans;
        x >>= 1;
    }
    return ans;
}

int ctzd(unsigned x)
{
    if (x == 0)
        return 32;
    int ans = 0;
    while ((x & 1) == 0)
    {
        ++ans;
        x >>= 1;
    }
    return ans;
}

ll id17(ul x)
{
    if (x == 0)
        return 64;
    ll ans = 0;
    while ((x & 1) == 0)
    {
        ++ans;
        x >>= 1;
    }
    return ans;
}

int cntc(const unsigned x)
{
    return cntd(x & 65535u) + cntd((x >> 16) & 65535u);
}

ll id26(const ul x)
{
    return cntdll(x & 65535ull) + cntdll((x >> 16) & 65535ull) + cntdll((x >> 32) & 65535ull) + cntdll((x >> 48) & 65535ull);
}

int clzc(const unsigned x)
{
    if (x & 4294901760u)
        return clzd(x >> 16) - 16;
    else
        return clzd(x);
}

ll id40(const ul x)
{
    if (x & 18446744069414584320ull)
        return clzc(x >> 32);
    else
        return clzc(x) + 32;
}

int ctzc(const unsigned x)
{
    if (x & 65535u)
        return ctzd(x & 65535u);
    else
        return ctzd(x >> 16) + 16;
}

ll id27(const ul x)
{
    if (x & 4294967295ull)
        return ctzc(x);
    else
        return ctzc(x >> 32) + 32;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("0\n");
    else
    {
        int v[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        --v;
        int q[n], qq[n];
        int mx = 0;
        for (int i = 0; i < n; ++i)
        {
            ++q[v[i]];
            if (q[v[i]] > mx)
                mx = q[v[i]];
        }
        int p;
        for (int i = 0; i < n; ++i)
        {
            if (q[v[i]] == mx)
            {
                p = v[i];
                break;
            }
        }
        int u[n + 1][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n + 1; ++j)
                u[j][i] = -1;
        int uu[n];
        for (int i = 0; i < n + 1; ++i)
            uu[i] = 0;
        for (int i = 0; i < n; ++i)
            if (i != p)
                ++uu[q[i]];
        int last = 0;
        int leftmost[n][n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                leftmost[i][j] = n + 1;
            leftmost[i][0] = 0;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] != p)
            {
                ++q[v[i]];
                if (q[v[i]] > mx)
                    mx = q[v[i]];
            }
        }
        for (int y = 0; y < fmin(n, 100); ++y)
        {
            if (y != p)
            {
                int g[n + 1];
                for (int i = 0; i < n + 1; ++i)
                    g[i] = -1;
                int b = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (v[i] == p)
                    {
                        ans = fmax(ans, i - g[uu[b] - 1] - 1);
                        if (b > 0)
                            --b;
                        else
                            g[uu[b]++] = i;
                    }
                    else if (v[i] == y)
                        ++b;
                }
                ans = fmax(ans, n - g[uu[b] - 1] - 1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
