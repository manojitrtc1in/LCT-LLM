#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define inf 1000000007
#define EPS (1e-8)

typedef struct {
    int x, y, z;
} pa3;

typedef struct {
    int x, y, z, w;
} pa4;

typedef struct {
    int x, y;
} pa2;

typedef struct {
    int first, second;
} pa;

typedef struct {
    int *vec[20];
    int *lo;
    int beki;
    int cor;
} Sparsetable_min;

typedef struct {
    char *STR;
    int *S;
    int *SL;
    pa *haba;
    int *SA;
    int *rank;
    int *LCP;
    int mojisu;
    int len;
} SAIS;

void init_sparsetable(Sparsetable_min *sm) {
    sm->beki = 19;
    sm->cor = (1 << sm->beki);
    sm->vec[0] = (int *)malloc((sm->cor) * sizeof(int));
    sm->lo = (int *)malloc((sm->cor + 1) * sizeof(int));
    sm->lo[0] = -1;
    for (int i = 1; i <= sm->cor; i++) {
        sm->lo[i] = sm->lo[i >> 1] + 1;
    }
}

void shoki2(Sparsetable_min *sm) {
    for (int i = 1; i <= sm->beki; i++) {
        for (int j = 0; j < sm->cor; j++) {
            if ((j + (1 << (i - 1))) < sm->cor) {
                sm->vec[i][j] = (sm->vec[i - 1][j] < sm->vec[i - 1][j + (1 << (i - 1))]) ? sm->vec[i - 1][j] : sm->vec[i - 1][j + (1 << (i - 1))];
            } else {
                sm->vec[i][j] = sm->vec[i - 1][j];
            }
        }
    }
}

int rangemin(Sparsetable_min *sm, int i, int j) {
    int haba = sm->lo[j - i];
    return (sm->vec[haba][i] < sm->vec[haba][j - (1 << haba)]) ? sm->vec[haba][i] : sm->vec[haba][j - (1 << haba)];
}

void make_suffix_array_string(SAIS *ss, char *str) {
    ss->STR = str;
    int cnt = 1;
    int *mapc = (int *)malloc(256 * sizeof(int)); // Assuming ASCII
    for (int i = 0; i < 256; i++) mapc[i] = 0;

    for (char *c = str; *c; c++) {
        if (mapc[*c] == 0) {
            mapc[*c] = cnt++;
        }
    }
    for (char *c = str; *c; c++) {
        ss->S = (int *)realloc(ss->S, (ss->len + 1) * sizeof(int));
        ss->S[ss->len++] = mapc[*c];
    }
    ss->mojisu = cnt;
    ss->S[ss->len] = 0;
    // Call to make_suffix_array_naibu() would go here
}

int main() {
    int n;
    scanf("%d", &n);
    char s[100001];
    scanf("%s", s);
    int *ve = (int *)malloc(n * sizeof(int));
    int cnt = 0;
    char t[100001] = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ve[i] = cnt;
        } else {
            ve[i] = cnt;
            cnt++;
            if (i % 2) {
                strcat(t, "b");
            } else {
                strcat(t, "a");
            }
        }
    }
    int m = strlen(t);
    if (m == 0) {
        int e;
        scanf("%d", &e);
        for (int i = 0; i < e; i++) {
            printf("Yes\n");
        }
        return 0;
    }
    for (int i = 0; i < m; i++) {
        t[strlen(t)] = 'a' ^ 'b' ^ t[i];
    }
    ve[cnt] = cnt;

    SAIS ss;
    ss.S = (int *)malloc((n + 1) * sizeof(int));
    ss.len = 0;
    make_suffix_array_string(&ss, t);
    // Call to make_lcp() would go here
    Sparsetable_min sm;
    init_sparsetable(&sm);
    for (int i = 0; i < ss.len; i++) {
        sm.vec[0][i] = ss.LCP[i];
    }
    shoki2(&sm);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l1, l2, p;
        scanf("%d %d %d", &l1, &l2, &p);
        l1--, l2--;
        int r1 = l1 + p, r2 = l2 + p;
        if (ve[r1] - ve[l1] != ve[r2] - ve[l2]) {
            printf("No\n");
            continue;
        }
        if (l1 % 2 == l2 % 2) {
            if (ve[r1] == ve[l1] || ve[r1] == ve[r2]) {
                printf("Yes\n");
                continue;
            }
            // Additional logic would go here
        } else {
            if (ve[r1] == ve[l1]) {
                printf("Yes\n");
                continue;
            }
            if (ve[r1] == ve[r2]) {
                printf("No\n");
                continue;
            }
            // Additional logic would go here
        }
    }
    return 0;
}
