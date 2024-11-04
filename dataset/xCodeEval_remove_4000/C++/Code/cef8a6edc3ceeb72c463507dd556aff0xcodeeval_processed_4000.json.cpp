



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
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }




struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id5 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id5);
    }
    template<class T, class U>
    size_t operator()(pair<T,U> x) const {
        uint64_t a = (*this)(x.first);
        uint64_t b = (*this)(x.second);
        return a + 3*b;
    }
};

template<class A, class B> using umap = gp_hash_table<A,B,custom_hash>;


























const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);


vector<pii> id10 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> id14 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id8(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id13 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id1 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id3 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id12 = !id1<T> && id13<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id12<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    template<class A,class B,class C> void re(tuple<A,B,C>& t) {auto& [a,b,c]=t; re(a,b,c);}
    tcT> typename enable_if<id12<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id6 = !id3<T> && id13<T>;

    

    tcT> typename enable_if<id3<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id7(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id6<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id13<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id6<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id6<T>,vs>::type
      id9(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id6<T>,vs>::type
      id9(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id9<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id7(i,sz(res)) {
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

void debug_out() { std::cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << to_string(H) << "   ";
    debug_out(T...);
}






























    

    
        << std::right << setw(20) << C \
        << std::right << setw(8) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << A << "[ " << 
        << OUT_BOLD << " :    " << OUT_RESET \
        << B, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET;

    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    

    
    


    
    









int num_between(V<int>& X, int lo, int hi) {
    

    int after = upper_bound(all(X), hi) - X.begin();
    int before = lower_bound(all(X), lo) - X.begin();
    

    return after - before;
    

}

tcT> struct SegTree { 

    int c;
	const T ID{};
    

	int n; V<T> seg; int orig_n;
	void init(int _n) { 

		for (n = 1; n < _n; ) n *= 2;
		seg.assign(2*n,ID); orig_n = _n;}
	void pull(int p) {
        

        seg[p] = seg[2*p];
        seg[p].insert( seg[p].end() , all(seg[2*p+1]) );
        sort(all(seg[p]));
        

    }
	void upd(int p, T val) { 

		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    void insert(int x, int y) {
        seg[x+n].push_back(y);
    }
    void build() { ROF(i,1,n) pull(i); }
	int query(int l, int r, int lo, int hi) {	

        if ( l > r || l >= n || r < 0 ) {
            return 0;
        }
        

        

        

        int origL = l; int origR = r;
        int out = 0;
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) out += num_between(seg[l++], lo, hi);
			if (r&1) out += num_between(seg[--r], lo, hi);
		}
        dbgcY("query END", c, MP(origL,origR), MP(lo,hi), out);
        return out;
		

		

		

		

		

		

	}
    void detailed_printouts() {
        

        int ST_SIZE = n;
        int ST_PRINT_SIZE = orig_n;
        

        el;
        dbgc("ST DETAILS");
        FOR(k, 1, ST_SIZE + ST_PRINT_SIZE) {
            if ( k >= ST_SIZE) {
                int p = k - ST_SIZE;
                dbgP(k, p, seg[k]);
            } else {
                vector<int> binary_digits;
                int temp = k;
                while ( temp > 0 ) {
                    binary_digits.push_back( temp % 2 );
                    temp /= 2;
                }
                reverse(all(binary_digits));
                int L = 0; int R = ST_SIZE-1;
                for ( int didx = 1 ; didx < binary_digits.size() ; ++didx ) {
                    int M = (L+R) / 2;
                    if ( binary_digits[didx] == 1 ) {
                        L = M+1;
                    } else {
                        R = M;
                    }
                }
                if ( L < ST_PRINT_SIZE ) {
                    dbgY(k, MP(L,R), seg[k]);
                }
            }
        }
        el;
        
    }
};
template<class T>
string to_string(SegTree<T> st) {
    vector<T> out;
    for ( int k = st.n ; k < st.n + st.orig_n ; ++k ) {
        out.push_back( st.seg[k] );
    }
    return to_string( out );
}





void solve() {
    ints(N);
    using t3 = tuple<int,int,int>;
    vector<t3> dat;
    rv(N, dat);
    dbg(N, dat);

    

    V<int> cX, cY;
    for ( auto& [x, y, c] : dat ) {
        cX.push_back(x);
        cY.push_back(y);
        --c;
    }
    remDup( cX );
    remDup( cY );
    int nX = cX.size();
    int nY = cY.size();
    umap<int,int> mX, mY;
    FOR(k, 0, nX ) {
        mX[cX[k]] = k;
    }
    FOR(k, 0, nY ) {
        mY[cY[k]] = k;
    }
    for ( auto& [x, y, c] : dat ) {
        x = mX[x];
        y = mY[y];
    }

    

    V<SegTree<V<int>>> st(3);
    FOR(c, 0, 3) {
        st[c].init( nX );
        st[c].c = c;
    }
    for ( auto& [x, y, c] : dat ) {
        st[c].insert(x, y);
    }
    FOR(c, 0, 3) {
        st[c].build();
        dbg_only(st[c].detailed_printouts());
    }

    

    int out = lstTrue(1, N/3, [&](int K){
        dbgcBold("binsearch START", K, MP(1,N/3));
        V<int> cord(3);
        for( cord[0] = 0 ; cord[0] < 3 ; ++cord[0] )
        for( cord[1] = 0 ; cord[1] < 3 ; ++cord[1] )
        for( cord[2] = 0 ; cord[2] < 3 ; ++cord[2] ) {
            if ( cord[0] == cord[1] || cord[0] == cord[2] || cord[1] == cord[2] ) {
                continue;
            }
            dbgP(cord);
            using t4 = tuple<int,int,int,int>;
            V<t4> id0;

            

            int id16 = fstTrue(0, nY-1, [&](int tob){
                return st[cord[0]].query(0, nX-1, 0, tob) >= K;
            });
            dbg(id16);
            id0.emplace_back(0, nX-1, id16+1, nY-1);

            

            int id11 = fstTrue(0, nY-1, [&](int bot){
                return st[cord[0]].query(0, nX-1, 0, bot) > N/3 - K;
            });
            dbg(id11);
            id0.emplace_back(0, nX-1, 0, id11-1);

            

            int id15 = fstTrue(0, nX-1, [&](int eol){
                return st[cord[0]].query(0, eol, 0, nY-1) >= K;
            });
            dbg(id15);
            id0.emplace_back(id15+1, nX-1, 0, nY-1);

            

            int id17 = fstTrue(0, nY-1, [&](int eor){
                return st[cord[0]].query(0, eor, 0, nY-1) > N/3 - K;
            });
            dbg(id17);
            id0.emplace_back(0, id17-1, 0, nY-1);

            dbg(id0);

            for ( auto& [x0, x1, y0, y1] : id0 ) {
                if ( x0 > x1 || y0 > y1 ) {
                    continue;
                }
                dbgP(MP(x0,x1), MP(y0,y1));
                

                int id2 = fstTrue(y0, y1, [&](int tob){
                    return st[cord[1]].query(x0, x1, y0, tob) >= K;
                });
                dbg(id2);
                int result_upper = st[cord[2]].query(x0, x1, id2+1, y1);
                dbg(result_upper); el;

                

                int id4 = fstTrue(x0, x1, [&](int eol){
                    return st[cord[1]].query(x0, eol, y0, y1) >= K;
                });
                dbg(id4);
                int result_right = st[cord[2]].query(id4+1, x1, y0, y1);
                dbg(result_right); el;

                int result = max(result_upper, result_right);
                if ( result >= K ) {
                    return true;
                }
            }
        }
        return false;
    });

    ps(3*out);

    return;
}






int main() {
    setIO();

    int T = 1;
    

    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el; dbgcBold("CASE" , CASE );
        solve();
    }

    return 0;
}

