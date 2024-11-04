

    

    
    
    


    

using namespace std;
using namespace __gnu_pbds;





using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;


using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<db,db>;










tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vll = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pii>;
using vpii = V<pii>;
using vpl = V<pll>;
using vpll = V<pll>;
using vpd = V<pdd>;































constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bigbit(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int id0(ll x) { 

    return x == 0 ? 0 : 63-__builtin_clzll(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id12(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(auto a, auto b) { return a/b-((a^b)<0&&a%b); } 


ll powll(ll b, ll e) {
    ll out = 1;
    while (e) {
        if (e&1) {out *= b;}
        b *= b; e >>= 1;
    }
    return out;
}
ll powmod(ll b, ll e, ll mod) {
    ll out = 1;
    while (e) {
        if (e&1) {out *= b; out %= mod;}
        b *= b; b %= mod; e >>= 1;
    }
    return out;
}



ll inv(ll a, ll p) {
    if (a == 1) {
 return 1; }
    return (p - (p / a) * inv(p % a, p)) % p;
}

ll id15(ll n, ll k, ll p) {
    

    if (k > n)  return 0;
    if (k == 0 || k == n)  return 1;

    ll res = 1;

    

    for (ll i = 0; i < k; i++) {
        res = (1LL * res * (n - i)) % p;
    }

    

    ll denom = 1;
    for (ll i = 1; i <= k; i++) {
        denom = (1LL * denom * i) % p;
    }

    

    ll id5 = inv(denom, p);

    

    res = (1LL * res * id5) % p;

    return res;
}

tcTU> bool ckmin(T& a, const U& b) {
    return (T)b < a ? a = (T)b, 1 : 0; } 

tcTU> bool ckmax(T& a, const U& b) {
    return a < (T)b ? a = (T)b, 1 : 0; } 


int maxi(int a, int b) {return max((int)a, (int)b);}
int mini(int a, int b) {return min((int)a, (int)b);}
ll maxll(ll a, ll b) {return max((ll)a, (ll)b);}
ll minll(ll a, ll b) {return min((ll)a, (ll)b);}


template <typename, typename = void>
constexpr bool id23{};

template <typename T>
constexpr bool id23<
    T,
    std::void_t< decltype(std::declval<T>().begin()),
                decltype(std::declval<T>().end())
    >
> = true;



struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id9 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id9);
    }
    template<class T, class U>
    size_t operator()(const pair<T,U>& x) const {
        uint64_t a = (*this)(x.first);
        uint64_t b = (*this)(x.second);
        return a + 3*b;
    }

    template <class... Ts> size_t operator()(const tuple<Ts...>& t) const {
        size_t out = 0;
        apply([&](const Ts& ...args) {
            ll m = 0;
            ((out += (*this)(args) * ++m), ...);
        }, t);
        return out;
    }

    template <typename A>
    typename enable_if<id23<A>, size_t>::type operator()(const A& v) const {
        uint64_t out = 0;
        uint64_t offset = 1;
        for (const auto& x : v) {
            uint64_t curr = (*this)(x);
            out ^= curr * offset;
            offset *= 3;
        }
        return out;
    }
};

template<class A, class B> using umap = gp_hash_table<A,B,custom_hash>;







template<class A> using uset = gp_hash_table<A,null_type,custom_hash>;


































auto id13(ll start, ll end, ll step=1) {
    ll iter_count = cdiv(end-start, step);
    ckmax(iter_count, 0);
  return std::ranges::views::iota(0LL, iter_count) |
         std::ranges::views::transform([=](ll x) { return x * step + start; });
}















V<int> rangeint(int start, int end, int inc=1) {
    V<int> out;
    if (inc > 0) {
        for(int curr = start; curr < end; curr += inc) {
            out.push_back(curr);
        }
        return out;
    } else {
        for(int curr = start; curr > end; curr += inc) {
            out.push_back(curr);
        }
        return out;
    }
}




const ll BIG = 1e18; 

const db PI = acos((db)-1);


vector<pii> id19 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> stepsDiagonal = {{1,1},{1,-1},{-1,-1},{-1,1}};
vector<pii> id24 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());











template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

tcT> ll fstTrue(ll lo, ll hi, T f) {
    ++hi; assert(lo <= hi); 

    while (lo < hi) { 

        ll mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
tcT> ll lstTrue(ll lo, ll hi, T f) {
    --lo; assert(lo <= hi); 

    while (lo < hi) { 

        ll mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

    auto it = t.find(u); assert(it != end(t));
    t.erase(it); }



template<class ForwardIt>
auto sumv(ForwardIt first, ForwardIt last)
{
    
    typename std::conditional<
        std::is_integral<typename std::iterator_traits<ForwardIt>::value_type>::value,
        ll,
        typename std::iterator_traits<ForwardIt>::value_type
    >::type out {};
    for (; first != last; ++first) {
        out += *first;
    }
    return out;
}
template<class T> auto sumv(T&& data) {return sumv(all(data));}
template<class T> auto max_element(T&& data) {return *max_element(all(data));}
template<class T> auto min_element(T&& data) {return *min_element(all(data));}




inline namespace Helpers {
    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id6 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id8 = is_printable<T>::value;


    tcT> typename enable_if<!id23<T>, void>::type increment_one(T& x, int inc) {x += inc;}
    tcT> typename enable_if<id23<T>, void>::type increment_one(T& t, int inc) { for(auto&& x : t) {increment_one(x, inc);} }

    template <class... Ts> void increment_one(tuple<Ts...>& t, int inc) {
        apply([&](Ts& ...args) {(increment_one(args, inc), ...);}, t);
    }

    void increment(auto& ...args) {(increment_one(args, +1), ...);} 

    void decrement(auto& ...args) {(increment_one(args, -1), ...);} 

}

inline namespace Input {
    tcT> constexpr bool id21 = !id6<T> && id23<T>;

    

    void re(auto &...args);
    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }  

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id21<T>,void>::type re(T& i); 


    template <class... Ts> void re(tuple<Ts...> &t) {
        apply([](Ts &...args) { re(args...); }, t);
    }

    tcT> typename enable_if<id21<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    void re(auto& ...args) { ((cin >> args), ...); } 


    

    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.resize(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }
    void rv1(size_t) {}
    tcTUU> void rv1(size_t N, V<T>& t, U&... u) {
        t.resize(N); re(t); for(auto& x : t) decrement(x);
        rv1(N,u...); }


    

    
    
    
    
    
    
}

inline namespace ToString {
    tcT> constexpr bool id10 = !id8<T> && id23<T>;

    

    tcT> typename enable_if<id8<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id11(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id10<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id23<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id10<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id10<T>,vs>::type
      id14(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id10<T>,vs>::type
      id14(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id14<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id11(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.back() += "}";
        return res;
    }
}

inline namespace Output {
    template<class... Ts> string tsish(const tuple<Ts...>& t) {
        string out = "";
        apply([&](const Ts& ...args) {((out += ts(args), out.push_back(' ')), ...);}, t);
        out.pop_back();
        return out;
    }
    string tsish(const char* s) {return s;}
    string tsish(const auto& t) {return to_string(t);}

    template<class T> void pr_sep(ostream& os, str, const T& t) { os << tsish(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    template<class T> void id16(ostream& os, str, T& t) { increment(t); os << tsish(t); decrement(t); }
    template<class T, class... U> void id16(ostream& os, str sep, T& t, U&... u) {
        id16(os,sep,t); os << sep; id16(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); }
    void ps1() { cout << "\n"; }
    template<class ...T> void ps1(T&... t) { id16(cout," ",t...); ps1(); }
    void pso() {}
    template<class ...T> void pso(const T&... t) { pr_sep(cout," ",t...); pso(); }
    void id1() {}
    template<class ...T> void id1(T&... t) { id16(cout," ",t...); id1(); }

    template<class T>
    void pv(T& dat) {bool f=1; for(auto&& x : dat) {if (!f) {cout<<' ';} f=0; cout << tsish(x);} cout<<'\n';}
    template<class T>
    void pv1(T& dat) {bool f=1; increment(dat); for(auto&& x : dat) {if (!f) {cout<<' ';} f=0; cout << tsish(x);} cout<<'\n'; decrement(dat);}
    template<class T>
    void pvn(T& dat) {bool f=1; for(auto&& x : dat) {if (!f) {cout<<'\n';} f=0; cout << tsish(x);} cout<<'\n';}
    template<class T>
    void id22(T& dat) {bool f=1; increment(dat); for(auto&& x : dat) {if (!f) {cout<<'\n';} f=0; cout << tsish(x);} cout<<'\n'; decrement(dat);}
    



    const clock_t beg = clock();
    
    db TIME() {return (db)(clock()-beg)/CLOCKS_PER_SEC;}

    const db beg = omp_get_wtime();
    db TIME() {return omp_get_wtime() - beg;}

    void flush() {std::cout << std::flush;}
}

inline namespace FileIO {
    void setIn(str s)  { if ( !freopen(s.c_str(),"r",stdin) ) assert(false); }
    void setOut(str s) { if ( freopen(s.c_str(),"w",stdout) ) assert(false); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        cout.tie(0);
        cin.exceptions(cin.failbit);
        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}








template <typename A, typename B>
string to_string(pair<A, B> p);

template<class ...Ts> string to_string(const tuple<Ts...>& t);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(char c) {
    return "'" + string(1, c) + "'";
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
typename enable_if<id23<A>, string>::type to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template<typename T>
V<T> id2(priority_queue<T> PQ) { 

    V<T> working;
    while (!PQ.empty()) {working.push_back(PQ.top()); PQ.pop();}
    reverse(all(working));
    return working;
}

template <typename T>
string to_string(priority_queue<T>&& PQ) {
    return to_string(id2(PQ));
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class ...Ts> string to_string(const tuple<Ts...>& t) {
    string out = "(";
    apply([&](const Ts& ...args) {((out += to_string(args) + ", "), ...);}, t);
    out.pop_back(); out.pop_back(); out.push_back(')'); return out;
}




template<class T, class S>
string id7(T&& q, S f, ll MAX) {
    string out;
    ll ctr = 0;
    bool trimmed = false;
    for ( auto&& x : q ) {
        if (ctr == MAX) {trimmed = true; break;}
        out.push_back('\t');
        out += to_string(ctr) + ":\t" + to_string(f(x)) + "\n";
        ++ctr;
    }
    

    string prefix = "";
    if (trimmed) {
        

        out.pop_back();
        out = prefix + "\n" + out + "\n\t... (full length " + to_string(q.size()) + ")";
        out.push_back('\n');
    } else {
        out = prefix + "\n" + out;
    }
    return out;
}


template<class T>
string id17(T&& q, ll MAX=id3) {
    return id7(q, [&](auto x) {return x;}, MAX);
}
string id17(V<bool>&& q, ll MAX=id3) {
    return id7(q, [&](auto x) {return static_cast<bool>(x);}, MAX);
}
template<class T>
string id17(priority_queue<T>&& PQ, ll MAX=id3) {
    return id17(id2(PQ), MAX);
}


template<class T, class S>
string id4(T&& q, S f, ll MAX=id3) {
    return id7(q, f, MAX);
}
template<class S>
string id4(V<bool>&& q, S f, ll MAX=id3) {
    return id7(q, [&](auto x) {return f(static_cast<bool>(x));}, MAX);
}
template<class T, class S>
string id4(priority_queue<T>&& PQ, S f, ll MAX=id3) {
    return id7(id2(PQ), f, MAX);
}





template<class T>
string id18(T&& q) {
    string out = "\n";
    for ( auto&& x : q ) {
        bool first = true;
        for ( auto& v : x ) {
            if ( !first ) {
                out += '\t';
            }
            out += to_string(v);
            first = false;
        }
        out += '\n';
    }
    return out;
}



void debug_out() {}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    // mostly no difference unless there's a background color.
    

    

    std::cerr << ' ' << to_string(H) << ' ';
    if (sizeof...(T)) {
        std::cerr << " ";
        debug_out(T...);
    }
}






































    

    
        std::cerr << OUT_BOLD << B \
        << std::right << setw(20) << C << ' ' \
        << OUT_RESET << OUT_BOLD << OUT_RED \
        << std::right << setw(7) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << A << "[ " << ARGTEXT << " ]" \
        << OUT_BOLD << " :   " << OUT_RESET \
        << B, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET << std::endl;

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    

    
    


    
    











const ll INF_ll = ll(2e18) + 1;
const int INF_i = int(2e9) + 1;



const int MOD = 998'244'353;






const int MAXN = 400000;

int n, t[4*MAXN];
bool marked[4*MAXN];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}


void solve() {
    lls(N);
    dbg(N)
    V<pl> segs;
    int dat[MAXN] = {0};
    build(dat, 1, 0, MAXN-1);
    FOR(i,0,N){
        lls(a,b);
        

        

        

        

        

        

        update(1, 0, MAXN-1, a, b, i+1);
    }



    ll tot = 0;
    FOR(i,0,MAXN-1){
        int x = get(1, 0, MAXN-1, i);

        if(x != 0){
            dbg(i, x, tot)
            if(x==1){
                tot += powmod(2, N-x, MOD) % MOD;
            }
            else{
            tot += 2 * powmod(3, x-2, MOD) * powmod(2, N-x, MOD) % MOD;
            }
            tot %= MOD;
        }
    }
    ps(tot);




    




    return;
}














int main() {
    setIO();

    int T = 1;
    
        dbgc("loading num cases!!!"); std::cin >> T;
    
    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        
            cout << "Case 
        
        el;
        
            dbgcBold("CASE" , CASE );
            solve();
        
            dbgcBold("brute force" , CASE );
            brute();
        
    }
    dbgR(TIME());
    return 0;
}



int main() {
    
        ll id20 = omp_get_num_procs();
        ll max_threads = omp_get_max_threads();
        dbgBold(id20, max_threads);
        omp_set_num_threads(id20 - 4);
    
    solve();
    dbgR(TIME());
    return 0;
}


