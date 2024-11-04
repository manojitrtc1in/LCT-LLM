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



#define sz(c) (ll(c.size()))
#define pb push_back
#define fst first
#define scd second
#define cmpBy(T, field) [](const T& x, const T& y){ return x.field < y.field; }
#define cmpByM(T, method) [](const T& x, const T& y) { return x.method() < y.method(); }



#define sqrt(x) sqrt(1.0*(x))
#define pow(x, n) pow(1.0*(x), n)



#define INF INT_MAX
#define MINF INT_MIN
#define LINF LONG_LONG_MAX
#define LMINF LONG_LONG_MIN
#define EPS (double)1e-9
#define PI (long double)3.14159265358979311600


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




template<typename T> inline int checkbit(T n, T i){return ((n >> i) & T(1));}
inline int bitcount(int n){return __builtin_popcount(n); }
inline int bitcount(ll n){return __builtin_popcountll(n); }
template<typename T> inline bool isPowerOfTwo(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}


template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T gcd_ex(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=gcd_ex(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}


template <typename Collection, typename UnaryOperation> void foreach(Collection &col, UnaryOperation op){for_each(all(col), op);}
template <typename Collection, typename UnaryOperation> Collection fmap(Collection &col, UnaryOperation op){transform(all(col), col.begin(), op); return col;}
template <typename Collection, typename binop> Collection zip(Collection& fc, Collection& sc,binop op) {transform(all(fc), sc.begin(), fc.begin(), op); return fc;}
template <typename Collection, typename Condition> bool exists(Collection& col,Condition con) {auto exist = find_if(all(col), con); return exist != col.end();}
template <typename Collection, typename Predicate> Collection filterNot(Collection& col, Predicate predicate) {auto returnIterator = remove_if(all(col), predicate); col.erase(returnIterator, end(col)); return col;}



template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}



template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}



template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }



template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }



template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto make_tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::make_tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::make_tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> make_tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto make_tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::make_tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::make_tensor(args...); }
















































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






















































































































































































void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }

class segment_tree{
    private:
        int *t;
        int ARRLEN;

        void _upd(int pos, int val, int v, int tl, int tr) {
            if (tl == tr) {
                t[v] = val;
            } else {
                int tm = (tl + tr)/2;
                if (pos <= tm) {
                    _upd(pos, val, v*2, tl, tm);
                } else {
                    _upd(pos, val, v*2+1, tm+1, tr);
                }
                t[v] = t[v*2] + t[v*2+1];
            }
        }
        int _getSum(int l, int r, int v, int tl, int tr) {
            if (tl == l && tr == r) {
                return t[v];
            } else {
                int tm = (tl + tr)/2;
                if (r <= tm) {
                    return _getSum(l, r, v*2, tl, tm);
                } else if (l >= tm+1) {
                    return _getSum(l, r, v*2+1, tm+1, tr);
                } else {
                    return  _getSum(l, tm, v*2, tl, tm) +
                            _getSum(tm+1, r, v*2+1, tm+1, tr);
                }
            }
        }
    public:
        segment_tree (const vector<int>& a) {
            ARRLEN = a.size();
            t = (int*)malloc((4*ARRLEN+1)*sizeof(int));
            function<void(int, int, int)> build = [&](int v, int tl, int tr) {
                if (tl == tr) {
                    t[v] = a[tl];
                } else {
                    int tm = (tl + tr)/2;
                    build(v*2, tl, tm);
                    build(v*2+1, tm+1, tr);
                    t[v] = t[v*2] + t[2*v+1];
                }
            };
            build(1, 0, ARRLEN-1);
        }
        void upd(int pos, int val) {
            _upd(pos, val, 1, 0, ARRLEN-1);
        }
        int getSum(int l, int r) {
            return _getSum(l, r, 1, 0, ARRLEN-1);
        }
        int size(){
            return ARRLEN;
        }
};

int main(){






    int V; scanf("%d", &V);
    vector<vector<int>> G(V);
    vector<pii> E(V-1);
    map<pii, int> Eid;
    in_range(i, 0, V-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
        E[i] = {u, v};
        Eid[E[i]] = i;


    }


    
    int root = max_element(all(G), cmpByM(vector<int>, size))-begin(G);
    vector<vector<pii>> paths;
    vector<map<pii, int>> id;
    vector<int> toRoot(V);
    map<pii, int> Ecomponent;
    vector<int> Vcomponent(V);
    toRoot[root] = 0;
    auto extractPaths = [&]() {
        vector<bool> used(V);
        function<void(int)> dfs = [&](int v){
            used[v] = true;
            for (auto &u : G[v]) {
                if (!used[u]) {
                    toRoot[u] = toRoot[v] + 1;
                    dfs(u);
                    pii e = {v, u};
                    if (!present(e, Eid)) {
                        e = {u, v};
                    }
                    paths.back().pb(e);
                    Ecomponent[paths.back().back()] = sz(paths)-1;


                }
            }
            Vcomponent[v] = sz(paths)-1;
        };
        for (auto &u : G[root]) {
            used[root] = true;
            paths.pb({});
            id.pb({});
            toRoot[u] = 1;
            dfs(u);
            pii e = {root, u};
                if (!present(e, Eid)) {
                    e = {u, root};
            }
            Ecomponent[e] = paths.size()-1;
            paths.back().pb(e); reverse(all(paths.back()));
            in_range(i, 0, paths.back().size()) {
                id.back()[paths.back().at(i)] = i;
            }
        }
    };
    extractPaths();







    
    vector<segment_tree> trees;
    for(auto &path : paths) {
        trees.emplace_back(vector<int> (sz(path)));
    }
    int Q;
    scanf("%d", &Q);
    in_range(test, 0, Q) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int e_id;
            scanf("%d", &e_id);
            e_id--;
            pii e = E[e_id];
            int path = Ecomponent[e];
            int compId = id[path][e];
            trees[path].upd(compId, 0);


        }
        if (type == 2) {
            int e_id;
            scanf("%d", &e_id);
            e_id--;
            pii e = E[e_id];


            int path = Ecomponent[e];
            int compId = id[path][e];


            trees[path].upd(compId, 1);
        }
        if (type == 3) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            int pathU = Vcomponent[u];
            int pathV = Vcomponent[v];
            int reachable;
            if (pathU == pathV || (u == root || v == root)) {
                if (u == v) {
                    reachable = 1;
                }
                else if (u == root || v == root) {
                    if (u != root) swap(u, v);          

                    int v_prev = *min_element(all(G[v]), [&](int v1, int v2) { return toRoot[v1] < toRoot[v2]; });


                    pii e = {v, v_prev};
                    if (!present(e, Ecomponent)) {
                        e = {v_prev, v};
                    }


                    int pathE = Ecomponent[e];
                    int compId = id[pathE][e];
                    reachable = (trees[pathE].getSum(0, compId) == 0);
                }
                else if (toRoot[u] > toRoot[v]) {
                    int u_prev = *min_element(all(G[u]), [&](int v1, int v2) { return toRoot[v1] < toRoot[v2]; });
                    int v_next = *max_element(all(G[v]), [&](int v1, int v2) { return toRoot[v1] < toRoot[v2]; });
                    pii eu = {u_prev, u};   if (!present(eu, Ecomponent)) eu = {u, u_prev};
                    pii ev = {v, v_next};   if (!present(ev, Ecomponent)) ev = {v_next, v};
                    int path = Ecomponent[eu];
                    int uid = id[path][eu];
                    int vid = id[path][ev];
                    reachable = (trees[path].getSum(min(uid, vid), max(uid, vid)) == 0);
                } else {
                    int u_next = *max_element(all(G[u]), [&](int v1, int v2) { return toRoot[v1] < toRoot[v2]; });
                    int v_prev = *min_element(all(G[v]), [&](int v1, int v2) { return toRoot[v1] < toRoot[v2]; });
                    pii eu = {u, u_next};   if(!present(eu, Ecomponent)) eu = {u_next, u};
                    pii ev = {v_prev, v};   if(!present(ev, Ecomponent)) ev = {v, v_prev};
                    int path = Ecomponent[eu];
                    int uid = id[path][eu];
                    int vid = id[path][ev];
                    reachable = (trees[path].getSum(min(uid, vid), max(uid, vid)) == 0);
                }
                if (!reachable) {
                    puts("-1");
                } else {
                    printf("%d\n", abs(toRoot[u] - toRoot[v]));
                }
            } else {


                int u_prev = *min_element(all(G[u]), [&](int v1, int v2) { return toRoot[v1] < toRoot[v2]; });
                int v_prev = *min_element(all(G[v]), [&](int v1, int v2) { return toRoot[v1] < toRoot[v2]; });
                pii eu = {u_prev, u}; if (!present(eu, Ecomponent)) eu = {u, u_prev};
                pii ev = {v_prev, v}; if (!present(ev, Ecomponent)) ev = {v, v_prev};
                int Upath = Ecomponent[eu];
                int Vpath = Ecomponent[ev];
                int uid = id[Upath][eu];
                int vid = id[Vpath][ev];
                reachable = ((trees[Upath].getSum(0, uid) + trees[Vpath].getSum(0, vid)) == 0);


                if (!reachable) {




                    puts("-1");
                } else {
                    printf("%d\n", toRoot[u] + toRoot[v]);
                }
            }
        }
    }
    return 0;
}
