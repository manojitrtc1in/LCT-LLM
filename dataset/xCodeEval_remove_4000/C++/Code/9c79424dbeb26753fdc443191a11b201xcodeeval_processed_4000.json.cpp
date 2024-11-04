



























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
inline bool id3(int x){ return (x != 0 && (x&(x - 1)) == 0); }






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
inline ll id1(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int id1(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void id5(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void id5(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void id0(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void id0(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = id1(res, x, m); x = id1(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
ll id4(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1;
    ll d = id4(b % a, a, y, y1);
    x = y1 - (b / a) * y;
    return d;
}














int p[1010101];
bool used[1010101];
int cnt[1010101];
const int id6 = 4096;
static char inbuf[id6 + 16];
static char* linp = inbuf + id6;
static char* inp = linp;
int read_int() {
    if (inp == linp) {
        cin.read(inbuf, id6);
        inp = inbuf;
    }
    int res = 0;
    while (true) {
        if (inp == linp) {
            cin.read(inbuf, id6);
            inp = inbuf;
        }
        if (*inp == ' ' || *inp == '\n') {
            break;
        }
        res = res * 10 + *inp++ - '0';
    }
    ++inp;
    return res;
}
static const int N = 1000100;
static const int K = N / 32 - 2;
static uint arr[N / 32];
static uint tmpArr[N / 32];
struct Bitset {
    int pos = 0;
    Bitset() {
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;
    }
    void add(int x) {
        int step = x / 32;
        int shift = x & 31;
        
        if (shift) {
            memcpy(tmpArr, arr, min(pos / 32 + 1, K) * 4);
            auto* dst = arr + step;
            int to = min(pos / 32 + 1, K - step) + 1;
            int k4 = to / 4;
            for (int i = k4 * 4; i < to; ++i) {
                auto val = tmpArr[i];
                

                

                dst[i] |= val << shift;
                dst[i + 1] |= val >> -shift;
            }
            auto* src = tmpArr;

while (k4--) {                                      \
auto val0 = src[0];                             \
auto val1 = src[1];                             \
auto val2 = src[2];                             \
auto val3 = src[3];                             \
dst[0] |= val0 << shift;                        \
dst[1] |= (val0 >> -shift) | (val1 << shift);   \
dst[2] |= (val1 >> -shift) | (val2 << shift);   \
dst[3] |= (val2 >> -shift) | (val3 << shift);   \
dst[4] |= val3 >> -shift;                       \
src += 4;                                       \
dst += 4;                                       \
} break;}
            switch (shift) {
                    CASE(1);
                    CASE(2);
                    CASE(3);
                    CASE(4);
                    CASE(5);
                    CASE(6);
                    CASE(7);
                    CASE(8);
                    CASE(9);
                    CASE(10);
                    CASE(11);
                    CASE(12);
                    CASE(13);
                    CASE(14);
                    CASE(15);
                    CASE(16);
                    CASE(17);
                    CASE(18);
                    CASE(19);
                    CASE(20);
                    CASE(21);
                    CASE(22);
                    CASE(23);
                    CASE(24);
                    CASE(25);
                    CASE(26);
                    CASE(27);
                    CASE(28);
                    CASE(29);
                    CASE(30);
                    CASE(31);
            }
        } else {
            memcpy(tmpArr, arr, min(pos / 32 + 1, K) * 4);
            auto* dst = arr + step;
            int to = min(pos / 32 + 1, K - step) + 1;
            for (int i = 0; i < to; ++i) {
                dst[i] |= tmpArr[i];
            }
        }
        pos += x;
    }
    bool check(int k) {
        uint x = arr[k / 32];
        return checkbit(x, k & 31);
    }
};
const int RK = 1000032 / 32;
struct id2 {
    int pos = 0;
    id2() {
        memset(arr, 0, sizeof(arr));
        arr[RK] = 1u << 31;
    }
    void add(int x) {
        int step = x / 32;
        int shift = x & 31;
        int from = max(1, RK - step - pos / 32);
        auto* dst = arr + from;
        auto* src = arr + step + from;
        int moves = RK - step - from + 1;
        if (shift) {
            for (int i = 0; i < moves; ++i) {
                auto val = src[i];
                dst[i] |= val >> shift;
                dst[i - 1] |= val << -shift;
            }
        } else {
            for (int i = 0; i < moves; ++i) {
                dst[i] |= src[i];
            }
        }
        pos += x;
    }
    bool check(int k) {
        k = 1000063 - k;
        uint x = arr[k / 32];
        return checkbit(x, k & 31);
    }
};
id2 dp;
int main() {

    FREIN("input.txt");    {
        id2 bs;
        for (int i = 0; i <= 20000; ++i) {
            bs.add(i);
        }
        int sum = 0;
        for (int i = 34; i <= 405000; i *= 2) {
            sum += bs.check(i);
        }
        CURTIME();
        DBN(sum);
        return 0;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    n = read_int();
    k = read_int();
    FI(n) {
        p[i] = read_int();
        p[i]--;
    }
    vector<int> v;
    FI(n) {
        if (!used[i]) {
            int k = 0;
            int cur = i;
            while (!used[cur]) {
                used[cur] = true;
                cur = p[cur];
                ++k;
            }
            v.push_back(k);
        }
    }
    int maxAns = 0;
    int t = 0;
    int s = 0;
    for (int x : v) {
        cnt[x]++;
        t += x & 1;
        s += x / 2;
    }
    v.clear();
    for (int i = 1; i <= 1000000; ++i) {
        int t = 1;
        while (cnt[i]) {
            t = min(cnt[i], t);
            cnt[i] -= t;
            v.push_back(t * i);
            t *= 2;
        }
    }
    sort(all(v));
    for (int x : v) {
        dp.add(x);
    }
    if (s >= k) {
        maxAns = k * 2;
    } else {
        maxAns = min(n, s * 2 + k - s);
    }
    int minAns;
    if (dp.check(k)) {
        minAns = k;
    } else {
        minAns = k + 1;
    }
    cout << minAns << " " << maxAns << endl;
    return 0;
}