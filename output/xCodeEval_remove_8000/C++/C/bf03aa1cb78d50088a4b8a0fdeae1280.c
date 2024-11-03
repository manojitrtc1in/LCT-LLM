#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 100001

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

bool try_recover(int l, int r, char* s, int* p) {
    if (r - l <= 1) {
        return true;
    }
    int mid = (l + r) / 2;
    if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
        return false;
    }
    int left[MAXN], right[MAXN];
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
    char s[MAXN];
    scanf("%s", s);
    reverse(s);

    int L = 1;
    int R = 1111;
    while (R - L > 1) {
        int len = (L + R) / 2;
        int p[MAXN];
        for (int i = 0; i < len; i++) {
            p[i] = i;
        }
        char tmp[MAXN];
        strcpy(tmp, s);
        bool recovered = try_recover(0, len, tmp, p);
        if (recovered) {
            if (strlen(tmp) == 0) {
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
    }
}

int main() {
    solve();
    return 0;
}
