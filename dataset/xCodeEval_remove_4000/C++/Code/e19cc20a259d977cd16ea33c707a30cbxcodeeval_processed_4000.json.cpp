
















using namespace std;
using ll = long long;
template<class T>using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD=1000000007;
const int MOD2=998244353;
const int INF=1<<30;
const ll INF2=(ll)1<<60;


void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T,class L>void scan(pair<T, L>& p){scan(p.first);scan(p.second);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}


void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T,class L>void print(const pair<T, L>& p){print(p.first);putchar(' ');print(p.second);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}


template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll modinv(ll a, ll m) {ll b = m, u = 1, v = 0;while (b) {ll t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}
ll updivide(ll a,ll b){if(a%b==0) return a/b;else return (a/b)+1;}
template<class T> void chmax(T &a,const T b){if(b>a)a=b;}
template<class T> void chmin(T &a,const T b){if(b<a)a=b;}

namespace internal {
constexpr long long safe_mod(long long x, long long m) {x %= m;if (x < 0) x += m;return x;}
struct barrett {
    unsigned int _m;
    unsigned long long im;
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned long long)(z)*im));

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};
constexpr long long id9(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}
constexpr bool id7(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id9(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {y = y * y % n;t <<= 1;}
        if (y != n - 1 && t % 2 == 0) {return false;}
    }
    return true;
}
template <int n> constexpr bool is_prime = id7(n);
constexpr std::pair<long long, long long> id1(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {long long u = s / t;s -= t * u;m0 -= m1 * u;auto tmp = s;s = t;t = tmp;tmp = m0;m0 = m1;m1 = tmp;}
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
constexpr int id5(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {divs[cnt++] = i;while (x % i == 0) {x /= i;}}
    }
    if (x > 1) {divs[cnt++] = x;}
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id9(g, (m - 1) / divs[i], m) == 1) {ok = false;break;}
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id5(m);
unsigned long long id0(unsigned long long n,unsigned long long m,unsigned long long a,unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {ans += n * (n - 1) / 2 * (a / m);a %= m;}
        if (b >= m) {ans += n * (b / m);b %= m;}
        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}
template <class T> using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;
template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}  

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id6 : internal::static_modint_base {
    using mint = id6;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {mint x;x._v = v;return x;}
    id6() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id6(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();_v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id6(T v) {_v = (unsigned int)(v % umod());}
    unsigned int val() const { return _v; }
    mint& operator++() {_v++;if (_v == umod()) _v = 0;return *this;}
    mint& operator--() {if (_v == 0) _v = umod();_v--;return *this;}
    mint operator++(int) {mint result = *this;++*this;return result;}
    mint operator--(int) {mint result = *this;--*this;return result;}
    mint& operator+=(const mint& rhs) {_v += rhs._v;if (_v >= umod()) _v -= umod();return *this;}
    mint& operator-=(const mint& rhs) {_v -= rhs._v;if (_v >= umod()) _v += umod();return *this;}
    mint& operator*=(const mint& rhs) {unsigned long long z = _v;z *= rhs._v;_v = (unsigned int)(z % umod());return *this;}
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {assert(0 <= n);mint x = *this, r = 1;while (n) {if (n & 1) r *= x;x *= x;n >>= 1;}return r;}
    mint inv() const {if (prime) {assert(_v);return pow(umod() - 2);} else {auto eg = internal::id1(_v, m);assert(eg.first == 1);return eg.second;}}
    friend mint operator+(const mint& lhs, const mint& rhs) {return mint(lhs) += rhs;}
    friend mint operator-(const mint& lhs, const mint& rhs) {return mint(lhs) -= rhs;}
    friend mint operator*(const mint& lhs, const mint& rhs) {return mint(lhs) *= rhs;}
    friend mint operator/(const mint& lhs, const mint& rhs) {return mint(lhs) /= rhs;}
    friend bool operator==(const mint& lhs, const mint& rhs) {return lhs._v == rhs._v;}
    friend bool operator!=(const mint& lhs, const mint& rhs) {return lhs._v != rhs._v;}
    

    friend istream& operator>>(istream& os,mint& rhs) noexcept {
        long long v;
        rhs = mint{(os >> v, v)};
        return os;
    }
    friend constexpr ostream& operator << (ostream &os, const mint& rhs) noexcept {
        return os << rhs._v;
    }
  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};
using mint=id6<1000000007>;
using mint2=id6<998244353>;



template< class T > struct id4{
    vector<vector<T>> data;
    id4(int H, int W) : data(H + 1, vector<T>(W + 1, 0)) {}
    void add(int y, int x, int z){
        y++, x++;
        if(y>=data.size()||x>=data[0].size())return;
        data[y][x]+=z;
    }
    void build(){
        for(int i=1;i<data.size();i++) {
            for(int j=1;j<data[i].size();j++) {
                data[i][j]+=data[i][j-1]+data[i-1][j]-data[i-1][j-1];
            }
        }
    }
    T query(int sy,int sx,int gy, int gx){
        return (data[gy][gx]-data[sy][gx]-data[gy][sx]+data[sy][sx]);
    }
};

template <class Cap, class Cost> struct id3 {
  public:
    id3() {}
    id3(int n) : _n(n), g(n) {}
    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap, cost});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0, -cost});
        return m;
    }
    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }
    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        std::vector<Cost> dual(_n, 0), dist(_n);
        std::vector<int> pv(_n), pe(_n);
        std::vector<bool> vis(_n);
        auto dual_ref = [&]() {
            std::fill(dist.begin(), dist.end(),
                      std::numeric_limits<Cost>::max());
            std::fill(pv.begin(), pv.end(), -1);
            std::fill(pe.begin(), pe.end(), -1);
            std::fill(vis.begin(), vis.end(), false);
            struct Q {
                Cost key;
                int to;
                bool operator<(Q r) const { return key > r.key; }
            };
            std::priority_queue<Q> que;
            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty()) {
                int v = que.top().to;
                que.pop();
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                for (int i = 0; i < int(g[v].size()); i++) {
                    auto e = g[v][i];
                    if (vis[e.to] || !e.cap) continue;
                    Cost cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost) {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }
            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost = cost;
        }
        return result;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

int main(){
    codefor{
        INT(n);
        vector2d(ll,A,2*n,2*n);
        in(A);
        ll ans=INF2,id2=0,id8=0;
        for(int y=n;y<2*n;y++){
            for(int x=n;x<2*n;x++){
                id2+=A[y][x];
                A[y][x]=0;
            }
        }
        out(id2+min({A[0][n],A[n-1][n],A[0][2*n-1],A[n-1][2*n-1],A[n][0],A[2*n-1][0],A[n][n-1],A[2*n-1][n-1]}));
    }
}