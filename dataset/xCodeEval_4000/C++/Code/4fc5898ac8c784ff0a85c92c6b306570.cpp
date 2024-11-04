
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>




void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define pb push_back
#define ed endl
#define doub(x) \
    ;           \
    cout << fixed << setprecision(20) << x;
#define int long long
#define ll long long
#define ld long double
#define db double
#define ull unsigned long long
#define mk make_pair
#define pii pair<int, int>
#define pldb pair<ldb, ldb>
#define ff first
#define ss second
#define vull vector<ull>
#define ub upper_bound
#define lb lower_bound
#define loop(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define sorts(v) sort(v.begin(), v.end())
#define sortg(v) sort(v.rbegin(), v.rend())
#define vi vector<int> 

#define vb vector<bool>
#define vldb vector<ldb>
#define vp vector<pii>
#define vpldb vector<pldb>
#define pqmin priority_queue<ll, vector<ll>, greater<ll>> 

#define pq priority_queue<int>                            

#define pqmaxp priority_queue<pair<int, int>>             

#define pqminp priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define mldb map<ldb, ldb>
#define us unordered_set<ll>
#define ppc(x) __builtin_popcount(x)
#define pp(x) __builtin_parity(x)
#define ppll(x) __builtin_parityll(x)
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define clzll(x) __builtin_clzll(x)
#define ctzll(x) __builtin_ctzll(x)
#define ppcll(x) __builtin_popcountll(x)
#define maxx 1e9 + 7
#define minn -(1e9 + 7)
ll mod = 1000000000 + 7; 

ll inf = 1e17;







const int N = 3e5 + 5;
bool prime[N];
void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << ed;
}
ll power(int a, int n, int p)
{
    int res = 1;
    a = a % p;
    if (a == 0)
        return 0;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % p;
        n = n >> 1;
        a = (1ll * a * a) % p;
    }
    return res;
}
bool pred(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.ss != p2.ss)
    {
        return (p1.ss < p2.ss);
    }
    else
    {
        return (p1.ff < p2.ff);
    }
}
void sort_second(vector<pair<int, int>> &v) { sort(v.begin(), v.end(), pred); }
template <typename type>
type gcd(type x, type y) { return y ? gcd(y, x % y) : x; }
template <typename type>
type lcm(type x, type y) { return x / gcd(x, y) * y; }
int countpf(int x)
{
    int ans = 0;
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0)
            ans++, x /= i;
    if (x > 1)
        ans++;
    return ans;
}
void normalize(pair<int, int> &p)
{
    int val1 = p.ff;
    int val2 = p.ss;
    int g = gcd(abs(val1), abs(val2));
    p.ff /= g;
    p.ss /= g;
}
class compa
{
public:
    bool operator()(int a, int b)
    {
        return (b < a);
    }
};



struct node1
{
    long long v = inf; 


    node1() {}
    node1(int val)
    {
        v = val; 

    }
    void merge(const node1 &l, const node1 &r)
    {
     v = min(l.v , r.v); 

    }
};



struct update1
{
    int v = inf; 

    update1() {}
    update1(int val)
    {
        v = val; 

    }
    void combine(update1 &other, const int32_t &tl, const int32_t &tr)
    {
        v = other.v; 

    }
    void apply(node1 &x, const int32_t &tl, const int32_t &tr)
    {

        

        x.v = (tr-tl+1) * v; 

    }
};



struct segtree1
{
    int len;
    vector<node1> t;
    vector<update1> u;
    vector<bool> lazy;
    node1 identity_element;
    update1 identity_transformation;
    segtree1(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node1();
        identity_transformation = update1();
    }
    void resizing(int l)
    {
        len=l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node1();
        identity_transformation = update1();
    }
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update1 upd)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node1 query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
        {
            return identity_element;
        }
        if (tl >= l && tr <= r)
        {
            return t[v];
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node1 a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    

    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update1 &upd)
    {
        if (l > tr || r < tl)
        {
            return;
        }
        if (tl >= l && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node1 query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update1 &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

struct node2
{
    long long v = -inf; 

    node2() {}
    node2(int val)
    {
        v = val; 

    }
    void merge(const node2 &l, const node2 &r)
    { 
        v = max(l.v , r.v); 

    }
};


struct update2
{
    int v = -inf; 

    update2() {}
    update2(int val)
    {
        v = val; 

    }

    void combine(update2 &other, const int32_t &tl, const int32_t &tr)
    {
        v = other.v; 

    }

    void apply(node2 &x, const int32_t &tl, const int32_t &tr)
    {

        x.v =(tr-tl+1) * v; 

    }
};

struct segtree2
{
    int len;
    vector<node2> t;
    vector<update2> u;
    vector<bool> lazy;
    node2 identity_element;
    update2 identity_transformation;
    segtree2(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node2();
        identity_transformation = update2();
    }
    void resizing(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node2();
        identity_transformation = update2();
    }
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update2 upd2)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd2, tl, tr);
        }
        upd2.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node2 query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
        {
            return identity_element;
        }
        if (tl >= l && tr <= r)
        {
            return t[v];
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node2 a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    

    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update2 &upd)
    {
        if (l > tr || r < tl)
        {
            return;
        }
        if (tl >= l && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node2 query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update2 &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};
segtree1 s1(2);
segtree2 s2(2);
vector<int>pos;
int solve(int low,int high)
{
    if(low==high)
    {
        return(0);
    }
    int mini=s1.query(low,high).v;
    int maxi=s2.query(low,high).v;
    if((pos[maxi]==low && pos[mini]==high) ||
       (pos[maxi]==high && pos[mini]==low))
    {
        return(1);
    }
    

    int ans=solve(low,min(pos[mini],pos[maxi]))+solve(min(pos[mini],pos[maxi]),max(pos[mini],pos[maxi]))+
    solve(max(pos[mini],pos[maxi]),high);
    return(ans);
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        s1.resizing(n+5);
        s2.resizing(n+5);
        pos.resize(n+5);
        for (int i = 1; i <= n; i++)
        {
            int val;
            cin>>val;
            pos[val] = i;
            s1.rupd(i,i,val);
            s2.rupd(i,i,val);
        }
        

        

        int low=1;
        int high=n;
        int ans=solve(low,high);
        cout<<ans<<ed;
    }
    return 0;
}
