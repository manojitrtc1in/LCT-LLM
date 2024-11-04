




using namespace std;






typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<string> vs;
template<typename T> vector<T> table(int n, T val){ return vector<T>(n, val); }
template<typename... Args> auto table(int n, Args... args){ auto val = table(args...); return vector<decltype(val)>(n, move(val)); }
template<typename... Args> using umap = unordered_map<Args...>;
template<typename... Args> using uset = unordered_set<Args...>;
typedef umap<ll,ll> umapl;






template<class T> bool mmin(T& a, const T& b) { return b<a?a=b,1:0; }
template<class T> bool mmax(T& a, const T& b) { return a<b?a=b,1:0; }
void put() {}
template<class T, class... Args> void put(const T& a, Args... args) { cout << a; if(sizeof...(args)) cout << ' '; put(args...); }
template<class... Args> void putn(Args... args) { put(args...); cout << endl; }
template<class... Args> void putb(Args... args) { put(args...); cout << ' '; }
template<class It> void put_each(It first, It last) { while(first!=last) { put(*first); if(++first!=last) putb(); } }
template<class T> void id0(const T& a) { put_each(a.begin(),a.end()); putn(); }
template<class T> void id5(const T& a) { put_each(a.begin(),a.end()); putb(); }
void yesno(bool c) { putn(c?"YES":"NO"); }
void yes() { yesno(true); } void no() { yesno(false); }
void imp() { putn("-1"); }
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;





template <int m>    

struct modint {
  public:
    static constexpr int mod() { return m; }

    modint() : _v(0) {}

    template <class T>
    modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }

    modint(bool v) { _v = ((unsigned int)(v) % umod()); }

    unsigned int val() const { return _v; }

    modint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    modint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    modint operator++(int) {
        modint result = *this;
        ++*this;
        return result;
    }
    modint operator--(int) {
        modint result = *this;
        --*this;
        return result;
    }

    modint& operator+=(const modint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    modint& operator*=(const modint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    modint& operator/=(const modint& rhs) { return *this = *this * rhs.inv(); }

    modint operator+() const { return *this; }
    modint operator-() const { return modint() - *this; }

    modint pow(long long n) const {
        assert(0 <= n);
        modint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    modint inv() const {
        assert(_v);
        return pow(umod() - 2);
    }

    friend modint operator+(const modint& lhs, const modint& rhs) { return modint(lhs) += rhs; }
    friend modint operator-(const modint& lhs, const modint& rhs) { return modint(lhs) -= rhs; }
    friend modint operator*(const modint& lhs, const modint& rhs) { return modint(lhs) *= rhs; }
    friend modint operator/(const modint& lhs, const modint& rhs) { return modint(lhs) /= rhs; }
    friend bool operator==(const modint& lhs, const modint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const modint& lhs, const modint& rhs) { return lhs._v != rhs._v; }
    friend bool operator<(const modint& lhs, const modint& rhs) { return lhs._v < rhs._v; }
    friend string to_string(const modint& rhs) { return to_string(rhs.val()); }
    friend std::ostream& operator<<(std::ostream& os, const modint& a) { os << to_string(a); return os; }
    
  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
};

template <int m>
struct hash<modint<m>> {
    size_t operator()(const modint<m>& a) const {
        size_t ans = 0;
        ans = (ans ^ (hash<unsigned int>()(a.val()) << 1)) >> 1;
        ans = (ans ^ (hash<int>()(a.mod()) << 1)) >> 1;
        return ans;
    }
};

using mint = modint<3>;







struct graph {
    int n, ecnt = 0;
    vector<int> from,to;
    vector<vector<pair<int,int>>> edg;

    graph(int n) : n(n), edg(n) {}

    virtual int add(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        from.push_back(a); to.push_back(b);
        edg[a].push_back({ecnt,b});
        edg[b].push_back({ecnt,a});
        return ecnt++;
    }

    virtual const vector<pair<int,int>>& neigh(int u) const { return edg[u]; }

    virtual void reserve_edges(int m) {
        from.reserve(m);
        to.reserve(m);
    }
};




template<class G>
struct directed : public G {
    vector<vector<pair<int,int>>> out,in;

    directed(int n) : G(n), out(n), in(n) {}

    int add(int a, int b) {
        int e = G::add(a,b);
        out[a].push_back({e,b});
        in[b].push_back({e,a});
        return e;
    }

    const vector<pair<int,int>>& neigh(int u) const { return out[u]; }

    using is_directed_t = void;
};

template <typename T, typename = void> struct is_directed : std::false_type {};
template <typename T> struct is_directed<T, typename T::is_directed_t> : std::true_type {};
using dir_graph = directed<graph>;




template<class W, class G> 
struct weighted : public G {
    vector<W> w;

    weighted(int n) : G(n) {}
    weighted(const G& g) : G(g), w(g.ecnt) {}

    int add(int a, int b) { 
        return add(a,b,W{0}); 
    }

    int add(int a, int b, W ww) {
        w.push_back(ww);
        return G::add(a,b);
    }

    void reserve_edges(int m) {
        G::reserve_edges(m);
        w.reserve(m);
    }

    using weight_t = W;
};



template <typename T> using weight_t = typename T::weight_t;


template <typename T, typename = void> struct is_weighted : std::false_type {};
template <typename T> struct is_weighted<T, void_t<weight_t<T>>> : std::true_type {};



template <typename T> struct type_t { using type = T; };
template <typename T, typename W, typename = void> struct weight_t_else : type_t<W> {};
template <typename T, typename W> struct weight_t_else<T, W, void_t<weight_t<T>>> : type_t<weight_t<T>> {};
template <typename T, typename W> using weight_t_else_t = typename weight_t_else<T,W>::type;

template<class T> using wdir_graph = weighted<T,dir_graph>;
template<class T> using wgraph = weighted<T,graph>;




void readin(graph& g, int m, int offset = 1) {
    g.reserve_edges(m);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a -= offset;
        b -= offset;
        g.add(a,b);
    }
}

template<class G>
void id1(G& g, int m, int offset = 1) {
    static_assert(is_weighted<G>::value==true);
    g.reserve_edges(m);
    for(int i=0; i<m; i++) {
        int a, b; 
        weight_t<G> w = 0;
        cin >> a >> b >> w;
        a -= offset;
        b -= offset;
        g.add(a,b,w);
    }
}

void id6(graph& g, int offset = 1) {
    g.reserve_edges(g.n-1);
    for(int i=2; i<=g.n; i++) {
        int p; cin >> p;
        int a = i-offset;
        p -= offset;
        g.add(a,p);
    }
}
















template<class T>
int gauss (vector < vector<T> > a, vector<T> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (a[i][col].val() > a[sel][col].val())   

                sel = i;
        if (a[sel][col] == 0)    

            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                T c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        T sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (sum != a[i][m])   

            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return 2;         

    return 1;
}

bool id2(vector<vector<int> > a) {
 
    int n = a.size();
    int m = a[0].size() - 1;
    vector<int> where(m, -1), ans(m, 0);
 
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++) {
            if (a[i][col]) {
                sel = i;
                break;
            }
        }
        if (!a[sel][col])continue;
 
        for (int i = col; i <= m; i++)
            swap(a[sel][i], a[row][i]);
 
        where[col] = row;
 
        for (int i = 0; i < n; i++) {
            if (i == row)continue;
            int c = a[i][col] * a[row][col] % 3;
            if (c == 0)continue;
 
            for (int j = col; j <= m; j++) {
                a[i][j] = (a[i][j] + (3 - c) * a[row][j]) % 3;
            }
        }
        row++;
    }
 
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] * a[where[i]][i] % 3;
 
 
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j)
            sum = (sum + ans[j] * a[i][j]) % 3;
 
        if (sum != a[i][m])return false;
    }
 
    for (int i = 0; i < m; i++) {
        if (ans[i] == 0)ans[i] = 3;
        cout << ans[i] << " ";
    }
    cout << endl;
    return true;
}

void id4 (vector<vector<mint>> a, vector<mint> &ans) {
  int n = (int) a.size();
  int m = (int) a[0].size() - 1;
 
  vector<int> where (m, -1);
  for (int col=0, row=0; col<m && row<n; ++col) {
    int sel = row;
    for (int i=row; i<n; ++i)
      if (a[i][col].val() > a[sel][col].val())
        sel = i;
    if (a[sel][col] == mint(0))
      continue;
    for (int i=col; i<=m; ++i)
      swap (a[sel][i], a[row][i]);
    where[col] = row;
 
    for (int i=0; i<n; ++i)
      if (i != row) {
        mint c = a[i][col] / (a[row][col]);
        for (int j=col; j<=m; ++j)
          a[i][j] -= a[row][j] * c;
      }
    ++row;
  }
 
  ans.assign (m, 0);
  for (int i=0; i<m; ++i)
    if (where[i] != -1)
      ans[i] = a[where[i]][m] / (a[where[i]][i]);
 
  for (int i=0; i<n; ++i) {
    mint sum = 0;
    for (int j=0; j<m; ++j)
      sum += ans[j] * a[i][j];
    if (sum != a[i][m]) {
      ans.clear();
    }
  }
}

const int MAX_N = 64;
 
int conn [MAX_N][MAX_N];
 
void solve() {
    int n,m; cin >> n >> m;
    wgraph<int> g(n);
    id1(g,m);


    auto adj = table(n,n,-1);
    auto a = table(0,m+1,int(0));
    
    forn(e,m) {
        adj[g.from[e]][g.to[e]] = adj[g.to[e]][g.from[e]] = e;
        if(g.w[e]!=-1) {
            vector<int> ne(m+1,int(0));
            ne[e] = 1;
            ne[m] = g.w[e]%3;
            a.push_back(ne);
        }
    }



    forn(u,n) fora(v,u+1,n-1) {


        if(adj[u][v]==-1) continue;
        fora(i,v+1,n-1) {
            if(adj[i][u]>-1 && adj[i][v]>-1) {
                vector<int> ne(m+1,int(0));
                ne[adj[u][v]] = ne[adj[i][u]] = ne[adj[i][v]] = 1;
                a.push_back(ne);


            }
        }
    }






 
    

    if(a.empty()) {
        return id0(vi(m,1));
    }

    vector<mint> ans(m);
    bool id3 = id2(a);
    if(!id3) return imp();
    return;







    vi ans2;
    for(auto xx : ans) ans2.push_back(xx.val() + 1);
    id0(ans2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1; cin >> tc;
    while(tc--) solve();

    return 0;
}
