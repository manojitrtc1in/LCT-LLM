






using namespace std;
using namespace chrono;
using namespace __gnu_pbds;



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


























void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}





mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());








const int MOD = 1e9 + 7;
const int N = 100005;
inline int gcd(int a, int b)   {if (b == 0) return a; return gcd(b, a % b);}

int lcm(int a, int b)          {return (a * b) / __gcd(a, b);}

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void init_code()
{

    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);


}

int id3(int n, int r, int p)
{
    int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            C[j] = (C[j] + C[j - 1]) % p;
        }
    }
    return C[r];
}

vector<int> primes(N + 1, 1);
void id4()
{
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (primes[i] == 1)
        {
            for (int j = 2; i * j <= N; j++)
            {
                primes[i * j] = 0;
            }
        }
    }
}

ll id5(int base, int power)
{
    long long ans = 1;
    while (power > 0)
    {
        if ((power % 2) == 0)
        {
            base = base * base;
            power /= 2;
        }
        else
        {
            ans *= base;
            power -= 1;
        }
    }
    return ans;
}

ll id1(string s)
{
    reverse(all(s));
    ll ans = 0;
    int i = 0;
    while (i < s.length())
    {
        ll num = (s[i] - '0') * id5(10, i);
        ans += num;
        i++;
    }
    return ans;
}

void dfs(int vertex, vector<int> *graph, vector<bool> &vis)
{
    
    vis[vertex] = 1;
    for (auto child : graph[vertex])
    {
        
        if (!vis[child])
        {
            dfs(child, graph, vis);
        }
        
    }
    
}

class dsu
{
    ll parent[N];
    ll size[N];
public:
    void make(ll v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    int find(ll v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void Union(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};


class Segment_tree
{
    ll n;
    ll *array, *seg_tree;
public:
    Segment_tree(vector<int> &v)
    {
        n = v.size();
        array = new ll[n];
        seg_tree = new ll[4 * n];
        rep(i, 0, v.size())
        {
            array[i] = v[i];
        }
    }

    void build(ll ind, ll low, ll high)
    {
        if (low == high)
        {
            seg_tree[ind] = array[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        seg_tree[ind] = max(seg_tree[2 * ind + 1], seg_tree[2 * ind + 2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r)
    {
        

        

        if ((low >= l) and (high <= r))
        {
            return seg_tree[ind];
        }

        

        

        if ((l > high) || (r < low))
        {
            return INT_MIN;
        }

        ll mid = (low + high) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }

    void update(ll ind, ll low, ll high, ll newind, ll val)
    {
        if (low == high)
        {
            seg_tree[ind] = val;
            return;
        }
        ll mid = low + (high - low) / 2;
        if (newind <= mid)
        {
            update(2 * ind + 1, low, mid, newind, val);
        }
        else {
            update(2 * ind + 2, mid + 1, high, newind, val);
        }
        seg_tree[ind] = max(seg_tree[2 * ind + 1], seg_tree[2 * ind + 2]);
    }
};


class id2
{
    ll n;
    vll arr, seg_tree, lazy;
public:
    id2(vll v)
    {
        n = v.size();
        arr.resize(4 * n);
        seg_tree.resize(4 * n);
        lazy.resize(4 * n);
        rep(i, 0, n)
        {
            arr[i] = v[i];
        }
        rep(i, 0, n)
        {
            seg_tree[i] = 0;
            lazy[i] = 0;
        }
    }

    void build_lazy(ll ind, ll low, ll high)
    {
        if (low == high)
        {
            seg_tree[ind] = arr[low];
            return;
        }

        ll mid = (low + high) / 2;
        build_lazy(2 * ind + 1, low, mid);
        build_lazy(2 * ind + 2, mid + 1, high);
        seg_tree[ind] = seg_tree[2 * ind + 1] + seg_tree[2 * ind + 2];
    }

    void update_lazy(ll ind, ll low, ll high, ll l, ll r, ll val)
    {
        

        if (lazy[ind] != 0)
        {
            seg_tree[ind] += (high - low + 1) * lazy[ind];
            

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        

        

        if (high < l || low > r)
        {
            return;
        }
        

        

        if (low >= l && high <= r)
        {
            

            seg_tree[ind] += (high - low + 1) * val;
            

            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        

        ll mid = (low + high) / 2;
        update_lazy(2 * ind + 1, low, mid, l, r, val);
        update_lazy(2 * ind + 2, mid + 1, high, l, r, val);
        seg_tree[ind] = seg_tree[2 * ind + 1] + seg_tree[2 * ind + 2];
    }

    ll query_lazy(ll ind, ll low, ll high, ll l, ll r)
    {
        

        if (lazy[ind] != 0)
        {
            seg_tree[ind] += (high - low + 1) * lazy[ind];
            

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        

        

        if (high < l || low > r)
        {
            return 0;
        }

        

        

        if (low >= l and high <= r)
        {
            return seg_tree[ind];
        }

        

        ll mid = (low + high) / 2;
        ll left = query_lazy(2 * ind + 1, low, mid, l, r);
        ll right = query_lazy(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void print()
    {
        rep(i, 0, n)
        {
            cout << seg_tree[i] << " ";
        }
    }
};

class id0
{
    int n;
    vi fen_tree;
public:
    id0(int num)
    {
        n = num + 1;
        fen_tree.assign(n, 0);
    }

    void update_fen(int ind, int val)
    {
        while (ind < n)
        {
            fen_tree[ind] += val;
            ind = ind + (ind & (-ind));
        }
    }

    int sum_fen(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += fen_tree[i];
            i = i - (i & (-i));
        }

        return s;
    }

    int rangesum_fen(int l, int r)
    {
        return sum_fen(r) - sum_fen(l - 1);
    }

    int lower_bound_fen(int k)
    {
        int cur = 0, prevsum = 0;
        re(i, log(n), 0)
        {
            if (fen_tree[cur + (1 << i)] < k)
            {
                cur += (1 << i);
                prevsum += fen_tree[cur];
            }
        }

        return (cur + 1);
    }

    void print_fen()
    {
        rep(i, 0, n)
        {
            cout << fen_tree[i] << " ";
        }
        cout << endl;
    }
};

bool isprime(ll n)
{
    rep(i, 2, sqrt(n) + 1)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void f1(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<pair<int, int>>> &sim)
{
    if ((i > n) || (j > m)) {
        return;
    }
    

    

    

    

    

    

    

    

    

    

    sim[i][j].first = min(sim[i - 1][j].first, sim[i][j - 1].first) + grid[i][j];
    sim[i][j].second = max(sim[i - 1][j].second, sim[i][j - 1].second) + grid[i][j];
    

    

    

    

    f1(i + 1, j, n, m, grid, sim);
    f1(i, j + 1, n, m, grid, sim);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    rep(i, 1, n + 1)
    {
        rep(j, 1, m + 1)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<pair<int, int>>> sim(n + 1, vector<pair<int, int>> (m + 1, {0, 0}));
    rep(i, 1, m + 1)
    {
        sim[1][i].first = sim[1][i - 1].first + grid[1][i];
        sim[1][i].second = sim[1][i - 1].second + grid[1][i];
    }
    rep(i, 1, n + 1)
    {
        sim[i][1].first = sim[i - 1][1].first + grid[i][1];
        sim[i][1].second = sim[i - 1][1].second + grid[i][1];
    }
    

    

    

    


    rep(i, 2, n + 1)
    {
        rep(j, 2, m + 1)
        {
            sim[i][j].first = min(sim[i - 1][j].first, sim[i][j - 1].first) + grid[i][j];
            sim[i][j].second = max(sim[i - 1][j].second, sim[i][j - 1].second) + grid[i][j];
        }
    }

    

    

    

    

    

    

    

    

    

    if ((n + m) % 2 == 0)
    {
        cout << "NO\n";
        return;
    }
    if ((sim[n][m].first <= 0) and (sim[n][m].second >= 0))
    {
        if (sim[n][m].first % 2 == 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main()
{
    init_code();

    freopen("Error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto start1 = high_resolution_clock::now();
    test
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

    cerr << "Time: " << duration.count() / 1000 << endl;

    return 0;
}