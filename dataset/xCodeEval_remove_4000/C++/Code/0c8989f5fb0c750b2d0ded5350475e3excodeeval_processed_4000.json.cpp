



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
































struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id6 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id6);
    }
    template<class T>
    size_t operator()(T x) const {
        static const uint64_t id6 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((uint64_t)int(x) + id6);
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


vector<pii> id17 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> stepsDiagonal = {{1,1},{1,-1},{-1,-1},{-1,1}};
vector<pii> id23 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());











template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id10(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } 


int maxi(int a, int b) {return max((int)a, (int)b);}
int mini(int a, int b) {return min((int)a, (int)b);}
ll maxll(ll a, ll b) {return max((ll)a, (ll)b);}
ll minll(ll a, ll b) {return min((ll)a, (ll)b);}

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
    tcT> constexpr bool id22 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id4 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id19 = !id1<T> && id22<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id19<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    template<class A,class B,class C> void re(tuple<A,B,C>& t) {auto& [a,b,c]=t; re(a,b,c);}
    template<class A,class B,class C, class D> void re(tuple<A,B,C,D>& t) {auto& [a,b,c,d]=t; re(a,b,c,d);}
    template<class A,class B,class C, class D, class E> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e]=t; re(a,b,c,d,e);}
    template<class A,class B,class C, class D, class E, class F> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e,f]=t; re(a,b,c,d,e,f);}
    tcT> typename enable_if<id19<T>,void>::type re(T& i) {
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
        rv(N,u...); }


    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
    
    
    
    
}

inline namespace ToString {
    tcT> constexpr bool id8 = !id4<T> && id22<T>;

    

    tcT> typename enable_if<id4<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id9(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id8<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id22<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id8<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id8<T>,vs>::type
      id11(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id8<T>,vs>::type
      id11(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id11<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id9(i,sz(res)) {
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
    template<class T> void id13(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void id13(ostream& os, str sep, const T& t, const U&... u) {
        id13(os,sep,t); os << sep; id13(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); }
    void ps1() { cout << "\n"; }
    template<class ...T> void ps1(const T&... t) { id13(cout," ",t...); ps1(); }

    template<class T>
    void pv(T& dat) {bool first=true; for(auto& x : dat) {if (!first) {cout<<' ';} first=false; cout << x;} cout<<'\n';}
    template<class T>
    void pv1(T& dat) {bool first=true; for(auto& x : dat) {if (!first) {cout<<' ';} first=false; cout << x+1;} cout<<'\n';}
    


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



template<class T>
string id14(T& q) {
    string out = "\n";
    int ctr = 0;
    for ( auto& x : q ) {
        out += to_string(ctr) + "\t" + to_string(x) + "\n";
        ++ctr;
    }
    return out;
}


template<class T>
string id16(T& q) {
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

    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    

    
    


    
    














const int MOD = 998244353;







template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } 

	int v; explicit operator int() const { return v; } 

	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) {
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) {
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }

	mint& operator+=(const mint& o) {
		if ((v += o.v) >= MOD) v -= MOD;
		return *this; }
	mint& operator-=(const mint& o) {
		if ((v -= o.v) < 0) v += MOD;
		return *this; }
	mint& operator*=(const mint& o) {
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0);
		return pow(a,MOD-2); }

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

using mi = mint<MOD,5>; 

using vmi = V<mi>;
using pmi = pair<mi,mi>;
using vpmi = V<pmi>;

V<vmi> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) id9(j,i+1)
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

template <int MOD, int RT>
string to_string(mint<MOD, RT> modint) {
    return to_string((int)modint);
}






void solve() {
    lls(K, Ain, id18);
    mi A = Ain;
    mi target_hash = id18;


    int id20 = K-1;

    int id20 = 4;

    if (K <= id20) {
        

        int num_players = (1<<K);
        int BITS = num_players - 1;
        V<int> out(num_players);
        FOR(mask, 0, (1<<BITS)) {
            V<int> curr = rangeint(1, num_players+1);
            V<int> wip;
            mi hash = 0;
            int bidx = 0;
            FOR(round, 0, K) {
                int placement = (1<<(K-round-1)) + 1;
                

                FOR(k, 0, curr.size()/2) {
                    int winner = curr[2*k];
                    int loser = curr[2*k+1];
                    if ((mask>>bidx) & 1) {
                        swap(winner, loser);
                    }
                    

                    ++bidx;
                    wip.push_back(winner);
                    hash += loser * pow(A, placement);
                    out[loser-1] = placement;
                }

                swap(curr, wip);
                wip.clear();
            }
            int champ = curr[0];
            hash += champ * A;  

            out[champ-1] = 1;
            dbg(mask, out);
            if ( hash == target_hash ) {
                return pv(out);
            }
        }
        return ps(-1);
    }

    

    

    int id3 = (1<<K);
    V<umap<int, int>> id2(id3);
    auto& chm = id2;  

    FOR(half, 0, 2) {
        int num_players = id3 / 2;
        int offset = half * num_players;
        int BITS = num_players - 1;
        int Kinner = K-1;
        

        FOR(mask, 0, (1<<BITS)) {
            V<int> curr = rangeint(offset+1, offset+num_players+1);
            V<int> wip;
            mi hash = 0;
            int bidx = 0;
            FOR(round, 0, Kinner) {
                int placement = (1<<(K-round-1)) + 1;
                

                FOR(k, 0, curr.size()/2) {
                    int winner = curr[2*k];
                    int loser = curr[2*k+1];
                    if ((mask>>bidx) & 1) {
                        std::swap(winner, loser);
                    }
                    

                    ++bidx;
                    wip.push_back(winner);
                    hash += loser * pow(A, placement);
                    

                }

                std::swap(curr, wip);
                wip.clear();
            }
            int champ = curr[0];
            

            

            

            chm[champ-1][(int)hash] = mask;
        }
    }
    dbg(pdh(chm));

    

    

    int id12 = -1;
    int id7 = -1;
    bool id15;
    FOR(champ_top, 0, id3 / 2) {
        for(auto& [id21, mask_top] : chm[champ_top]) {
            mi hash_top = id21;
            FOR(champ_bottom, id3/2, id3) {
                
                mi id0 = target_hash - hash_top - mi(champ_top+1)*A - mi(champ_bottom+1)*A*A;
                mi id5 = target_hash - hash_top - mi(champ_top+1)*A*A - mi(champ_bottom+1)*A;
                dbg(champ_top, champ_bottom, hash_top);
                dbg(target_hash, hash_top, mi(champ_top+1)*A);
                dbg(id0, id5, chm[champ_bottom]);
                el;
                if ( chm[champ_bottom].find((int)id0) != chm[champ_bottom].end() ) {
                    

                    

                    

                    id12 = mask_top;
                    id7 = chm[champ_bottom][(int)id0];
                    id15 = true;
                    break;
                }
                if ( chm[champ_bottom].find((int)id5) != chm[champ_bottom].end() ) {
                    

                    

                    

                    id12 = mask_top;
                    id7 = chm[champ_bottom][(int)id5];
                    id15 = false;
                    break;
                }
            }
            if (id12 >= 0) {
                break;
            }
        }
        if (id12 >= 0) {
            break;
        }
    }

    if (id12 == -1) {
        return ps(-1);
    }

    

    V<int> out(id3);
    V<int> masks = {id12, id7};
    FOR(half, 0, 2) {
        int num_players = id3 / 2;
        int offset = half * num_players;
        

        int Kinner = K-1;
        int mask = masks[half];

        {
            V<int> curr = rangeint(offset+1, offset+num_players+1);
            V<int> wip;
            mi hash = 0;
            int bidx = 0;
            FOR(round, 0, Kinner) {
                int placement = (1<<(K-round-1)) + 1;
                dbgR(Kinner, num_players, round, placement);
                FOR(k, 0, curr.size()/2) {
                    int winner = curr[2*k];
                    int loser = curr[2*k+1];
                    if ((mask>>bidx) & 1) {
                        std::swap(winner, loser);
                    }
                    

                    ++bidx;
                    wip.push_back(winner);
                    hash += loser * pow(A, placement);
                    out[loser-1] = placement;
                }

                std::swap(curr, wip);
                wip.clear();
            }
            int champ = curr[0];
            hash += champ * A;  

            if ((id15 && half == 0) || (!id15 && half == 1)) {
                out[champ-1] = 1;
            } else {
                out[champ-1] = 2;
            }
            

        }
    }
    pv(out);

    return;
}








int main() {
    setIO();

    int T = 1;
    

    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el; dbgcBold("CASE" , CASE );

        solve();

        brute();

    }
    dbg(TIME());

    return 0;
}

