























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
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a < t2.a; else return t1.b < t2.b; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }





















































inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return (x >> 31) | (-x >> 31); }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }







template<typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i < v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i < sz; i++) cout << a[i] << " "; cout << endl; }








inline ll binpow(ll x, ll n){ ll res = 1; while (n){ if (n & 1)res *= x; x *= x; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(int a, int b){ return a / gcd(a, b)*(ll)b; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
inline ll lcm(ll a, ll b, ll c){ return lcm(lcm(a, b), c); }
inline ll lcm(int a, int b, int c){ return lcm(lcm(a, b), (ll)c); }

inline ll max(ll a, ll b){ return (a > b) ? a : b; }
inline int max(int a, int b){ return (a > b) ? a : b; }
inline double max(double a, double b){ return (a > b) ? a : b; }
inline ll max(ll a, ll b, ll c){ return max(a, max(b, c)); }
inline int max(int a, int b, int c){ return max(a, max(b, c)); }
inline double max(double a, double b, double c){ return max(a, max(b, c)); }
inline ll min(ll a, ll b){ return (a < b) ? a : b; }
inline int min(int a, int b){ return (a < b) ? a : b; }
inline double min(double a, double b){ return (a < b) ? a : b; }
inline ll min(ll a, ll b, ll c){ return min(a, min(b, c)); }
inline int min(int a, int b, int c){ return min(a, min(b, c)); }
inline double min(double a, double b, double c){ return min(a, min(b, c)); }

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }











int a[500010];
int b[500010];
int d[500010];
int dres[500010];
int tres[500010];
int cpos[500010];
pii pr[500010];
map<int, int> pos;
struct StreeMin
{
    pii tr[2000010];
    void build(int cur, int l, int r)
    {
        if (l != r)
        {
            int m = (l + r) >> 1;
            int dcur = cur + cur;
            build(dcur, l, m);
            build(dcur + 1, m + 1, r);
            tr[cur] = min(tr[dcur], tr[dcur + 1]);
        }
        else
        {
            tr[cur] = { INF, l };
        }
    }
    void upd(int cur, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tr[cur] = { val, l };
        }
        else
        {
            int m = (l + r) >> 1;
            int dcur = cur + cur;
            if (pos <= m)
                upd(dcur, l, m, pos, val);
            else
                upd(dcur + 1, m + 1, r, pos, val);
            tr[cur] = min(tr[dcur], tr[dcur + 1]);
        }
    }
    pii getmin(int cur, int l, int r, int x, int y)
    {
        if (x > y) return{ INF, INF };
        if (x < l) x = l;
        if (y > r) y = r;
        if (x > r || y < l) return{ INF, INF };
        if (l == x && r == y) return tr[cur];
        int m = (l + r) >> 1;
        int dcur = cur + cur;
        return min(getmin(dcur, l, m, x, y), getmin(dcur + 1, m + 1, r, x, y));
    }
};
StreeMin wmin;
vector<int> v[500010];
map<int, int> m;
int ms = 1;
int y[500010];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
        y[i] = a[i];
    }
    sort(y + 1, y + 1 + n);
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(y + 1, y + 1 + n, a[i]) - y;
    wmin.build(1, 0, n);
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        if (v[x].size())
        {
            wmin.upd(1, 0, n, v[x].back(), i);
        }
        v[x].push_back(i);
    }
    for (int i = 0; i <= n + 1; ++i){
        v[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        if (v[x].size() > 0)
        {
            int p = v[x].back();
            wmin.upd(1, 0, n, p, INF);

            int t = v[x].back();
            int dd = dres[t - 1];
            pii pres = wmin.getmin(1, 0, n, t + 1, i - 1);
            int pos = pres.first;
            int prevpos = pres.second;

            if (pos != INF && dd + 1 > d[pos])
            {
                d[pos] = dd + 1;
                pr[pos] = { pos, t };
            }
            if (v[x].size() > 1)
            {
                t = v[x][v[x].size() - 2];
                dd = dres[t - 1];
                pii pres = wmin.getmin(1, 0, n, t + 1, i - 1);
                int pos = pres.first;
                int prevpos = pres.second;
                if (pos != INF && dd + 1 > d[pos])
                {
                    d[pos] = dd + 1;
                    pr[pos] = { pos, t };
                }
            }
            if (v[x].size() > 2)
            {
                int t = v[x][v[x].size() - 3];
                if (dres[t - 1] + 1 > d[i])
                {
                    d[i] = dres[t - 1] + 1;
                    pr[i] = { i, v[x][v[x].size() - 3] };
                }
            }
        }
        if (dres[i - 1] >= d[i])
        {
            tres[i] = tres[i - 1];
            dres[i] = dres[i - 1];
        }
        else
        {
            dres[i] = d[i];
            tres[i] = i;
        }
        v[x].push_back(i);
    }
    cout << dres[n] * 4 << endl;
    int cur = n;
    vector<int> ans;
    while (true)
    {
        int p = tres[cur];
        if (p == 0) break;
        ans.push_back(pr[p].first);
        ans.push_back(pr[p].second);
        ans.push_back(pr[p].first);
        ans.push_back(pr[p].second);
        cur = pr[p].second - 1;
    }
    reverse(all(ans));
    for (int x : ans){
        cout << b[x] << ' ';
    }
    cout << endl;
    return 0;
}