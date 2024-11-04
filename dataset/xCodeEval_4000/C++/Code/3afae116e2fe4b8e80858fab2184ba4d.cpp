#pragma region
#ifdef DCCLYDE_LOCAL
#include "/home/dcclyde/puzzles/code/templates/superheader.h"
#else
#define NDEBUG  

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif
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
#define mp make_pair
#define MP make_pair
#define MT make_tuple





#define tcT template<class T
#define tcTU tcT, class U


tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vll = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpii = V<pi>;
using vpl = V<pl>;
using vpll = V<pll>;
using vpd = V<pd>;





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define emp emplace


















constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bigbit(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int bigbitll(ll x) { 

    return x == 0 ? 0 : 63-__builtin_clzll(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(auto a, auto b) { return a/b-((a^b)<0&&a%b); } 


tcTU> bool ckmin(T& a, const U& b) {
    return (T)b < a ? a = (T)b, 1 : 0; } 

tcTU> bool ckmax(T& a, const U& b) {
    return a < (T)b ? a = (T)b, 1 : 0; } 


int maxi(int a, int b) {return max((int)a, (int)b);}
int mini(int a, int b) {return min((int)a, (int)b);}
ll maxll(ll a, ll b) {return max((ll)a, (ll)b);}
ll minll(ll a, ll b) {return min((ll)a, (ll)b);}


template <typename, typename = void>
constexpr bool is_iterable_v{};

template <typename T>
constexpr bool is_iterable_v<
    T,
    std::void_t< decltype(std::declval<T>().begin()),
                decltype(std::declval<T>().end())
    >
> = true;

template <typename, typename=void>
constexpr bool is_tuplelike_v{};

template <typename T>
constexpr bool is_tuplelike_v<
    T,
    void_t<
        decltype(std::get<0>(declval<T>())),
        decltype(std::tuple_size_v<T>)
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
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<class T, class U>
    size_t operator()(pair<T,U> x) const {
        uint64_t a = (*this)(x.first);
        uint64_t b = (*this)(x.second);
        return a + 3*b;
    }

    template<typename A>
    typename enable_if<is_iterable_v<A>, size_t>::type operator()(const A& v) const {
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







#define unordered_map DCCLYDE_REMINDER_DONT_USE_UNPROTECTED_HASH_MAP
#define unordered_set DCCLYDE_REMINDER_DONT_USE_UNPROTECTED_HASH_SET




#define CONCAT_INNER(a, b) a ## b
#define CONCAT(a, b) CONCAT_INNER(a, b)
#define FORll(i,a,b) for (ll i = ((ll)a); i < ((ll)b); ++i)
#define FORint(i,a,b) for (int i = ((int)a); i < ((int)b); ++i)


#define FOR3(i,a,b) FORll(i,a,b)
#define F0R(i,a) FOR(i,0,a)
#define ROFll(i,a,b) for (ll i = ((ll)b)-1; i >= ((ll)a); --i)
#define ROFint(i,a,b) for (int i = ((int)b)-1; i >= ((int)a); --i)


#define ROF(i,a,b) ROFll(i,a,b)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(CONCAT(_,__LINE__),a)
#define each(a,x) for (auto& a: x)
#define foreach(a,x) each(a,x)

#define FOR1(x) for(auto x)
#if __cplusplus >= 202002L
auto stepped_iota(ll start, ll end, ll step=1) {
    ll iter_count = cdiv(end-start, step);
    ckmax(iter_count, 0);
  return std::ranges::views::iota(0LL, iter_count) |
         std::ranges::views::transform([=](ll x) { return x * step + start; });
}
#define FOR4(i,s,e,step) for(auto i : stepped_iota(s, e, step))
#endif

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define FOR(...) GET_MACRO(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)

#pragma region  

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
#pragma endregion



const ll BIG = 1e18; 

const db PI = acos((db)-1);


vector<pii> stepsOrthogonal = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> stepsDiagonal = {{1,1},{1,-1},{-1,-1},{-1,1}};
vector<pii> steps8dirs = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
#pragma region  









#pragma endregion
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
ll sumv(ForwardIt first, ForwardIt last)
{
    

    ll out = 0;
    for (; first != last; ++first) {
        out += *first;
    }
    return out;
}
template<class T> auto sumv(const T& data) {return sumv(all(data));}
template<class T> auto max_element(const T& data) {return *max_element(all(data));}
template<class T> auto min_element(const T& data) {return *min_element(all(data));}


#define tcTUU tcT, class ...U

inline namespace Helpers {
    

    

    

    

    

    

    

    

    


    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool is_readable_v = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool is_printable_v = is_printable<T>::value;


    tcT> typename enable_if<!is_iterable_v<T> && !is_tuplelike_v<T>, void>::type increment_one(T& x, int inc) {x += inc;}
    tcT> typename enable_if<is_iterable_v<T>, void>::type increment_one(T& t, int inc) { for(auto& x : t) {increment_one(x, inc);} }

    template<class T, size_t k>
    void increment_one_tuplehelper(T& t, int inc) {
        increment_one(get<k>(t), inc);
        if constexpr (k < tuple_size_v<T> - 1) {
            increment_one_tuplehelper<T, k+1>(t, inc);
        }
    }
    tcT> typename enable_if<is_tuplelike_v<T>, void>::type increment_one(T& t, int inc) {
        increment_one_tuplehelper<T,0>(t, inc);
    }

    void increment() {} 

    tcTUU> void increment(T t, U&... u) { increment_one(t,+1); increment(u...); }
    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { increment_one(t,-1); increment(u...); }
}

inline namespace Input {
    tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;

    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    template<class A,class B,class C> void re(tuple<A,B,C>& t) {auto& [a,b,c]=t; re(a,b,c);}
    template<class A,class B,class C, class D> void re(tuple<A,B,C,D>& t) {auto& [a,b,c,d]=t; re(a,b,c,d);}
    template<class A,class B,class C, class D, class E> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e]=t; re(a,b,c,d,e);}
    template<class A,class B,class C, class D, class E, class F> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e,f]=t; re(a,b,c,d,e,f);}
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


    

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


    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
    #define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
    #define chars(...) char __VA_ARGS__; re(__VA_ARGS__);
    #define lls(...) ll __VA_ARGS__; re(__VA_ARGS__);
    #define ll1(...) lls(__VA_ARGS__); decrement(__VA_ARGS__);
    #define strings(...) string __VA_ARGS__; re(__VA_ARGS__);
}

inline namespace ToString {
    tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

    

    tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type
      ts_lev(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type
      ts_lev(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = ts_lev<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        F0R(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.back() += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    template<class T> void pr_sep1(ostream& os, str, const T& t) { os << ts(increment(t)); }
    template<class T, class... U> void pr_sep1(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep1(os,sep,t); os << sep; pr_sep1(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); }
    void ps1() { cout << "\n"; }
    template<class ...T> void ps1(const T&... t) { pr_sep1(cout," ",t...); ps1(); }
    void pso() {}
    template<class ...T> void pso(const T&... t) { pr_sep(cout," ",t...); pso(); }
    void pso1() {}
    template<class ...T> void pso1(const T&... t) { pr_sep1(cout," ",t...); pso1(); }

    template<class T>
    void pv(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<' ';} f=0; cout << x;} cout<<'\n';}
    template<class T>
    void pv1(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<' ';} f=0; cout << increment(x);} cout<<'\n';}
    template<class T>
    void pvn(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<'\n';} f=0; cout << x;} cout<<'\n';}
    template<class T>
    void pvn1(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<'\n';} f=0; cout << increment(x);} cout<<'\n';}
    


    const clock_t beg = clock();
    

    db TIME() {return (db)(clock()-beg)/CLOCKS_PER_SEC;}
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

#pragma region  






template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p);

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
string to_string(A v) {
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ", " + to_string(get<4>(p)) + ")";
}



template<class T>
string print_details_helper(T& q) {
    string out = "\n";
    int ctr = 0;
    for ( auto&& x : q ) {
        out.push_back('\t');
        out += to_string(ctr) + ":\t" + to_string(x) + "\n";
        ++ctr;
    }
    return out;
}
string print_details_helper(V<bool>& q) {
    string out = "\n";
    int ctr = 0;
    for ( auto&& x : q ) {
        out.push_back('\t');
        out += to_string(ctr) + ":\t" + to_string(static_cast<bool>(x)) + "\n";
        ++ctr;
    }
    return out;
}
#define pdh print_details_helper

template<class T>
string print_tsv_helper(T& q) {
    string out = "\n";
    for ( auto& x : q ) {
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
#define pth print_tsv_helper


void debug_out() {}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    

    

    

    std::cerr << ' ' << to_string(H) << ' ';
    if (sizeof...(T)) {
        std::cerr << " ";
        debug_out(T...);
    }
}



#define BOLD_MAYBE     ";1"  


#define OUT_RESET       "\033[0m"
#define OUT_BOLD        "\033[;1m"
#define OUT_RED         "\033[31" << "m"
#define OUT_CYAN        "\033[36" << BOLD_MAYBE << "m"


#define OUT_GREEN       "\033[32" << "m"
#define OUT_BLUE        "\033[34" << BOLD_MAYBE << "m"
#define OUT_WHITE       "\033[97" << "m"
#define OUT_MARK        "\033[0;30;41;1m"
#define OUT_YELLOW      "\033[33" << BOLD_MAYBE << "m"
#define OUT_PURPLE      "\033[35" << BOLD_MAYBE << "m"


#define dbgc(...) ;
#define dbg(...) ;
#define el ;
#define dbgcBold(...) ;
#define dbgY(...) ;
#define dbgcY(...) ;
#define dbgP(...) ;
#define dbgcP(...) ;
#define dbgR(...) ;
#define dbgcR(...) ;
#define dbgB(...) ;
#define dbgcB(...) ;
#define dbgW(...) ;
#define dbgcW(...) ;
#define dbg_only(...) ;
#define local_run (false)
#ifdef DCCLYDE_LOCAL
    

    #define dbgcbase(A, B, C, ...) std::cout << std::flush; \
        std::cerr << OUT_BOLD << B \
        << std::right << setw(20) << C << ' ' \
        << OUT_RESET << OUT_BOLD << OUT_RED \
        << std::right << setw(7) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << A << "[ " << #__VA_ARGS__ << " ]" \
        << OUT_BOLD << " :   " << OUT_RESET \
        << B, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET << std::endl;

    #undef dbgcBold
    #define dbgcBold(...) dbgcbase(OUT_GREEN, OUT_MARK, __VA_ARGS__)

    #undef dbg
    #define dbg(...) dbgcbase(OUT_GREEN, OUT_CYAN, "", __VA_ARGS__)
    #undef dbgc
    #define dbgc(...) dbgcbase(OUT_GREEN, OUT_CYAN, __VA_ARGS__)

    #undef dbgY
    #define dbgY(...) dbgcbase(OUT_GREEN, OUT_YELLOW, "", __VA_ARGS__)
    #undef dbgcY
    #define dbgcY(...) dbgcbase(OUT_GREEN, OUT_YELLOW, __VA_ARGS__)

    #undef dbgP
    #define dbgP(...) dbgcbase(OUT_GREEN, OUT_PURPLE, "", __VA_ARGS__)
    #undef dbgcP
    #define dbgcP(...) dbgcbase(OUT_GREEN, OUT_PURPLE, __VA_ARGS__)

    #undef dbgR
    #define dbgR(...) dbgcbase(OUT_GREEN, OUT_RED, "", __VA_ARGS__)
    #undef dbgcR
    #define dbgcR(...) dbgcbase(OUT_GREEN, OUT_RED, __VA_ARGS__)

    #undef dbgB
    #define dbgB(...) dbgcbase(OUT_GREEN, OUT_BLUE, "", __VA_ARGS__)
    #undef dbgcB
    #define dbgcB(...) dbgcbase(OUT_GREEN, OUT_BLUE, __VA_ARGS__)

    #undef dbgW
    #define dbgW(...) dbgcbase(OUT_GREEN, OUT_WHITE, "", __VA_ARGS__)
    #undef dbgcW
    #define dbgcW(...) dbgcbase(OUT_GREEN, OUT_WHITE, __VA_ARGS__)

    #undef dbg_only
    #define dbg_only(...) __VA_ARGS__;

    #undef el
    #define el std::cerr << std::flush; std::cerr << '\n';  


    #undef local_run
    #define local_run (true)
#endif
#pragma endregion

#define timebomb(a) dbg_only({static int _bomb = 0; if(++_bomb>=a) {dbgc("boom!", a);exit(1);}});

#define YES ps("YES");
#define NO ps("NO");
#define Yes ps("Yes");
#define No ps("No");

const ll INF_ll = ll(2e18) + 1;
const int INF_i = int(2e9) + 1;






#pragma endregion





tcT, class S> struct LazySeg {
	const T idT{}; const S idS{-1};  

	int n; V<T> seg; V<S> lazy; int orig_n; int SZ;
	T cmb(T a, T b) {  

		return a+b;
	}
	void init(int _n) {
		orig_n = _n; for (n = 1; n < _n; ) n *= 2;
		SZ = n; seg.assign(2*n,idT); lazy.assign(2*n, idS);  

	}
	void push(int ind, int L, int R) { 

        if (lazy[ind] != idS) {
            seg[ind] = (R-L+1)*lazy[ind]; 

            if (L != R) F0R(i,2) lazy[2*ind+i] = lazy[ind]; 

        }
		lazy[ind] = idS;
	} 

	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { ROF(i,1,SZ) pull(i); }
    void push_all(int ind=1, int L=0, int R=-1) {
        if ( R == -1 ) {R = SZ-1;} push(ind, L, R);
        if (L < R) {int M = (L+R)/2; push_all(2*ind, L, M); push_all(2*ind+1, M+1, R);}
    }
	void upd(int lo,int hi,S inc,int ind=1,int L=0, int R=-1) {
        if ( R == -1 ) {R = SZ-1;}
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M);
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=-1) {
        if ( R == -1 ) {R = SZ-1;}
		push(ind,L,R); if (lo > R || L > hi) return idT;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
    

	

	

    

    

	

	

	

	

    

	

	

    

	

	

    

    

	

	

	

	

    

	

	

    void detailed_printouts() {
        #pragma region
        dbg_only(
        int ST_SIZE = n;
        int ST_PRINT_SIZE = orig_n;
        

        el;
        dbgc("LazySeg DETAILS");
        FOR(k, 1, ST_SIZE + ST_PRINT_SIZE) {
            if ( k >= ST_SIZE) {
                int p = k - ST_SIZE;
                dbgP(k, p, seg[k], lazy[k]);
            } else {
                vector<int> binary_digits;
                int temp = k;
                while ( temp > 0 ) {
                    binary_digits.push_back( temp % 2 );
                    temp /= 2;
                }
                reverse(all(binary_digits));
                int L = 0; int R = ST_SIZE-1;
                FOR(didx, 1, binary_digits.size()) {
                    int M = (L+R) / 2;
                    if ( binary_digits[didx] == 1 ) {
                        L = M+1;
                    } else {
                        R = M;
                    }
                }
                if ( L < ST_PRINT_SIZE ) {
                    dbgY(k, MP(L,R), seg[k], lazy[k]);
                }
            }
        }
        el;
        );  

        #pragma endregion
    }
};

template<class T, class S>
string to_string(LazySeg<T, S> st) {
    st.push_all(); vector<T> out;
    FOR(k, st.n, st.n + st.orig_n) { out.push_back(st.seg[k]); }
    return to_string(out);
}






void solve() {
    lls(N, Q);
    strings(start_position, end_position);
    V<pll> queries;
    rv1(Q, queries);
    dbgR(N, Q);
    dbgR(start_position, end_position, queries);
    el;

    LazySeg<ll,ll> st;
    st.init(N);
    FOR(k, 0, N) {st.seg[st.n+k] = (end_position[k] == '1');}
    st.build();
    dbgY(st);

    ROF(qid, 0, Q) {
        auto& [l, r] = queries[qid];
        ll s = st.query(l, r);
        ll len = r - l + 1;
        if (2*s == len) {return NO;}
        if (2*s > len) {st.upd(l, r, 1);}
        else {st.upd(l, r, 0);}
    }
    string result(N, '0');
    FOR(k, 0, N) {result[k] += st.query(k,k);}
    if (result == start_position) {return YES;}
    else {return NO;}
}









#pragma region
int main() {
    setIO();

    int T = 1;
#ifndef SINGLE_CASE
    dbgc("loading num cases!!!"); std::cin >> T;  

#endif
    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el;
#ifndef DCCLYDE_BRUTEFORCE
        dbgcBold("CASE" , CASE );
        solve();
#else
        dbgcBold("brute force" , CASE );
        brute();
#endif
    }
    dbgR(TIME());

    return 0;
}
#pragma endregion
