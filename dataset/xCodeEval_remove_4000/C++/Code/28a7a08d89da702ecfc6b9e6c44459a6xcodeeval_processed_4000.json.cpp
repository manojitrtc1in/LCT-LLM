
using namespace std;



typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int>> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pair<int, int>> vp;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<pair<int, int>>> vvp;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vector<vector<T>>>;
template <typename T>
using vvvv = vector<vector<vector<vector<T>>>>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqg = priority_queue<T, vector<T>, greater<T>>;




























    [&] {                            \
        ll ac = _ac, wa = _wa;       \
        while (abs(ac - wa) > 1) {   \
            ll wj = (ac + wa) / 2;   \
            (_f(wj) ? ac : wa) = wj; \
        }                            \
        return ac;                   \
    }()











    for (ll i = (a) + ((b) - (a)-1) / (c) * (c); i >= (a); i -= c)

    overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)













    cout << 

    cout << 
         << x3 << endl

    cout << 
         << x3 << ", " 

    cout << 
         << x3 << ", " 


    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
    (__VA_ARGS__)




template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &e : v) is >> e;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &e : v) os << e << ' ';
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto &e : v) {
        for (auto &c : e) os << c << ' ';
        os << endl;
    }
    return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << p.first << "," << p.second;
    return os;
}
template <class T>
ostream &operator<<(ostream &s, set<T> P) {
    fore(it, P) {
        s << it << " ";
    }
    return s;
}
template <class T1, class T2>
ostream &operator<<(ostream &s, map<T1, T2> P) {
    fore(x, y, P) {
        s << "<" << x << "->" << y << "> ";
    }
    return s;
}
template <class T>
ostream &operator<<(ostream &s, multiset<T> P) {
    fore(it, P) {
        s << it << " ";
    }
    return s;
}
template <class T>
ostream &operator<<(ostream &s, unordered_set<T> P) {
    fore(it, P) {
        s << it << " ";
    }
    return s;
}
template <class T1, class T2>
ostream &operator<<(ostream &s, unordered_map<T1, T2> P) {
    fore(x, y, P) {
        s << "<" << x << "->" << y << "> ";
    }
    return s;
}
struct fast_ios {
    fast_ios() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(12);
    };
} id0;

clock_t start_time = clock();
double now_time() {
    clock_t end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

void input_graph(vector<vector<int>> &g, int m = -1, int bidirected = true) {
    if (m == -1) m = g.size() - 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        if (bidirected) g[v].push_back(u);
    }
}

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {
    }

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {
    }

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt &p) const {
        return ModInt(*this) += p;
    }

    ModInt operator-(const ModInt &p) const {
        return ModInt(*this) -= p;
    }

    ModInt operator*(const ModInt &p) const {
        return ModInt(*this) *= p;
    }

    ModInt operator/(const ModInt &p) const {
        return ModInt(*this) /= p;
    }

    bool operator==(const ModInt &p) const {
        return x == p.x;
    }

    bool operator!=(const ModInt &p) const {
        return x != p.x;
    }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() {
        return mod;
    }
};

vector<int> iota(int n, int s = 0) {
    vi a(n);
    iota(a.begin(), a.end(), s);
    return a;
}
template <class T>
void sort(vector<T> &v) {
    sort(all(v));
}
template <class T>
void rsort(vector<T> &v) {
    sort(rall(v));
}
template <class T>
void reverse(vector<T> &v) {
    reverse(all(v));
}
template <class T>
auto min(const T &a) {
    return *min_element(all(a));
}
template <class T>
auto max(const T &a) {
    return *max_element(all(a));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> uniq(vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}
template <class T>
vector<T> compress(vector<T> v) {
    vector<T> v2(v.size());
    v2 = v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < (int)v2.size(); i++) {
        v2[i] = lower_bound(v.begin(), v.end(), v2[i]) - v.begin();
    }
    return v2;
}
template <typename T>
vector<T> acc(vector<T> &v, bool er = false) {
    vector<T> res(v.size() + 1);
    for (int i = 0; i < (int)v.size(); i++) {
        res[i + 1] = res[i] + v[i];
    }
    if (er) res.erase(res.begin());
    return res;
}
template <typename T>
vector<vector<T>> acc(vector<vector<T>> &v, bool er = false) {
    int h = v.size(), w = v[0].size();
    vector<vector<T>> res(h + 1, vector<T>(w + 1));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res[i + 1][j + 1] =
                v[i][j] + res[i][j + 1] + res[i + 1][j] - res[i][j];
        }
    }
    if (er) {
        res.erase(res.begin());
        for (int i = 0; i < h; i++) res[i].erase(res[i].begin());
    }
    return res;
}
template <class T>
T exp(T x, ll n) {
    T res = 1;
    while (n > 0) {
        if (n & 1) res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}
long long pow_mod(long long x, long long n, const long long &p) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}
constexpr ll ten(int n) {
    return n == 0 ? 1 : ten(n - 1) * 10;
}
long long ceil(long long x, long long y) {
    return (x + y - 1) / y;
}
void yesno(bool x) {
    if (x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
void yes() {
    cout << "YES" << endl;
}
void no() {
    cout << "NO" << endl;
}
void err() {
    cout << -1 << endl;
}

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

long long inf = 2000000000005000005;
double eps = 1e-9;




















void solve();
int r1, r2, r3;
signed main() {
    int testcase = 1;
    cin >> testcase;
    srand(time(NULL));
    r1 = rand() * rand() + rand();
    r2 = rand() * rand() + rand();
    r3 = rand() * rand() + rand();
    for (int i = 0; i < testcase; i++) {
        solve();
    }
}

int hash1(int x, int y) {
    return (x * r1) ^ (y * r2);
}

int hash2(int x, int y, char c) {
    return (x * r1) ^ (y * r2) ^ (((int)c * r3) << 2);
}
string s;
umap<int, int> mem;
umap<int, int> mem2;

int dfs(int l, int r, char last = 'Z') {
    if (l > r) return 0;
    int h1 = hash1(l, r);
    int h2 = hash2(l, r, last);
    if (last == 'Z' && mem.count(h1)) return mem[h1];
    if (last != 'Z' && mem2.count(h2)) return mem2[h2];
    if ((l + r) % 2 == 0) {
        bool draw = false;
        int x = dfs(l, r - 1);
        if (x < 0) return mem2[h2] = 1;
        if (x == 0) {
            if (s[r] < last) return mem2[h2] = 1;
            if (s[r] == last) draw = true;
        }

        x = dfs(l + 1, r);
        if (x < 0) return mem2[h2] = 1;
        if (x == 0) {
            if (s[l] < last) return mem2[h2] = 1;
            if (s[l] == last) draw = true;
        }
        if (draw) return mem2[h2] = 0;
        return mem2[h2] = -1;
    } else {
        int x = dfs(l + 1, r, s[l]);
        int y = dfs(l, r - 1, s[r]);
        if (x < 0 || y < 0) return mem[h1] = 1;
        if (x == 0 || y == 0) return mem[h1] = 0;
        return mem[h1] = -1;
    }
}

void solve() {
    s.clear();
    mem.clear();
    mem2.clear();
    cin >> s;
    int n = s.size();
    int ans = dfs(0, n - 1);
    if (ans < 0) cout << "Bob" << endl;
    if (ans == 0) cout << "Draw" << endl;
    if (ans > 0) cout << "Alice" << endl;
    

}