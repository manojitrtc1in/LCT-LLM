#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1111

void merge(int* a, int* b, char* log, int l, int m, int r) {
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (a[i] < a[j]) {
            log[k - l] = '0';
            b[k] = a[i];
            i++;
        } else {
            log[k - l] = '1';
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i < m) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j < r) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int p = l; p < r; p++) {
        a[p] = b[p];
    }
}

void merge_sort(int* a, int* b, char* log, int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort(a, b, log, l, m);
    merge_sort(a, b, log, m, r);
    merge(a, b, log, l, m, r);
}

char* check(int* a, int n) {
    int* b = (int*)malloc(n * sizeof(int));
    char* log = (char*)malloc((n - 1) * sizeof(char));

    merge_sort(a, b, log, 0, n);

    free(b);
    return log;
}

int try_recover(int l, int r, char* s, int* p) {
    if (r - l <= 1) {
        return 1;
    }
    int mid = (l + r) / 2;
    if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
        return 0;
    }
    int* left = (int*)malloc((mid - l) * sizeof(int));
    int* right = (int*)malloc((r - mid) * sizeof(int));
    int pos = l;
    while (pos < mid && pos < r) {
        if (*s == '1') {
            right[pos - mid] = p[pos];
        } else {
            left[pos - l] = p[pos];
        }
        pos++;
        s++;
    }
    while (pos < mid) {
        left[pos - l] = p[pos];
        pos++;
    }
    while (pos < r) {
        right[pos - mid] = p[pos];
        pos++;
    }
    pos = l;
    for (int i = 0; i < mid - l; i++) {
        p[pos] = left[i];
        pos++;
    }
    for (int i = 0; i < r - mid; i++) {
        p[pos] = right[i];
        pos++;
    }
    free(left);
    free(right);
    return 1;
}

void solve() {
    char s[MAX_LEN];
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 2; i <= MAX_LEN; i++) {
        int* p = (int*)malloc(i * sizeof(int));
        for (int j = 0; j < i; j++) {
            p[j] = j;
        }
        char* tmp = strdup(s);
        if (try_recover(0, i, tmp, p) && tmp[0] == '\0') {
            printf("%d\n", i);
            for (int j = 0; j < i; j++) {
                printf("%d ", p[j] + 1);
            }
            printf("\n");
            free(p);
            free(tmp);
            return;
        }
        free(p);
        free(tmp);
    }
}

int main() {
    solve();
    return 0;
}
