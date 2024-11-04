



























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
















int a[101010];
tri q[310101];
int ans[310100];
int best = 0;




























































































struct Node {
    Node* lp;
    Node* rp;
    int ans;
    int cnt;
    int min;
    int max;
};
Node nodes[3200020];
Node *lastn = nodes;
Node *root = nullptr;
template<int val>
void update(Node*& cur, int l, int r, int x) {
    if (cur == nullptr) {
        cur = lastn++;
    }
    if (l == r) {
        cur->cnt += val;
        if (cur->cnt > 1) {
            cur->ans = 0;
        } else {
            cur->ans = INF;
        }
        cur->max = cur->min = l;
    } else {
        int m = (l + r) / 2;
        if (x <= m) {
            update<val>(cur->lp, l, m, x);
        } else {
            update<val>(cur->rp, m + 1, r, x);
        }
        cur->cnt += val;
        if (!cur->cnt) {
            cur->ans = 0;
        } else if (!cur->lp || cur->lp->cnt == 0) {
            cur->ans = cur->rp->ans;
            cur->min = cur->rp->min;
            cur->max = cur->rp->max;
        } else if (!cur->rp || cur->rp->cnt == 0) {
            cur->ans = cur->lp->ans;
            cur->min = cur->lp->min;
            cur->max = cur->lp->max;
        } else {
            cur->ans =  min(min(cur->lp->ans, cur->rp->ans), cur->rp->min - cur->lp->max);
            cur->min = cur->lp->min;
            cur->max = cur->rp->max;
        }
    }
}
struct Ver {
    int *a;
    int ans;
};
Ver tr[402020];
int* getNew(int cnt) {
    return new int[cnt];
}
void build(int cur, int l, int r) {
    tr[cur].a = getNew(r - l + 1);
    if (l == r) {
        tr[cur].a[0] = a[l];
        tr[cur].ans = INF;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        build(dcur, l, m);
        build(dcur + 1, m + 1, r);
        int siz = r - l + 1;
        std::merge(tr[dcur].a, tr[dcur].a + m - l + 1, tr[dcur + 1].a, tr[dcur + 1].a + r - m, tr[cur].a);
        int ans = INF;
        for (int i = 1; i < siz; ++i) {
            ans = min(ans, tr[cur].a[i] - tr[cur].a[i - 1]);
        }
        tr[cur].ans = ans;
    }
}
int getAns(int cur, int l, int r, int x, int y);
void update(int cur, int l, int r, int to, int x, int& d) {
    if (l == r) {
        tr[cur].ans = min(tr[cur].ans, abs(x - tr[cur].a[0]));
        d = min(tr[cur].ans, d);
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        int siz = r - l + 1;
        auto it = std::lower_bound(tr[cur].a, tr[cur].a + siz, x);
        if ((it == tr[cur].a + siz || *it >= x + d) && (it == tr[cur].a || *(it - 1) <= x - d)) {
            d = min(d, getAns(cur, l, r, l, to));
            return;
        }
        if (to > m) {
            update(dcur + 1, m + 1, r, to, x, d);
            update(dcur, l, m, m, x, d);
        } else {
            update(dcur, l, m, to, x, d);
        }
        tr[cur].ans = min(tr[cur].ans, min(tr[dcur].ans, tr[dcur + 1].ans));


    }
}
int getAns(int cur, int l, int r, int x, int y) {


    if (l == x && r == y) {
        return tr[cur].ans;
    } else {
        int m = (l + r) / 2;
        int dcur = cur + cur;
        if (y <= m) {
            return getAns(dcur, l, m, x, y);
        } else if (x > m) {
            return getAns(dcur + 1, m + 1, r, x, y);
        } else {
            return min(getAns(dcur, l, m, x, m), getAns(dcur + 1, m + 1, r, m + 1, y));
        }
    }
}
void add(int x) {
    update<1>(root, 1, 1000000000, x);
}
void del(int x) {
    update<-1>(root, 1, 1000000000, x);
}
int getAns() {
    return root->ans;
}
int main() {
    if (0) {
        FREOUT("input.txt");
        int n = 30000;
        cout << n << endl;
        FI(n) {
            a[i] = 1 + rand() % 999999999;
            cout << a[i] << ' ';
        }
        int m = n * 3;
        cout << m << endl;
        FI(m) {
            int x = rand() % (n - 2) + 1;
            int y = rand() % (n - 1 - x) + x + 1;
            cout << x << ' ' << y << endl;
        }
        
        return 0;
    }




    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    scanf("%d", &n);
    FI(n) {
        scanf("%d", a + i);
    }
    int m;
    scanf("%d", &m);


    int qs = 0;
    FI(m) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        const int K = 31;
        if (y - x <= K) {
            int ars[K + 1];
            int siz = y - x + 1;
            for (int i = x; i <= y; ++i) {
                ars[i - x] = a[i];
            }
            sort(ars, ars + siz);
            int ans = ars[1] - ars[0];
            for (int i = 2; i < siz; ++i) {
                ans = min(ans, ars[i] - ars[i - 1]);
            }
            ::ans[i] = ans;
        } else {
            q[qs++] = {x, y, i};
        }
    }








    sort(q, q + qs, [](const tri& t1, const tri& t2) {
        return t1.b < t2.b;
    });
    int curr = 0;
    build(1, 0, n - 1);
    FI(qs) {
        auto curq = q[i];
        int l = curq.a;
        int r = curq.b;
        int idx = curq.c;
        while (curr < r) {
            ++curr;
            int d = INF;


            update(1, 0, n - 1, curr - 1, a[curr], d);




        }


        ans[idx] = getAns(1, 0, n - 1, l, r);


    }

    const int K = 330;
    sort(q, q + qs, [](const tri& t1, const tri& t2) {
        int b1 = t1.a / K;
        int b2 = t2.a / K;
        return b1 < b2 || (b1 == b2 && t1.b < t2.b);
    });
    int curl = 0;
    int curr = 0;
    add(a[0]);
    FI(qs) {
        auto curq = q[i];
        int l = curq.a;
        int r = curq.b;
        int idx = curq.c;
        while (curr < r) {
            ++curr;
            add(a[curr]);
        }
        while (curl > l) {
            --curl;
            add(a[curl]);
        }
        while (curr > r) {
            del(a[curr]);
            --curr;
        }
        while (curl < l) {
            del(a[curl]);
            ++curl;
        }
        ans[idx] = getAns();
    }

    FI(m) {
        cout << ans[i] << '\n';


    }




    return 0;
}



