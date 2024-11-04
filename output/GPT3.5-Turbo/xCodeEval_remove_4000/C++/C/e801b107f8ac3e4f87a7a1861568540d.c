#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define EACH(x, v) for (typeof((v).begin()) x = (v).begin(); x != (v).end(); ++x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef double db;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    ll first;
    ll second;
} pll;

typedef struct {
    db first;
    db second;
} pdb;

typedef struct {
    int* data;
    int size;
} vi;

typedef struct {
    bool* data;
    int size;
} vb;

typedef struct {
    ll* data;
    int size;
} vl;

typedef struct {
    db* data;
    int size;
} vd;

typedef struct {
    char** data;
    int size;
} vs;

typedef struct {
    pii* data;
    int size;
} vpi;

typedef struct {
    pll* data;
    int size;
} vpl;

typedef struct {
    pdb* data;
    int size;
} vpd;

void id0() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

ll nod(ll a, ll b) {
    if (b > a) {
        ll temp = a;
        a = b;
        b = temp;
    }
    while (b > 0) {
        a %= b;
        ll temp = a;
        a = b;
        b = temp;
    }
    return a;
}

ll nok(ll a, ll b) {
    return a * b / nod(a, b);
}

void sp(ll a, double b) {
    printf("%.lf", b);
}

ll binpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return binpow(a, n - 1) * a;
    } else {
        ll b = binpow(a, n / 2);
        return b * b;
    }
}

void read_double(double* d) {
    char t[100];
    scanf("%s", t);
    *d = atof(t);
}

void read_long_double(long double* d) {
    char t[100];
    scanf("%s", t);
    *d = strtold(t, NULL);
}

void read_char(char* c) {
    scanf(" %c", c);
}

void read_bool(bool* b) {
    char t[10];
    scanf("%s", t);
    if (strcmp(t, "true") == 0) {
        *b = true;
    } else {
        *b = false;
    }
}

void read_string(char* s) {
    scanf("%s", s);
}

void read_vector_int(vi* x) {
    scanf("%d", &(x->size));
    x->data = (int*)malloc(x->size * sizeof(int));
    for (int i = 0; i < x->size; ++i) {
        scanf("%d", &(x->data[i]));
    }
}

void read_vector_bool(vb* x) {
    scanf("%d", &(x->size));
    x->data = (bool*)malloc(x->size * sizeof(bool));
    for (int i = 0; i < x->size; ++i) {
        char t[10];
        scanf("%s", t);
        if (strcmp(t, "true") == 0) {
            x->data[i] = true;
        } else {
            x->data[i] = false;
        }
    }
}

void read_vector_ll(vl* x) {
    scanf("%d", &(x->size));
    x->data = (ll*)malloc(x->size * sizeof(ll));
    for (int i = 0; i < x->size; ++i) {
        scanf("%lld", &(x->data[i]));
    }
}

void read_vector_db(vd* x) {
    scanf("%d", &(x->size));
    x->data = (db*)malloc(x->size * sizeof(db));
    for (int i = 0; i < x->size; ++i) {
        scanf("%lf", &(x->data[i]));
    }
}

void read_vector_string(vs* x) {
    scanf("%d", &(x->size));
    x->data = (char**)malloc(x->size * sizeof(char*));
    for (int i = 0; i < x->size; ++i) {
        x->data[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", x->data[i]);
    }
}

void read_vector_pii(vpi* x) {
    scanf("%d", &(x->size));
    x->data = (pii*)malloc(x->size * sizeof(pii));
    for (int i = 0; i < x->size; ++i) {
        scanf("%d%d", &(x->data[i].first), &(x->data[i].second));
    }
}

void read_vector_pll(vpl* x) {
    scanf("%d", &(x->size));
    x->data = (pll*)malloc(x->size * sizeof(pll));
    for (int i = 0; i < x->size; ++i) {
        scanf("%lld%lld", &(x->data[i].first), &(x->data[i].second));
    }
}

void read_vector_pdb(vpd* x) {
    scanf("%d", &(x->size));
    x->data = (pdb*)malloc(x->size * sizeof(pdb));
    for (int i = 0; i < x->size; ++i) {
        scanf("%lf%lf", &(x->data[i].first), &(x->data[i].second));
    }
}

char* to_string_char(char c) {
    char* res = (char*)malloc(2 * sizeof(char));
    res[0] = c;
    res[1] = '\0';
    return res;
}

char* to_string_bool(bool b) {
    char* res = (char*)malloc(6 * sizeof(char));
    if (b) {
        strcpy(res, "true");
    } else {
        strcpy(res, "false");
    }
    return res;
}

char* to_string_string(char* s) {
    char* res = (char*)malloc((strlen(s) + 1) * sizeof(char));
    strcpy(res, s);
    return res;
}

char* to_string_vector_bool(vb x) {
    char* res = (char*)malloc((x.size + 1) * sizeof(char));
    for (int i = 0; i < x.size; ++i) {
        if (x.data[i]) {
            res[i] = '1';
        } else {
            res[i] = '0';
        }
    }
    res[x.size] = '\0';
    return res;
}

char* to_string_vector_int(vi x) {
    char* res = (char*)malloc((2 * x.size + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < x.size; ++i) {
        res[index++] = x.data[i] + '0';
        res[index++] = ' ';
    }
    res[index] = '\0';
    return res;
}

char* to_string_vector_string(vs x) {
    int total_length = 0;
    for (int i = 0; i < x.size; ++i) {
        total_length += strlen(x.data[i]);
    }
    char* res = (char*)malloc((total_length + x.size) * sizeof(char));
    int index = 0;
    for (int i = 0; i < x.size; ++i) {
        for (int j = 0; j < strlen(x.data[i]); ++j) {
            res[index++] = x.data[i][j];
        }
        res[index++] = ' ';
    }
    res[index] = '\0';
    return res;
}

char* to_string_vector_pii(vpi x) {
    char* res = (char*)malloc((4 * x.size + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < x.size; ++i) {
        char temp[20];
        sprintf(temp, "%d %d", x.data[i].first, x.data[i].second);
        for (int j = 0; j < strlen(temp); ++j) {
            res[index++] = temp[j];
        }
        res[index++] = ' ';
    }
    res[index] = '\0';
    return res;
}

char* to_string_vector_pll(vpl x) {
    char* res = (char*)malloc((20 * x.size + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < x.size; ++i) {
        char temp[30];
        sprintf(temp, "%lld %lld", x.data[i].first, x.data[i].second);
        for (int j = 0; j < strlen(temp); ++j) {
            res[index++] = temp[j];
        }
        res[index++] = ' ';
    }
    res[index] = '\0';
    return res;
}

char* to_string_vector_pdb(vpd x) {
    char* res = (char*)malloc((30 * x.size + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < x.size; ++i) {
        char temp[40];
        sprintf(temp, "%.lf %.lf", x.data[i].first, x.data[i].second);
        for (int j = 0; j < strlen(temp); ++j) {
            res[index++] = temp[j];
        }
        res[index++] = ' ';
    }
    res[index] = '\0';
    return res;
}

void write_char(char c) {
    printf("%s", to_string_char(c));
}

void write_bool(bool b) {
    printf("%s", to_string_bool(b));
}

void write_string(char* s) {
    printf("%s", to_string_string(s));
}

void write_vector_bool(vb x) {
    printf("%s", to_string_vector_bool(x));
}

void write_vector_int(vi x) {
    printf("%s", to_string_vector_int(x));
}

void write_vector_string(vs x) {
    printf("%s", to_string_vector_string(x));
}

void write_vector_pii(vpi x) {
    printf("%s", to_string_vector_pii(x));
}

void write_vector_pll(vpl x) {
    printf("%s", to_string_vector_pll(x));
}

void write_vector_pdb(vpd x) {
    printf("%s", to_string_vector_pdb(x));
}

void print() {
    printf("\n");
}

void print_char(char c) {
    write_char(c);
    print();
}

void print_bool(bool b) {
    write_bool(b);
    print();
}

void print_string(char* s) {
    write_string(s);
    print();
}

void print_vector_bool(vb x) {
    write_vector_bool(x);
    print();
}

void print_vector_int(vi x) {
    write_vector_int(x);
    print();
}

void print_vector_string(vs x) {
    write_vector_string(x);
    print();
}

void print_vector_pii(vpi x) {
    write_vector_pii(x);
    print();
}

void print_vector_pll(vpl x) {
    write_vector_pll(x);
    print();
}

void print_vector_pdb(vpd x) {
    write_vector_pdb(x);
    print();
}

void yes(bool ok) {
    print(ok ? "YES" : "Yes");
}

void no(bool ok) {
    print(ok ? "NO" : "No");
}

ll a[200005];

void solve() {
    map<ll, ll> m;
    ll n, s, k;
    scanf("%lld%lld%lld", &n, &s, &k);
    ll ans = MOD;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if (i >= k) {
            m[a[i - k]]--;
            if (m[a[i - k]] == 0) {
                cnt--;
            }
            m[a[i]]++;
            if (m[a[i]] == 1) {
                cnt++;
            }
            ans = min(ans, cnt);
        } else {
            m[a[i]]++;
            if (m[a[i]] == 1) {
                cnt++;
            }
        }
    }
    ans = min(ans, cnt);
    printf("%lld\n", ans);
}

int main() {
    id0();
    ll t = 1;
    scanf("%lld", &t);
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}
