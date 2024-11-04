
































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
inline bool id2(int x){ return (x != 0 && (x&(x - 1)) == 0); }
template<class T1, class T2, class T3> T1 inline clamp(T1 x, const T2& a, const T3& b) { if (x < a) return a; else if (x > b) return b; else return x; }
unsigned long long id6() {
    unsigned long long ret;
    

    return ret;
}






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
inline ll id7(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int id7(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void id5(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void id5(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void id4(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void id4(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = id7(res, x, m); x = id7(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
inline ll id0(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n >>= 1; } return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
ll id3(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1;
    ll d = id3(b % a, a, y, y1);
    x = y1 - (b / a) * y;
    return d;
}
















struct Node {
    bool invert;
    bool fullZero = true;
    bool fullOne;
};

Node tr[101010 * 4 * 8];
void push(int cur) {
    int dcur = cur + cur;
    if (tr[cur].invert) {
        for (int q : {dcur, dcur + 1}) {
            swap(tr[q].fullOne, tr[q].fullZero);
            tr[q].invert ^= 1;
        }
        tr[cur].invert = false;
    }
    if (tr[cur].fullOne) {
        tr[cur].fullOne = false;
        for (int q : {dcur, dcur + 1}) {
            tr[q].fullOne = true;
            tr[q].fullZero = false;
            tr[q].invert = false;
        }
    }
    if (tr[cur].fullZero) {
        tr[cur].fullZero = false;
        for (int q : {dcur, dcur + 1}) {
            tr[q].fullZero = true;
            tr[q].fullOne = false;
            tr[q].invert = false;
        }
    }
}
void upd(int cur) {
    int dcur = cur + cur;
    tr[cur].fullZero = tr[dcur].fullZero && tr[dcur + 1].fullZero;
    tr[cur].fullOne = tr[dcur].fullOne && tr[dcur + 1].fullOne;
}
void drawOne(int cur, int l, int r, int x, int y) {
    

    if (tr[cur].fullOne) return;
    if (l == x && r == y) {
        tr[cur].fullOne = true;
        tr[cur].fullZero = false;
        tr[cur].invert = false;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        push(cur);
        if (y <= m) {
            drawOne(dcur, l, m, x, y);
        } else if (x > m) {
            drawOne(dcur + 1, m + 1, r, x, y);
        } else {
            drawOne(dcur, l, m, x, m);
            drawOne(dcur + 1, m + 1, r, m + 1, y);
        }
        upd(cur);
        

    }
}

void drawZero(int cur, int l, int r, int x, int y) {
    

    if (tr[cur].fullZero) return;
    if (l == x && r == y) {
        tr[cur].fullZero = true;
        tr[cur].fullOne = false;
        tr[cur].invert = false;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        push(cur);
        if (y <= m) {
            drawZero(dcur, l, m, x, y);
        } else if (x > m) {
            drawZero(dcur + 1, m + 1, r, x, y);
        } else {
            drawZero(dcur, l, m, x, m);
            drawZero(dcur + 1, m + 1, r, m + 1, y);
        }
        upd(cur);
    }
}
void invert(int cur, int l, int r, int x, int y) {
    

    if (l == x && r == y) {
        swap(tr[cur].fullOne, tr[cur].fullZero);
        tr[cur].invert ^= 1;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        push(cur);
        if (y <= m) {
            invert(dcur, l, m, x, y);
        } else if ( x > m) {
            invert(dcur + 1, m + 1, r, x, y);
        } else {
            invert(dcur, l, m, x, m);
            invert(dcur + 1, m + 1, r, m + 1, y);
        }
        upd(cur);
    }
}
int id1(int cur, int l, int r) {
    

    if (l == r || tr[cur].fullZero) {
        return l;
    }
    int m = (l + r) / 2;
    int dcur = cur + cur;
    push(cur);
    upd(cur);
    if (!tr[dcur].fullOne) {
        return id1(dcur, l, m);
    } else {
        return id1(dcur + 1, m + 1, r);
    }
}


trll q[101010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    FREIN("input.txt");

    set<ll> s;
    int n;
    cin >> n;
    vector<ll> v;
    v.push_back(1);
    FI(n) {
        cin >> q[i];
        v.push_back(q[i].b);
        v.push_back(q[i].c + 1);
    }
    sort(all(v));
    reunique(v);
    FI(n) {
        q[i].b = int(lower_bound(all(v), q[i].b) - v.begin());
        q[i].c = int(lower_bound(all(v), q[i].c + 1) - v.begin());
    }
    const int K = (int) v.size();
    for (int i = 0; i < n; ++i) {
        int t = q[i].a;
        if (t == 3) {
            invert(1, 0, K, q[i].b, q[i].c - 1);
        } else if (t == 2) {
            drawZero(1, 0, K, q[i].b, q[i].c - 1);
        } else {
            drawOne(1, 0, K, q[i].b, q[i].c - 1);
        }
        cout << v[id1(1, 0, K)] << '\n';
    }
    
    return 0;
}