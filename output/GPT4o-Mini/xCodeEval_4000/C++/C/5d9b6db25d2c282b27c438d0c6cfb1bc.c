#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAX_LEN 1111
#define MIN_LEN 2

typedef struct {
    int *data;
    size_t size;
} Permutation;

void init_permutation(Permutation *p, size_t size) {
    p->size = size;
    p->data = (int *)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
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
            log[k++] = '0';
            b[k - 1] = a[i++];
        } else {
            log[k++] = '1';
            b[k - 1] = a[j++];
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

char* check(int *a, int n) {
    int *b = (int *)malloc(n * sizeof(int));
    char *log = (char *)malloc(n * sizeof(char));
    merge(a, b, 0, n, log);
    free(b);
    return log;
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
    
    for (int i = mid - 1; i >= l; i--) {
        left[left_size++] = p[i];
    }
    for (int i = r - 1; i >= mid; i--) {
        right[right_size++] = p[i];
    }
    
    int pos = l;
    while (left_size > 0 && right_size > 0) {
        if (strlen(s) == 0) {
            return false;
        }
        char ch = s[strlen(s) - 1];
        s[strlen(s) - 1] = '\0'; // Remove last character

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
    int len = strlen(s);
    char *reversed_s = (char *)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        reversed_s[i] = s[len - 1 - i];
    }
    reversed_s[len] = '\0';

    for (int length = MIN_LEN; length <= MAX_LEN; length++) {
        Permutation p;
        init_permutation(&p, length);
        char *tmp = strdup(reversed_s);
        if (try_recover(0, length, tmp, p.data) && strlen(tmp) == 0) {
            printf("%d\n", length);
            for (int i = 0; i < length; i++) {
                printf("%d ", p.data[i] + 1);
            }
            printf("\n");
            free(tmp);
            free_permutation(&p);
            free(reversed_s);
            return;
        }
        free(tmp);
        free_permutation(&p);
    }
    free(reversed_s);
}

int main() {
    solve();
    return 0;
}
