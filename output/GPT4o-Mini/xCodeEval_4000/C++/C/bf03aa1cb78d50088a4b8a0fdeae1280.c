#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAX_LEN 1111
#define MAXN 100001

typedef struct {
    int *data;
    size_t size;
} Permutation;

void init_permutation(Permutation *p, size_t size) {
    p->size = size;
    p->data = (int *)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        p->data[i] = i;
    }
}

void free_permutation(Permutation *p) {
    free(p->data);
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
            log[k - l] = '0';
            b[k++] = a[i++];
        } else {
            log[k - l] = '1';
            b[k++] = a[j++];
        }
    }
    while (i < m) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int p = l; p < r; ++p) {
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
    
    int left[MAX_LEN], right[MAX_LEN];
    int left_size = 0, right_size = 0;
    
    for (int i = mid - 1; i >= l; --i) {
        left[left_size++] = p[i];
    }
    for (int i = r - 1; i >= mid; --i) {
        right[right_size++] = p[i];
    }
    
    int pos = l;
    while (left_size > 0 && right_size > 0) {
        if (strlen(s) == 0) {
            return false;
        }
        char ch = s[strlen(s) - 1];
        s[strlen(s) - 1] = '\0';

        if (ch == '1') {
            p[pos++] = right[--right_size];
        } else {
            p[pos++] = left[--left_size];
        }
    }
    while (left_size > 0) {
        p[pos++] = left[--left_size];
    }
    while (right_size > 0) {
        p[pos++] = right[--right_size];
    }
    return true;
}

void solve() {
    char s[MAX_LEN];
    scanf("%s", s);
    strrev(s);

    int L = 1, R = MAX_LEN;
    while (R - L > 1) {
        int len = (L + R) / 2;
        Permutation p;
        init_permutation(&p, len);
        char tmp[MAX_LEN];
        strcpy(tmp, s);
        bool recovered = try_recover(0, len, tmp, p.data);
        if (recovered) {
            if (strlen(tmp) == 0) {
                int ans[MAX_LEN];
                for (int i = 0; i < len; ++i) {
                    ans[p.data[i]] = i;
                }
                printf("%d\n", len);
                for (int i = 0; i < len; ++i) {
                    printf("%d ", ans[i] + 1);
                }
                printf("\n");
                free_permutation(&p);
                return;
            }
            L = len;
        } else {
            R = len;
        }
        free_permutation(&p);
    }
    assert(false);
}

int main() {
    solve();
    return 0;
}
