#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} pii;

pii tr[1010101];
char s[2020202];

pii merge(pii a, pii b) {
    if (b.first == 0) {
        a.second += b.second;
        return a;
    } else {
        b.first += a.first;
        return b;
    }
}

void build(int cur, int l, int r) {
    if (l == r) {
        if (s[l] == 'A') {
            tr[cur] = (pii){0, 1};
        } else {
            tr[cur] = (pii){1, 0};
        }
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        build(dcur, l, m);
        build(dcur + 1, m + 1, r);
        tr[cur] = merge(tr[dcur], tr[dcur + 1]);
    }
}

pii get(int cur, int l, int r, int x, int y) {
    if (x > r || y < l) return (pii){0, 0};
    if (x <= l && r <= y) return tr[cur];
    int m = (l + r) / 2;
    int dcur = cur + cur;
    return merge(get(dcur, l, m, x, y), get(dcur + 1, m + 1, r, x, y));
}

int solve() {
    char t[1010101];
    scanf("%s %s", s, t);
    int n = strlen(s);
    strcat(s, t);
    int sn = strlen(s);
    build(1, 0, sn - 1);
    int q;
    scanf("%d", &q);
    char ans[1010101] = {0};
    while (q--) {
        int l[2], r[2];
        for (int i = 0; i < 2; i++) {
            scanf("%d %d", &l[i], &r[i]);
            l[i] += n;
            r[i] += n;
            l[i]--;
            r[i]--;
        }
        pii a = get(1, 0, sn - 1, l[0], r[0]);
        pii b = get(1, 0, sn - 1, l[1], r[1]);
        if (a.first > b.first || a.first % 2 != b.first % 2 || a.second < b.second) {
            strcat(ans, "0");
            continue;
        }
        strcat(ans, ((a.first == b.first && a.second % 3 == b.second % 3) ||
                      (a.first != b.first && a.first > 0) ||
                      (a.second > b.second && a.first != b.first)) ? "1" : "0");
    }
    printf("%s\n", ans);
    return 0;
}

int main() {
    return solve();
}
