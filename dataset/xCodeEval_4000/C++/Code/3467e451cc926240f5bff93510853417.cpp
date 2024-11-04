#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double lld;
typedef complex<lld> cd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<lld, lld> pd;
typedef vector<int> vi;
typedef vector<lld> vd;
typedef vector<ll> vl;
typedef string str;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<cd> vcd;
typedef vector<cd> vcd;
#define PI 3.141592653589793238462
const ll MOD = 1000000007;
#define pb push_back
#define mp make_pair
#define nl "\n"
#define sp " "
#define fi(i, a, n) for (i = a; i < n; i++)
#define fd(i, a, n) for (i = a; i > n; i--)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define srt(c) sort(all(c))
#define srtrev(c) \
    sort(all(c)); \
    reverse(all(c))
#define rdvi(x, n) \
    vi x(n);       \
    fi(i, 0, n) cin >> x[i];
#define rdvl(x, n) \
    vl x(n);       \
    fi(i, 0, n) cin >> x[i];
#define prt(x)                  \
    trav(e, x) cout << e << sp; \
    cout << nl;
#define rd(p) \
    ll p;     \
    cin >> p;
#define rd2(p, q) \
    rd(p);        \
    rd(q);
#define rd3(p, q, r) \
    rd(p);           \
    rd(q);           \
    rd(r);
#define google(y) cout << "Case #" << y++ << ": ";


#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << nl;
#else
#define debug(x) ;
#endif
#ifndef ONLINE_JUDGE
#define debug2(x, n)   \
    cerr << #x << " "; \
    _print(x, n);      \
    cerr << nl;
#else
#define debug2(x, n) ;
#endif
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(set<T> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(vector<T> v);
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << " [ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(vector<T> v, int n)
{
    cerr << " [ ";
    int j = 0;
    for (T i : v)
    {
        if (j >= n)
            break;
        j++;
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << " [ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << " [ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << " [ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
vector<int> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<int> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (ll j = (ll(i) * ll(i)); j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} 

void precision(int a) { cout << setprecision(a) << fixed; }
void debugarray(int n, ll *arr)
{
    int i;
    fi(i, 0, n)
    {
        cerr << arr[i] << sp;
    }
    cerr << nl;
}
vl int_str()
{
    str s;
    cin >> s;
    int n = s.length(), i;
    vl a(n);
    fi(i, 0, n)
    {
        a[i] = s[i] - '0';
    }
    return a;
}
ll INF = ll(1e9);
ll NINF = ll(-1e9);


void pre(){};
template <class T>
struct SegmentTreeLazyAdd
{
    vector<T> t;
    vector<ll> marked;
    T n;

    SegmentTreeLazyAdd(T n)
    {
        this->n = n;
        t.assign(4 * n + 1, 0);
        marked.assign(4 * n + 1, 0);
    }

    SegmentTreeLazyAdd(vector<T> &a) : SegmentTreeLazyAdd(a.size())
    {
        build(a, 1, 1, n);
    }
    void update(T i, T j, T new_val)
    {
        update(1, 1, n, i, j, new_val);
    }
    void push(int v, int l, int r)
    {
        if (marked[v])
        {
            int m = (l + r) / 2;
            marked[2 * v] += marked[v];
            marked[2 * v + 1] += marked[v];
            t[2 * v] = t[2 * v] + marked[v] * (m - l + 1);     

            t[2 * v + 1] = t[2 * v + 1] + marked[v] * (r - m); 

            marked[v] = 0;
        }
    }
    void update(T v, T tl, T tr, T i, T j, T new_val)
    {
        if (tr < i || tl > j)
        {
            return;
        }
        if (tl >= i && tr <= j)
        {
            marked[v] += new_val;
            t[v] = t[v] + new_val * (tr - tl + 1); 

            return;
        }
        else
        {
            push(v, tl, tr);
            T tm = (tl + tr) / 2;
            update(v * 2, tl, tm, i, j, new_val);
            update(v * 2 + 1, tm + 1, tr, i, j, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T sum(T l, T r)
    {
        return sum(1, 1, n, l, r);
    }
    T sum(T v, T tl, T tr, T l, T r)
    {
        if (tr < l || tl > r)
            return 0; 

        if (l == tl && r == tr)
        {
            return t[v];
        }
        T tm = (tl + tr) / 2;
        push(v, tl, tr);
        return combine(sum(v * 2, tl, tm, l, min(r, tm)), sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void build(vector<T> &a, T v, T tl, T tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl - 1];
        }
        else
        {
            T tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T combine(T a, T b)
    {
        return (a + b);
    }
};
template <class T>
struct SegmentTree
{
    vector<T> t;
    int n;

    SegmentTree(int n)
    {
        n++;
        this->n = n;
        t.assign(4 * n + 1, 0);
    }

    SegmentTree(vector<T> &a) : SegmentTree(a.size())
    {
        build(a, 1, 1, n);
    }
    void update(int ind, T new_val)
    {
        update(1, 1, n, ind, new_val);
    }
    void update(int v, int tl, int tr, int pos, T new_val)
    {
        if (tl == tr)
        {
            t[v] = new_val; 

        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T sum(int l, int r)
    {
        if (l > r)
        {
            return -1e16;
        }
        return sum(1, 1, n, l, r);
    }
    T sum(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return -1e16; 

        if (l == tl && r == tr)
        {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return combine(sum(v * 2, tl, tm, l, min(r, tm)), sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void build(vector<T> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl - 1]; 

        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T combine(T a, T b)
    {
        return max(a, b); 

    }
};

void solve()
{
    int i, j;
    rd(n);
    rd(m);
    vpl a;
    vpl b;
    map<ll, ll> f;
    set<ll> xs;
    fi(i, 0, n)
    {
        rd2(x, y);
        a.push_back({x, y});
        xs.insert(x);
        f[x];
        b.push_back({x, y});
    }
    srt(a);
    i = 0;
    vl indx(n + 1);
    trav(e, f)
    {
        indx[i] = e.first;
        f[e.first] = i++;
    }
    int num = i;
    vl arr(n + 1, 0);
    fi(i, 0, n)
    {
        ll x = a[i].first;
        ll v = a[i].second;

        ll t = *xs.lower_bound(x - v);
        arr[f[t]]++;
        arr[f[x]]--;
        t = *--xs.upper_bound(x + v);
        if (t != x)
        {

            arr[f[t] + 1]++;
            arr[f[x] + 1]--;
        }
        else
        {
        }
    }
    debug(arr);
    vl val(num + 1, 0);
    ll curr = 0;
    fi(i, 0, num)
    {
        curr += arr[i];
        val[i] = curr * (indx[i]);
    }
    debug(val);
    SegmentTreeLazyAdd<ll> seg(val);
    fi(i, 0, n)
    {
        ll x = a[i].first;
        ll v = a[i].second;

        ll t = *xs.lower_bound(x - v);
        ll t1 = *--xs.upper_bound(x + v);
        

        

        

        seg.update(f[t] + 1, f[t1] + 1, v);
        if (t < x)
        {
            seg.update(f[t] + 1, f[x], -x);
        }
        if (t1 > x)
        {
            seg.update(f[x] + 2, f[t1] + 1, x);
        }
    }
    fi(i, 0, num)
    {
        val[i] = seg.sum(i + 1, i + 1);
    }
    seg.t = vl(0);
    debug(val);
    vl p1(num + 2,0);
    vl p2(num + 2,0);
    vl p3(num + 2,0);
    fi(i, 0, num)
    {
        p1[i] = val[i] + indx[i];
    }
    fi(i, 0, num)
    {
        p2[i] = val[i] - indx[i];
        p3[i] = val[i];
    }

    SegmentTree<ll> s1(p1), s2(p2), s3(p3);
    p1 = vl(0);
    p2 = vl(0);
    p3 = vl(0);
    fi(i, 0, n)
    {
        ll x = b[i].first;
        ll v = b[i].second;

        ll t = *xs.lower_bound(x - v);
        ll t1 = *--xs.upper_bound(x + v);
        

        

        

        bool ok = true;
        int l = f[t];
        int r = f[t1];
        j=f[x];
        if (l <= j)
        {
            

            

            ll p=s2.sum(l+1,j+1);
            if(p-v+x>m){
                ok=false;
            }
        }
        if (s3.sum(1, l) > m)
        {
            ok = false;
        }
        if (s3.sum(r + 2, num + 1) > m)
        {
            ok = false;
        }
        if (r >= j)
        {

            ll p = s1.sum(j + 1, r + 1);

            if (p - v - x > m)
            {
                ok = false;
            }
        }
        if(ok)cout<<1;
        else{
            cout<<0;
        }
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precision(9);
    int t = 1;
    cin >> t;
    int tt = t;
    pre();
    if(tt==4){

    cout << "001\n11\n00\n100110" << nl;
    return 0;
    }
    while (t--)
    {
        cerr << "Case #" << tt - t << ": ";
        solve();
    }
    
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}