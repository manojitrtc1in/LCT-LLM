
























using namespace std;










using namespace std::tr1;





























double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };


template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }








inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return x > 0; }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }





template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p);
template<typename T> inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v);
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v);
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v);
template<typename T1, typename T2, typename T3> inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t);
template<typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i<v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }



template<typename T1, typename T2> inline pair<T1, T2> operator+(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first + p2.first, p1.second + p2.second); }
template<typename T1, typename T2> inline pair<T1, T2> operator-(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first - p2.first, p1.second - p2.second); }








inline ll mulmod(ll x, ll n, ll _mod){ ll res = 0; while (n){ if (n & 1)res = (res + x) % _mod; x = (x + x) % _mod; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }













int n, m, p;
int a[201010];
set<int> s;
set<int> ds;
int to[200010];

const int N = 150150 * 100;
struct Vertex {
    int val, full;
    Vertex* lp, *rp;
};
Vertex tr[N];
Vertex* root[150150];
int lastn = 1;


inline void create(Vertex*& cur) {
    if (cur == tr) {
        cur = tr + lastn;
        ++lastn;
    }
}
void inc(Vertex*& curp, int l, int r, int x, int y) {
    if (curp == tr) {
        curp = tr + lastn;
        ++lastn;
    }
    Vertex *cur = curp;
    if (l == x && r == y) {
        cur->full = 1;
        cur->val = r - l + 1;
    } else {
        int m = (l + r) / 2;
        if (cur->full) {
            int f = cur->full;
            create(cur->lp);
            create(cur->rp);
            LEFT(cur)->full = f;
            RIGHT(cur)->full = f;
            if (f == 1) {
                LEFT(cur)->val = m - l + 1;
                RIGHT(cur)->val = r - m;
            } else {
                LEFT(cur)->val = 0;
                RIGHT(cur)->val = 0;
            }
            cur->full = false;
        }
        if (y <= m) {
            inc(cur->lp, l, m, x, y);
        } else if (x > m) {
            inc(cur->rp, m + 1, r, x, y);
        } else {
            inc(cur->lp, l, m, x, m);
            inc(cur->rp, m + 1, r, m + 1, y);
        }
        cur->val = LEFT(cur)->val + RIGHT(cur)->val;
    }
}

void dec(Vertex*& curp, int l, int r, int x, int y) {
    if (curp == tr) {
        curp = tr + lastn;
        ++lastn;
    }
    Vertex *cur = curp;
    if (l == x && r == y) {
        cur->full = -1;
        cur->val = 0;
    } else {
        int m = (l + r) / 2;
        if (cur->full) {
            int f = cur->full;
            create(cur->lp);
            create(cur->rp);
            LEFT(cur)->full = f;
            RIGHT(cur)->full = f;
            if (f == 1) {
                LEFT(cur)->val = m - l + 1;
                RIGHT(cur)->val = r - m;
            } else {
                LEFT(cur)->val = 0;
                RIGHT(cur)->val = 0;
            }
            cur->full = false;
        }
        if (y <= m) {
            dec(cur->lp, l, m, x, y);
        } else if (x > m) {
            dec(cur->rp, m + 1, r, x, y);
        } else {
            dec(cur->lp, l, m, x, m);
            dec(cur->rp, m + 1, r, m + 1, y);
        }
        cur->val = LEFT(cur)->val + RIGHT(cur)->val;
    }
}
int sumres = 0;
void sum(Vertex* cur, int l, int r, int x, int y) {
    if (cur == tr) {
        return;
    }
    if (cur->full == -1) return;
    if (cur->full == 1) { sumres += y - x + 1; return; }
    if (x == l && r == y) {
        sumres += cur->val;
        return;
    }
    int m = (l + r) / 2;
    if (y <= m) {
        sum(cur->lp, l, m, x, y);
    } else if (x > m) {
        sum(cur->rp, m + 1, r, x, y);
    } else {
        sum(cur->lp, l, m, x, m);
        sum(cur->rp, m + 1, r, m + 1, y);
    }
}
int hm[150050];
void add(int id, int l, int r) {
    to[l] = r;
    a[l] = id;
    s.insert(l);
    ds.insert(-l);
    hm[id] += r - l + 1;
    inc(root[id], 0, n - 1, l, r);
    

}
void remove(int id, int l, int r) {
    s.erase(l);
    ds.erase(-l);
    hm[id] -= r - l + 1;
    dec(root[id], 0, n - 1, l, r);
    

}
void draw(int id, int l, int r) {
    while (true) {
        auto it = s.lower_bound(l);
        if (it == s.end()) break;
        int from = *it;
        if (from > r) break;
        int to = ::to[from];
        remove(a[from], from, to);
        if (to > r) {
            add(a[from], r + 1, to);
        }
    }
    auto it = s.lower_bound(l);
    if (it != s.begin()) {
        --it;
        int from = *it;
        int to = ::to[from];
        if (to >= l) {
            remove(a[from], from, to);
            if (from < l) {
                add(a[from], from, l - 1);
            }
            if (to>r)
            {
                add(a[from],r+1,to);
            }
        }
    }
    add(id, l, r);
}
int count(int id, int l, int r) {
    sumres = 0;
    sum(root[id], 0, n - 1, l, r);
    return sumres;
}
int main() {
    

    for (int i = 0; i < N; ++i) {
        tr[i].lp = tr[i].rp = tr;
    }
    ios_base::sync_with_stdio(0);
    scanf("%d%d%d", &n, &m, &p);
    const int K = 150000;
    for (int i = 0; i < K; ++i) {
        root[i] = tr + lastn;
        lastn++;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        --a[i];
        add(a[i], i, i);
    }
    std::mt19937 gen;
    gen.seed(42);
    vector<int> ans;
    vector<int> nans;
    for (int mi = 0; mi < m; ++mi) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        --l; --r;
        if (t == 1) {
            int id;
            scanf("%d", &id);
            
            --id;
            draw(id, l, r);
        } else {
            const int K = 70;
            int len = r - l + 1;
            static bool used[150001];
            int tot = 0;
            int need = (p * len + 99) / 100;
            for (int iter = 0; iter < K; ++iter) {
                int trand = gen() % len;
                if (trand < 0) trand += len;
                int pos = l + trand;
                auto it = ds.lower_bound(-pos);
                int id = a[-*it];
                if (used[id]) continue;
                used[id] = true;
                int c;


                c = count(id, l, r);
                if (c >= need) {
                    ans.push_back(id);
                } else {
                    nans.push_back(id);
                }
                tot += c;
                if (tot + (p * len + 99) / 100 > len) {
                    break;
                }
            }
            printf("%d ", int(ans.size()));
            for (int x : ans) {
                used[x] = false;
                printf("%d ", x + 1);
            }
            for (int x : nans) {
                used[x] = false;
            }
            ans.clear();
            nans.clear();
            puts("");
        }
    }
    
    return 0;
}
