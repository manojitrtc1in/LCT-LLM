

using namespace std;

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
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }
















const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);


vector<pii> id6 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> id9 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id4(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } 


int maxi(int a, int b) {return max((int)a, (int)b);}
int mini(int a, int b) {return min((int)a, (int)b);}
int maxll(ll a, ll b) {return max((ll)a, (ll)b);}
int minll(ll a, ll b) {return min((ll)a, (ll)b);}

tcTU> T fstTrue(T lo, T hi, U f) {
    ++hi; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    --lo; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } 




inline namespace Helpers {
    

    

    

    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool id8 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id0 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id1 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id7 = !id0<T> && id8<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id7<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    tcT> typename enable_if<id7<T>,void>::type re(T& i) {
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

    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
    
    
    
}

inline namespace ToString {
    tcT> constexpr bool id2 = !id1<T> && id8<T>;

    

    tcT> typename enable_if<id1<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id3(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id2<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id8<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id2<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id2<T>,vs>::type
      id5(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id2<T>,vs>::type
      id5(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id5<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id3(i,sz(res)) {
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
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); }

    template<class T>
    void pv(T& dat) {for(auto& x : dat) cout<<x<<' '; cout<<'\n';}
    


    const clock_t beg = clock();
    

    db TIME() {return (db)(clock()-beg)/CLOCKS_PER_SEC;}
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        cout.tie(0);
        cin.exceptions(cin.failbit);
        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}






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

void debug_out() { std::cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << to_string(H) << "   ";
    debug_out(T...);
}


















    

    

    
        << std::right << setw(20) << A \
        << std::right << setw(8) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << OUT_GREEN << "[ " << 
        << OUT_BOLD << " :    " << OUT_RESET \
        << OUT_CYAN, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET;
    
    

    

    
    
    

    
    

    
    
    
    
    









vector<int> psq;
void precompute() {
    const int MAX = 3162;
    vector<bool> is_prime(MAX+1, true);
    for ( int p = 2 ; p <= MAX ; ++p ) {
        if ( ! is_prime[p] ) {
            continue;
        }
        psq.push_back( p*p );
        for ( int m = 2 ; p*m <= MAX ; ++m ) {
            is_prime[p*m] = false;
        }
    }
    

    return;
}

void solve_small() {
    ints(N, K);
    vector<int> dat;
    rv(N, dat);
    dbg(N, dat);

    set<int> seen;
    int out = 1;
    for ( auto& x : dat ) {
        dbg(out, x, seen);
        for ( auto& p2 : psq ) {
            while ( x % p2 == 0 ) {
                x /= p2;
            }
        }
        if ( seen.count(x) ) {
            seen.clear();
            ++out;
        }
        seen.insert(x);
    }

    ps(out);
    return;
}


const int INF = 2e9;






tcT> struct SegTreeElements { 

	const T ID{};
    

	int n; V<T> seg; int orig_n;
	void init(int _n) { 

		for (n = 1; n < _n; ) n *= 2;
		seg.assign(2*n,ID); orig_n = _n;}
	

	void upd(int p, int c) { 

        p += n;
        int old = -3;
        if ( seg[p].size() > 0 ) {
            old = *(seg[p].begin());
            seg[p].clear();
        }
		seg[p].insert( c );
        for (p /= 2; p; p /= 2) {
            

            if ( seg[2*p].count(old) == 0 && seg[2*p+1].count(old) == 0 ) {
                seg[p].erase( old );
            }
            seg[p].insert( c );
            

        }
    }
	bool query_lt(int l, int r, int c) {	

		

		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) {
                

                if ( seg[l].lower_bound(c) != seg[l].begin() ) {
                

                    return true;
                }
                ++l;
            }
			if (r&1) {
                --r;
                if ( seg[r].lower_bound(c) != seg[r].begin() ) {
                

                    return true;
                }
                

            }
		}
		

        return false;
	}

	bool query(int l, int r, int c) {	

		

		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) {
                

                if ( seg[l].count(c) ) {
                    return true;
                }
                ++l;
            }
			if (r&1) {
                --r;
                if ( seg[r].count(c) ) {
                    return true;
                }
                

            }
		}
		

        return false;
	}

    int findFirst(int lo, int c, int p=0, int l=-1, int r=-1) {
        if ( p == 0 ) {
            l = 0;
            r = n-1;
            p = 1;
        }
        if ( r < lo || seg[p].count(c) == 0 ) {
            return -1;
        }
        int mid = (l + r) / 2;
        int result_left = findFirst(lo, c, 2*p, 0, l, mid);
        if ( result_left
        while ( p < n ) {
            if ( seg[2*p].count(c) ) {
                p *= 2;
            } else {
                p = p*2 + 1;
            }
        }
        return p - n;
    }
};



void solve() {
    ints(N, K);
    vector<int> dat;
    rv(N, dat);
    dbg(N, dat);
    map<int, pair<int, vector<int>>> appearances;

    FOR(k, 0, dat.size()) {
        auto& x = dat[k];
        for ( auto& p2 : psq ) {
            while ( x % p2 == 0 ) {
                x /= p2;
            }
        }
        appearances[x].first = -1;
        appearances[x].second.push_back( k );
    }
    dbg(appearances);

    dbg(dat);
    

    vector<vector<pii>> dp( N+1 , vector<pii>( K+1 , MP(INF, -1) ) );
    dp[0][0] = MP(1, 0);
    FOR(n, 0, N) {
        el;
        FOR(k, 0, K+1) {
            auto& [cost, nstart] = dp[n][k];
            if ( cost == INF ) {
                continue;
            }

            

            

            auto& [aptr, alist] = appearances[dat[n]];
            dbg(n, k, dp[n][k], aptr, alist);
            if ( aptr == -1 || alist[aptr] < -nstart ) {
                dp[n+1][k] = min(dp[n+1][k], dp[n][k]);
                continue;
            }

            

            if ( k < K ) {
                dp[n+1][k+1] = min(dp[n+1][k+1], dp[n][k]);
            }

            

            pair<int,int> proposed = {cost + 1, -n};
            dp[n+1][k] = min(dp[n+1][k], proposed);
        }
        appearances[dat[n]].first += 1;  

        dbg(n+1, dp[n+1]);
    }

    int out = INF;
    for ( auto& [cost, curr_start] : dp[N] ) {
        out = min(out, cost);
    }
    ps(out);
}




int main() {
    setIO();
    precompute();

    int T = 1;
    std::cin >> T;  dbgc("loading num cases!!!")  

    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el; dbgc("CASE" , CASE );
        solve();
    }

    return 0;
}
