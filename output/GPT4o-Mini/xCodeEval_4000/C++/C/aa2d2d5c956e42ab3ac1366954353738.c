#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define AL 26
#define N 1000000 + 13

int n;
char s[N];
int m;
int t[N];

int nxt[N][AL];
int cnt[N], mx[N];
int masks[3274813];

int read() {
    if (scanf("%s", s) != 1)
        return 0;
    n = strlen(s);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char buf[N];
        scanf("%s", buf);
        int x = 0;
        for (int j = 0; j < strlen(buf); j++)
            x |= (1 << (buf[j] - 'a'));
        t[i] = x;
    }
    return 1;
}

void solve() {
    for (int i = 0; i < AL; i++) nxt[n][i] = n;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < AL; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }

    memset(masks, -1, sizeof(masks));
    for (int i = 0; i < m; i++) {
        if (masks[t[i]] == -1) {
            masks[t[i]] = i;
        }
    }

    memset(cnt, 0, sizeof(cnt));
    memset(mx, -1, sizeof(mx));

    for (int i = 0; i < n; i++) {
        int lst = i;
        int cur = (1 << (s[lst] - 'a'));
        while (1) {
            int mn = n;
            for (int j = 0; j < AL; j++) if (!((cur >> j) & 1))
                mn = (mn < nxt[lst][j]) ? mn : nxt[lst][j];
            if (masks[cur] != -1) {
                int x = masks[cur];
                if (mx[x] != mn - 1) {
                    mx[x] = mn - 1;
                    ++cnt[x];
                }
            }
            if (mn == n)
                break;
            lst = mn;
            cur |= (1 << (s[lst] - 'a'));
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d\n", cnt[masks[t[i]]]);
}

int main() {
    while (read()) {
        solve();
    }
}
