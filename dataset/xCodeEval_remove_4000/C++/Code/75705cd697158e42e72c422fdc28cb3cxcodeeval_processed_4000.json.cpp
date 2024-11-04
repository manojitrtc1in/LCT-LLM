



























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














pii resp[50];
int q[50];
char ans[10];
void fill(int *a, int x) {
    for (int j = 0; j < 4; ++j) {
        a[j] = x % 10;
        x /= 10;
    }
}
pii dif(int x, int y) {
    pii res(0, 0);
    int xx[4];
    fill(xx, x);
    int yy[4];
    fill(yy, y);
    for (int i = 0; i < 4; ++i) {
        if (xx[i] == yy[i]) {
            ++res.first;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j) continue;
            if (xx[i] == yy[j]) {
                ++res.second;
                break;
            }
        }
    }
    return res;
}
pii ask(int x) {
    pii res;
    char s[5] = {0};
    for (int i = 3; i >= 0; --i) {
        s[i] = x % 10 + '0';
        x /= 10;
    }
    cout << s << endl;
    cin >> res;
    return res;
}
int main() {
    int a[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = '0' + i;
    }
    vector<int> v;
    for (int i = 0; i < 10000; ++i) {
        int x[4];
        int t = i;
        FJ(4) {
            x[j] = t % 10;
            t /= 10;
        }
        sort(x, x + 4);
        bool ok = x[0] != x[1] && x[1] != x[2] && x[2] != x[3];
        if (!ok) continue;
        v.push_back(i);
    }
    const pii OK = {4, 0};
    set<int> possible(v.begin(), v.end());
    srand(time(0));
    int qw = v[0];
    q[0] = qw;
    resp[0] = ask(qw);
    if (resp[0] == OK) {
        return 0;
    }
    vector<int> toRemove;
    for (int step = 0; step < 7; ++step) {
        for (int x: possible) {
            if (dif(x, qw) != resp[step]) {
                toRemove.push_back(x);
            }
        }
        for (int x : toRemove) {
            possible.erase(x);
        }
        toRemove.clear();
        int res = INF;
        vector<int> best;
        for (int move : v) {
            int cnt[4][4] = {};
            for (int ans : possible) {
                auto f = dif(move, ans);
                cnt[f.first][f.second]++;
            }
            int cur = 0;
            FI(4) FJ(4) {
                cur = max(cur, cnt[i][j]);
            }
            if (cur < res) {
                best.clear();
                res = cur;
            }
            if (cur == res) {
                best.push_back(move);
            }
        }
        qw = best[0];
        resp[step + 1] = ask(qw);
        if (resp[step + 1] == OK) {
            break;
        }
    }
    
    
    return 0;
}