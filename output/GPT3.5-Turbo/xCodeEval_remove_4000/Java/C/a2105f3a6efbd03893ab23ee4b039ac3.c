#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 400000

int primes[MAXN];

void id0(int n) {
    if (n <= 32) {
        int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
            if (n < primes[i]) {
                int* result = (int*)malloc(i * sizeof(int));
                for (int j = 0; j < i; j++) {
                    result[j] = primes[j];
                }
                return result;
            }
        }
        int* result = (int*)malloc(sizeof(primes) / sizeof(primes[0]) * sizeof(int));
        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
            result[i] = primes[i];
        }
        return result;
    }

    int u = n + 32;
    double lu = log(u);
    int* ret = (int*)malloc(((int)(u / lu + u / lu / lu * 1.5)) * sizeof(int));
    ret[0] = 2;
    int pos = 1;

    int* isnp = (int*)calloc((n + 1) / 32 / 2 + 1, sizeof(int));
    int sup = (n + 1) / 32 / 2 + 1;

    int id3[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for (int k = 0; k < sizeof(id3) / sizeof(id3[0]); k++) {
        int tp = id3[k];
        ret[pos++] = tp;
        int* ptn = (int*)calloc(tp, sizeof(int));
        for (int i = (tp - 3) / 2; i < tp << 5; i += tp) {
            ptn[i >> 5] |= 1 << (i & 31);
        }
        for (int j = 0; j < sup; j += tp) {
            for (int i = 0; i < tp && i + j < sup; i++) {
                isnp[j + i] |= ptn[i];
            }
        }
        free(ptn);
    }

    int magic[] = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
    int h = n / 2;
    for (int i = 0; i < sup; i++) {
        for (int j = ~isnp[i]; j != 0; j &= j - 1) {
            int pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27];
            int p = 2 * pp + 3;
            if (p > n) {
                break;
            }
            ret[pos++] = p;
            if ((long)p * p > n) {
                continue;
            }
            for (int q = (p * p - 3) / 2; q <= h; q += p) {
                isnp[q >> 5] |= 1 << q;
            }
        }
    }

    primes = (int*)malloc(pos * sizeof(int));
    for (int i = 0; i < pos; i++) {
        primes[i] = ret[i];
    }
    free(ret);
    free(isnp);
}

long id7(long n)
{
    assert(n >= 4);

    int s = (int)sqrt(n) * 100; 

    int cachelimit = s;
    id0(s);
    int* xcums = (int*)calloc((s >> 6) + 1, sizeof(int));
    long* isp = (long*)calloc((s >> 6) + 1, sizeof(long));
    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        isp[primes[i] >> 6] |= 1L << primes[i];
    }
    for (int i = 0; i < (s >> 6); i++) {
        xcums[i + 1] = xcums[i] + __builtin_popcountll(isp[i]);
    }

    int M = sizeof(primes) / sizeof(primes[0]);
    int B = 100;

    int** cumps = (int**)malloc(M * sizeof(int*));
    bool* b = (bool*)malloc(sizeof(bool));
    int len = 1;
    for (int i = 0; i < M; i++) {
        len *= primes[i];
        bool* c = (bool*)malloc(len * sizeof(bool));
        for (int j = 0; j < primes[i]; j++) {
            for (int k = j; k < len; k += primes[i]) {
                c[k] = b[0];
            }
        }
        for (int k = 0; k < len; k += primes[i]) {
            cumps[i] = (int*)malloc((len + 1) * sizeof(int));
            for (int j = 0; j < len; j++) {
                cumps[i][j + 1] = cumps[i][j] + (c[j] ? 1 : 0);
            }
        }
        primes[i] = len;
        b = c;
    }

    long ret = 0;
    for (int i = 0; i < M; i++) {
        ret += cumps[i][primes[i]] * (n / primes[i]) + cumps[i][(int)(n % primes[i] + 1)];
    }

    return ret;
}

void solve()
{
    long n;
    scanf("%ld", &n);
    long ans = 0;
    if (n <= 10) {
        if (n >= 6) {
            ans++;
        }
        if (n >= 8) {
            ans++;
        }
        if (n >= 10) {
            ans++;
        }
        printf("%ld\n", ans);
        return;
    }

    long ml = id7(n / 2);
    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        long plus = ml - (i + 1);
        if (plus <= 0) {
            break;
        }
        ans += plus;
    }

    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
        if ((long)primes[i] * primes[i] * primes[i] <= n) {
            ans++;
        }
        else {
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
