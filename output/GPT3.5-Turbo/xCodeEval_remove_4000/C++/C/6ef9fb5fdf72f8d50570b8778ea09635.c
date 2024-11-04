#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000013

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int a;
    int b;
} pair;

typedef struct {
    int* arr;
    int size;
} vector;

int INF = 1000000000;
li INF64 = 1000000000000000000;
int MOD = 1000000007;
ld EPS = 1e-9;
ld PI = 3.14159265358979323846;

char* s;
int n;

int sz(vector* v) {
    return v->size;
}

void init_vector(vector* v) {
    v->arr = NULL;
    v->size = 0;
}

void push_back(vector* v, int val) {
    v->arr = realloc(v->arr, (v->size + 1) * sizeof(int));
    v->arr[v->size] = val;
    v->size++;
}

void free_vector(vector* v) {
    free(v->arr);
    v->arr = NULL;
    v->size = 0;
}

void print_pair(pair* a) {
    printf("(%d, %d)", a->a, a->b);
}

void print_vector(vector* v) {
    printf("[");
    for (int i = 0; i < sz(v); i++) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", v->arr[i]);
    }
    printf("]");
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int read() {
    char buf[N];
    if (scanf("%s", buf) != 1) {
        return 0;
    }
    s = malloc((strlen(buf) + 1) * sizeof(char));
    strcpy(s, buf);
    n = strlen(s);
    return 1;
}

vector ord;

void gen(int n) {
    if (n == 1) {
        push_back(&ord, 1);
        return;
    }
    gen(n / 2);
    gen((n + 1) / 2);
    push_back(&ord, n);
}

int get(int t, int ans) {
    free_vector(&ord);
    init_vector(&ord);
    gen(t);
    int l = 0;
    int pr = 0;
    for (int i = 0; i < sz(&ord); i++) {
        int x = ord.arr[i];
        if (x == 1) {
            pr++;
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        int r = l;
        int fl = 0;
        while (r < n) {
            if (s[r++] == '0') {
                cnt0++;
                if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                    fl = 1;
                    break;
                }
            }
            else {
                cnt1++;
                if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                    fl = 1;
                    break;
                }
            }
        }
        if (!fl) {
            break;
        }
        l = r;
        pr++;
    }
    if (!ans) {
        return sz(&ord) - pr;
    }
    if (l != n || pr != sz(&ord)) {
        printf("ERROR: l = %d, n = %d, pr = %d, sz(ord) = %d\n", l, n, pr, sz(&ord));
    }
    vector res;
    init_vector(&res);
    l = 0;
    for (int i = 0; i < sz(&ord); i++) {
        int x = ord.arr[i];
        if (x == 1) {
            push_back(&res, 0);
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        int r = l;
        int fl = 0;
        vector L, R;
        init_vector(&L);
        init_vector(&R);
        while (r < n) {
            if (s[r++] == '0') {
                push_back(&L, cnt0 + cnt1);
                cnt0++;
                if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                    fl = 1;
                    break;
                }
            }
            else {
                push_back(&R, cnt0 + cnt1);
                cnt1++;
                if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                    fl = 1;
                    break;
                }
            }
        }
        while (cnt0 < x / 2) {
            push_back(&L, cnt0 + cnt1);
            cnt0++;
        }
        while (cnt1 < (x + 1) / 2) {
            push_back(&R, cnt0 + cnt1);
            cnt1++;
        }
        vector nw;
        init_vector(&nw);
        for (int j = 0; j < sz(&res) - 2; j++) {
            push_back(&nw, L.arr[res.arr[j]]);
        }
        for (int j = 0; j < sz(&res) - 1; j++) {
            push_back(&nw, R.arr[res.arr[j]]);
        }
        free_vector(&res);
        push_back(&res, nw);
        if (!fl) {
            break;
        }
        l = r;
    }
    printf("%d\n", t);
    for (int i = 0; i < sz(&res); i++) {
        printf("%d ", res.arr[i] + 1);
    }
    printf("\n");
    free_vector(&res);
    return 1;
}

void solve() {
    int l = 1, r = n + 1;
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (get(m, 0) == 0) {
            res = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    get(res, 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    int tt = clock();
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        read();
        solve();
    }
    free(s);
    free_vector(&ord);
    printf("TIME = %d\n", clock() - tt);
    return 0;
}
