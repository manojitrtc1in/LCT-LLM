#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int first;
    int second;
} pii;

char s[1010101];
pii tr[1010101];

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
            tr[cur].first = 0;
            tr[cur].second = 1;
        } else {
            tr[cur].first = 1;
            tr[cur].second = 0;
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
    if (x > r || y < l) {
        pii empty = {0, 0};
        return empty;
    }
    if (x <= l && r <= y) {
        return tr[cur];
    }
    int m = (l + r) / 2;
    int dcur = cur + cur;
    return merge(get(dcur, l, m, x, y), get(dcur + 1, m + 1, r, x, y));
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    scanf("%s", s + n);
    int sn = strlen(s);
    build(1, 0, sn - 1);
    int q;
    scanf("%d", &q);
    char ans[1010101];
    int ansIndex = 0;
    while (q--) {
        int l[2], r[2];
        for (int i = 0; i < 2; i++) {
            scanf("%d %d", &l[i], &r[i]);
            l[i]--;
            r[i]--;
        }
        l[1] += n;
        r[1] += n;
        pii a = get(1, 0, sn - 1, l[0], r[0]);
        pii b = get(1, 0, sn - 1, l[1], r[1]);
        if (a.first > b.first || a.first % 2 != b.first % 2 || a.second < b.second) {
            ans[ansIndex++] = '0';
            continue;
        }
        ans[ansIndex++] = ((a.first == b.first && a.second % 3 == b.second % 3) ||
                (a.first != b.first && a.first > 0) ||
                (a.second > b.second && a.first != b.first)) ? '1' : '0';
    }
    ans[ansIndex] = '\0';
    printf("%s\n", ans);
    return 0;
}
