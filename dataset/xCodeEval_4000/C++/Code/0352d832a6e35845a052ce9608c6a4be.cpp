#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


#define FOR(i,l,r) for (ll i = (l); i < (r); ++i)
#define RFOR(i,l,r) for (ll i = (r)-1; (l) <= i; --i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define COUNT(c,v) count(ALL(c),(v))
#define SZ(c) ((ll)(c).size())
#define BIT(b,i) (((b)>>(i)) & 1)
#define PCNT(b) __builtin_popcountll(b)
#define P0(i) (((i) & 1) == 0)
#define P1(i) (((i) & 1) == 1)
#define LB(c,v) distance((c).begin(), lower_bound(ALL(c), (v)))
#define UB(c,v) distance((c).begin(), upper_bound(ALL(c), (v)))
#define UQ(c) SORT(c), (c).erase(unique(ALL(c)), (c).end())
#define END(...) do { print(__VA_ARGS__); exit(0); } while (0)
#define elif else if
template<class T> using PQ_max = priority_queue<T>;
template<class T> using PQ_min = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = (1 << 30) - 1;   

constexpr ll INF = (1LL << 62) - 1;  

#ifdef _LOCAL
    #define debug_bar cerr << "----------------------------------------\n";
    #define debug_header cerr << "[" << __FUNCTION__ << ":" << __LINE__ << "] "
    #define debug(...) do { debug_header; cerr << #__VA_ARGS__ << " = "; view(__VA_ARGS__); cerr << '\n'; } while (0)
    #define debug2(vv) do { debug_header; cerr << #vv << " = [\n"; view2d(vv); cerr << "  ]\n"; } while (0)
    #define debug3(vvv) do { debug_header; cerr << #vvv << " = [\n"; view3d(vvv); cerr << "  ]\n"; } while (0)
    void view() {}
    void view(const int& a) { if (abs(a) == inf) { cerr << "+-"[signbit(a)] << "inf"; } else { cerr << a; } }
    void view(const ll& a) { if (abs(a) == INF) { cerr << "+-"[signbit(a)] << "INF"; } else { cerr << a; } }
    template<class T> void view(const T& a) { cerr << a; }
    template<class P1, class P2> void view(const pair<P1, P2>& a) { cerr << "("; view(a.first); cerr << ", "; view(a.second); cerr << ")"; }
    template<class T1, class T2, class T3> void view(const tuple<T1, T2, T3>& a) { cerr << "("; view(get<0>(a)); cerr << ", "; view(get<1>(a)); cerr << ", "; view(get<2>(a)); cerr << ")"; }
    template<class T1, class T2, class T3, class T4> void view(const tuple<T1, T2, T3, T4>& a) { cerr << "("; view(get<0>(a)); cerr << ", "; view(get<1>(a)); cerr << ", "; view(get<2>(a)); cerr << ", "; view(get<3>(a)); cerr << ")"; }
    template<class T> void view(const vector<T>& v){ cerr << "["; for (int i = 0; i < (int)v.size(); i++) { if (i) { cerr << ", "; } view(v[i]); } cerr << "]"; }
    template<class T> void view(const vector<vector<T>>& vv){ cerr << "["; for (int i = 0; i < (int)vv.size(); i++) { if (i) { cerr << ", "; } view(vv[i]); } cerr << "]"; }
    template<class K, class V> void view(const map<K, V>& mp){ cerr << "["; for (auto it = mp.begin(); it != mp.end(); it++) { if (it != mp.begin()) { cerr << ", "; } cerr << "("; view(it->first); cerr << ", "; view(it->second); cerr << ")"; } cerr << "]"; }
    template<class K, class V> void view(const multimap<K, V>& mmp){ cerr << "["; for (auto it = mmp.begin(); it != mmp.end(); it++) { if (it != mmp.begin()) { cerr << ", "; } cerr << "("; view(it->first); cerr << ", "; view(it->second); cerr << ")"; } cerr << "]"; }
    template<class T> void view(const set<T>& s){ cerr << "["; for (auto it = s.begin(); it != s.end(); it++) { if (it != s.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(const multiset<T>& ms){ cerr << "["; for (auto it = ms.begin(); it != ms.end(); it++) { if (it != ms.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(const deque<T>& d){ cerr << "(front)<-["; for (auto it = d.begin(); it != d.end(); it++) { if (it != d.begin()) { cerr << ", "; } view(*it); } cerr << "]"; }
    template<class T> void view(stack<T> s){ vector<T> v; while (not s.empty()) { v.push_back(s.top()); s.pop(); } reverse(v.begin(), v.end()); view(v); cerr << "->(top)"; }
    template<class T> void view(queue<T> q){ vector<T> v; while (not q.empty()) { v.push_back(q.front()); q.pop(); } cerr << "(front)<-"; view(v); }
    template<class T> void view(PQ_max<T> pq){ vector<T> v; while (not pq.empty()) { v.push_back(pq.top()); pq.pop(); } cerr << "(top)<-"; view(v); }
    template<class T> void view(PQ_min<T> pq){ vector<T> v; while (not pq.empty()) { v.push_back(pq.top()); pq.pop(); } cerr << "(top)<-"; view(v); }
    template<class T> void view2d(const vector<vector<T>>& vv){ for (int i = 0; i < (int)vv.size(); i++) { cerr << "    "; view(vv[i]); cerr << ",\n"; } }
    template<class T> void view3d(const vector<vector<vector<T>>>& vvv) { for (int i = 0; i < (int)vvv.size(); i++) { for (int j = 0; j < (int)vvv[i].size(); j++) { cerr << "    " << " ["[j == 0]; view(vvv[i][j]); if (j == (int)vvv[i].size() - 1) { cerr << "]"; } cerr << ",\n"; } if (i < (int)vvv.size() - 1) { cerr << "\n"; } } }
    template<class T, class... Ts> void view(const T& a, const Ts&... b) { view(a); cerr << ", "; view(b...); }
#else
    #define cerr if (false) cerr
    #define debug_bar
    #define debug(...)
    #define debug2(vv)
    #define debug3(vvv)
#endif
template<class... T> void input(T&... a) { (cin >> ... >> a); }
void print() { cout << '\n'; }
template<class T> void print(const T& a) { cout << a << '\n'; }
template<class T, class... Ts> void print(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void cout_line(const vector<T>& ans, int l, int r) { for (int i = l; i < r; i++) { if (i != l) { cout << ' '; } cout << ans[i]; } cout << '\n'; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> T SUM(const vector<T>& A) { return accumulate(ALL(A), T(0)); }
template<class T> vector<T> cumsum(const vector<T>& A, bool offset = false) { int N = A.size(); vector<T> S(N+1, 0); for (int i = 0; i < N; i++) { S[i+1] = S[i] + A[i]; } if (not offset) { S.erase(S.begin()); } return S; }
template<class T> string to_binary(T x, int B) { string s; while (x) { s += ('0' + (x & 1)); x >>= 1; } while ((int)s.size() < B) { s += '0'; } reverse(s.begin(), s.end()); return s; }
ll mod(ll x, ll m) { assert(m != 0); return (x % m + m) % m; }
ll ceil(ll a, ll b) { if (b < 0) { return ceil(-a, -b); } assert(b > 0); return (a < 0 ? a / b : (a + b - 1) / b); }
ll floor(ll a, ll b) { if (b < 0) { return floor(-a, -b); } assert(b > 0); return (a > 0 ? a / b : (a - b + 1) / b); }
ll powint(ll x, ll n) { assert(n >= 0); if (n == 0) { return 1; }; ll res = powint(x, n>>1); res *= res; if (n & 1) { res *= x; } return res; }
pair<ll,ll> divmod(ll a, ll b) { assert(b != 0); ll q = floor(a, b); return make_pair(q, a - q * b); }
ll bitlen(ll b) { if (b <= 0) { return 0; } return (64LL - __builtin_clzll(b)); }
ll digit_len(ll n) { assert(n >= 0); if (n == 0) { return 1; } ll sum = 0; while (n > 0) { sum++; n /= 10; } return sum; }
ll digit_sum(ll n) { assert(n >= 0); ll sum = 0; while (n > 0) { sum += n % 10; n /= 10; } return sum; }
ll digit_prod(ll n) { assert(n >= 0); if (n == 0) { return 0; } ll prod = 1; while (n > 0) { prod *= n % 10; n /= 10; } return prod; }
ll xor_sum(ll x) { assert(0 <= x); switch (x % 4) { case 0: return x; case 1: return 1; case 2: return x ^ 1; case 3: return 0; } assert(false); }
string toupper(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = toupper(T[i]); } return T; }
string tolower(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = tolower(T[i]); } return T; }
int a2i(const char& c) { assert(islower(c)); return (c - 'a'); }
int A2i(const char& c) { assert(isupper(c)); return (c - 'A'); }
int d2i(const char& d) { assert(isdigit(d)); return (d - '0'); }
char i2a(const int& i) { assert(0 <= i && i < 26); return ('a' + i); }
char i2A(const int& i) { assert(0 <= i && i < 26); return ('A' + i); }
char i2d(const int& i) { assert(0 <= i && i <= 9); return ('0' + i); }
using P = pair<ll,ll>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VVS = vector<VS>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VLD = vector<ld>;
using VVLD = vector<VLD>;
using VVVLD = vector<VVLD>;
const ld EPS = 1e-10;
const ld PI  = acosl(-1.0);



#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  


using namespace atcoder;
























































































































































int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int tt; cin >> tt;
    while (tt--) {
        int N; input(N);
        VI A(N); REP(i,N) { input(A[i]); }

        ll zero = 0;
        REP(i,N) if (A[i] == 0) { zero++; A[i]++; }

        int B = 30;
        auto check = [&](const VI& A) -> bool {
            dsu uf(B);
            ll x = 0;
            for (const auto& a : A) {
                x |= a;
                int prv = -1;
                REP(b,B) if (BIT(a,b)) {
                    if (prv == -1) {
                        prv = b;
                    } else {
                        uf.merge(prv, b);
                        prv = b;
                    }
                }
            }
            int t = -1;
            REP(b,B) if (BIT(x,b)) { t = b; break; }
            return uf.size(t) == PCNT(x);
        };

        bool ok = false;
        if (check(A)) {
            print(zero + 0);
            cout_line(A,0,N);
            ok = true;
        }
        if (ok) continue;

        REP(i,N) if (A[i] > 1) {
            A[i]--;
            if (check(A)) {
                print(zero + 1);
                cout_line(A,0,N);
                ok = true; break;
            }
            A[i]++;
        }
        if (ok) continue;

        REP(i,N) {
            A[i]++;
            if (check(A)) {
                print(zero + 1);
                cout_line(A,0,N);
                ok = true; break;
            }
            A[i]--;
        }
        if (ok) continue;

        RREP(b,B) {
            VI memo;
            REP(i,N) if (BIT(A[i],b)) memo.push_back(i);
            if (memo.size() < 2) continue;
            A[memo[0]]--;
            A[memo[1]]++;
            assert(check(A));
            print(zero + 2);
            cout_line(A,0,N);
            ok = true; break;
        }
        if (ok) continue;

        assert(false);
    }


    return 0;
}