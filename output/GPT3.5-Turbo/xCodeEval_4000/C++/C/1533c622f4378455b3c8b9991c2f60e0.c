#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int X;
    int Y;
} pii;

int count_tro(int r) {
    int ans = 0;
    while (r) {
        ++ans;
        r >>= 1;
    }
    return ans;
}

pii unite_seg(const pii p1, const pii p2, const int n) {
    if ((p1.X == -1) || (p2.X == -1))
        return (pii) {-1, -1};
    pii np1 = {0, (p1.Y - p1.X) % n};
    pii np2 = {(p2.X - p1.X) % n, (p2.Y - p1.X) % n};
    if (np2.X <= np2.Y) {
        if (np2.Y == n - 1)
            return (pii) {-1, -1};
        else
            return (pii) {(np1.X + p1.X) % n, (np1.Y > np2.Y ? np1.Y : np2.Y) + p1.X};
    } else {
        if (np2.X <= np1.Y + 1)
            return (pii) {-1, -1};
        else
            return (pii) {(np2.X + p1.X) % n, (np1.Y > np2.Y ? np1.Y : np2.Y) + p1.X};
    }
}

typedef struct {
    int n;
    pii** sp;
} sparse;

void construct(sparse* s, pii* v, int size) {
    s->n = size;
    int r = count_tro(size - 1);
    s->sp = (pii**) malloc(r * sizeof(pii*));
    for (int i = 0; i < r; ++i) {
        s->sp[i] = (pii*) malloc(size * sizeof(pii));
        for (int j = 0; j < size; ++j) {
            s->sp[i][j] = v[j];
        }
    }
    for (int i = 1; i < r; ++i) {
        for (int j = 0; j < size; ++j) {
            pii p1 = s->sp[i - 1][j];
            pii p2 = s->sp[i - 1][(j + (1 << (i - 1))) % size];
            s->sp[i][j] = unite_seg(p1, p2, size);
        }
    }
}

pii segment(sparse* s, int l, int r) {
    if ((l == -1) || (r == -1))
        return (pii) {-1, -1};
    int szz = (r - l + s->n) % s->n;
    if (l == r)
        return s->sp[0][l];
    int g = count_tro(szz) - 1;
    return unite_seg(s->sp[g][l], s->sp[g][((r + 1 - (1 << g)) % s->n + s->n) % s->n], s->n);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int* r = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &r[i]);
    }
    int zz = count_tro(n) + 1;
    sparse* v = (sparse*) malloc(zz * sizeof(sparse));
    pii* prs = (pii*) malloc(n * sizeof(pii));
    for (int i = 0; i < n; ++i) {
        if (r[i] >= n - 1)
            prs[i] = (pii) {-1, -1};
        else
            prs[i] = unite_seg((pii) {((i - r[i]) % n + n) % n, i}, (pii) {i, (i + r[i]) % n}, n);
    }
    construct(&v[0], prs, n);
    for (int i = 1; i < zz; ++i) {
        pii* new_prs = (pii*) malloc(n * sizeof(pii));
        for (int j = 0; j < n; ++j) {
            pii pairr = segment(&v[i - 1], j, j);
            new_prs[j] = segment(&v[i - 1], pairr.X, pairr.Y);
        }
        construct(&v[i], new_prs, n);
        free(new_prs);
    }
    for (int i = 0; i < n; ++i) {
        pii my_pr = {i, i};
        int ans = 0;
        for (int j = zz - 1; j >= 0; --j) {
            pii new_pr = segment(&v[j], my_pr.X, my_pr.Y);
            if (new_pr.X != -1) {
                ans += (1 << j);
                my_pr = new_pr;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");
    free(r);
    free(v);
    free(prs);
    return 0;
}
