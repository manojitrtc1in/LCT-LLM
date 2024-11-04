#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long ll;

char s[30];
int cnt;
char leading;
bool lead = true;
ll res;

ll alpha(int n);
ll beta(int n);
ll power(ll n, int p);

int main()
{
    scanf("%s", s);

    leading = s[0];

    if (isdigit(leading))
        lead = false;

    for (int i = 0; i < strlen(s); ++i)
    {
        if (isalpha(s[i]))
            cnt++;
    }

    if (!lead)
    {
        res = alpha(cnt) * power(10, cnt);
    }
    else
    {
        if (leading == '?')
            res = alpha(cnt) * power(10, cnt - 1) * 9;
        else
            res = beta(cnt) * power(10, cnt);
    }

    printf("%lld\n", res);

    return 0;
}

ll alpha(int n)
{
    ll cnt = 10LL, res = 1LL;
    for (int i = 0; i < (n < 11 ? n : 11); ++i)
    {
        res *= cnt;
        cnt = cnt > 0 ? cnt - 1 : 0;
    }
    return res;
}

ll beta(int n)
{
    ll cnt = 9LL, res = 9LL;
    for (int i = 0; i < (n - 1 < 11 ? n - 1 : 11); ++i)
    {
        res *= cnt;
        cnt = cnt > 0 ? cnt - 1 : 0;
    }
    return res;
}

ll power(ll n, int p)
{
    if (p <= 0)
        return 1;

    ll x = power(n, p / 2);

    if (p & 1)
        return x * x * n;
    else
        return x * x;
}
