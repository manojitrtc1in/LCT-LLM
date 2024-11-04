



























using namespace std;










using namespace tr1;


































double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef int itn;

template<class T1, class T2, class T3>
struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
template<class T1, class T2, class T3>
bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
template<class T1, class T2, class T3>
bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}





















inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T>
inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }






TT1T2 inline ostream& operator << (ostream& os, const pair<T1, T2>& p);
TT1 inline ostream& operator << (ostream& os, const vector<T>& v);
TT1T2 inline ostream& operator << (ostream& os, const set<T1, T2>&v);
TT1T2 inline ostream& operator << (ostream& os, const multiset<T1, T2>&v);
TT1T2 inline ostream& operator << (ostream& os, priority_queue<T1, T2> v);
TT1T2T3 inline ostream& operator << (ostream& os, const map<T1, T2, T3>& v);
TT1T2T3 inline ostream& operator << (ostream& os, const multimap<T1, T2, T3>& v);
TT1T2T3 inline ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
TT1T2 inline ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 inline ostream& operator << (ostream& os, const vector<T>& v){ bool fi = 1; os << "["; for (int i = 0; i<v.size(); i++){ if (!fi)os << ", "; os << v[i]; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, const set<T1, T2>&v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << *ii; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, const multiset<T1, T2>&v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << *ii; fi = 0; }return os << "]"; }
TT1T2T3 inline ostream& operator << (ostream& os, const map<T1, T2, T3>& v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << "(" << ii->first << " -> " << ii->second << ") "; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << "(" << ii->first << " -> " << ii->second << ") "; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool fi = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!fi) os << ", "; fi = 0; os << x; } return os << "]"; }
TT1T2T3 inline ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
TT1T2 void printarray(T1 a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }



TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t);
TT1T2 inline istream& operator >> (istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
TT1 inline istream& operator >> (istream& os, vector<T>& v) {
    if (v.size()) for (T& t : v) os >> t; else {
        string s; T obj; while (s.empty()) {getline(os, s); if (!os) return os;}
        stringstream ss(s); while (ss >> obj) v.push_back(obj);
    }
    return os;
}
TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }




TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }








template<class T> bool isPrime(T x) { if (x < 2) return 0; for (T i = 2; i * i <= x; ++i) if (x % i == 0) return 0; return 1; }
inline void normmod(ll &x, ll m) { x %= m; if (x < 0) x += m; }
inline ll id4(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int id4(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void id3(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void id3(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void id2(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void id2(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = id4(res, x, m); x = id4(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
ll id1(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1;
    ll d = id1(b % a, a, y, y1);
    x = y1 - (b / a) * y;
    return d;
}

















int a[1010101];
int l[1010101];
int r[1010101];
int tr[1010101];
const int N = 1000000;
void add(int x) {
    for (int i = x; i <= N; i |= (i + 1)) {
        tr[i]++;
    }
}
int sum(int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        res += tr[i];
    }
    return res;
}
struct Fenw {
    ll *tr;
    int n;
    Fenw() {};
    Fenw(int n) {
        this->n = n;
        tr = new ll[n + 1];
        memset(tr, 0, (n + 1) * sizeof(ll));
    }
    void add(int x, ll val) {
        for (int i = x; i <= n; i |= (i + 1)) {
            tr[i] += val;
        }
    }
    ll sum(int x) {
        ll res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            res += tr[i];
        }
        return res;
    }
    ll sum(int a, int b) {
        if (b < a) return 0;
        auto res = sum(b) - sum(a - 1);
        normmod(res, mod);
        return res;
    }
};
int cnt[1010101];
int localPos[101010];
Fenw fl[101010];
Fenw fr[101010];
ll ans = 0;
struct Stree {
    ll *tr;
    ll *sum;
    int *cnt;
    int n;
    Stree() {
        
    }
    Stree(int n) {
        this->n = n;
        while (n & (n - 1)) {
            ++n;
        }
        tr = new ll[n * 2 + 2];
        cnt = new int[n * 2 + 2];
        sum = new ll[n * 2 + 2];
        memset(tr, 0, (n * 2 + 2) * sizeof(ll));
        memset(cnt, 0, (n * 2 + 2) * sizeof(int));
        memset(sum, 0, (n * 2 + 2) * sizeof(ll));
    }
    void add(int cur, int l, int r, int pos, ll val) {
        if (l == r) {
            cnt[cur] = 1;
            tr[cur] = 0;
            sum[cur] = val;
        } else {
            int m = (l + r) / 2;
            int dcur = cur + cur;
            if (pos <= m) {
                add(dcur, l, m, pos, val);
            } else {
                add(dcur + 1, m + 1, r, pos, val);
            }
            tr[cur] = tr[dcur] + tr[dcur + 1] + cnt[dcur] * sum[dcur + 1];
            sum[cur] = sum[dcur] + sum[dcur + 1];
            cnt[cur] = cnt[dcur] + cnt[dcur + 1];
        }
    }
    void add(int pos, ll val) {
        add(1, 0, n - 1, pos, val);
    }
    void del(int cur, int l, int r, int pos) {
        if (l == r) {
            cnt[cur] = 0;
            tr[cur] = 0;
            sum[cur] = 0;
        } else {
            int m = (l + r) / 2;
            int dcur = cur + cur;
            if (pos <= m) {
                del(dcur, l, m, pos);
            } else {
                del(dcur + 1, m + 1, r, pos);
            }
            tr[cur] = tr[dcur] + tr[dcur + 1] + cnt[dcur] * sum[dcur + 1];
            sum[cur] = sum[dcur] + sum[dcur + 1];
            cnt[cur] = cnt[dcur] + cnt[dcur + 1];
        }
    }
    void del(int pos) {
        del(1, 0, n - 1, pos);
    }
    triple<ll, ll, int> getsum(int cur, int l, int r, int x, int y) {
        if (l == x && r == y) {
            return {tr[cur], sum[cur], cnt[cur]};
        } else {
            int m = (l + r) / 2;
            int dcur = cur + cur;
            if (y <= m) {
                return getsum(dcur, l, m, x, y);
            } else if (x > m) {
                return getsum(dcur + 1, m + 1, r, x, y);
            } else {
                auto s1 = getsum(dcur, l, m, x, m);
                auto s2 = getsum(dcur + 1, m + 1, r, m + 1, y);
                s1.a += s2.a + s1.c * s2.b;
                s1.b += s2.b;
                s1.c += s2.c;
                return s1;
            }
        }
    }
    ll calc(int x, int y) {
        if (x > y) return 0;
        return getsum(1, 0, n - 1, x, y).a % mod;
    }
};
struct Rtree {
    ll *tr;
    ll *sum;
    int *cnt;
    int n;
    Rtree() {}
    Rtree(int n) {
        this->n = n;
        while (n & (n - 1)) {
            ++n;
        }
        tr = new ll[n * 2 + 2];
        cnt = new int[n * 2 + 2];
        sum = new ll[n * 2 + 2];
        memset(tr, 0, (n * 2 + 2) * sizeof(ll));
        memset(cnt, 0, (n * 2 + 2) * sizeof(int));
        memset(sum, 0, (n * 2 + 2) * sizeof(ll));
    }
    void add(int cur, int l, int r, int pos, ll val) {
        if (l == r) {
            cnt[cur] = 1;
            tr[cur] = 0;
            sum[cur] = val;
        } else {
            int m = (l + r) / 2;
            int dcur = cur + cur;
            if (pos <= m) {
                add(dcur, l, m, pos, val);
            } else {
                add(dcur + 1, m + 1, r, pos, val);
            }
            tr[cur] = tr[dcur] + tr[dcur + 1] + cnt[dcur + 1] * sum[dcur];
            sum[cur] = sum[dcur] + sum[dcur + 1];
            cnt[cur] = cnt[dcur] + cnt[dcur + 1];
        }
    }
    void add(int pos, ll val) {
        add(1, 0, n - 1, pos, val);
    }
    void del(int cur, int l, int r, int pos) {
        if (l == r) {
            cnt[cur] = 0;
            tr[cur] = 0;
            sum[cur] = 0;
        } else {
            int m = (l + r) / 2;
            int dcur = cur + cur;
            if (pos <= m) {
                del(dcur, l, m, pos);
            } else {
                del(dcur + 1, m + 1, r, pos);
            }
            tr[cur] = tr[dcur] + tr[dcur + 1] + cnt[dcur + 1] * sum[dcur];
            sum[cur] = sum[dcur] + sum[dcur + 1];
            cnt[cur] = cnt[dcur] + cnt[dcur + 1];
        }
    }
    void del(int pos) {
        del(1, 0, n - 1, pos);
    }
    triple<ll, ll, int> getrevsum(int cur, int l, int r, int x, int y) {
        if (l == x && r == y) {
            return {tr[cur], sum[cur], cnt[cur]};
        } else {
            int m = (l + r) / 2;
            int dcur = cur + cur;
            if (y <= m) {
                return getrevsum(dcur, l, m, x, y);
            } else if (x > m) {
                return getrevsum(dcur + 1, m + 1, r, x, y);
            } else {
                auto s1 = getrevsum(dcur, l, m, x, m);
                auto s2 = getrevsum(dcur + 1, m + 1, r, m + 1, y);
                s2.a += s1.a + s2.c * s1.b;
                s2.b += s1.b;
                s2.c += s1.c;
                return s2;
            }
        }
    }
    ll rcalc(int x, int y) {
        if (x > y) return 0;
        return getrevsum(1, 0, n - 1, x, y).a % mod;
    }
};
Rtree sli[101010];
Stree sri[101010];
void addMan(int x) {
    int id = a[x];
    int p = localPos[x];
    int l = ::l[x];
    int r = ::r[x];
    auto fl = ::fl[id];
    auto fr = ::fr[id];
    auto sli = ::sli[id];
    auto sri = ::sri[id];
    int n = cnt[id];
    ans += fl.sum(0, p - 1) % mod * fr.sum(p + 1, n - 1) % mod;
    normmod(ans, mod);
    ans += l * sri.calc(p + 1, n - 1) % mod;
    normmod(ans, mod);
    ans += r * sli.rcalc(0, p - 1) % mod;
    normmod(ans, mod);
    fl.add(p, l);
    fr.add(p, r);
    sli.add(p, l);
    sri.add(p, r);
}
void delMan(int x) {
    int id = a[x];
    int p = localPos[x];
    int l = ::l[x];
    int r = ::r[x];
    auto fl = ::fl[id];
    auto fr = ::fr[id];
    auto sli = ::sli[id];
    auto sri = ::sri[id];
    int n = cnt[id];
    ans -= fl.sum(0, p - 1) % mod * fr.sum(p + 1, n - 1) % mod;
    normmod(ans, mod);
    ans -= l * sri.calc(p + 1, n - 1);
    normmod(ans, mod);
    ans -= r * sli.rcalc(0, p - 1) % mod;
    normmod(ans, mod);
    fl.add(p, -l);
    fr.add(p, -r);
    sli.del(p);
    sri.del(p);
}
int main() {

    FREIN("input.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    FI(n) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(all(v));
    reunique(v);
    FI(n) {
        a[i] = int(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
        localPos[i] = cnt[a[i]]++;
    }
    FI(n) {
        if (cnt[i]) {
            fl[i] = Fenw(cnt[i]);
            fr[i] = Fenw(cnt[i]);
            sli[i] = Rtree(cnt[i]);
            sri[i] = Stree(cnt[i]);
        }
    }
    FI(n) {
        l[i] = sum(a[i]);
        add(a[i]);
    }
    memset(tr, 0, sizeof(tr));
    for (int i = n - 1; i >= 0; --i) {
        r[i] = sum(a[i]);
        add(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        addMan(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1) {
            delMan(x);
        } else {
            addMan(x);
        }
        cout << ans << '\n';
    }
    
    
    
    return 0;
}





