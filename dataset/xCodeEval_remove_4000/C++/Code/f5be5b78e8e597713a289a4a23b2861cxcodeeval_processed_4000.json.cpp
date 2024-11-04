


















    vector<type> name(size);                                                                                                                                   \
    IN(name)


    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)







using namespace std;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


    int id0;                                                                                                                                           \
    IN(id0)

    ll id0;                                                                                                                                            \
    IN(id0)

    ull id0;                                                                                                                                           \
    IN(id0)

    string id0;                                                                                                                                        \
    IN(id0)

    char id0;                                                                                                                                          \
    IN(id0)

    double id0;                                                                                                                                        \
    IN(id0)

    ld id0;                                                                                                                                            \
    IN(id0)
int scan() { return getchar(); }
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(vector<T> &);
template <class T, size_t size> void scan(array<T, size> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T, size_t size> void scan(T (&)[size]);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(deque<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T, size_t size> void scan(array<T, size> &a) {
    for(auto &i : a) scan(i);
}
template <class T, class L> void scan(pair<T, L> &p) {
    scan(p.first);
    scan(p.second);
}
template <class T, size_t size> void scan(T (&a)[size]) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
string stin() {
    string s;
    cin >> s;
    return s;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <class T> void UNIQUE(vector<T> &x) {
    sort(all(x));
    x.erase(unique(all(x)), x.end());
}
int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}
void print() { putchar(' '); }
void print(bool a) { cout << a; }
void print(int a) { cout << a; }
void print(long long a) { cout << a; }
void print(char a) { cout << a; }
void print(string &a) { cout << a; }
void print(double a) { cout << a; }
template <class T> void print(const vector<T> &);
template <class T, size_t size> void print(const array<T, size> &);
template <class T, class L> void print(const pair<T, L> &p);
template <class T, size_t size> void print(const T (&)[size]);
template <class T> void print(const vector<T> &a) {
    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
    cout << endl;
}
template <class T> void print(const deque<T> &a) {
    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, size_t size> void print(const array<T, size> &a) {
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, class L> void print(const pair<T, L> &p) {
    cout << '(';
    print(p.first);
    cout << ",";
    print(p.second);
    cout << ')';
}
template <class T> void print(set<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T> void print(multiset<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T, size_t size> void print(const T (&a)[size]) {
    print(a[0]);
    for(auto i = a; ++i != end(a);) {
        cout << " ";
        print(*i);
    }
}
template <class T> void print(const T &a) { cout << a; }
int out() {
    putchar('\n');
    return 0;
}
template <class T> int out(const T &t) {
    print(t);
    putchar('\n');
    return 0;
}
template <class Head, class... Tail> int out(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
    return 0;
}
ll gcd(ll a, ll b) {
    while(b) {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}
ll lcm(ll a, ll b) {
    if(!a || !b) return 0;
    return a * b / gcd(a, b);
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
vector<int> divisor(int x) {
    vector<int> ans;
    for(int i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    sort(all(y));
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
int popcount(ll x) { return __builtin_popcountll(x); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }
template <typename T> void shuffle(vector<T> &v) {
    rep3(i, v.size() - 1, 1) { swap(v[i], v[rnd(i)]); }
}

vector<string> YES{"NO", "YES"};
vector<string> Yes{"No", "Yes"};
vector<string> yes{"no", "yes"};




    cout << 
    print(x);                                                                                                                                                  \
    cout << endl;
void err() {}
template <class T> void err(const T &t) {
    print(t);
    cout << " ";
}
template <class Head, class... Tail> void err(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
}


template <class... T> void err(const T &...) {}


template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedTree = vector<Edges<T>>;
template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
template <typename T> using Matrix = vector<vector<T>>;
using Graph = vector<vector<int>>;
using tree = vector<vector<int>>;

tree getTree(int n, int offset = 1) {
    tree res(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset, b -= offset;
        res[a].emplace_back(b);
        res[b].emplace_back(a);
    }
    return res;
}
template <typename T> WeightedTree<T> id2(int n, int offset = 1) {
    WeightedTree<T> res(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset, b -= offset;
        T c;
        cin >> c;
        res[a].emplace_back(b, c);
        res[b].emplace_back(a, c);
    }
    return res;
}

Graph getGraph(int n, int m, int offset = 1) {
    Graph res(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a -= offset, b -= offset;
        res[a].emplace_back(b);
        res[b].emplace_back(a);
    }
    return res;
}

template <typename T> WeightedGraph<T> id1(int n, int m, int offset = 1) {
    WeightedGraph<T> res(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        T c;
        cin >> c;
        res[a].emplace_back(b, c);
        res[b].emplace_back(a, c);
    }
}
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;









namespace modular {
ll MOD = 1;

const int MAXN = 1100000;
class modint {
    using u64 = ll;
    ll Modulus;

  public:
    u64 a;

    modint(const u64 x = 0) noexcept : Modulus(MOD), a(((x % MOD) + MOD) % MOD) {}
    u64 &value() noexcept { return a; }
    modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
    modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
    modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
    template <typename T> modint operator^(T rhs) const noexcept { return modint(*this) ^= rhs; }
    modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if(a >= Modulus) { a -= Modulus; }
        return *this;
    }
    modint &operator-=(const modint rhs) noexcept {
        if(a < rhs.a) { a += Modulus; }
        a -= rhs.a;
        return *this;
    }
    modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    bool operator==(const modint rhs) const noexcept { return a == rhs.a; }
    bool operator<(const modint rhs) const noexcept { return a < rhs.a; }
    template <typename T> modint &operator^=(T n) noexcept {
        modint res = 1;
        modint x = a;
        while(n) {
            if(n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        a = res.a;
        return *this;
    }
};


vmint Inv, Prd, Invprd;
void setmod(ll x) {
    MOD = x;
    Inv = {0, 1}, Prd = Invprd = {1, 1};
}
mint inv(int n) {
    if(Inv.size() > n)
        return Inv[n];
    else {
        for(int i = Inv.size(); i <= n; ++i) Inv.emplace_back(Inv[MOD % i] * (-MOD / i));
        return Inv[n];
    }
}
mint prd(int n) {
    if(Prd.size() > n)
        return Prd[n];
    else
        for(int i = Prd.size(); i <= n; ++i) Prd.emplace_back(Prd[i - 1] * i);
    return Prd[n];
}
mint invprd(int n) {
    if(Invprd.size() > n)
        return Invprd[n];
    else
        for(int i = Invprd.size(); i <= n; ++i) Invprd.emplace_back(Invprd[i - 1] * inv(i));
    return Invprd[n];
}
mint modpow(ll a, ll n) {
    mint x = a;
    return x ^= n;
}
modint operator/(modint l, modint r) {
    if(r.a < MAXN) return l * inv(r.a);
    return l * (r ^ (MOD - 2));
}
modint operator/=(modint &l, modint r) { return l = l / r; }
mint cmb(int a, int b) {
    if(a < b) return 0;
    if(a < 0 || b < 0) return 0;
    return prd(a) * invprd(b) * invprd(a - b);
}
ostream &operator<<(ostream &os, mint a) {
    os << a.a;
    return os;
}
istream &operator>>(istream &is, mint &a) {
    ll x;
    is >> x;
    a = x;
    return is;
}
} 


using namespace modular;

main() {
    INT(m);LL(n);
    setmod(m);
    vmint a(n);
    rep(i, n) cin >> a[i];
    if(n == m) {
        cout << "0 1\n";
        return 0;
    }
    if(n == 1 or m == 2) {
        cout << a[0] << " 0\n";
        return 0;
    }
    mint t, s;
    rep(i, n) {
        t += a[i];
        s += a[i] * a[i];
    }
    mint N = n;
    mint aa = (n * (n-1) / 2);
    mint b = n * (n-1);
    mint c = (ll)n * (n-1) * (n * 2 - 1) / 6;
    

    

    mint d, x;
    set<mint> se;
    rep(i, n) se.emplace(a[i]);
    rep(i, n) {
        x = a[i];
        d = (t - x * n) / aa;
        if(N * x * x + b * d * x + c * d * d == s) {
            int cnt = 0;
            mint now = x;
            while(cnt < n and se.count(now)) {
                cnt++;
                now += d;
            }
            if(cnt == n) {
                cout << x << " " << d << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}