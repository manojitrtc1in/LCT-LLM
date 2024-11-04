



























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
inline ll id5(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int id5(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void id4(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void id4(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void id2(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void id2(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = id5(res, x, m); x = id5(x, x, m); n >>= 1; } return res; }
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
















int a[101010];
tri q[310101];
int ans[310100];
struct Ver {
    int *a;
    int **ptrLeft;
    int **ptrRight;
    int ans;
};
Ver tr[402020];
int mem[101010 * 20];
int *pool = mem;
int* getNew(int cnt) {
    auto res = pool;
    pool += cnt;
    return res;
}
int *mem2[101010 * 40];
auto* pool2 = mem2;
int** id3(int cnt) {
    auto res = pool2;
    pool2 += cnt;
    return res;
}
void merge(int* src1, int* src2, int siz1, int siz2, int* dst, int** ptr1, int** ptr2) {
    int it = 0;
    ptr1[siz1 + siz2] = src1 + siz1;
    ptr2[siz1 + siz2] = src2 + siz2;
    while (siz1 || siz2) {
        *ptr1 = src1;
        *ptr2 = src2;
        if (!siz2 || (siz1 && *src1 < *src2)) {
            *dst = *src1;
            --siz1;
            ++src1;
        } else {
            *dst = *src2;
            --siz2;
            ++src2;
        }
        if (it && dst[-1] == dst[0]) {
            ptr1[0] = ptr1[-1];
            ptr2[0] = ptr2[-1];
        }
        ++it;
        ++dst;
        ++ptr1;
        ++ptr2;
    }
}
void build(int cur, int l, int r) {
    tr[cur].a = getNew(r - l + 1);
    tr[cur].ptrLeft = id3(r - l + 2);
    tr[cur].ptrRight = id3(r - l + 2);
    if (l == r) {
        tr[cur].a[0] = a[l];
        tr[cur].ans = INF;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        build(dcur, l, m);
        build(dcur + 1, m + 1, r);
        int siz = r - l + 1;
        merge(tr[dcur].a, tr[dcur + 1].a, m - l + 1, r - m, tr[cur].a, tr[cur].ptrLeft, tr[cur].ptrRight);
        int ans = INF;
        for (int i = 1; i < siz; ++i) {
            ans = min(ans, tr[cur].a[i] - tr[cur].a[i - 1]);
        }
        tr[cur].ans = ans;
    }
}
int getAns(int cur, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return tr[cur].ans;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        if (y <= m) {
            return getAns(dcur, l, m, x, y);
        } else if (x > m) {
            return getAns(dcur + 1, m + 1, r, x, y);
        } else {
            return min(getAns(dcur, l, m, x, y), getAns(dcur + 1, m + 1, r, x, y));
        }
    }
}


void update(int cur, int l, int r, int to, int x, int& d, int *it) {


    if (l == r) {
        tr[cur].ans = min(tr[cur].ans, abs(x - tr[cur].a[0]));
        d = min(tr[cur].ans, d);
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        int siz = r - l + 1;
        if ((it == tr[cur].a + siz || *it >= x + d) && (it == tr[cur].a || *(it - 1) <= x - d)) {
            d = min(d, getAns(cur, l, r, l, to));
            return;
        }
        int idx = int(it - tr[cur].a);
        if (to > m) {
            update(dcur + 1, m + 1, r, to, x, d, tr[cur].ptrRight[idx]);
        }
        update(dcur, l, m, to, x, d, tr[cur].ptrLeft[idx]);
        tr[cur].ans = min(tr[cur].ans, min(tr[dcur].ans, tr[dcur + 1].ans));
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    FREIN("input.txt");
    FREOUT("out.txt");

    int n;
    scanf("%d", &n);
    FI(n) {
        scanf("%d", a + i);
    }
    int m;
    scanf("%d", &m);
    FI(m) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        q[i] = {x, y, i};
    }
    sort(q, q + m, [](const tri& t1, const tri& t2) {
        return t1.b < t2.b;
    });
    int curr = 0;
    build(1, 0, n - 1);
    FI(m) {
        auto curq = q[i];
        int l = curq.a;
        int r = curq.b;
        int idx = curq.c;
        while (curr < r) {
            ++curr;
            int d = INF;
            auto xptr = std::lower_bound(tr[1].a, tr[1].a + n, a[curr]);
            update(1, 0, n - 1, curr - 1, a[curr], d, xptr);
        }
        ans[idx] = getAns(1, 0, n - 1, l, r);
    }
    FI(m) {
        printf("%d\n", ans[i]);
    }
    CURTIME();
    return 0;
}


