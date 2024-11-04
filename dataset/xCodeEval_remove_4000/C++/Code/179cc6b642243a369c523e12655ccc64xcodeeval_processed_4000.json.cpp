









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
using vpi = V<pi>;
using vpii = V<pi>;
using vpl = V<pl>;
using vpll = V<pll>;
using vpd = V<pd>;

































constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bigbit(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int id1(ll x) { 

    return x == 0 ? 0 : 63-__builtin_clzll(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id11(int x) { return p2(x)-1; }

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




struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id8 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id8);
    }
    template<class T, class U>
    size_t operator()(pair<T,U> x) const {
        uint64_t a = (*this)(x.first);
        uint64_t b = (*this)(x.second);
        return a + 3*b;
    }
};

template<class A, class B> using umap = gp_hash_table<A,B,custom_hash>;







template<class A> using uset = gp_hash_table<A,null_type,custom_hash>;































auto id12(ll start, ll end, ll step=1) {
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




inline namespace Helpers {
    

    

    

    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool id23 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id4 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id7 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id21 = !id4<T> && id23<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id4<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id21<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    template<class A,class B,class C> void re(tuple<A,B,C>& t) {auto& [a,b,c]=t; re(a,b,c);}
    template<class A,class B,class C, class D> void re(tuple<A,B,C,D>& t) {auto& [a,b,c,d]=t; re(a,b,c,d);}
    template<class A,class B,class C, class D, class E> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e]=t; re(a,b,c,d,e);}
    template<class A,class B,class C, class D, class E, class F> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e,f]=t; re(a,b,c,d,e,f);}
    tcT> typename enable_if<id21<T>,void>::type re(T& i) {
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
        t.resize(N); re(t); for(auto& x : t) --x;
        rv1(N,u...); }


    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
    
    
    
    
}

inline namespace ToString {
    tcT> constexpr bool id9 = !id7<T> && id23<T>;

    

    tcT> typename enable_if<id7<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id10(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id9<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id23<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id9<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id9<T>,vs>::type
      id13(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id9<T>,vs>::type
      id13(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id13<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id10(i,sz(res)) {
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
    template<class T> void id16(ostream& os, str, const T& t) { os << ts(t+1); }
    template<class T, class... U> void id16(ostream& os, str sep, const T& t, const U&... u) {
        id16(os,sep,t); os << sep; id16(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); }
    void ps1() { cout << "\n"; }
    template<class ...T> void ps1(const T&... t) { id16(cout," ",t...); ps1(); }
    void pso() {}
    template<class ...T> void pso(const T&... t) { pr_sep(cout," ",t...); pso(); }
    void id2() {}
    template<class ...T> void id2(const T&... t) { id16(cout," ",t...); id2(); }

    template<class T>
    void pv(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<' ';} f=0; cout << x;} cout<<'\n';}
    template<class T>
    void pv1(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<' ';} f=0; cout << x+1;} cout<<'\n';}
    template<class T>
    void pvn(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<'\n';} f=0; cout << x;} cout<<'\n';}
    template<class T>
    void id22(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<'\n';} f=0; cout << x+1;} cout<<'\n';}
    


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
string id17(T& q) {
    string out = "\n";
    int ctr = 0;
    for ( auto& x : q ) {
        out.push_back('\t');
        out += to_string(ctr) + ":\t" + to_string(x) + "\n";
        ++ctr;
    }
    return out;
}


template<class T>
string id18(T& q) {
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



void debug_out() {}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    

    

    

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
        << A << "[ " << 
        << OUT_BOLD << " :   " << OUT_RESET \
        << B, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET << std::endl;

    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    

    
    


    
    
















const ll INF = 1e9;

char other_char(char c) {
    return (c == 'R') ? 'L' : 'R';
}

tcT, class S> struct LazySeg {
	const T idT{}; const S idS{INF};  

	int n; V<T> seg; V<S> lazy; int orig_n; int SZ;
	T cmb(T a, T b) {  

		return a+b;
	}
	void init(int _n) {
		orig_n = _n; for (n = 1; n < _n; ) n *= 2;
		SZ = n; seg.assign(2*n,idT); lazy.assign(2*n, idS);  

	}
	void push(int ind, int L, int R) { 

		

		if (lazy[ind] != INF) {
            seg[ind] = (R-L+1)*lazy[ind]; 

    		if (L != R) id10(i,2) lazy[2*ind+i] = lazy[ind]; 

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
        if (hi < lo) {return;} ckmax(lo, 0); ckmin(hi, SZ-1);
        if ( R == -1 ) {R = SZ-1;}
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M);
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=-1) {
        if (hi < lo) {return idT;} ckmax(lo, 0); ckmin(hi, SZ-1);
        if ( R == -1 ) {R = SZ-1;}
		push(ind,L,R); if (lo > R || L > hi) return idT;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
    int first_nonzero(int ind=1, int L=0, int R=-1) {
        if (R == -1) {R = SZ-1;}
        if (query(L, R, ind, L, R) == 0) {return -1;}
        if (L == R) {return L;}
        int M = (L+R)/2;
        int out = first_nonzero(2*ind, L, M);
        if (out == -1) {
            out = first_nonzero(2*ind+1, M+1, R);
        }
        return out;
    }
    void detailed_printouts() {
        

        int ST_SIZE = n;
        int id6 = orig_n;
        

        el;
        dbgc("LazySeg DETAILS");
        FOR(k, 1, ST_SIZE + id6) {
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
                if ( L < id6 ) {
                    dbgY(k, MP(L,R), seg[k], lazy[k]);
                }
            }
        }
        el;
        
    }
};
template<class T, class S>
string to_string(LazySeg<T, S> st) {
    st.push_all();
    vector<T> out;
    for ( int k = st.n ; k < st.n + st.orig_n ; ++k ) {
        out.push_back( st.seg[k] );
    }
    return to_string( out );
}



void solve() {
    lls(N, MAX_VALUE);
    using t5 = tuple<ll,ll,ll,ll,ll>;
    V<t5> dat(N);
    FOR(k, 0, N) {
        auto& [a,b,c,d,e] = dat[k];
        cin >> a >> b >> c >> d >> e;
    }
    

    

    


    V<ll> uncompressed;
    FOR(k, 0, N) {
        auto& [a,b,c,d,e] = dat[k];
        uncompressed.push_back(a);
        uncompressed.push_back(b);
        uncompressed.push_back(c);
        uncompressed.push_back(d);
        uncompressed.push_back(e);
    }
    remDup(uncompressed);
    umap<ll,ll> uncinv;
    MAX_VALUE = uncompressed.size() - 1;
    FOR(k, 0, uncompressed.size()) {
        uncinv[uncompressed[k]] = k;
    }
    FOR(k, 0, N) {
        auto& [a,b,c,d,e] = dat[k];
        a = uncinv[a];
        b = uncinv[b];
        c = uncinv[c];
        d = uncinv[d];
        e = uncinv[e];
    }
    dbgR(N, pdh(dat));
    el;

    LazySeg<ll,ll> stL, stR;
    stL.init(MAX_VALUE + 1);
    stR.init(MAX_VALUE + 1);
    assert(uncinv[0] == 0);
    dbgP(stL);
    stL.upd(0,0,1);
    stR.upd(0,0,1);
    dbgP(stL);
    dbg_only(stL.detailed_printouts());

    V<set<pll>> id15(MAX_VALUE + 1);
    V<set<pll>> id14(MAX_VALUE + 1);
    ll prev_c = 0;

    

    FOR(qid, 0, N) {
        auto& [c, min_l, max_l, min_r, max_r] = dat[qid];

        int id3 = stL.first_nonzero();
        int id5 = stR.first_nonzero();
        bool id0 = (id3 == -1);
        bool id20 = (id5 == -1);
        dbg(id3, id5);

        if (id0 && id20) {return no;}
        if ((c < min_l || c > max_l) && (c < min_r || c > max_r)) {return no;}

        if (c < min_l || c > max_l) {
            stR.upd(0, MAX_VALUE, 0);
        } else {
            if (!id0) {
                stR.upd(prev_c, prev_c, 1);
                id14[prev_c].emplace(qid-1, id3);
            }
            stR.upd(0, min_r-1, 0);
            stR.upd(max_r + 1, MAX_VALUE, 0);
        }
        if (c < min_r || c > max_r) {
            stL.upd(0, MAX_VALUE, 0);
        } else {
            if (!id20) {
                stL.upd(prev_c, prev_c, 1);
                id15[prev_c].emplace(qid-1, id5);
            }
            stL.upd(0, min_l-1, 0);
            stL.upd(max_l + 1, MAX_VALUE, 0);
        }
        prev_c = c;
        el;
        dbgY(qid, dat[qid]);
        dbg(stL, stL.query(0, MAX_VALUE));
        dbg(id15);
        dbgP(stR, stR.query(0, MAX_VALUE));
        dbgP(id14);
    }
    dbg(stL, stL.query(0, MAX_VALUE));
    dbg(stR, stR.query(0, MAX_VALUE));
    bool id0 = (stL.query(0, MAX_VALUE) == 0);
    bool id20 = (stR.query(0, MAX_VALUE) == 0);
    if (id0 && id20) {
        return no;
    }

    yes;
    

    string out(N, '.');
    ll L, R;
    char holding;
    ll hold_until, change_for;

    ll last_card = get<0>(dat[N-1]);
    dbg(id15[last_card])
    dbg(id14[last_card])

    if (id0) {
        L = get<0>(dat[N-1]);
        R = stR.first_nonzero();
        

        

        holding = 'R';
        

        dbg(holding, L, R, out, id14[R]);
        tie(hold_until, change_for) = *id14[R].rbegin();
    } else {
        R = get<0>(dat[N-1]);
        L = stL.first_nonzero();
        

        

        holding = 'L';
        dbg(holding, L, R, out, id15[L]);
        tie(hold_until, change_for) = *id15[L].rbegin();
    }
    dbgP(pdh(id15));
    dbg(pdh(id14));
    dbgY(L, R, out, holding, MP(hold_until, change_for));
    el;
    ROF(qid, 1, N) {
        if (qid == hold_until) {
            if (holding == 'L') {
                holding = 'R';
                

                

                R = change_for;
                


                auto it = id14[R].lower_bound(MP(qid, -INF));
                if (it == id14[R].begin()) {
                    dbgcBold("not found", R, id14[R]);
                    assert(false);
                } else {
                    --it;
                    tie(hold_until, change_for) = *it;
                    dbgP(qid, id14[R], MP(hold_until, change_for));
                }
            } else {
                holding = 'L';
                L = change_for;
                

                

                auto it = id15[L].lower_bound(MP(qid, -INF));
                if (it == id15[L].begin()) {
                    dbgcBold("not found", L, id15[L]);
                    assert(false);
                } else {
                    --it;
                    tie(hold_until, change_for) = *it;
                    dbgR(qid, id15[L], MP(hold_until, change_for));
                }
            }
        }
        out[qid] = other_char(holding);
        dbg(qid, out, holding, hold_until);
    }
    out[0] = (hold_until == 0) ? (holding) : (other_char(holding));

    V<int> out_final(N);
    FOR(k, 0, N) {
        if (out[k] == 'R') {out_final[k] = 1;}
    }
    pv(out_final);

    return;
}









int main() {
    setIO();

    int T = 1;

    dbgc("loading num cases!!!"); std::cin >> T;  


    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el;

        dbgcBold("CASE" , CASE );
        solve();

        dbgcBold("brute force" , CASE );
        brute();

    }
    dbgR(TIME());

    return 0;
}















