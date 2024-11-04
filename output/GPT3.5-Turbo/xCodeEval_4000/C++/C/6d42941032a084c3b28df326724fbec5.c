#include <stdio.h>

#define M 998244353

int inverse(int a, int n)
{
    int t, nt, r, nr, q, tmp;
    if (n < 0)
        n = -n;
    if (a < 0)
        a = n - (-a % n);
    t = 0; nt = 1; r = n; nr = a % n;
    while (nr != 0)
    {
        q = r / nr;
        tmp = nt; nt = t - q * nt; t = tmp;
        tmp = nr; nr = r - q * nr; r = tmp;
    }
    if (r > 1)
        return -1;
    if (t < 0)
        t += n;
    return t;
}

int sum(int a, int b, int p)
{
    int c = a + b;
    return c >= p ? c - p : c;
}

int prod(int a, int b, int p)
{
    return (a * (long long)b) % p;
}

int raz(int a, int b, int p)
{
    int c = a - b;
    return c < 0 ? c + p : c;
}

int pow_mod(int a, int b, int p)
{
    if (b < 2)
    {
        if (b == 0)
            return 1;
        else
            return a;
    }
    int temp = pow_mod(a, b >> 1, p);
    temp = prod(temp, temp, p);
    if (b & 1)
        return prod(temp, a, p);
    else
        return temp;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int w[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &w[i]);
    int W1 = 0, W2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i])
            W1 += w[i];
        else
            W2 += w[i];
    }
    int probs[m + 1];
    probs[0] = 1;
    for (int i = 0; i < m; ++i)
    {
        int new_probs[m + 1];
        for (int d1 = 0; d1 <= i; ++d1)
        {
            int d2 = d1 - i;
            int w1 = W1 + d1;
            int w2 = W2 + d2;
            int w0 = w1 + w2;
            if (probs[d1] && (w2 >= 0))
            {
                int inv_w0 = inverse(w0, M);
                if (w2 > 0)
                    new_probs[d1] = sum(new_probs[d1], prod(probs[d1], prod(w2, inv_w0, M), M), M);
                new_probs[d1 + 1] = sum(new_probs[d1 + 1], prod(probs[d1], prod(w1, inv_w0, M), M), M);
            }
        }
        for (int j = 0; j <= m; ++j)
            probs[j] = new_probs[j];
    }
    int after_ops_1[m + 1], after_ops_2[m + 1];
    after_ops_1[0] = 1;
    after_ops_2[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        after_ops_1[i] = prod(after_ops_1[i - 1], sum(1, inverse(W1 + i - 1, M), M), M);
    }
    for (int i = 1; i <= m; ++i)
    {
        after_ops_2[i] = prod(after_ops_2[i - 1], raz(1, inverse(W2 - i + 1, M), M), M);
    }
    int coef1 = 0, coef2 = 0;
    for (int i = 0; i <= m; ++i)
        coef1 = sum(coef1, prod(after_ops_1[i], probs[i], M), M);
    for (int i = 0; i <= m; ++i)
        coef2 = sum(coef2, prod(after_ops_2[i], probs[m - i], M), M);
    for (int i = 0; i < n; ++i)
    {
        if (a[i])
            printf("%d\n", prod(w[i], coef1, M));
        else
            printf("%d\n", prod(w[i], coef2, M));
    }
    return 0;
}
