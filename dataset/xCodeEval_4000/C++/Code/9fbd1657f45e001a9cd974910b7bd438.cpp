#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U


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





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }



#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

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
constexpr int msk2(int x) { return p2(x)-1; }

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

	const clock_t beg = clock();
	#define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}



tcT> struct RMQ {
	int level(int x) { return 31-__builtin_clz(x); }
	V<T> v; V<vi> jmp;
	int cmb(int a, int b) {
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); }
	void init(const V<T>& _v) {
		v = _v; jmp = {vi(sz(v))};
		iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = cmb(jmp[j-1][i],
				jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) {
		assert(l <= r); int d = level(r-l+1);
		return cmb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};






template<class Char> struct SuffixArray {
	V<Char> S; int N; vi sa, isa, lcp;
	void init(V<Char> _S) { N = sz(S = _S)+1; genSa(); genLcp(); }
	void genSa() { 

		sa = isa = vi(N); sa[0] = N-1; iota(1+all(sa),0);
		sort(1+all(sa),[&](int a, int b) { return S[a] < S[b]; });
		FOR(i,1,N) { int a = sa[i-1], b = sa[i];
			isa[b] = i > 1 && S[a] == S[b] ? isa[a] : i; }
		for (int len = 1; len < N; len *= 2) { 

			

			vi s(sa), is(isa), pos(N); iota(all(pos),0); 
			each(t,s) {int T=t-len;if (T>=0) sa[pos[isa[T]]++] = T;}
			FOR(i,1,N) { int a = sa[i-1], b = sa[i]; 

				isa[b] = is[a]==is[b]&&is[a+len]==is[b+len]?isa[a]:i; }
		}
	}
	void genLcp() { 

		lcp = vi(N-1); int h = 0;
		F0R(b,N-1) { int a = sa[isa[b]-1];
			while (a+h < sz(S) && S[a+h] == S[b+h]) ++h;
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

int N;

vi prefix_answers(SuffixArray<int>& SA, V<int> A) {
	set<int> positions;
	V<vpi> to_kill(N+1);
	vi ans;
	F0R(i,N) {
		auto deal = [&](set<int>::iterator il, set<int>::iterator ir) {
			int l = *il, r = *ir;
			assert(l < r);
			to_kill.at(r+SA.getLCP(l,r)).pb({l,r});
		};
		auto del = [&](set<int>::iterator it) {
			if (it != begin(positions) && next(it) != end(positions)) deal(prev(it),next(it));
			positions.erase(it);
		};
		{
			auto it = positions.ins(i).f;
			if (i) deal(prev(it),it);
		}
		while (sz(to_kill[i])) {
			pi p = to_kill[i].bk; to_kill[i].pop_back();
			auto it = positions.find(p.f);
			if (it == end(positions) || next(it) == end(positions) || *next(it) != p.s) continue;
			if (SA.isa[p.f] > SA.isa[p.s]) del(it);
			else del(next(it));
		}
		ans.pb(*positions.rbegin());
	}
	return ans;
}



using H = AR<int,1>; 

H makeH(int c) { return {c}; }
uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);


const H base{10};



H operator+(H l, H r) { 
	F0R(i,1) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
	return l; }
H operator-(H l, H r) { 
	F0R(i,1) if ((l[i] -= r[i]) < 0) l[i] += MOD;
	return l; }
H operator*(H l, H r) { 
	F0R(i,1) l[i] = (ll)l[i]*r[i]%MOD;
	return l; }







V<H> pows{{1}};
struct HashRange {
	vi S; V<H> cum{{}};
	void add(int c) { S.pb(c); cum.pb(base*cum.bk+makeH(c)); }
	void add(vi s) { reverse(all(s)); each(c,s) add(c); }
	void extend(int len) { while (sz(pows) <= len) 
		pows.pb(base*pows.bk); }
	H hash(int l, int r) { 
		tie(l,r) = mp(N-1-r,N-1-l);
		int len = r+1-l; extend(len);
		return cum[r+1]-pows[len]*cum[l]; }
	
};





HashRange HR;

struct HH {
	int l,r;
	ll len; H val;
	HH(): l(0), r(-1), len(0), val({0}) {}
	HH(int l_, int r_): l(l_), r(r_) {
		len = r-l+1;
		val = HR.hash(l,r);
	}
	HH(int len_, H val_): len(len_), val(val_) {}
	HH get_prefix(int p) {
		assert(1 <= p && p <= len);
		return HH(l,l+p-1);
	}
};

HH operator+(HH l, const HH& r) {
	assert(l.len < N);
	HR.extend(l.len);
	l.val = l.val+r.val*pows.at(l.len);
	l.len += r.len;
	return l;
}

H hash_prefix(pi p, int partial_len) {
	assert(p.s-p.f+1 >= partial_len);
	return HR.hash(p.f,p.f+partial_len-1);
}

H hash_at(pi p, int pos) {
	assert(p.s-p.f+1 > pos);
	return HR.hash(p.f+pos,p.f+pos);
}

tcT> struct NotSegTree {
	vl lens{0};
	V<H> hashes{H{}};
	deque<pi> intervals;
	void push_front(int l, int r) {
		dbg("PUSH FRONT",l,r);
		const int len = r-l+1;
		lens.pb(len+lens.bk);
		HR.extend(len);
		hashes.pb(HR.hash(l,r)+pows.at(len)*hashes.bk);
		intervals.pb({l,r});
	}
	vi get_all_indices() {
		vi res;
		R0F(i,sz(intervals)) {
			auto p = intervals[i];
			FOR(j,p.f,p.s+1) res.pb(j);
		}
		return res;
	}
	vi get_indices() {
		reverse(all(intervals));
		vi ans;
		each(p,intervals) {
			FOR(i,p.f,p.s+1) {
				ans.pb(i);
				if (sz(ans) == N) break;
			}
			if (sz(ans) == N) break;
		}
		assert(sz(ans) == N);
		return ans;
	}
	HH get_prefix_ok(int len) {
		const int ori_len = len;
		HR.extend(N);
		HH H{};
		R0F(i,sz(intervals)) {
			

			FOR(j,intervals[i].f,intervals[i].s+1) {
				if (len) {
					

					H = H+HH(j,j);
					

					--len;
				}
			}
		}
		assert(H.len == ori_len);
		

		return H;
	}
	HH get_prefix(int len) {
		

		

		

		HR.extend(N);
		int i = fstTrue(0,sz(lens)-1,[&](int x) {
			return lens.bk-lens[x] <= len;
		});
		const int partial_len = lens.bk-lens.at(i);
		H h = hashes.bk-hashes.at(i)*pows.at(partial_len);
		

		

		

		

		

		if (partial_len < len) {
			h = h+pows.at(partial_len)*hash_prefix(intervals.at(i-1),len-partial_len);
		}
		

		

		

		

		return HH{len,h};
	}
	H hash_at(int pos) {
		

		

		

		

		

		

		int i = fstTrue(0,sz(lens)-1,[&](int x) {
			return lens.bk-lens[x] <= pos;
		});
		const int partial_len = lens.bk-lens.at(i);
		return ::hash_at(intervals.at(i-1),pos-partial_len);
	}
};

vi tran(vi A) {
	SuffixArray<int> SA; SA.init(A);
	HR = HashRange();
	HR.add(A);
	

	

	

	

	

	vi p = prefix_answers(SA,A);
	vi q(N);
	F0R(i,N) {
		const int len = i+1-p[i];
		int lo = 1, hi = (i+1)/len;
		q[i] = lstTrue(lo,hi,[&](int x) { 
			return SA.getLCP(i+1-len*x,i+1-len*(x-1)) >= len*(x-1); });
		q[i] = i+1-len*q[i];
		assert(q[i] >= 0);
	}

	NotSegTree<HH> ST;
	R0F(i,N) { 

		

		

		

		

		const int len = N-i;
		int smarter = p.at(i);
		auto hash_bounds = [&](int l, int r) {
			assert(l <= i);
			HH ans = HH(l,min(r,i));
			l = i+1;
			if (l <= r) {
				ans = ans+ST.get_prefix(r-l+1);
			}
			return ans.val;
		};
		auto hash_start = [&](int l, int len) { return hash_bounds(l,l+len-1); };
		auto hash_at = [&](int l) {
			if (l <= i) return HR.hash(l,l);
			return ST.hash_at(l-i-1);
		};
		if (p[i] != q[i] && q[i]+len-1 > i) {
			

			int lcp = lstTrue(1,len,[&](int x) {
				return hash_start(p[i],x) == hash_start(q[i],x);
			});
			

			

			

			if (lcp < len && hash_at(q[i]+lcp) < hash_at(p[i]+lcp)) {
				smarter = q[i];
			}
			if (lcp < len) {
				dbg("WHOOPS",q[i]+lcp,p[i]+lcp,hash_at(q[i]+lcp),hash_at(p[i]+lcp));
			}
		} 
		int l = smarter, r = min(smarter+len,i+1);
		ST.push_front(l,r-1);
	}
	vi inds = ST.get_indices();
	vi ans;
	each(i,inds) ans.pb(A.at(i));
	return ans;
}

int main() {
	setIO();
	re(N);
	vi A(N); re(A);
	V<vi> seq{A};
	while (1) {
		vi new_bk = tran(seq.bk);
		if (new_bk == seq.bk) break;
		seq.pb(new_bk);
	}
	dbg(sz(seq));
	ints(q);
	rep(q) {
		ints(a,b);
		ckmin(a,sz(seq)-1);
		cout << seq.at(a).at(b-1) << "\n";
	}
	

}

