
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








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










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

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
	hi ++; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); 

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

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id7<T>,void>::type re(T& i) {
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

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
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
	

	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void id9(const T& t) {
		cerr << "\n\n" << ts_sep(id5<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

	const clock_t beg = clock();
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}



template<int SZ> struct Sieve { 
	bitset<SZ> is_prime; vi primes;
	Sieve() {
		is_prime.set(); is_prime[0] = is_prime[1] = 0;
		for (int i = 4; i < SZ; i += 2) is_prime[i] = 0;
		for (int i = 3; i*i < SZ; i += 2) if (is_prime[i])
			for (int j = i*i; j < SZ; j += i*2) is_prime[j] = 0;
		id3(i,SZ) if (is_prime[i]) primes.pb(i);
	}
	

	

	

	

	

	

	

	

	

	

};

Sieve<1100000> S;
int C,N;
vi to_query{1};
vi ans;

void dfs(int ind, int num) {
	if (S.primes[ind] > C/num) return;
	to_query.pb(num*S.primes[ind]);
	dfs(ind+1,num*S.primes[ind]);
	dfs(ind+1,num);
}

int simulate(int x) {
	vi des{1,4,5,6,8,10};
	int xo = 0;
	each(t,des) if (gcd(x,t) == 1) xo ^= t;
	return xo;
}

bool dealt[1000005];
vi sol;

V<vi> gen_answers(vi group, int des) {
	assert(sz(group) <= 260);
	V<pair<int,bitset<260>>> cands;
	id3(i,sz(group)) {
		bitset<260> b; b[i] = 1;
		cands.pb({group[i],b});
	}
	vi found;
	R0F(i,20) {
		FOR(j,sz(found),sz(group)) if (cands[j].f&(1<<i)) {
			swap(cands[sz(found)],cands[j]);
			found.pb(i);
			break;
		}
		if (sz(found) && found.bk == i) {
			int k = sz(found)-1;
			FOR(j,sz(found),sz(group)) if (cands[j].f&(1<<i)) {
				cands[j].f ^= cands[k].f;
				cands[j].s ^= cands[k].s;
			}
		}
	}
	FOR(i,sz(found),sz(group)) assert(cands[i].f == 0);
	bitset<260> one_sol;
	id3(i,sz(found)) if (des&(1<<found[i])) {
		des ^= cands[i].f;
		one_sol ^= cands[i].s;
	}
	if (sz(found) == sz(group)) {
		id3(i,sz(group)) if (one_sol[i]) sol.pb(group[i]);
		return {};
	}
	vb exists_sol(sz(group)+1);
	V<vi> solutions(sz(group)+1);
	rep(100) {
		bitset<260> cur_sol = one_sol;
		FOR(i,sz(found),sz(group)) {
			if (rng()&1) cur_sol ^= cands[i].s;
		}
		int n = cur_sol.count();
		if (!exists_sol[n]) {
			exists_sol[n] = 1;
			id3(i,sz(group)) if (cur_sol[i]) solutions[n].pb(group[i]);
		}
	}
	V<vi> ret;
	id3(i,sz(group)+1) if (exists_sol[i]) ret.pb(solutions[i]);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	re(C,N);
	int ori_N = N;
	vi group[1000005];
	dfs(0,1);
	pr(sz(to_query));

	


	each(t,to_query) cout << " " << t;
	cout << endl;
	vi answers(sz(to_query)); 
	re(answers);
	

	

	


	ans = vi(C+1,-1);
	ans[1] = answers[0];
	FOR(i,1,sz(to_query)) 

		ans[to_query[i]] = answers[i]^answers[0];
	

	

	FOR(i,2,C+1) if (ans[i] != -1)
		for (int j = 2*i; j <= C; j += i) if (ans[j] != -1)
			ans[j] ^= ans[i];
	ROF(i,1,C+1) if (ans[i] != -1)
		for (int j = 2*i; j <= C; j += i) if (ans[j] != -1)
			ans[i] ^= ans[j];
	ROF(i,1,C+1) if (ans[i] != -1)
		for (int j = i; j <= C; j += i) if (!dealt[j]) {
			dealt[j] = 1;
			group[i].pb(j);
		}
	

	V<bitset<70000>> posi;
	posi.eb(); posi.bk[0] = 1;
	V<V<vi>> id6;

	FOR(i,1,C+1) if (sz(group[i])) {
		auto a = gen_answers(group[i],ans[i]);
		if (sz(a)) {
			

			

			id6.pb(a);
			posi.eb();
			each(t,a) {
				posi.bk |= posi[sz(posi)-2]<<sz(t);
			}
		}
	}
	N -= sz(sol);
	

	assert(posi.bk[N]);
	while (sz(posi) > 1) {
		posi.pop_back();
		bool found = 0;
		each(t,id6.bk) if (posi.bk[N-sz(t)]) {
			N -= sz(t);
			each(u,t) sol.pb(u);
			found = 1;
			break;
		}
		assert(found);
		id6.pop_back();
	}
	

	assert(sz(sol) == ori_N);
	for (int i: sol) cout << i << " ";
	cout << endl;

	

	

	

	

	

	

	

	

	

	

	

	

	

	



	

	

	

	

	

	



	


	

	

	



	




	

	


	
	

}


