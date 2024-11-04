#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1111

void merge(int* a, int* b, int l, int m, int r) {
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
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

void mergeSort(int* a, int* b, int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(a, b, l, m);
    mergeSort(a, b, m, r);
    merge(a, b, l, m, r);
}

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void solve() {
    char s[MAX_LEN];
    scanf("%s", s);
    reverse(s);

    int L = 1;
    int R = MAX_LEN;
    while (R - L > 1) {
        int len = (L + R) / 2;
        int* p = (int*)malloc(len * sizeof(int));
        int* tmp = (int*)malloc(len * sizeof(int));
        for (int i = 0; i < len; i++) {
            p[i] = i;
        }
        char* str = strdup(s);
        int recovered = 1;
        for (int i = 0; i < len; i++) {
            if (str[i] == '1') {
                int j = i;
                while (j < len && str[j] == '1') {
                    j++;
                }
                if (j == len) {
                    recovered = 0;
                    break;
                }
                mergeSort(p, tmp, i, j + 1);
                i = j;
            }
        }
        if (recovered) {
            if (strlen(str) == 0) {
                printf("%d\n", len);
                for (int i = 0; i < len; i++) {
                    printf("%d ", p[i] + 1);
                }
                printf("\n");
                return;
            }
            L = len;
        } else {
            R = len;
        }
        free(p);
        free(tmp);
        free(str);
    }
}

int main() {
    solve();
    return 0;
}
