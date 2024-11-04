#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AL 26
#define N 100013

int n;
char s[N];
int m;
int t[N];

void read() {
    scanf("%s", s);
    n = strlen(s);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        int tmp = 0;
        for (int j = 0; s[j] != '\0'; j++) {
            tmp |= (1 << (s[j] - 'a'));
        }
        t[i] = tmp;
    }
}

int nxt[N][AL];
int cnt[N], mx[N];
int masks[N], mask_cnt;

void solve() {
    for (int i = 0; i < AL; i++) {
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < AL; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
    }

    mask_cnt = 0;
    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < mask_cnt; j++) {
            if (masks[j] == t[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            masks[mask_cnt++] = t[i];
        }
    }

    memset(cnt, 0, sizeof(cnt));
    memset(mx, -1, sizeof(mx));

    for (int i = 0; i < n; i++) {
        int lst = i;
        int cur = (1 << (s[lst] - 'a'));
        while (1) {
            int mn = n;
            for (int j = 0; j < AL; j++) {
                if (!((cur >> j) & 1)) {
                    mn = (mn < nxt[lst][j]) ? mn : nxt[lst][j];
                }
            }
            for (int j = 0; j < mask_cnt; j++) {
                if (cur == masks[j]) {
                    if (mx[j] != mn - 1) {
                        mx[j] = mn - 1;
                        cnt[j]++;
                    }
                    break;
                }
            }
            if (mn == n) {
                break;
            }
            lst = mn;
            cur |= (1 << (s[lst] - 'a'));
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < mask_cnt; j++) {
            if (t[i] == masks[j]) {
                printf("%d\n", cnt[j]);
                break;
            }
        }
    }
}

int main() {
    while (1) {
        if (!read()) {
            break;
        }
        solve();
    }
    return 0;
}
