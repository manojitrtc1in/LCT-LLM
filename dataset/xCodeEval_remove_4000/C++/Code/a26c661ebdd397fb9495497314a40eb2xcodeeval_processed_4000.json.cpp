


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




void out() {
    cout << endl;
}
template <class T>
void out(const T &a) {
    cout << a;
    cout << endl;
}
template <class T, class... Ts>
void out(const T &a, const Ts &...b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << endl;
}

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
template <class T, class S>
bool chmax(T &a, const S &b) {
    if (a < (T)b) {
        a = (T)b;
        return 1;
    }
    return 0;
}
template <class T, class S>
bool chmin(T &a, const S &b) {
    if ((T)b < a) {
        a = (T)b;
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
long long exp(long long x, ll n) {
    long long res = 1;
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
constexpr long long ten(int n) {
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

















const int N = 5e5 + 13;
const int A = 1e6 + 13;

vi divs[A];
int a[N];
int gr_lf[N], gr_rg[N];
int less_lf[N], less_rg[N];

vi pos[A];
int ind[A];


void solve();

signed main() {
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i < A; i++) {
        for (int j = i; j < A; j += i) divs[j].pb(i);
    }
    for (int i = 0; i < testcase; i++) {
        solve();
    }
}

void solve() {
    int n;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    {
        stack<int> st;
        rep(i, n) {
            while (!st.empty() && a[st.top()] < a[i]) st.pop();
            gr_lf[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }
    {
        stack<int> st;
        rrep(i, n) {
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            gr_rg[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }
    {
        stack<int> st;
        rep(i, n) {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            less_lf[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }
    {
        stack<int> st;
        rrep(i, n) {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            less_rg[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }

    int ans = 0;
    rep(i, n) {
        for (int x : divs[a[i]]) {
            if (ind[x] >= 1) {
                int j = pos[x][ind[x] - 1];
                if (j > gr_lf[i] && less_rg[j] > i) {
                    ans += (j - max(gr_lf[i], less_lf[j])) *
                           (min(gr_rg[i], less_rg[j]) - i);
                }
            }
            if (ind[x] < (int)pos[x].size()) {
                int j = pos[x][ind[x]];
                if (j < gr_rg[i] && less_lf[j] < i) {
                    ans += (i - max({gr_lf[i], less_lf[j],
                                     ind[x] >= 1 ? pos[x][ind[x] - 1] : -1})) *
                           (min(gr_rg[i], less_rg[j]) - j);
                }
            }
        }
        ind[a[i]]++;
    }
    out(ans);
    rep(i, n) {
        pos[a[i]].erase(all(pos[a[i]]));
        gr_lf[i] = gr_rg[i] = less_lf[i] = less_rg[i] = 0;
        ind[a[i]] = 0;
    }
}