#include <stdio.h>
#include <stdlib.h>

#define M 998244353

int inverse(int a, int n)
{
    int c = 1;
    while (n != 1)
    {
        int q = n / a;
        int t = a;
        a = n % a;
        n = t;
        t = c;
        c = -q * c + t;
    }
    return c;
}

int sum(int a, int b, int p)
{
    int c = a + b;
    if (c >= p)
        c -= p;
    return c;
}

int prod(int a, int b, int p)
{
    long long c = (long long)a * b;
    return c % p;
}

int raz(int a, int b, int p)
{
    int c = a - b;
    if (c < 0)
        c += p;
    return c;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int *w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    int W1 = 0, W2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            W1 += w[i];
        else
            W2 += w[i];
    }

    int *probs = (int *)calloc(m + 1, sizeof(int));
    probs[0] = 1;
    for (int i = 0; i < m; i++)
    {
        int *new_probs = (int *)calloc(m + 1, sizeof(int));
        for (int d1 = 0; d1 <= i; d1++)
        {
            int d2 = d1 - i;
            int w1 = W1 + d1;
            int w2 = W2 + d2;
            int w0 = w1 + w2;
            if (probs[d1] && (w2 >= 0))
            {
                int id16 = inverse(w0, M);
                if (w2 > 0)
                    new_probs[d1] = sum(new_probs[d1], prod(probs[d1], prod(w2, id16, M), M), M);
                new_probs[d1 + 1] = sum(new_probs[d1 + 1], prod(probs[d1], prod(w1, id16, M), M), M);
            }
        }
        free(probs);
        probs = new_probs;
    }

    int *id4 = (int *)malloc((m + 1) * sizeof(int));
    int *id29 = (int *)malloc((m + 1) * sizeof(int));
    id4[0] = 1;
    id29[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        id4[i] = prod(id4[i - 1], sum(1, inverse(W1 + i - 1, M), M), M);
    }
    for (int i = 1; i <= m; i++)
    {
        id29[i] = prod(id29[i - 1], raz(1, inverse(W2 - i + 1, M), M), M);
    }

    int coef1 = 0, coef2 = 0;
    for (int i = 0; i <= m; i++)
        coef1 = sum(coef1, prod(id4[i], probs[i], M), M);
    for (int i = 0; i <= m; i++)
        coef2 = sum(coef2, prod(id29[i], probs[m - i], M), M);

    for (int i = 0; i < n; i++)
    {
        if (a[i])
            printf("%d\n", prod(w[i], coef1, M));
        else
            printf("%d\n", prod(w[i], coef2, M));
    }

    free(a);
    free(w);
    free(probs);
    free(id4);
    free(id29);

    return 0;
}
