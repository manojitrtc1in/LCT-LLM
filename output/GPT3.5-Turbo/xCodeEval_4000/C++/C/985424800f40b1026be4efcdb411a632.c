#include <stdio.h>
#include <stdlib.h>

long long a[101010];

long long cnk(long long n, long long k)
{
    long long ret = 1;
    for (long long i = n - k + 1; i <= n; i++)
    {
        ret *= i;
    }
    for (int i = 1; i <= k; i++)
    {
        ret /= i;
    }
    return ret;
}

void solve()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    if (k == 1)
    {
        printf("1\n");
        exit(0);
    }
    a[2] = 1;
    for (int i = 3; i <= 10; i++)
    {
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }

    long long ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans += cnk(n, k - i) * a[k - i];
    }

    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}
