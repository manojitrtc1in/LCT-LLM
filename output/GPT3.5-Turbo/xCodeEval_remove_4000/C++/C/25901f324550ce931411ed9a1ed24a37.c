#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef struct {
    int x;
    int y;
    int z;
} pa3;

typedef struct {
    int x;
    int y;
    int z;
    int w;
} pa4;

typedef struct {
    int x;
    int y;
} pa2;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

int gcd(int v, int b) {
    if (v == 0)
        return b;
    if (b == 0)
        return v;
    if (v > b)
        return gcd(b, v);
    if (v == b)
        return b;
    if (b % v == 0)
        return v;
    return gcd(v, b % v);
}

int mod;
int id8(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int d = id8(b, a % b, y, x);
    *y -= a / b * (*x);
    return d;
}

pa2 operator+(const pa2 *l, const pa2 *r) {
    pa2 res;
    res.x = l->x + r->x;
    res.y = l->y + r->y;
    return res;
}

pa2 operator-(const pa2 *l, const pa2 *r) {
    pa2 res;
    res.x = l->x - r->x;
    res.y = l->y - r->y;
    return res;
}

typedef struct {
    int beki;
    int cor;
    int **vec;
    int *lo;
} Sparsetable_min;

void shoki1(Sparsetable_min *st) {
    int i, j;
    st->vec = (int **)malloc((st->beki + 1) * sizeof(int *));
    for (i = 0; i <= st->beki; i++) {
        st->vec[i] = (int *)malloc(st->cor * sizeof(int));
    }
    st->lo = (int *)malloc((st->cor + 1) * sizeof(int));
    st->lo[0] = -1;
    for (i = 1; i <= st->cor; i++) {
        st->lo[i] = st->lo[i >> 1] + 1;
    }
}

void shoki2(Sparsetable_min *st) {
    int i, j;
    for (i = 1; i <= st->beki; i++) {
        for (j = 0; j < st->cor; j++) {
            if ((j + (1 << (i - 1))) < st->cor) {
                st->vec[i][j] = min(st->vec[i - 1][j], st->vec[i - 1][j + (1 << (i - 1))]);
            } else {
                st->vec[i][j] = st->vec[i - 1][j];
            }
        }
    }
}

int rangemin(Sparsetable_min *st, int i, int j) {
    int haba = st->lo[j - i];
    return min(st->vec[haba][i], st->vec[haba][j - (1 << haba)]);
}

typedef struct {
    char *STR;
    int *S;
    int *SL;
    pa2 *haba;
    int *SA;
    int *rank;
    int *LCP;
    int id3;
    int len;
} SAIS;

void make_suffix_array_string(SAIS *ss, char *str) {
    int i, j, cnt;
    ss->STR = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(ss->STR, str);
    set<char> setc;
    map<char, int> mapc;
    for (i = 0; i < strlen(str); i++) {
        setc.insert(str[i]);
    }
    cnt = 1;
    for (auto it = setc.begin(); it != setc.end(); it++) {
        mapc[*it] = cnt;
        cnt++;
    }
    ss->S = (int *)malloc((strlen(str) + 1) * sizeof(int));
    for (i = 0; i < strlen(str); i++) {
        ss->S[i] = mapc[str[i]];
    }
    ss->id3 = cnt;
    ss->S[strlen(str)] = 0;
    make_suffix_array_naibu(ss);
}

void make_suffix_array_saiki(SAIS *ss, int *ve, int id0) {
    int i;
    ss->S = (int *)malloc((strlen(str) + 1) * sizeof(int));
    for (i = 0; i < strlen(str); i++) {
        ss->S[i] = ve[i];
    }
    ss->id3 = id0 + 1;
    ss->S[strlen(str)] = 0;
    make_suffix_array_naibu(ss);
}

void make_suffix_array_naibu(SAIS *ss) {
    int i, j, cnt, len, id7, id2, rt, e1, e2;
    cnt = ss->id3;
    len = strlen(ss->STR);
    ss->haba = (pa2 *)malloc((cnt + 1) * sizeof(pa2));
    ss->haba[0].x = 0;
    ss->haba[0].y = 0;
    for (i = 1; i <= cnt; i++) {
        ss->haba[i].x = ss->haba[i - 1].y + 1;
        ss->haba[i].y = ss->haba[i - 1].y + kosuu[i];
    }
    ss->SL = (int *)malloc(len * sizeof(int));
    for (i = len - 1; i >= 0; i--) {
        if (i == len - 1) {
            ss->SL[i] = 1;
        } else {
            if (ss->S[i] < ss->S[i + 1]) {
                ss->SL[i] = 1;
            } else if (ss->S[i] > ss->S[i + 1]) {
                ss->SL[i] = 0;
            } else {
                ss->SL[i] = ss->SL[i + 1];
            }
        }
    }
    id7 = 0;
    vector<int> LMS;
    vector<int> id6(len, 0);
    rt = 0;
    for (i = 1; i < len; i++) {
        if (ss->SL[i - 1] == 0 && ss->SL[i] == 1) {
            LMS.push_back(i);
            id6[i] = rt;
            id7++;
            rt++;
        }
    }
    for (i = 0; i < id7 - 1; i++) {
        ss->SL[LMS[i]] = -(LMS[i + 1] - LMS[i] + 1);
    }
    ss->SL[len - 1] = -1;
    ss->SA = (int *)malloc(len * sizeof(int));
    int *pos = (int *)malloc(cnt * sizeof(int));
    for (i = 0; i < len; i++) {
        ss->SA[i] = -1;
    }
    for (i = 0; i < cnt; i++) {
        pos[i] = 0;
    }
    for (i = 0; i < len; i++) {
        if (ss->SL[i] < 0) {
            ss->SA[ss->haba[ss->S[i]].y - pos[ss->S[i]]] = i;
            pos[ss->S[i]]++;
        }
    }
    induced_sort(ss->SA, len, cnt);
    vector<pa> id1;
    for (i = 0; i < len; i++) {
        if (ss->SL[ss->SA[i]] < 0) {
            if (i == 0) {
                id1.push_back({ss->SA[i], 1});
            } else if (id1.back().y == 1) {
                id1.push_back({ss->SA[i], 2});
            } else if (ss->SL[ss->SA[id2]] != ss->SL[ss->SA[i]]) {
                id1.push_back({ss->SA[i], id1.back().y + 1});
            } else {
                int id5 = -ss->SL[ss->SA[id2]];
                bool bo = true;
                for (j = 0; j < id5; j++) {
                    if (ss->S[ss->SA[id2] + j] != ss->S[ss->SA[i] + j]) {
                        bo = 0;
                        break;
                    }
                }
                if (bo) {
                    id1.push_back({ss->SA[i], id1.back().y});
                } else {
                    id1.push_back({ss->SA[i], id1.back().y + 1});
                }
            }
            id2 = i;
        }
    }
    for (i = 0; i < cnt; i++) {
        pos[i] = 0;
    }
    for (i = 0; i < len; i++) {
        ss->SA[i] = -1;
    }
    if (id7 == id1.back().y) {
        for (i = id7 - 1; i >= 0; i--) {
            int c = id1[i].x;
            ss->SA[ss->haba[ss->S[c]].y - pos[ss->S[c]]] = c;
            pos[ss->S[c]]++;
        }
    } else {
        vector<int> rec(LMS.size());
        for (i = 0; i < id7; i++) {
            rec[id6[id1[i].x]] = id1[i].y;
        }
        SAIS id4;
        make_suffix_array_saiki(&id4, rec, id1.back().y);
        for (i = id7; i > 0; i--) {
            int c = LMS[id4.SA[i]];
            ss->SA[ss->haba[ss->S[c]].y - pos[ss->S[c]]] = c;
            pos[ss->S[c]]++;
        }
    }
    induced_sort(ss->SA, len, cnt);
    ss->rank = (int *)malloc(len * sizeof(int));
    for (i = 0; i < len; i++) {
        ss->rank[ss->SA[i]] = i;
    }
}

void induced_sort(int *ve, int len, int cnt) {
    int i, j;
    int *ue = (int *)malloc(cnt * sizeof(int));
    for (i = 0; i < cnt; i++) {
        ue[i] = 0;
    }
    for (i = 0; i < len; i++) {
        if (ve[i] == -1)
            continue;
        if (ve[i] == 0)
            continue;
        if (SL[ve[i] - 1] == 0) {
            ve[haba[S[ve[i] - 1]].x + ue[S[ve[i] - 1]]] = ve[i] - 1;
            ue[S[ve[i] - 1]]++;
        }
        if (SL[ve[i]] < 0 && i > 0)
            ve[i] = -1;
    }
    for (i = 0; i < cnt; i++) {
        ue[i] = 0;
    }
    for (i = len - 1; i >= 0; i--) {
        if (ve[i] == -1)
            continue;
        if (ve[i] == 0)
            continue;
        if (SL[ve[i] - 1] != 0) {
            ve[haba[S[ve[i] - 1]].y - ue[S[ve[i] - 1]]] = ve[i] - 1;
            ue[S[ve[i] - 1]]++;
        }
    }
    for (i = 0; i < len; i++) {
        if (ve[i] == -1)
            assert(0);
    }
}

void make_lcp(SAIS *ss) {
    int i, j, h;
    ss->LCP = (int *)malloc(ss->len * sizeof(int));
    h = 0;
    ss->LCP[0] = 0;
    for (i = 0; i < ss->len - 1; i++) {
        j = ss->SA[ss->rank[i] - 1];
        if (h > 0)
            h--;
        for (; j + h < ss->len - 1 && i + h < ss->len - 1; h++) {
            if (ss->S[j + h] != ss->S[i + h])
                break;
        }
        ss->LCP[ss->rank[i] - 1] = h;
    }
}

int lower_bound(SAIS *ss, char *p) {
    int m = strlen(p);
    int ue = ss->len, si = 0, me;
    while (ue - si > 1) {
        me = (ue + si) / 2;
        if (strcmp(ss->STR + ss->SA[me], p) < 0)
            si = me;
        else
            ue = me;
    }
    return ue;
}

int exist(SAIS *ss, char *p) {
    int l = strlen(p);
    int id = lower_bound(ss, p);
    return strcmp(ss->STR + ss->SA[id], p) == 0;
}

pa2 range(SAIS *ss, char *p) {
    pa2 res;
    res.x = lower_bound(ss, p);
    res.y = lower_bound(ss, strcat(p, "{"));
    return res;
}

int main() {
    int n, q, i, l1, l2, p, r1, r2, e;
    char s[MAXN], t[MAXN];
    scanf("%d", &n);
    scanf("%s", s);
    int *ve = (int *)malloc(n * sizeof(int));
    int cnt = 0;
    char *t = (char *)malloc(n * sizeof(char));
    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            ve[i] = cnt;
        } else {
            ve[i] = cnt;
            cnt++;
            if (i % 2)
                t[i] = 'b';
            else
                t[i] = 'a';
        }
    }
    int m = strlen(t);
    if (m == 0) {
        scanf("%d", &e);
        for (i = 0; i < e; i++)
            printf("Yes\n");
        return 0;
    }
    for (i = 0; i < m; i++)
        t[i + m] = 'a' ^ 'b' ^ t[i];
    ve[n] = cnt;
    SAIS ss;
    make_suffix_array_string(&ss, t);
    make_lcp(&ss);
    Sparsetable_min sm;
    sm.beki = 19;
    sm.cor = (1 << sm.beki);
    shoki1(&sm);
    for (i = 0; i < ss.LCP; i++)
        sm.vec[0][i] = ss.LCP[i];
    shoki2(&sm);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d%d%d", &l1, &l2, &p);
        l1--, l2--;
        r1 = l1 + p, r2 = l2 + p;
        if (ve[r1] - ve[l1] != ve[r2] - ve[l2]) {
            printf("No\n");
            continue;
        }
        if (l1 % 2 == l2 % 2) {
            if (ve[r1] == ve[l1] || ve[r1] == ve[r2]) {
                printf("Yes\n");
                continue;
            }
            int e1 = ss.rank[ve[l1]];
            int e2 = ss.rank[ve[l2]];
            if (e1 > e2)
                swap(e1, e2);
            if (rangemin(&sm, e1, e2) >= ve[r1] - ve[l1]) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            if (ve[r1] == ve[l1]) {
                printf("Yes\n");
                continue;
            }
            if (ve[r1] == ve[r2]) {
                printf("No\n");
                continue;
            }
            int e1 = ss.rank[ve[l1]];
            int e2 = ss.rank[ve[l2] + m];
            if (e1 > e2)
                swap(e1, e2);
            if (rangemin(&sm, e1, e2) >= ve[r1] - ve[l1]) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
