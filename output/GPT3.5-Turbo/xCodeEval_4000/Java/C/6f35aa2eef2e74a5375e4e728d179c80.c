#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 400000

int primes[MAXN];

void sieveEratosthenes(int n, int *ret, int *pos)
{
    if (n <= 32)
    {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++)
        {
            if (n < primes[i])
            {
                *pos = i;
                for (int j = 0; j < i; j++)
                {
                    ret[j] = primes[j];
                }
                return;
            }
        }
        *pos = sizeof(primes) / sizeof(primes[0]);
        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++)
        {
            ret[i] = primes[i];
        }
        return;
    }

    int u = n + 32;
    double lu = log(u);
    int size = (int)(u / lu + u / lu / lu * 1.5);
    int *ret = (int *)malloc(size * sizeof(int));
    ret[0] = 2;
    *pos = 1;

    int *isnp = (int *)malloc(((n + 1) / 32 / 2 + 1) * sizeof(int));
    int sup = (n + 1) / 32 / 2 + 1;

    int tprimes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 0; i < sizeof(tprimes) / sizeof(tprimes[0]); i++)
    {
        ret[*pos] = tprimes[i];
        (*pos)++;
        int *ptn = (int *)malloc(tprimes[i] * sizeof(int));
        for (int j = (tprimes[i] - 3) / 2; j < tprimes[i] << 5; j += tprimes[i])
        {
            ptn[j >> 5] |= 1 << (j & 31);
        }
        for (int j = 0; j < sup; j += tprimes[i])
        {
            for (int k = 0; k < tprimes[i] && k + j < sup; k++)
            {
                isnp[j + k] |= ptn[k];
            }
        }
        free(ptn);
    }

    int magic[] = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
    int h = n / 2;
    for (int i = 0; i < sup; i++)
    {
        for (int j = ~isnp[i]; j != 0; j &= j - 1)
        {
            int pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27];
            int p = 2 * pp + 3;
            if (p > n)
                break;
            ret[*pos] = p;
            (*pos)++;
            if ((long)p * p > n)
                continue;
            for (int q = (p * p - 3) / 2; q <= h; q += p)
                isnp[q >> 5] |= 1 << q;
        }
    }

    free(isnp);
}

long pi(long x, int *primes, int size)
{
    if (x <= primes[size - 1])
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (x < primes[i])
            {
                return count;
            }
            count++;
        }
        return count;
    }

    int A = pi(sqrt(sqrt(x)), primes, size);
    long ret = A + phi(x, A, primes, size) - P2(x, A, primes, size) - P3(x, A, primes, size) - 1;
    return ret;
}

long phi(long x, int A, int *primes, int size)
{
    if (A > 0 && A - 1 < size)
    {
        return cumps[A - 1][FP[A - 1]] * (x / FP[A - 1]) + cumps[A - 1][(int)(x % FP[A - 1] + 1)];
    }
    if (A > 0 && x <= (long)primes[A - 1] * primes[A - 1])
    {
        return pi(x, primes, size) - A + 1;
    }
    long ret = x;
    for (int i = A - 1; i >= 0; i--)
    {
        ret -= phi(x / primes[i], i, primes, size);
    }
    return ret;
}

long P2(long x, int A, int *primes, int size)
{
    int B = pi(sqrt(x), primes, size);
    long ret = 0;
    for (int i = A; i < B; i++)
    {
        ret += pi(x / primes[i], primes, size);
    }
    ret -= (long)(B - A) * (B + A - 1) / 2;
    return ret;
}

long P3(long x, int A, int *primes, int size)
{
    int C = pi(cbrt(x), primes, size);
    long ret = 0;
    for (int i = A; i < C; i++)
    {
        long xi = x / primes[i];
        int B = pi(sqrt(xi), primes, size);
        for (int j = i; j < B; j++)
        {
            ret += pi(xi / primes[j], primes, size) - j;
        }
    }
    return ret;
}

long sqrt(long n)
{
    long i = (long)sqrt(n) - 2;
    while (i * i <= n)
        i++;
    return i - 1;
}

long cbrt(long n)
{
    long i = (long)cbrt(n) - 2;
    while (i * i * i <= n)
        i++;
    return i - 1;
}

void solve()
{
    long n;
    scanf("%ld", &n);
    long ans = 0;
    int size;
    sieveEratosthenes(MAXN, primes, &size);
    for (int i = 0; i < size; i++)
    {
        long plus = pi(n / primes[i], primes, size) - (i + 1);
        if (plus <= 0)
            break;
        ans += plus;
    }

    for (int i = 0; i < size; i++)
    {
        if ((long)primes[i] * primes[i] * primes[i] <= n)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    printf("%ld\n", ans);
}

int main()
{
    solve();
    return 0;
}
