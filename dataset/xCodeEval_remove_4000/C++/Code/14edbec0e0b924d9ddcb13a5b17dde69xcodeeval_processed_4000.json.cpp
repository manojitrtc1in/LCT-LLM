

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


mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

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
	tcT> constexpr bool id7 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id6 = !id0<T> && id7<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id6<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id6<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


	

	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	

	void decrement() {} 

	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	
	
}

inline namespace ToString {
	tcT> constexpr bool id2 = !id1<T> && id7<T>;

	

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

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id7<T>,str>::type ts_sep(T v, str sep) {
		

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
			if (sz(res)) res.bk += ",";
			vs tmp = id5<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id3(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
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
    


	const clock_t beg = clock();
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

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

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << to_string(H) << "   ";
    debug_out(T...);
}

















    

    

    
        << std::right << setw(20) << A \
        << std::right << setw(8) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << OUT_GREEN << "[ " << 
        << OUT_BOLD << " :    " << OUT_RESET \
        << OUT_CYAN, debug_out(__VA_ARGS__); \
        cerr << OUT_RESET;
    
    

    

    
    
    

    
    

    
    
    
    
    










void solve() {
    ints(N);
    vector<ll> A(N+1), B(N+1);  

	for ( int k = 1 ; k <= N ; ++k ) {
		cin >> A[k];
	}
	for ( int k = 1 ; k <= N ; ++k ) {
		cin >> B[k];
		if ( k > 1 ) {
			B[k] -= A[k];
			A[k] = 0;
		}
	}
    dbg(N, A, B); el;

	vector<ll> R( N+1 ), S( N+1 , -1 );
	
	for ( int k = 2 ; k <= N ; ++k ) {
		R[k] += B[k] - A[k];
		

		for ( int m = 2 ; m*k <= N ; ++m ) {
			dbgc("apply" , k , S[k] , m*k , S[m*k] , S );
			R[m*k] -= R[k];
			S[m*k] -= S[k];
		}
	}
	dbg( R );
	dbg( S );

	

	map<ll, tuple<ll,ll,ll,ll>> ds;
	ll from_flat = 0;
	for ( int k = 2 ; k <= N ; ++k ) {
		if ( S[k] == 0 ) {
			from_flat += abs(R[k]);
			continue;
		}
		if ( R[k] % S[k] == 0 ) {
			auto& [baseL, baseR, l, r] = ds[ -R[k] / S[k] ];
			baseL += 0;
			baseR += 0;
			l += abs(S[k]);
			r += abs(S[k]);
			continue;
		}
		dbgc("?!?!?!?!?!?!?!?!?!");
		

		ll just_left = db(-R[k]) / S[k];
		just_left -= 5;
		while ( (just_left * S[k] + R[k]) * ((just_left+1) * S[k] + R[k]) > 0 ) {
			++just_left;
		}
		{
			auto& [baseL, baseR, l, r] = ds[ -R[just_left] / S[just_left] ];
			baseL += abs(R[k] + S[k] * just_left);
			baseR += abs(R[k] + S[k] * just_left);
			l += abs(S[k]);
			r += 0;
		}
		ll just_right = just_left + 1;
		{
			auto& [baseL, baseR, l, r] = ds[ -R[just_right] / S[just_right] ];
			baseL += abs(R[k] + S[k] * just_right);
			baseR += abs(R[k] + S[k] * just_right);
			l += 0;
			r += abs(S[k]);
		}
	}

	dbgc("proc START" , ds );
	const ll INF = 2e18;
	{
		ll prev_r = 0;
		ll prev_base = 0;
		ll prev_pos = INF;
		for ( auto& [pos, tup] : ds ) {
			auto& [baseL, baseR, l, r] = tup;
			ll dpos;
			if ( prev_pos == INF ) {
				dpos = pos;
			} else {
				dpos = pos - prev_pos;
			}
			r += prev_r;
			baseR += prev_base + dpos * prev_r;

			tie( prev_pos , prev_r , prev_base ) = tie( pos , r , baseR );
		}
	}

	dbgc("proc HALF" , ds );
	{
		ll prev_l = 0;
		ll prev_base = 0;
		ll prev_pos = -INF;
		for ( auto& [pos, tup] : ds | views::reverse ) {
			auto& [baseL, baseR, l, r] = tup;
			ll dpos;
			if ( prev_pos == -INF ) {
				dpos = pos;
			} else {
				dpos = prev_pos - pos;
			}
			l += prev_l;
			baseL += prev_base + dpos * prev_l;

			tie( prev_pos , prev_l , prev_base ) = tie( pos , l , baseL );
		}
	}
	dbgc("proc DONE" , ds );

	ints( num_queries );
	id3( qidx , num_queries ) {
		ints( q );
		ll c1 = q - A[1];
		ll out = abs(c1) + from_flat;
		el; dbg(qidx, q, out);
		if ( ds.size() == 0 ) {
			

			cout << out << '\n';
			dbgc("flat" , out );
			continue;
		}

		auto itL = ds.lower_bound( c1 );
		if ( itL != ds.end() && itL->first == c1 ) {
			dbgc("exact" , out );
			

			auto& [baseL, baseR, l, r] = itL->second;
			out += baseL + baseR;
			cout << out << '\n';
			continue;
		}
		if ( itL != ds.begin() ) {
			

			--itL;
			ll pos = itL->first;
			auto& [baseL, baseR, l, r] = itL->second;
			ll contrib = (c1 - pos) * r + baseR;
			out += contrib;
			dbgc("L contrib" , contrib , out );
		}

		auto itR = ds.lower_bound( c1 );
		if ( itR != ds.end() ) {
			

			ll pos = itR->first;
			auto& [baseL, baseR, l, r] = itR->second;
			ll contrib = (pos - c1) * l + baseL;
			out += contrib;
			dbgc("R contrib" , contrib , out );
		}
		cout << out << '\n';
		dbgc("hard" , out );
		continue;
	}

	return;
}




int main() {
	setIO();

    int T = 1;
    

    for ( int k = 1 ; k <= T ; ++k ) {
        el; dbgc("CASE" , k );
        solve();
    }

    return 0;
}

