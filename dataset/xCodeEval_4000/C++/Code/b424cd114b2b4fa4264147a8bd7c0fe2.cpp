#define _CRT_DISABLE_PERFCRIT_LOCKS
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;




#define in_range(i, l, r) for(ll i = l; i < r; i++)

#define all(v) begin(v), end(v)
#define rall(v) (v).rbegin(), (v).rend()

#define tr(it, container) for(auto it = begin(container); it != end(container); it++)
#define rtr(it, container) for(auto it = (container).rbegin(); it != (container).rend(); it++)

#define present(element, container) ((container).find(element) != end(container))

#define _T(...) __VA_ARGS__
#define forever() for(;;)



#define sz(c) (ll(c.size()))
#define pb push_back
#define fst first
#define scd second
#define cmpBy(T, field) [](const T& x, const T& y){ return x.field < y.field; }



#define sqrt(x) sqrt(1.0*(x))
#define pow(x, n) pow(1.0*(x), n)



#define INF (numeric_limits<int>::max())
#define MINF (numeric_limits<int>::min())
#define LINF (numeric_limits<long long>::max())
#define LMINF (numeric_limits<long long>::min())
#define EPS (1E-9)
#define PI ((long double)3.14159265358979311600)

#define reunique(container) ((container).resize(unique(all(container))-begin(container)))


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;




template<typename T> inline int checkbit(T n, T i){return ((n >> i) & T(1));}
inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<typename T> inline bool isPowerOfTwo(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }

void bitprint(int n, int w=32){ for (int i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }
void bitprint(ll n, int w=64){ for (ll i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }


template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T gcd_ex(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=gcd_ex(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}


template <typename Collection, typename UnaryOperation> void foreach(Collection &col, UnaryOperation op){for_each(all(col), op);}
template <typename Collection, typename UnaryOperation> Collection fmap(Collection &col, UnaryOperation op){transform(all(col), col.begin(), op); return col;}
template <typename Collection, typename binop> Collection zip(Collection& fc, Collection& sc,binop op) {transform(all(fc), sc.begin(), fc.begin(), op); return fc;}
template <typename Collection, typename Condition> bool exists(Collection& col,Condition con) {auto exist = find_if(all(col), con); return exist != col.end();}
template <typename Collection, typename Predicate> Collection filterNot(Collection& col, Predicate predicate) {auto returnIterator = remove_if(all(col), predicate); col.erase(returnIterator, end(col)); return col;}



void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }
template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}
template<class T> inline void getarr(T* arr, int l, int r) { in_range(i, l, r) cin >> arr[i]; }



template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> inline void printarr(T* arr, int l, int r) { in_range(i, l, r) {cout << arr[i] << " ";}; cout << "\n"; }



template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }



template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }



template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::tensor(args...); }
















































#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)         cerr<<#a<<" = "<<(a)<<"\n"
#define DBN2(a,b)       cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<"\n"
#define DBN3(a,b,c)     cerr<<#a<<" = "<<(a)<<", "<<#b<<" = " <<(b)<<", "<<#c<<" = "<<(c)<<"\n"
#define DBN4(a,b,c,d)   cerr<<#a<<" = "<<(a)<<", "<<#b<<" ="<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)

#define DEBUG






















































































































template<int N, char Aa = '0', char Az = '9'>
struct AhoCorasick{
const static int A = Az-Aa+1;
    int trie[N][A];
    int size = 0;
    bool end[N];
    int link[N];
    int queue[N];

    int add_node() {
        memset(trie[size], 0, A * sizeof(int));
        end[size] = link[size] = 0;
        return size++;
    }

    AhoCorasick() { init(); }
    void init() { size = 0; add_node(); }
    void add_string(const char* s, int n) {
        int state = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i]-Aa;
            if (!trie[state][c]) trie[state][c] = add_node();
            state = trie[state][c];
        }
        end[state] = true;
    }
    void construct() {
        queue[0] = 0;
        for (int qa = 0, qb = 1; qa < qb; ++qa) {
            int v = queue[qa];
            for (int c = 0; c < A; c++) {
                if (trie[v][c]) {
                    int u = link[v];
                    while (u != 0 && !trie[u][c]) u = link[u];
                    link[trie[v][c]] = v == 0 ? 0 : trie[u][c];
                    queue[qb++] = trie[v][c];
                } else { trie[v][c] = trie[link[v]][c]; }
            }
        }
    }
};

const int MAXN = 1001, MAXLEN = 51, MAXV = MAXN*MAXLEN/2;
const int MOD = 1e9+7;
char s[MAXN], x[MAXLEN], y[MAXLEN];
AhoCorasick<MAXV> AC;
int dp[MAXLEN][MAXV][8];

int main(){






    scanf("%s%s%s", s, x, y);
    int n = strlen(s);
    int d = strlen(x);
    int halfd = d/2;
    for (int i = 0; i < n-halfd+1; i++) {
        AC.add_string(s+i, halfd);
    }
    AC.construct();
    dp[0][0][3] = 1;
    for (int len = 0; len < d; len++) {
        for (int v = 0; v < AC.size; v++) {
            for (int mask = 0; mask < 8; mask++) {
                if (dp[len][v][mask]) {
                    for (int c = 0; c < 10; c++) {
                        int newmask = mask&4;
                        if (mask & 1) {
                            if (x[len]-'0' > c) continue;
                            if (x[len]-'0' == c) newmask |= 1;
                        }
                        if (mask & 2) {
                            if (y[len]-'0' < c) continue;
                            if (y[len]-'0' == c) newmask |= 2;
                        }
                        int u = AC.trie[v][c];
                        if (AC.end[u]) newmask |= 4;
                        int &res = dp[len+1][u][newmask];
                        res += dp[len][v][mask];
                        if (res >= MOD) res -= MOD;
                    }
                }
            }
        }
    }
    int answ = 0;
    for (int v = 0; v < AC.size; v++) {
        for (int mask = 0; mask < 4; mask++) {
            answ += dp[d][v][mask|4];
            if (answ >= MOD) answ -= MOD;
        }
    }
    printf("%d\n", answ);
    return 0;
}
