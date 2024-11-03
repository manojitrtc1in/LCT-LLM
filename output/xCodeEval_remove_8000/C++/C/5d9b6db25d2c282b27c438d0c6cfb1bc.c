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

bool try_recover(int l, int r, char* s, int* p) {
    if (r - l <= 1) {
        return true;
    }
    int mid = (l + r) / 2;
    if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
        return false;
    }
    int left[MAX_LEN], right[MAX_LEN];
    int left_len = 0, right_len = 0;
    for (int i = mid - 1; i >= l; i--) {
        left[left_len++] = p[i];
    }
    for (int i = r - 1; i >= mid; i--) {
        right[right_len++] = p[i];
    }
    int pos = l;
    while (left_len > 0 && right_len > 0) {
        if (strlen(s) == 0) {
            return false;
        }
        char ch = s[strlen(s) - 1];
        s[strlen(s) - 1] = '\0';

        if (ch == '1') {
            p[pos++] = right[--right_len];
        } else {
            p[pos++] = left[--left_len];
        }
    }
    while (left_len > 0) {
        p[pos++] = left[--left_len];
    }
    while (right_len > 0) {
        p[pos++] = right[--right_len];
    }
    return true;
}

void solve() {
    char s[MAX_LEN];
    scanf("%s", s);
    reverse(s);

    int p[MAX_LEN];
    for (int len = 2; len <= MAX_LEN; len++) {
        for (int i = 0; i < len; i++) {
            p[i] = i;
        }
        char tmp[MAX_LEN];
        strcpy(tmp, s);
        if (try_recover(0, len, tmp, p) && strlen(tmp) == 0) {
            printf("%d\n", len);
            for (int i = 0; i < len; i++) {
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
