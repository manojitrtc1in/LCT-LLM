


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;














    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)





    cerr << 
    _print(x);         \
    cerr << endl;


void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(unordered_set<T> v)
{
    cerr << "[ ";
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
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

class id0
{
    ll *rank, *parent, n;

public:
    id0(ll n)
    {
        rank = new ll[n];
        parent = new ll[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (ll i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    ll find(ll x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(ll x, ll y)
    {
        ll xset = find(x);
        ll yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};
struct hashFunction
{
    size_t operator()(const pair<ll, ll> &x) const
    {
        return x.first ^ x.second;
    }
};
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id1);
    }
};
void solve()
{
    ll n;
    cin >> n;
    map<ll, vector<ll>> mmp;
    vector<ll> a(n);
    map<ll, ll> ans;
    vector<ll> ava;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        a[i] = t;
        mmp[t].push_back(i + 1);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (mmp.find(i) == mmp.end())
        {
            ava.push_back(i);
        }
    }
    ll un = 0;
    vector<ll> v;

    for (auto x : mmp)
    {
        if (x.second.size() == 1)
        {
            if (x.second[0] == x.first)
            {
                un++;
                v.push_back(x.second[0]);
                ava.push_back(x.first);
            }
            else
            {
                ans[x.second[0]] = x.first;
            }
            continue;
        }
        un += (x.second.size() - 1);
        ll tar = 0;
        for (auto y : x.second)
        {
            if (y != x.first)
            {
                tar = y;
                break;
            }
        }
        ans[tar] = x.first;
        for (auto y : x.second)
        {
            if (y != tar)
                v.push_back(y);
        }
    }
    debug(ans);
    sort(all(ava));
    debug(mmp);
    debug(ava);
    sort(all(v));
    debug(v);
    for (ll i = 1; i < v.size(); i++)
    {
        if (v[i] == ava[i])
        {
            swap(ava[i], ava[i - 1]);
        }
    }
    if (v.size() > 1 && v[0] == ava[0])
    {
        swap(ava[0], ava[1]);
    }
    debug(ava);
    for (ll i = 0; i < v.size(); i++)
    {
        ans[v[i]] = ava[i];
    }
    debug(ans);
    if (v.size() == 1 && ava[0] == v[0])
    {
        ll tar = 0;
        for (auto x : ans)
        {
            if (x.second == a[v[0] - 1])
            {
                tar = x.first;
                break;
            }
        }
        if (tar)
        {
            ans[v[0]] = ans[tar];
            ans[tar] = ava[0];
        }
        else
        {
            if (v[0] > 1)
            {
                ans[v[0]] = ans[v[0] - 1];
                ans[v[0] - 1] = ava[0];
            }
            else
            {
                ans[v[0]] = ans[v[0] + 1];
                ans[v[0] + 1] = ava[0];
            }
            un++;
        }
    }
    cout << n - un << "\n";
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main()
{

    

    

    freopen("Error.txt", "w", stderr);

    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}