#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>

#define MAXN 100001

typedef struct {
    int *data;
    size_t size;
} Vector;

void vector_init(Vector *v, size_t size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
    memset(v->data, 0, size * sizeof(int));
}

void vector_free(Vector *v) {
    free(v->data);
}

void merge(int *a, int *b, int l, int r, char *log) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    merge(a, b, l, m, log);
    merge(a, b, m, r, log);
    int i = l, j = m, k = l;

    while (i < m && j < r) {
        if (a[i] < a[j]) {
            log[k++] = '0';
            b[k] = a[i++];
        } else {
            log[k++] = '1';
            b[k] = a[j++];
        }
    }
    while (i < m) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int p = l; p < r; p++) {
        a[p] = b[p];
    }
}

bool try_recover(int l, int r, char *s, int *p) {
    if (r - l <= 1) {
        return true;
    }
    int mid = (l + r) / 2;
    if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
        return false;
    }
    Vector left, right;
    vector_init(&left, mid - l);
    vector_init(&right, r - mid);
    
    for (int i = mid - 1; i >= l; i--) {
        left.data[mid - 1 - i] = p[i];
    }
    for (int i = r - 1; i >= mid; i--) {
        right.data[r - 1 - i] = p[i];
    }
    int pos = l;
    while (left.size > 0 && right.size > 0) {
        if (strlen(s) == 0) {
            vector_free(&left);
            vector_free(&right);
            return false;
        }
        char ch = s[strlen(s) - 1];
        s[strlen(s) - 1] = '\0';

        if (ch == '1') {
            p[pos++] = right.data[--right.size];
        } else {
            p[pos++] = left.data[--left.size];
        }
    }
    while (left.size > 0) {
        p[pos++] = left.data[--left.size];
    }
    while (right.size > 0) {
        p[pos++] = right.data[--right.size];
    }
    vector_free(&left);
    vector_free(&right);
    return true;
}

void solve() {
    char s[100001];
    scanf("%s", s);
    strrev(s);

    int L = 1;
    int R = 1111;
    while (R - L > 1) {
        int len = (L + R) / 2;
        int *p = (int *)malloc(len * sizeof(int));
        char *tmp = strdup(s);
        bool recovered = try_recover(0, len, tmp, p);
        if (recovered) {
            if (strlen(tmp) == 0) {
                int *ans = (int *)malloc(len * sizeof(int));
                for (int i = 0; i < len; i++) {
                    ans[p[i]] = i;
                }
                printf("%d\n", len);
                for (int x = 0; x < len; x++) {
                    printf("%d ", ans[x] + 1);
                }
                printf("\n");
                free(ans);
                free(p);
                free(tmp);
                return;
            }
            L = len;
        } else {
            R = len;
        }
        free(p);
        free(tmp);
    }
    assert(false);
}

int main() {
    solve();
    return 0;
}
