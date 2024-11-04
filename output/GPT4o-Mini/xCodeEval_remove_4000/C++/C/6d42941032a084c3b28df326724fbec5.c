#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 998244353
#define MAXN 2000001

typedef long long ll;
typedef struct {
    int X, Y;
} pii;

typedef struct {
    ll X, Y;
} pll;

typedef struct {
    int *data;
    int size;
} vi;

vi create_vi(int size) {
    vi v;
    v.data = (int *)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void free_vi(vi *v) {
    free(v->data);
}

int prod(int a, int b, int M) {
    return ((ll)(a)) * b % M;
}

int sum(int a, int b, int M) {
    int c = a + b;
    return c >= M ? c - M : c;
}

int raz(int a, int b, int M) {
    int c = a - b;
    return c < 0 ? c + M : c;
}

int inverse(int a, int n) {
    int c = id20(a, n).X;
    if (c < 0) c += n;
    return c;
}

int id20(int a, int b) {
    if (b) {
        int c = a / b;
        pii ans1 = id20(b, a - b * c);
        return (pii){ans1.Y, ans1.X - ans1.Y * c};
    } else {
        return (pii){1, 0};
    }
}

void read_vi(vi *v) {
    for (int i = 0; i < v->size; ++i) {
        scanf("%d", &v->data[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vi a = create_vi(n);
    read_vi(&a);
    
    vi w = create_vi(n);
    read_vi(&w);
    
    int W1 = 0, W2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a.data[i]) {
            W1 += w.data[i];
        } else {
            W2 += w.data[i];
        }
    }
    
    vi probs = create_vi(m + 1);
    probs.data[0] = 1;
    
    for (int i = 0; i < m; ++i) {
        vi new_probs = create_vi(m + 1);
        for (int d1 = 0; d1 <= i; ++d1) {
            int d2 = d1 - i;
            int w1 = W1 + d1;
            int w2 = W2 + d2;
            int w0 = w1 + w2;
            if (probs.data[d1] && (w2 >= 0)) {
                int id16 = inverse(w0, M);
                if (w2 > 0) {
                    new_probs.data[d1] = sum(new_probs.data[d1], prod(probs.data[d1], prod(w2, id16, M), M), M);
                }
                new_probs.data[d1 + 1] = sum(new_probs.data[d1 + 1], prod(probs.data[d1], prod(w1, id16, M), M), M);
            }
        }
        free_vi(&probs);
        probs = new_probs;
    }
    
    vi id4 = create_vi(m + 1);
    vi id29 = create_vi(m + 1);
    id4.data[0] = 1; 
    id29.data[0] = 1;
    
    for (int i = 1; i <= m; ++i) {
        id4.data[i] = prod(id4.data[i - 1], sum(1, inverse(W1 + i - 1, M), M), M);
    }
    
    for (int i = 1; i <= m; ++i) {
        id29.data[i] = prod(id29.data[i - 1], raz(1, inverse(W2 - i + 1, M), M), M);
    }
    
    int coef1 = 0, coef2 = 0;
    for (int i = 0; i <= m; ++i) {
        coef1 = sum(coef1, prod(id4.data[i], probs.data[i], M), M);
    }
    
    for (int i = 0; i <= m; ++i) {
        coef2 = sum(coef2, prod(id29.data[i], probs.data[m - i], M), M);
    }
    
    for (int i = 0; i < n; ++i) {
        if (a.data[i]) {
            printf("%d\n", prod(w.data[i], coef1, M));
        } else {
            printf("%d\n", prod(w.data[i], coef2, M));
        }
    }
    
    free_vi(&a);
    free_vi(&w);
    free_vi(&probs);
    free_vi(&id4);
    free_vi(&id29);
    
    return 0;
}
