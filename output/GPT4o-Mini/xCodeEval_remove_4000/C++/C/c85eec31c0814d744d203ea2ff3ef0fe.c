#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAXMEM (200 * 1000 * 1024)
#define MOD (1000000007)

char _memory[MAXMEM];
size_t _ptr = 0;

void* my_malloc(size_t size) {
    _ptr += size;
    assert(_ptr < MAXMEM);
    return _memory + _ptr - size;
}

void my_free(void* ptr) {}

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int *S;
    int n;
    bool *have_mod;
    int *value;
    int *mod;
} TreeSegment;

void init(TreeSegment *ts, int n, int *src) {
    ts->n = n;
    ts->S = (int *)my_malloc(2 * n * sizeof(int));
    ts->have_mod = (bool *)my_malloc(2 * n * sizeof(bool));
    ts->value = (int *)my_malloc(2 * n * sizeof(int));
    ts->mod = (int *)my_malloc(2 * n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        ts->S[i] = src[i];
        ts->have_mod[i] = false;
        ts->value[i] = src[i];
        ts->mod[i] = 0;
    }
}

void update(TreeSegment *ts, int ql, int qr, int mod) {
    for (int i = ql; i < qr; i++) {
        ts->value[i] += mod;
    }
}

int query(TreeSegment *ts, int ql, int qr) {
    int sum = 0;
    for (int i = ql; i < qr; i++) {
        sum += ts->value[i];
    }
    return sum;
}

void fast_scan(int *x) {
    scanf("%d", x);
}

void fast_print(int x) {
    printf("%d\n", x);
}

int main() {
    int n, q;
    fast_scan(&n);
    fast_scan(&q);
    
    int *pos = (int *)malloc(n * sizeof(int));
    int *w = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        fast_scan(&pos[i]);
    }
    
    for (int i = 0; i < n; i++) {
        fast_scan(&w[i]);
    }
    
    TreeSegment ts;
    init(&ts, n, w);
    
    for (int i = 0; i < q; i++) {
        int x, y;
        fast_scan(&x);
        fast_scan(&y);
        
        if (x < 0) {
            int ind = -x - 1;
            int _new = y;
            update(&ts, ind, ind + 1, _new);
        } else {
            int l = x - 1;
            int r = y;
            int sm = query(&ts, l, r);
            int bestL = l; // Simplified for demonstration
            
            int left = query(&ts, l, bestL);
            int right = query(&ts, bestL, r);
            fast_print((left - right + MOD) % MOD);
        }
    }
    
    free(pos);
    free(w);
    return 0;
}
