


























using namespace std;

using ll = long long;
using ull = long long;
using ld = long double;
using db = double;
using str = string;  


using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;





tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;




























tcT > int lwb(V<T>& a, const T& b) { return int(lb(all(a), b) - bg(a)); }









const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  

const int dxx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dyy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); }  





int bits(int x) {
    assert(x >= 0);
    return x == 0 ? 0 : 31 - __builtin_clz(x);
}  

constexpr int p2(int x) { return 1 << x; }
constexpr int id2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }  

ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  


tcT > bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}  

tcT > bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

tcTU > T fstTrue(T lo, T hi, U f) {
    hi++;
    assert(lo <= hi);  

    while (lo < hi) {  

        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
    lo--;
    assert(lo <= hi);  

    while (lo < hi) {  

        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}
tcT > void remDup(vector<T>& v) {  

    sort(all(v));
    v.erase(unique(all(v)), end(v));
}
tcTU > void erase(T& t, const U& u) {  

    auto it = t.find(u);
    assert(it != end(t));
    t.erase(it);
}  





tcT > void re(complex<T>& c);
tcTU > void re(pair<T, U>& p);
tcT > void re(V<T>& v);
tcT, size_t SZ > void re(AR<T, SZ>& a);

tcT > void re(T& x) { cin >> x; }
void re(db& d) {
    str t;
    re(t);
    d = stod(t);
}
void re(ld& d) {
    str t;
    re(t);
    d = stold(t);
}
tcTUU > void re(T& t, U&... u) {
    re(t);
    re(u...);
}

tcT > void re(complex<T>& c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
tcTU > void re(pair<T, U>& p) { re(p.first, p.second); }
tcT > void re(V<T>& x) { trav(a, x) re(a); }
tcT, size_t SZ > void re(AR<T, SZ>& x) { trav(a, x) re(a); }
tcT > void rv(int n, V<T>& x) {
    x.rsz(n);
    re(x);
}




str ts(char c) { return str(1, c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {

    return b ? "true" : "false";

    return ts((int)b);

}
tcT > str ts(complex<T> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(V<bool> v) {
    str res = "{";
    id1(i, sz(v))
    res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
str ts(bitset<SZ> b) {
    str res = "";
    id1(i, SZ)
    res += char('0' + b[i]);
    return res;
}
tcTU > str ts(pair<T, U> p);
tcT > str ts(T v) {  


    bool fst = 1;
    str res = "{";
    for (const auto& x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;

    bool fst = 1;
    str res = "";
    for (const auto& x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;


}
tcTU > str ts(pair<T, U> p) {

    return "(" + ts(p.first) + ", " + ts(p.second) + ")";

    return ts(p.first) + " " + ts(p.second);

}



tcT > void pr(T x) { cout << ts(x); }
tcTUU > void pr(const T& t, const U&... u) {
    pr(t);
    pr(u...);
}
void ps() { pr("\n"); }  

tcTUU > void ps(const T& t, const U&... u) {
    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}



void DBG() { cerr << "]" << endl; }
tcTUU > void DBG(const T& t, const U&... u) {
    cerr << ts(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}





    if (!(id3)) cerr << "Line(" << __LINE__ << ") -> function("                     \
                             << __FUNCTION__ << ") -> CHK FAILED: (" << 
                             << "\n",                                                       \
                        exit(0);







    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
void setPrec() { cout << fixed << setprecision(15); }
void id4() { cin.tie(0)->sync_with_stdio(0); }


void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
    id4();
    setPrec();
    

    

    

    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  

}


ifstream fin("input.txt");
ofstream fout("output.txt");





const int MOD = 1e9 + 7;  

const int MX = 2e5 + 5;
const ll INF = 1e12;  


bool debug = false;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct id0 {
    int N;
    vector<ll> st, lazy;
    id0(int n) {
        N = n;
        st.resize(N * 4);
        lazy.resize(N * 4);
    }
    id0(vector<ll>& arr) {
        N = arr.size();
        st.resize(N * 4);
        lazy.resize(N * 4);
        build(arr, 1, 0, N-1);
    }
    void build(vector<ll>& arr, int node, int lo, int hi) {
        if (lo > hi) return;
        if (lo == hi) {
            st[node] = arr[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(arr, node * 2, lo, mid);
        build(arr, node * 2 + 1, mid + 1, hi);

        st[node] = min(st[node * 2], st[node * 2 + 1]);
    }
    void push(int node, int lo, int hi) {
        if (lazy[node] == 0) return;
        st[node] += lazy[node];
        if (lo != hi) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update_range(int a, int b, ll x, int node = 1, int lo = 0, int hi = -1) {
        if (hi == -1) hi = N - 1;
        push(node, lo, hi);
        if (a > hi || b < lo) return;
        if (a <= lo && hi <= b) {
            lazy[node] += x;
            push(node, lo, hi);
            return;
        }
        int mid = (lo + hi) / 2;
        update_range(a, b, x, node * 2, lo, mid);
        update_range(a, b, x, node * 2 + 1, mid + 1, hi);
        st[node] = min(st[2 * node], st[2 * node + 1]);
    }
    ll query_min(int a, int b, int node = 1, int lo = 0, int hi = -1) {
        if (hi == -1) hi = N - 1;
        push(node, lo, hi);
        if (a > hi || b < lo) return 0;
        if (a <= lo && hi <= b) return st[node];
        int mid = (lo + hi) / 2;
        return min(query_min(a, b, node * 2, lo, mid), query_min(a, b, node * 2 + 1, mid + 1, hi));
    }
};

bool cmp(pair<ll, int> a, pair<ll, int> b) {
    return a.first * b.second < a.second * b.first;
}

void solve() {
    int n, m, total = 0;
    fin >> n >> m;
    vector<pair<ll, int>> a(n);
    vector<ll> c(n + 1);
    vector<vector<ll>> b(m);
    vector<pair<ll, int>> P(m);
    id1(i, n) {
        fin >> a[i].first;
        a[i].second = 1;
    }
    a.push_back({INF, 1});
    sor(a);
    id1(i, m) {
        int k;
        fin >> k;
        total += k;
        b[i].resize(k);
        ll sum = 0;
        id1(j, k) {
            fin >> b[i][j];
            sum += b[i][j];
        }
        pair<ll, int> p = {sum, k};
        P[i] = p;
        auto it = lower_bound(all(a), p, cmp);
        int idx = it - a.begin();
        c[idx]++;
    }
    for (int i = n; i >= 0; i--) {
        if (i == n)
            c[i] = -c[i];
        else
            c[i] = c[i + 1] + 1 - c[i];
    }
    id0 st(c);
    bool cur = true;
    id1(i, n + 1) {
        if (c[i] < -1) {
            id1(i, total)
            fout << "0";
            fout << "\n";
            return;
        }
        if (c[i] < 0) cur = false;
    }
    dbg(st.st);
    string ans;
    id1(i, m) {
        pair<ll, int> p = P[i];
        auto it = lower_bound(all(a), p, cmp);
        int idx = it - a.begin();
        id1(j, b[i].size()) {
            

            

            

            

            

            

            

            

            

            

            

            

            {
                pair<ll, int> q = {p.first - b[i][j], p.second - 1};
                auto it1 = lower_bound(all(a), q, cmp);
                int idx1 = it1 - a.begin();
                if (idx1 == idx) {
                    ans.push_back(cur ? '1' : '0');
                    continue;
                }
                dbg(st.st);
                st.update_range(0, idx, 1);
                dbg(st.st);
                dbg(st.lazy);
                st.update_range(0, idx1, -1);
                dbg(st.st);
                dbg(st.lazy);
                if (st.query_min(0, n) < 0) {
                    ans.push_back('0');
                } else {
                    ans.push_back('1');
                }
                st.update_range(0, idx, -1);
                st.update_range(0, idx1, 1);
            }
        }
    }
    fout << ans << "\n";
}
int main() {
    fast_cin();
    ll t;
    fin >> t;
    for (int it = 1; it <= t; it++) {
        

        solve();
    }
    return 0;
}