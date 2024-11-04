































using namespace std;




typedef const int cint;
typedef unsigned int uint;
typedef long long ll;
typedef const long long cll;
typedef unsigned long long ull;
typedef long double ld;
typedef const long double cld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef set<int> si;
typedef set<ll> sll;
typedef set<ld> sld;
typedef set<string> ss;
typedef map<int, int> mi;
typedef map<ll, ll> mll;
typedef map<int, ll> mill;
typedef map<ll, int> mlli;
typedef map<int, string> mis;
typedef map<string, int> msi;










































































































































template<class T, class U> inline void id1(T &a, U b) { a = min(a, b); }
template<class T, class U> inline void id8(T &a, U b) { a = max(a, b); }

template<typename T> inline bool updmax(T &a, const T &b){ return a < b ? a = b, 1 : 0; }
template<typename T> inline bool updmin(T &a, const T &b){ return a > b ? a = b, 1 : 0; }



template<class T, class U> istream &operator>>(istream &in, pair<T, U> &a)
{
    in >> a.first >> a.second;
    return in;
}

template<class T, class U> ostream &operator<<(ostream &out, const pair<T, U> &a)
{
    out << a.first << ' ' << a.second;
    return out;
}

template<class T> istream &operator>>(istream &in, vector<T> &a)
{
    forn(i, sz(a))
        in >> a[i];
    return in;
}

template<class T> ostream &operator<<(ostream &out, const vector<T> &a)
{
    forn(i, sz(a))
        out << a[i] << ' ';
    return out;
}



int next_int()
{
    scid(tmp);
    return tmp;
}

ll next_ll()
{
    sclld(tmp);
    return tmp;
}



ll modPow(ll a, ll b, ll MOD){
    ll ret = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ret = modMul(ret, a, MOD);
        a = modMul(a, a, MOD);
    }
    return ret;
}






cll id7 = 100;
cll id5 = 1000;
cll id0 = 1000 * 1000;
cll id4 = id5 * id0;



cint id10 = (int)(id7 * id5) + EXTRA_MEMORY;
cint id11 = (int)(2 * id7 * id5) + EXTRA_MEMORY;
cint id9 = (int)(3 * id7 * id5) + EXTRA_MEMORY;
cint id3 = (int)(4 * id7 * id5) + EXTRA_MEMORY;
cint id2 = (int)(5 * id7 * id5) + EXTRA_MEMORY;






cint INF = (int)id4 + 7;
cint INF2 = 1 << 30;
cll INFLL = 4LL * id4 * id4 + 7;
cll id6 = 1LL << 60;



cld Pi = acos(-1.0);
cld EPS = 1e-7;

cint MOD = (int)id4 + 7;









enum
{
    MAXN = 1200012,
};



int fix[MAXN];

int t[4 * MAXN];
int new_val[4 * MAXN];

void update(int v, int tl, int tr)
{
    int tm = (tl + tr) / 2;
    tl = fix[tl];
    tr = fix[tr];
    tm = fix[tm];

    int n1 = t[2 * v];
    if (new_val[2 * v] != -1) {
        n1 = (tm - tl) * new_val[2 * v];
    }

    int n2 = t[2 * v + 1];
    if (new_val[2 * v + 1] != -1) {
        n2 = (tr - tm) * new_val[2 * v + 1];
    }

    t[v] = n1 + n2;
}

void push(int v, int tl, int tr)
{
    if (new_val[v] == -1) {
        return;
    }

    t[v] = (fix[tr] - fix[tl]) * new_val[v];

    if (tr - tl > 1) {
        new_val[2 * v] = new_val[v];
        new_val[2 * v + 1] = new_val[v];
    }

    new_val[v] = -1;
}

void change(int v, int tl, int tr, int ql, int qr, int val)
{
    push(v, tl, tr);

    if (ql <= tl && tr <= qr) {
        new_val[v] = val;
        return;
    }

    if (ql >= tr || tl >= qr) {
        return;
    }

    int tm = (tl + tr) / 2;
    change(2 * v,     tl, tm, ql, qr, val);
    change(2 * v + 1, tm, tr, ql, qr, val);

    update(v, tl, tr);
}

int get_sum(int n)
{
    push(1, 0, n);
    return t[1];
}

struct Query
{
    int l, r, k;
} queries[MAXN];






























int main() {

    ifstream in(PREF_TASK"in"SUFF_TASK);
    ofstream out(PREF_TASK"out"SUFF_TASK);


    memset(new_val, -1, sizeof(new_val));

    sc2id(n, q);
    forn(i, q) {
        sc3id(l, r, k);
        --l, --r;
        queries[i] = {l, r, k};
    }



    forn(i, q) {
        fix[i] = queries[i].l;
        fix[q + i] = queries[i].r;
    }
    forn(i, q) {
        fix[2 * q + i] = queries[i].l + 1;
        fix[3 * q + i] = queries[i].r + 1;
    }
    fix[4 * q] = 0;
    fix[4 * q + 1] = n;





    sort(fix, fix + 4 * q + 2);
    int nn = unique(fix, fix + 4 * q + 2) - fix;












    forn(i, q) {
        int l = queries[i].l;
        int r = queries[i].r;
        int k = queries[i].k;

        int fl = lower_bound(fix, fix + nn, l) - fix;
        int fr = lower_bound(fix, fix + nn, r) - fix;

        k %= 2;
        change(1, 0, nn, fl, fr + 1, k);

        prinl(n - get_sum(nn));
    }



    in.close();
    out.close();

    return 0;
}








