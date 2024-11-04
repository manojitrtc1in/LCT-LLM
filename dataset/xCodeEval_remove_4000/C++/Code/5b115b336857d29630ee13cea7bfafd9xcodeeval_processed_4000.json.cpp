































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






TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p);
TT1 ostream& operator << (ostream& os, const vector<T>& v);
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, const multiset<T1, T2>&v);
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v);
TT1T2T3 ostream& operator << (ostream& os, const map<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const multimap<T1, T2, T3>& v);
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v){    bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multiset<T1,T2>&v){bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const map<T1,T2,T3>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool f = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) os << ", "; f = 0; os << x; } return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
TT1T2 void printarray(T1 a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }



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
















int a[401010];
bool ok[402020][2];
vector<int> b;
vector<int> x;
vector<int> y;
vector<int> other;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    FI(n) {

        a[i] = 1 + rand() % 100;

        cin >> a[i];

    }
    if (k > m || m > n) {
        cout << - 1 << endl;
        return 0;
    }
    int cnt[2];
    FJ(2) {
        int g = 0;

        FI(n) {
            ok[i][j] = rand() % 5 == 0;


            g += ok[i][j];
        }

        cin >> g;

        cnt[j] = g;
        if (g < k) {
            cout << -1 << endl;
            return 0;
        }
        while (g--) {
            int x;

            cin >> x;

            --x;
            ok[x][j] = true;
        }
    }
    int both = 0;
    FI(n) {
        if (ok[i][0] && ok[i][1]) {
            ++both;
            b.push_back(a[i]);
        } else if (ok[i][0]) {
            x.push_back(a[i]);
        } else if (ok[i][1]) {
            y.push_back(a[i]);
        } else {
            other.push_back(a[i]);
        }
    }
    DBN(both, cnt[0], cnt[1]);
    if (both < k && both + (k - both) * 2 > m) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = LLINF;
    sort(all(b));
    sort(all(x));
    sort(all(y));
    int need = 0;
    while (need + (k - need) * 2 > m || need + n - b.size() < m || need + cnt[0] - both < k || need + cnt[1] - both < k) {
        ++need;
    }
    assert(need <= b.size() && need <= m);
    while (x.size() > 0 && (int)x.size() > k - need) {
        other.push_back(x.back());
        x.pop_back();
    }
    while (y.size() > 0 && (int)y.size() > k - need) {
        other.push_back(y.back());
        y.pop_back();
    }
    multiset<int> w;
    multiset<int> free;
    for (int x : other) {
        w.insert(x);
    }
    while (w.size() + x.size() + y.size() + need > m) {
        auto it = --w.end();
        free.insert(*it);
        w.erase(it);
    }
    ll cur = 0;
    for (int i = 0; i < need; ++i) {
        cur += b[i];
    }
    for (int t : x) {
        cur += t;
    }
    for (int t : y) {
        cur += t;
    }
    for (int x : w) {
        cur += x;
    }
    assert(x.size() + w.size() + y.size() + need == m);


    DBN(x.size(), w.size(), y.size(), need);
    DBN(need);
    for (int i = need; i <= b.size() && i <= m; ++i) {


        assert(x.size() + w.size() + y.size() + i == m);
        ans = min(ans, cur);
        if (i == b.size() || i == m) break;
        cur += b[i];
        if (!x.empty()) {
            w.insert(x.back());
            x.pop_back();
        }
        if (!y.empty()) {
            w.insert(y.back());
            y.pop_back();
        }
        while (w.size() + i + 1 + x.size() + y.size() > m) {
            assert(!w.empty());
            auto it = w.end();
            --it;
            cur -= *it;
            free.insert(*it);
            w.erase(it);
        }
        while (!free.empty() && !w.empty()) {
            auto it = free.begin();
            int val = *it;
            if (!w.empty() && *(--w.end()) > val) {
                cur -= *--w.end();
                free.insert(*--w.end());
                w.erase(--w.end());
                w.insert(val);
                cur += val;
                free.erase(it);
            } else {
                break;
            }
        }
    }
    assert(ans != LLINF);
    cout << ans << endl;
    
    
    return 0;
}








