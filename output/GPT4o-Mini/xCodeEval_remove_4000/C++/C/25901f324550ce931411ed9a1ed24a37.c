#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

typedef struct {
    int x, y, z;
} pa3;

bool pa3_less(pa3 a, pa3 b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

bool pa3_greater(pa3 a, pa3 b) {
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    return a.z > b.z;
}

bool pa3_equal(pa3 a, pa3 b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

typedef struct {
    int x, y, z, w;
} pa4;

bool pa4_less(pa4 a, pa4 b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    if (a.z != b.z) return a.z < b.z;
    return a.w < b.w;
}

bool pa4_greater(pa4 a, pa4 b) {
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    if (a.z != b.z) return a.z > b.z;
    return a.w > b.w;
}

typedef struct {
    int x, y;
} pa2;

pa2 pa2_add(pa2 a, pa2 b) {
    return (pa2){a.x + b.x, a.y + b.y};
}

pa2 pa2_sub(pa2 a, pa2 b) {
    return (pa2){a.x - b.x, a.y - b.y};
}

bool pa2_less(pa2 a, pa2 b) {
    return a.y != b.y ? a.y < b.y : a.x < b.x;
}

bool pa2_greater(pa2 a, pa2 b) {
    return a.x != b.x ? a.x > b.x : a.y > b.y;
}

bool pa2_equal(pa2 a, pa2 b) {
    return a.x == b.x && a.y == b.y;
}

bool pa2_not_equal(pa2 a, pa2 b) {
    return !(a.x == b.x && a.y == b.y);
}

char* itos(int i) {
    char* buffer = (char*)malloc(12);
    sprintf(buffer, "%d", i);
    return buffer;
}

int gcd(int v, int b) {
    if (v == 0) return b;
    if (b == 0) return v;
    if (v > b) return gcd(b, v);
    if (v == b) return b;
    if (b % v == 0) return v;
    return gcd(v, b % v);
}

typedef struct {
    int* vec;
    int* lo;
    int beki;
    int cor;
} Sparsetable_min;

void shoki1(Sparsetable_min* sm) {
    sm->vec = (int*)malloc((sm->beki + 1) * sm->cor * sizeof(int));
    sm->lo = (int*)malloc((sm->cor + 1) * sizeof(int));
    sm->lo[0] = -1;
    for (int i = 1; i <= sm->cor; i++) {
        sm->lo[i] = sm->lo[i >> 1] + 1;
    }
}

void shoki2(Sparsetable_min* sm) {
    for (int i = 1; i <= sm->beki; i++) {
        for (int j = 0; j < sm->cor; j++) {
            if ((j + (1 << (i - 1))) < sm->cor) {
                sm->vec[i * sm->cor + j] = 
                    (sm->vec[(i - 1) * sm->cor + j] < sm->vec[(i - 1) * sm->cor + j + (1 << (i - 1))]) ? 
                    sm->vec[(i - 1) * sm->cor + j] : 
                    sm->vec[(i - 1) * sm->cor + j + (1 << (i - 1))]);
            } else {
                sm->vec[i * sm->cor + j] = sm->vec[(i - 1) * sm->cor + j];
            }
        }
    }
}

int rangemin(Sparsetable_min* sm, int i, int j) {
    int haba = sm->lo[j - i];
    return (sm->vec[haba * sm->cor + i] < sm->vec[haba * sm->cor + (j - (1 << haba))]) ? 
           sm->vec[haba * sm->cor + i] : 
           sm->vec[haba * sm->cor + (j - (1 << haba))];
}

typedef struct {
    char* STR;
    int* S;
    int* SL;
    pa* haba;
    int* SA;
    int* rank;
    int* LCP;
    int id3;
    int len;
} SAIS;

void make_suffix_array_string(SAIS* sa, char* str) {
    sa->STR = str;
    int setc[256] = {0};
    int mapc[256] = {0};
    for (int i = 0; str[i]; i++) {
        setc[(unsigned char)str[i]] = 1;
    }
    int cnt = 1;
    for (int i = 0; i < 256; i++) {
        if (setc[i]) {
            mapc[i] = cnt++;
        }
    }
    for (int i = 0; str[i]; i++) {
        sa->S[i] = mapc[(unsigned char)str[i]];
    }
    sa->id3 = cnt;
    sa->S[strlen(str)] = 0;
    make_suffix_array_naibu(sa);
}

void make_suffix_array_naibu(SAIS* sa) {
    int cnt = sa->id3;
    sa->len = strlen(sa->STR);
    int* kosuu = (int*)calloc(cnt, sizeof(int));
    for (int i = 0; i < sa->len; i++) {
        kosuu[sa->S[i]]++;
    }
    sa->haba = (pa*)malloc(cnt * sizeof(pa));
    sa->haba[0] = (pa){0, 0};
    for (int i = 1; i < cnt; i++) {
        sa->haba[i] = (pa){sa->haba[i - 1].second + 1, sa->haba[i - 1].second + kosuu[i]};
    }
    sa->SL = (int*)malloc(sa->len * sizeof(int));
    for (int i = sa->len - 1; i >= 0; i--) {
        if (i == sa->len - 1) {
            sa->SL[i] = 1;
        } else {
            if (sa->S[i] < sa->S[i + 1]) sa->SL[i] = 1;
            else if (sa->S[i] > sa->S[i + 1]) sa->SL[i] = 0;
            else sa->SL[i] = sa->SL[i + 1];
        }
    }
    // Further implementation needed...
}

int main() {
    int n;
    scanf("%d", &n);
    char s[100001];
    scanf("%s", s);
    int* ve = (int*)malloc(n * sizeof(int));
    int cnt = 0;
    char t[100001] = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ve[i] = cnt;
        } else {
            ve[i] = cnt;
            cnt++;
            if (i % 2) strcat(t, "b");
            else strcat(t, "a");
        }
    }
    int m = strlen(t);
    if (m == 0) {
        int e;
        scanf("%d", &e);
        for (int i = 0; i < e; i++) printf("Yes\n");
        return 0;
    }
    for (int i = 0; i < m; i++) {
        t[strlen(t)] = 'a' ^ 'b' ^ t[i];
    }
    ve[cnt] = cnt;
    SAIS ss;
    ss.S = (int*)malloc((n + 1) * sizeof(int));
    ss.SL = (int*)malloc((n + 1) * sizeof(int));
    ss.SA = (int*)malloc((n + 1) * sizeof(int));
    ss.rank = (int*)malloc((n + 1) * sizeof(int));
    ss.LCP = (int*)malloc((n + 1) * sizeof(int));
    make_suffix_array_string(&ss, t);
    // Further implementation needed...
    return 0;
}
