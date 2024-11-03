#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 1111

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void merge(int* a, int* b, int l, int m, int r, char* log) {
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

void mergeSort(int* a, int* b, int l, int r, char* log) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(a, b, l, m, log);
    mergeSort(a, b, m, r, log);
    merge(a, b, l, m, r, log);
}

bool tryRecover(int l, int r, char* s, int* p) {
    if (r - l <= 1) {
        return true;
    }
    int mid = (l + r) / 2;
    if (!tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p)) {
        return false;
    }
    int left[MAX_LEN];
    int right[MAX_LEN];
    int pos = l;
    int leftPos = 0;
    int rightPos = 0;
    while (leftPos < mid - l && rightPos < r - mid) {
        char ch = s[strlen(s) - 1];
        s[strlen(s) - 1] = '\0';
        if (ch == '1') {
            p[pos] = right[rightPos];
            rightPos++;
        } else {
            p[pos] = left[leftPos];
            leftPos++;
        }
        pos++;
    }
    while (leftPos < mid - l) {
        p[pos] = left[leftPos];
        leftPos++;
        pos++;
    }
    while (rightPos < r - mid) {
        p[pos] = right[rightPos];
        rightPos++;
        pos++;
    }
    return true;
}

void solve() {
    char s[MAX_LEN];
    scanf("%s", s);
    reverse(s);

    int len = strlen(s);
    int p[MAX_LEN];
    for (int i = 0; i < len; i++) {
        p[i] = i;
    }

    for (int l = 2; l <= len; l++) {
        int a[MAX_LEN];
        for (int i = 0; i < l; i++) {
            a[i] = p[i];
        }
        char log[MAX_LEN];
        mergeSort(a, p, 0, l, log);
        log[l] = '\0';
        char tmp[MAX_LEN];
        strcpy(tmp, s);
        if (tryRecover(0, l, tmp, p) && strlen(tmp) == 0) {
            printf("%d\n", l);
            for (int i = 0; i < l; i++) {
                printf("%d ", p[i] + 1);
            }
            printf("\n");
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}
