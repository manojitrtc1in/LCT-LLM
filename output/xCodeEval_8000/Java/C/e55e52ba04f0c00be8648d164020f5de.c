#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 10000001

int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void generatePrimeFactors(int x)
{
    while (x != 1)
    {
        printf("%d ", spf[x]);
        x = x / spf[x];
    }
}

void solve()
{
    long n;
    scanf("%ld", &n);

    long x = n;

    sieve();

    while (x % 2 == 0)
    {
        printf("2 ");
        x = x / 2;
    }

    for (int i = 3; i * i <= x; i += 2)
    {
        while (x % i == 0)
        {
            printf("%d ", i);
            x = x / i;
        }
    }

    if (x > 2)
        printf("%ld ", x);

    printf("\n");

    if (n == 1)
    {
        printf("1\n");
        printf("0\n");
    }
    else if (x > 1)
    {
        printf("1\n");
        printf("0\n");
    }
    else if (n == 2)
    {
        printf("1\n");
        printf("0\n");
    }
    else
    {
        printf("1\n");
        printf("%ld\n", n);
    }
}

int main()
{
    solve();

    return 0;
}
