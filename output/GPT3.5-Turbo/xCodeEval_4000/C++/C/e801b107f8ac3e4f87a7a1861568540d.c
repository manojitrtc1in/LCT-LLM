#include <stdio.h>
#include <stdlib.h>

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
    int* data;
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

#define mp(a, b) make_pair(a, b)
#define ff first
#define ss second
#define sz(x) (x).size
#define all(x) (x).data, (x).data + (x).size
#define rall(x) (x).data + (x).size - 1, (x).data - 1
#define ins(x) insert(x)
#define ft(x) (x).data[0]
#define bk(x) (x).data[(x).size - 1]
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define lb(x, y) lower_bound(x, y)
#define ub(x, y) upper_bound(x, y)
#define vv(x) vector<vector<x> >
#define mi(x) map<int, x>
#define ms(x) map<string, x>
#define ml(x) map<ll, x>
#define all_sum(a, b) accumulate(a, b, 0)
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (int i = 0; i < (a).size; i++) { auto x = (a).data[i];
void adskiy_razgon() {
    setbuf(stdout, NULL);
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

void read_int(int* x) {
    scanf("%d", x);
}

void read_ll(ll* x) {
    scanf("%lld", x);
}

void read_double(double* x) {
    char t[100];
    scanf("%s", t);
    *x = atof(t);
}

void read_ld(ld* x) {
    char t[100];
    scanf("%s", t);
    *x = atof(t);
}

void read_string(char* x) {
    scanf("%s", x);
}

void read_char(char* x) {
    scanf(" %c", x);
}

void read_vi(vi* x) {
    read_int(&(x->size));
    x->data = (int*)malloc(x->size * sizeof(int));
    for (int i = 0; i < x->size; i++) {
        read_int(&(x->data[i]));
    }
}

void read_vb(vb* x) {
    read_int(&(x->size));
    x->data = (int*)malloc(x->size * sizeof(int));
    for (int i = 0; i < x->size; i++) {
        read_int(&(x->data[i]));
    }
}

void read_vl(vl* x) {
    read_int(&(x->size));
    x->data = (ll*)malloc(x->size * sizeof(ll));
    for (int i = 0; i < x->size; i++) {
        read_ll(&(x->data[i]));
    }
}

void read_vd(vd* x) {
    read_int(&(x->size));
    x->data = (db*)malloc(x->size * sizeof(db));
    for (int i = 0; i < x->size; i++) {
        read_double(&(x->data[i]));
    }
}

void read_vs(vs* x) {
    read_int(&(x->size));
    x->data = (char**)malloc(x->size * sizeof(char*));
    for (int i = 0; i < x->size; i++) {
        x->data[i] = (char*)malloc(100 * sizeof(char));
        read_string(x->data[i]);
    }
}

void read_vpi(vpi* x) {
    read_int(&(x->size));
    x->data = (pii*)malloc(x->size * sizeof(pii));
    for (int i = 0; i < x->size; i++) {
        read_int(&(x->data[i].first));
        read_int(&(x->data[i].second));
    }
}

void read_vpl(vpl* x) {
    read_int(&(x->size));
    x->data = (pll*)malloc(x->size * sizeof(pll));
    for (int i = 0; i < x->size; i++) {
        read_ll(&(x->data[i].first));
        read_ll(&(x->data[i].second));
    }
}

void read_vpd(vpd* x) {
    read_int(&(x->size));
    x->data = (pdb*)malloc(x->size * sizeof(pdb));
    for (int i = 0; i < x->size; i++) {
        read_double(&(x->data[i].first));
        read_double(&(x->data[i].second));
    }
}

char* to_string_char(char c) {
    char* res = (char*)malloc(2 * sizeof(char));
    res[0] = c;
    res[1] = '\0';
    return res;
}

char* to_string_bool(int b) {
    if (b) {
        return "true";
    } else {
        return "false";
    }
}

char* to_string_string(char* s) {
    return s;
}

char* to_string_vi(vi* v) {
    char* res = (char*)malloc((v->size + 1) * sizeof(char));
    for (int i = 0; i < v->size; i++) {
        res[i] = '0' + v->data[i];
    }
    res[v->size] = '\0';
    return res;
}

char* to_string_int(int x) {
    char* res = (char*)malloc(100 * sizeof(char));
    sprintf(res, "%d", x);
    return res;
}

char* to_string_ll(ll x) {
    char* res = (char*)malloc(100 * sizeof(char));
    sprintf(res, "%lld", x);
    return res;
}

char* to_string_double(double x) {
    char* res = (char*)malloc(100 * sizeof(char));
    sprintf(res, "%.lf", x);
    return res;
}

char* to_string_ld(ld x) {
    char* res = (char*)malloc(100 * sizeof(char));
    sprintf(res, "%.lf", x);
    return res;
}

char* to_string_vpi(vpi* v) {
    char* res = (char*)malloc((v->size * 2 + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < v->size; i++) {
        char* first = to_string_int(v->data[i].first);
        char* second = to_string_int(v->data[i].second);
        for (int j = 0; first[j] != '\0'; j++) {
            res[index++] = first[j];
        }
        res[index++] = ' ';
        for (int j = 0; second[j] != '\0'; j++) {
            res[index++] = second[j];
        }
        if (i != v->size - 1) {
            res[index++] = ' ';
        }
        free(first);
        free(second);
    }
    res[index] = '\0';
    return res;
}

void write_char(char* x) {
    printf("%s", x);
}

void write_string(char* x) {
    printf("%s", x);
}

void write_int(int x) {
    printf("%d", x);
}

void write_ll(ll x) {
    printf("%lld", x);
}

void write_double(double x) {
    printf("%.lf", x);
}

void write_ld(ld x) {
    printf("%.lf", x);
}

void write_vi(vi* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%d", x->data[i]);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
}

void write_vpi(vpi* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%d %d", x->data[i].first, x->data[i].second);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
}

void write_vpl(vpl* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%lld %lld", x->data[i].first, x->data[i].second);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
}

void write_vpd(vpd* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%.lf %.lf", x->data[i].first, x->data[i].second);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
}

void print() {
    printf("\n");
}

void print_char(char* x) {
    printf("%s\n", x);
}

void print_string(char* x) {
    printf("%s\n", x);
}

void print_int(int x) {
    printf("%d\n", x);
}

void print_ll(ll x) {
    printf("%lld\n", x);
}

void print_double(double x) {
    printf("%.lf\n", x);
}

void print_ld(ld x) {
    printf("%.lf\n", x);
}

void print_vi(vi* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%d", x->data[i]);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_vpi(vpi* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%d %d", x->data[i].first, x->data[i].second);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_vpl(vpl* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%lld %lld", x->data[i].first, x->data[i].second);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_vpd(vpd* x) {
    for (int i = 0; i < x->size; i++) {
        printf("%.lf %.lf", x->data[i].first, x->data[i].second);
        if (i != x->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void yes(int ok) {
    if (ok) {
        printf("YES\n");
    } else {
        printf("Yes\n");
    }
}

void no(int ok) {
    if (ok) {
        printf("NO\n");
    } else {
        printf("No\n");
    }
}

ll a[200005];

void solve() {
    mi(ll) m;
    ll n, s, k;
    read_ll(&n);
    read_ll(&s);
    read_ll(&k);
    ll ans = MOD;
    ll cnt = 0;
    FOR(i, 1, n + 1) {
        read_ll(&(a[i]));
        if (i >= k) {
            m.data[a[i - k]]--;
            if (m.data[a[i - k]] == 0) {
                cnt--;
            }
            m.data[a[i]]++;
            if (m.data[a[i]] == 1) {
                cnt++;
            }
            ans = ans < cnt ? ans : cnt;
        } else {
            m.data[a[i]]++;
            if (m.data[a[i]] == 1) {
                cnt++;
            }
        }
    }
    ans = ans < cnt ? ans : cnt;
    print_ll(ans);
}

int main() {
    adskiy_razgon();
    ll t = 1;
    read_ll(&t);
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}
