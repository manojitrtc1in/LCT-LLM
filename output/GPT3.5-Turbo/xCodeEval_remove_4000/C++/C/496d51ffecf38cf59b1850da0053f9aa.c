#include <stdio.h>
#include <stdlib.h>

#define ll long long

ll eps = 0.0000001;
double pi = acos(-1);

ll fastpower(ll b, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p % 2)
        {
            ans = (ans * b);
        }
        b = b * b;
        p /= 2;
    }
    return ans;
}

ll id0(ll b, ll p, ll m)
{
    ll ans = 1;
    while (p)
    {
        if (p % 2)
        {
            ans = ((ans % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p /= 2;
    }
    return ans % m;
}

char *id1(ll n)
{
    char *ans = (char *)malloc(100 * sizeof(char));
    int ch = 0;
    if (n < 0)
    {
        n *= -1;
        ch = 1;
    }
    if (n == 0)
    {
        ans = "0";
    };
    int i = 0;
    while (n)
    {
        ll mo = n % 10;
        mo += 48;
        char m = mo;
        ans[i] = m;
        n /= 10;
        i++;
    }
    if (ch)
    {
        ans[i] = '-';
        i++;
    }
    ans[i] = '\0';
    return ans;
}

int compare(double f, double s)
{
    return (abs(f - s) < eps);
}

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll a2 = a;
        a = b;
        b = a2 % b;
    }
    return a;
}

const int N = 1e2 + 1;

long powcnt[N];
long ans;

void preprocess(long num)
{
    for (ll i = 30; i >= 0; i--)
    {
        if (num >= (1 << i))
        {
            num -= (1 << i);
            powcnt[i]++;
        }
    }
}

void solve(long curp)
{
    for (long i = curp; i <= 30; i++)
    {
        if (powcnt[i] > 0)
        {
            powcnt[i]--;
            ans++;
            for (long j = curp; j < i; j++)
            {
                powcnt[j]++;
            }
            break;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    long *v = (long *)malloc(m * sizeof(long));
    for (int i = 0; i < n; i++)
    {
        long x;
        scanf("%ld", &x);
        preprocess(x);
    }
    for (int i = 0; i < m; i++)
    {
        long x;
        scanf("%ld", &x);
        v[i] = x;
    }
    for (int i = 0; i < m; i++)
    {
        solve(v[i]);
    }
    printf("%ld\n", ans);
    return 0;
}
