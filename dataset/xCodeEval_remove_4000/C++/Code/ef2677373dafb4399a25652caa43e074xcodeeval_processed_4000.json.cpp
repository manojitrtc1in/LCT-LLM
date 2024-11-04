




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

const ll MOD = 1000000007;










    sort(all(c)); \
    reverse(all(c))

    vi x(n);       \
    fi(i, 0, n) cin >> x[i];

    vl x(n);       \
    fi(i, 0, n) cin >> x[i];

    trav(e, x) cout << e << sp; \
    cout << nl;

    ll p;     \
    cin >> p;

    rd(p);        \
    rd(q);

    rd(p);           \
    rd(q);           \
    rd(r);





    cerr << 
    _print(x);         \
    cerr << nl;





    cerr << 
    _print(x, n);      \
    cerr << nl;



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
    cerr << "]\n";
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
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << " [ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(queue<T, V> v)
{
    cerr << " [ ";
    while (!v.empty())
    {
        _print(v.front());
        cerr << " ";
        v.pop();
    }
    cerr << "]";
}
template <class T, class V>
void _print(stack<T, V> v)
{
    cerr << " [ ";
    while (!v.empty())
    {
        _print(v.top());
        cerr << " ";
        v.pop();
    }
    cerr << "]";
}
template <class T, class V>
void _print(priority_queue<T, V> v)
{
    cerr << " [ ";
    while (!v.empty())
    {
        _print(v.front());
        cerr << " ";
        v.pop();
    }
    cerr << "]";
}
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

    vl x(n + 1);    \
    fi(i, 1, n + 1) cin >> x[i];


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
ll id0(ll a, ll b) { return expo(a, b - 2, b); }
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
    return (mod_mul(a, id0(b, m), m) + m) % m;
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
ll INF = ll(1e15);
ll NINF = ll(-1e9);


template <class T>
struct id1
{
    vector<T> t;
    vector<bool> marked;
    T n;

    id1(T n)
    {
        this->n = n;
        t.assign(4 * n + 1, 0);
        marked.assign(4 * n + 1, false);
    }

    id1(vector<T> &a) : id1(a.size())
    {
        build(a, 1, 1, n);
    }
    void update(T i,T j, T new_val)
    {
        update(1, 1, n, i,j, new_val);
    }
    void push(int v, int l, int r)
    {
        if (marked[v])
        {
            

            t[2 * v] = t[v];
            t[2 * v + 1] = t[v];
            marked[2 * v] = true;
            marked[2 * v + 1] = true;
            marked[v] = false;
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
            t[v] = new_val;
            marked[v] = true;
            return;
        }
        else
        {
            push(v, tl, tr);
            T tm = (tl + tr) / 2;
            update(v * 2, tl, tm, i,j, new_val);
            update(v * 2 + 1, tm + 1, tr, i,j, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T sum(T l, T r,T val)
    {
        return sum(1, 1, n, l, r,val);
    }
    T sum(T v, T tl, T tr, T l, T r,T val)
    {
        if (l>r)
            return -1;
        if (l == tl && r == tr)
        {
            if(t[v]>=val)return -1;

            while(l!=r){
                push(v,l,r);
                int m=(l+r)/2;
                if(t[2*v]<val){
                    r=m;
                    v=2*v;
                }
                else{
                    l=m+1;
                    v=2*v+1;
                }
            }
            return l;
            
        }
        T tm = (tl + tr) / 2;
        push(v,tl,tr);
        int p=sum(v * 2, tl, tm, l, min(r, tm),val);
        if(p!=-1)return p;

        return sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r,val);
    }

    T sum2(T l, T r)
    {
        return sum2(1, 1, n, l, r);
    }
    T sum2(T v, T tl, T tr, T l, T r)
    {
        if (l>r)
            return INF;
        if (l == tl && r == tr)
        {
            cerr<<tl<<sp<<v<<nl;
            return t[v];
        }
        T tm = (tl + tr) / 2;
        push(v,tl,tr);
        return combine(sum2(v * 2, tl, tm, l, min(r, tm)), sum2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void build(vector<T> &a, T v, T tl, T tr)
    {
        if (tl == tr)
        {
            

            
            t[v] = a[tl];
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
        return min(a , b);
    }
};
template <class T>
struct SegmentTree
{
    vector<T> t;
    vector<bool> marked;
    T n;

    SegmentTree(T n)
    {
        this->n = n;
        t.assign(4 * n + 1, 0);
        marked.assign(4 * n + 1, false);
    }

    SegmentTree(vector<T> &a) : SegmentTree(a.size())
    {
        build(a, 1, 1, n);
    }
    void update(T i,T j, T new_val)
    {
        update(1, 1, n, i,j, new_val);
    }
    void push(int v, int l, int r)
    {
        if (marked[v])
        {
            int m = (l + r) / 2;
            t[2 * v] = t[v] / (r - l + 1) * (m - l + 1);
            t[2 * v + 1] = t[v] / (r - l + 1) * (r - m);
            marked[2 * v] = true;
            marked[2 * v + 1] = true;
            marked[v] = false;
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
            t[v] = (tr - tl + 1) * new_val;
            marked[v] = true;
            return;
        }
        else
        {
            push(v, tl, tr);
            T tm = (tl + tr) / 2;
            update(v * 2, tl, tm, i,j, new_val);
            update(v * 2 + 1, tm + 1, tr, i,j, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T sum(T l, T r)
    {
        return sum(1, 1, n, l, r);
    }
    T sum(T v, T tl, T tr, T l, T r)
    {
        if (tr<l||tl>r)
            return 0;
        if (l == tl && r == tr)
        {
            return t[v];
        }
        T tm = (tl + tr) / 2;
        push(v,tl,tr);
        return combine(sum(v * 2, tl, tm, l, min(r, tm)), sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void build(vector<T> &a, T v, T tl, T tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl ];
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
void solve()
{
    int i, j;
    rd2(n, m);
    rdvl1(a, n);
    vl curr_speed(n + 1, INF);
    vl train(n + 1, 0);
    fi(i, 1, n + 1)
    {
        if (a[i] < curr_speed[i - 1])
        {
            train[i] = 1;
            curr_speed[i] = a[i];
        }
        else
        {
            curr_speed[i] = curr_speed[i - 1];
        }
    }
    SegmentTree<ll> cnt(train);
    id1<ll> speed(curr_speed);
    

    

    

    

    

    

    debug(curr_speed);
    debug(speed.t);
    fi(i, 0, m)
    {
        rd2(k, b);
        ll p = speed.sum2(k, k);
        debug(p);
        if (a[k] - b >= p)
        {
            a[k] -= b;
        }
        else
        {
            a[k] -= b;
            ll last = n + 1;
            ll p=speed.sum(k+1,n,a[k]);
            if(p!=-1)last=p;
            last--;
            speed.update( k, last, a[k]);
            cnt.update( k + 1, last, 0);
            cnt.update(k, k, 1);
        }
        cout << cnt.sum(1, n) << sp;
    }
    cout << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precision(9);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}