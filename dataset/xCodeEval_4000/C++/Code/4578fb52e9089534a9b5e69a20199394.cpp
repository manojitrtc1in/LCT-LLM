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

struct Interval {
	int l,r,id;
	AR<int,2> bounds{-1,-1};
	void set_bound(int i, int val) {
		assert(0 <= i && i <= 1 && bounds[i] == -1);
		bounds[i] = val;
	}
};

int N;
V<Interval> intervals;
vi child[2005];
AR<AR<vi,2>,2> dp[2005], prev_dp[2005], stor_dp[2005];

ll ans = 0;

int dif(int l, int r) {
	assert(l < r);
	return r-l;
}

vi& operator+=(vi& a, int b) {
	each(t,a) if (t != -1) t += b;
	return a;
}

vi& operator-=(vi& a, int b) {
	each(t,a) if (t != -1) {
		t -= b;
		assert(t >= 0);
	}
	return a;
}

void check_max(vi& a, const vi& b) {
	while (sz(a) < sz(b)) a.pb(-1);
	F0R(i,sz(b)) ckmax(a[i],b[i]);
}

vi convolve(const vi& a, const vi& b) {
	assert(sz(a) && sz(b));
	vi c(sz(a)+sz(b)-1,-1);
	F0R(i,sz(a)) if (a[i] != -1) F0R(j,sz(b)) if (b[j] != -1)
		ckmax(c[i+j],a[i]+b[j]);
	return c;
}

void upd(vi& v, int ind, int val) {
	while (sz(v) <= ind) v.pb(-1);
	ckmax(v[ind],val);
}

void gen_dp(int x) {
	if (!sz(child[x])) {
		

		dp[x][0][0] = {dif(intervals[x].l,intervals[x].r)};
	} else {
		F0R(i,sz(child[x])) {
			int y = child[x][i];
			gen_dp(y);
			if (i == 0) {
				prev_dp[x] = dp[y];
			} else {
				swap(stor_dp[y],prev_dp[x]);
				F0R(a,2) F0R(b,2) F0R(c,2) {
					vi v = convolve(stor_dp[y][a][b],dp[y][b][c]);
					if (b) {
						v += dif(intervals[child[x][i-1]].r,intervals[y].l);
						v.ins(begin(v),-1);
					}
					check_max(prev_dp[x][a][c],v);
				}
			}
		}
		F0R(i,2) F0R(j,2) { 

			if (i) prev_dp[x][i][j] += dif(intervals[x].l,intervals[child[x].ft].l);
			if (j) prev_dp[x][i][j] += dif(intervals[child[x].bk].r,intervals[x].r);
		}
		F0R(i,2) F0R(j,2) F0R(k,sz(prev_dp[x][i][j])) {
			int v = prev_dp[x][i][j][k]; if (v == -1) continue;
			if (k) upd(dp[x][i][j],k-1,v); 

			if (i) upd(dp[x][0][j],k,v); 

			if (j) upd(dp[x][i][0],k,v); 

		}
	}
	

	F0R(i,2) F0R(j,2) { 

		if (!i) check_max(dp[x][1][j],dp[x][i][j]);
		if (!j) check_max(dp[x][i][1],dp[x][i][j]);
	}
}

int get_val(const vi& v, int ind) {
	if (ind < sz(v)) return v[ind];
	return -1;
}

void reconstruct(int l, int x, int r, vi available) {
	int des = get_val(dp[x][l != -1][r != -1],sz(available));
	assert(des != -1);
	

	if (l != -1 && get_val(dp[x][0][r != -1],sz(available)) == des) {
		intervals[l].set_bound(1,intervals[x].l);
		l = -1;
	}
	if (r != -1 && get_val(dp[x][l != -1][0],sz(available)) == des) {
		intervals[r].set_bound(0,intervals[x].r);
		r = -1;
	}
	if (sz(child[x]) == 0) {
		

		assert(l == -1 && r == -1 && sz(available) == 0);
		intervals[x].set_bound(0,intervals[x].l);
		intervals[x].set_bound(1,intervals[x].r);
		return;
	}
	if (des == get_val(prev_dp[x][l != -1][r != -1],sz(available)+1)) available.pb(x);
	else if (l == -1 && des == get_val(prev_dp[x][1][r != -1],sz(available))) {
		l = x;
		intervals[x].set_bound(0,intervals[x].l);
	} else if (r == -1 && des == get_val(prev_dp[x][l != -1][1],sz(available))) {
		r = x;
		intervals[x].set_bound(1,intervals[x].r);
	}
	else assert(0);
	F0R(i,2) F0R(j,2) { 

		if (i) prev_dp[x][i][j] -= dif(intervals[x].l,intervals[child[x].ft].l);
		if (j) prev_dp[x][i][j] -= dif(intervals[child[x].bk].r,intervals[x].r);
	}
	R0F(i,sz(child[x])) {
		int y = child[x][i];
		if (i == 0) {
			reconstruct(l,y,r,available);
			return;
		}
		F0R(b,3) {
			assert(b != 2);
			int a = (l != -1);
			int c = (r != -1);
			vi v = convolve(stor_dp[y][a][b],dp[y][b][c]);
			int extra_dif = b?dif(intervals[child[x][i-1]].r,intervals[y].l):0;
			if (b) {
				v += extra_dif;
				v.ins(begin(v),-1);
			}
			int des = get_val(prev_dp[x][l != -1][r != -1],sz(available));
			assert(des != -1);
			if (get_val(v,sz(available)) == des) {
				int popped = -1;
				if (b) {
					popped = available.bk;
					available.pop_back();
				}
				int avail_right_sz = -1;
				F0R(i0,sz(stor_dp[y][a][b])) F0R(i1,sz(dp[y][b][c])) {
					int v0 = stor_dp[y][a][b][i0], v1 = dp[y][b][c][i1];
					if (i0+i1 == sz(available) && v0 != -1 && v1 != -1 && v0+v1+extra_dif == des) {
						avail_right_sz = i1;
						break;
					}
				}
				assert(avail_right_sz != -1);
				vi available_right;
				rep(avail_right_sz) {
					available_right.pb(available.bk);
					available.pop_back();
				}
				reconstruct(popped,y,r,available_right);
				r = popped;
				break;
			}
		}
		swap(prev_dp[x],stor_dp[y]);
	}
}

void solve_subtree(int x) {
	gen_dp(x);
	ans += dp[x][0][0][0];
	reconstruct(-1,x,-1,{});
}

int main() {
	setIO(); re(N);
	intervals.rsz(N);
	F0R(i,N) {
		re(intervals[i].l,intervals[i].r);
		intervals[i].id = i;
	}
	sort(all(intervals),[](const Interval& a, const Interval& b) {
		return a.l < b.l; });
	vi stk{N};
	F0R(i,N) {
		while (sz(stk) > 1 && intervals[stk.bk].r < intervals[i].l) stk.pop_back();
		child[stk.bk].pb(i);
		stk.pb(i);
	}
	F0R(i,N+1) dbg(i,child[i]);
	for (int i: child[N]) solve_subtree(i);
	sort(all(intervals),[](const Interval& a, const Interval& b) {
		return a.id < b.id; });
	ps(ans);
	

	int len = 0;
	each(t,intervals) {
		assert(t.bounds[0] != -1 && t.bounds[0] < t.bounds[1]);
		ps(t.bounds[0],t.bounds[1]);
		len += t.bounds[1]-t.bounds[0];
	}
	assert(len == ans);
}

