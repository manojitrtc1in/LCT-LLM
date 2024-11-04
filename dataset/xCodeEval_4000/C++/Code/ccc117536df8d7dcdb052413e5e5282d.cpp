#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 


using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U


tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;



#define mp make_pair
#define f first
#define s second





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }



#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

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


#define tcTUU tcT, class ...U

inline namespace Helpers {
	

	

	

	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	

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
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
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
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
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

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
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
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
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
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else 

		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}



struct ACfixed { 

	static const int ASZ = 26;
	AR<int,26> to[1000005];
	int link[1000005];
	int max_suf[1000005];
	int cnt = 1;
	ACfixed() {
		F0R(i,1000005) max_suf[i] = -1;
	}
	int add(int ind, str s) { 

		int v = 0;
		each(C,s) {
			int c = C-'a';
			if (!to[v][c]) to[v][c] = cnt++;
			v = to[v][c];
		}
		max_suf[v] = ind;
		return v;
	}
	

	

	

	void init() { 

		link[0] = -1; 
		queue<int> q; q.push(0);
		while (sz(q)) {
			int v = q.ft; q.pop();
			if (max_suf[v] == -1 && link[v] != -1) {
				max_suf[v] = max_suf[link[v]];
			}
			F0R(c,ASZ) {
				int u = to[v][c]; if (!u) continue;
				link[u] = link[v] == -1 ? 0 : to[link[v]][c];
				q.push(u); 
			}
			if (v) F0R(c,ASZ) if (!to[v][c]) 
				to[v][c] = to[link[v]][c];
		}
	}
};





















































































template<class T> struct RMQ { 

	int level(int x) { return 31-__builtin_clz(x); } 
	AR<int,1000005> jmp[20];
	

	

	void init(const vector<T>& v) {
		F0R(i,sz(v)) jmp[0][i] = v[i];
		for (int j = 1; 1<<j <= sz(v); ++j) {
			F0R(i,sz(jmp[j])) jmp[j][i] = min(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { 

		assert(l <= r); int d = level(r-l+1);
		return min(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return index(l,r); }
};






clock_t beg = clock();



vi sa_is(const vi& s, int upper) {
	int n = sz(s); if (!n) return {};
	vi sa(n); vb ls(n); 

	R0F(i,n-1) ls[i] = s[i] == s[i+1] ? ls[i+1] : s[i] < s[i+1]; 
	

	

	vi sum_l(upper), sum_s(upper);
	F0R(i,n) (ls[i] ? sum_l[s[i]+1] : sum_s[s[i]]) ++; 

	F0R(i,upper) { 
		if (i) sum_l[i] += sum_s[i-1]; 

		sum_s[i] += sum_l[i]; 

	}
	auto induce = [&](const vi& lms) {
		fill(all(sa),-1);
		vi buf = sum_s;
		for (int d: lms) if (d != n) sa[buf[s[d]]++] = d; 

		buf = sum_l; sa[buf[s[n-1]]++] = n-1;
		F0R(i,n) { 

			int v = sa[i]-1;
			if (v >= 0 && !ls[v]) sa[buf[s[v]]++] = v;
		}
		buf = sum_l;
		R0F(i,n) { 

			int v = sa[i]-1;
			if (v >= 0 && ls[v]) sa[--buf[s[v]+1]] = v; 

		}
	};
	vi lms_map(n+1,-1), lms; int m = 0;
	FOR(i,1,n) if (!ls[i-1] && ls[i]) lms_map[i] = m++, lms.pb(i);
	induce(lms); 

	vi sorted_lms; each(v,sa) if (lms_map[v] != -1) sorted_lms.pb(v);
	vi rec_s(m); int rec_upper = 0; 

	FOR(i,1,m) { 

		int l = sorted_lms[i-1], r = sorted_lms[i];
		int end_l = lms_map[l]+1 < m ? lms[lms_map[l]+1] : n;
		int end_r = lms_map[r]+1 < m ? lms[lms_map[r]+1] : n;
		bool same = 0; 

		if (end_l-l == end_r-r) {
			for (;l < end_l && s[l] == s[r]; ++l,++r);
			if (l != n && s[l] == s[r]) same = 1;
		}
		rec_s[lms_map[sorted_lms[i]]] = (rec_upper += !same);
	}
	vi rec_sa = sa_is(rec_s,rec_upper+1);
	F0R(i,m) sorted_lms[i] = lms[rec_sa[i]];
	induce(sorted_lms); 

	return sa;
}

struct SuffixArray {
	str S; int N; vi sa, isa, lcp;
	void init(str _S) { N = sz(S = _S)+1; genSa(); genLcp(); }
	void genSa() { 

		vi tmp(sz(S));
		F0R(i,sz(tmp)) tmp[i] = S[i]-'a';
		sa = sa_is(tmp,26); sa.ins(begin(sa),sz(S));
		isa = vi(N);
		F0R(i,N) isa[sa[i]] = i;

		

		

		

		

		

		

		

		

		

		

		

	}
	void genLcp() { 

		lcp = vi(N-1); int h = 0;
		F0R(b,N-1) { int a = sa[isa[b]-1];
			while (a+h < sz(S) && S[a+h] == S[b+h]) h ++;
			lcp[isa[b]-1] = h; if (h) h--; }
		R.init(lcp); 

		

	}
	RMQ<int> R; 
	int getLCP(int a, int b) { 

		if (a == b) return sz(S)-a;
		int l = isa[a], r = isa[b]; if (l > r) swap(l,r);
		return R.query(l,r-1);
	}
};


SuffixArray SA;

str tot;


































ACfixed AC;
int N;

vi query[1000005];
vi special_sub[1000005][2];



template <class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
	template<typename... Args> T sum(int r, Args... args) {
		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
		return res; }
	template<typename... Args> T query(int l, int r, Args... 
		args) { return sum(r,args...)-sum(l-1,args...); }
}; 
template<class T, int N> int get_kth(const BIT<T,N>& bit, T des) { 
	assert(des > 0);
	int ind = 0;
	for (int i = 1<<bits(N); i; i /= 2)
		if (ind+i <= N && bit.bit[ind+i].val < des)
			des -= bit.bit[ind += i].val;
	assert(ind < N); return ind+1;
}

BIT<int,1000005> special;
int timer[1000005];
vi added;

int main() {
	setIO(); re(N);

	vs v; v.rsz(N); 
	

	re(v);

	each(t,v) tot += t;
	

	F0R(i,sz(v)) AC.add(i,v[i]);
	assert(sz(tot) <= 1000000);
	SA.init(tot);
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	AC.init();
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);

	ll ans = 0;
	vi ind_st(sz(v));
	int csum = 0;
	F0R(i,sz(v)) {
		ind_st[i] = csum;
		csum += sz(v[i]);
	}
	F0R(i,sz(v)) {
		F0R(j,sz(v[i])+1) {
			query[j].clear();
			special_sub[j][0].clear();
			special_sub[j][1].clear();
		}
		int ind = 0;

		vpi interval;
		F0R(j,sz(v[i])) {
			char c = v[i][j];
			ind = AC.to[ind][c-'a'];
			if (j == sz(v[i])-1) ind = AC.link[ind];
			if (ind != -1) {
				int x = AC.max_suf[ind];
				if (x != -1) {
					int wut = sz(v[x]);
					interval.pb({j+1-wut,j+1});
					if (timer[x] != i+1) {
						timer[x] = i+1;
						query[wut].pb(x);
					}
				}
			}
		}

		reverse(all(interval));
		int cnt = sz(v[i]);
		each(t,interval) {
			while (cnt >= t.s) --cnt;
			while (cnt >= t.f) {
				special_sub[t.s-cnt][cnt != t.f].pb(ind_st[i]+cnt);
				--cnt;
			}
		}

		auto ad = [&](int x) {
			added.pb(x);
			special.upd(x,1);
		};
		
		R0F(j,sz(v[i])+1) {
			for (int x: special_sub[j][1]) ad(SA.isa[x]);
			for (int k: query[j]) {
				int x = SA.isa[ind_st[k]];
				int sum = special.sum(x);
				if (sum) {
					int tmp = get_kth(special,sum);
					if (SA.R.query(tmp,x-1) >= sz(v[k])) continue;
				}
				if (sum < sz(added)) {
					int tmp = get_kth(special,sum+1);
					if (SA.R.query(x,tmp-1) >= sz(v[k])) continue;
				}
				++ans;
			}
			for (int x: special_sub[j][0]) ad(SA.isa[x]);
		}

		for (int x: added) special.upd(x,-1);
		added.clear();
	}
	ps(ans);
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	

}


