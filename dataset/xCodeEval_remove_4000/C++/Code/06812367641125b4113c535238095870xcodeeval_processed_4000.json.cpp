
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
 




tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
 





 

















 


tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
 








 
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
constexpr int id6(int x) { return p2(x)-1; }
 
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
	tcT> constexpr bool id11 = is_iterable<T>::value;
 
	

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
	tcT> constexpr bool id2 = is_printable<T>::value;
}
 
inline namespace Input {
	tcT> constexpr bool id9 = !id0<T> && id11<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 

 
	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id9<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id9<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id3 = !id2<T> && id11<T>;
 
	

	tcT> typename enable_if<id2<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id5(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id3<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id3<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }
 
	

	template<int, class T> typename enable_if<!id3<T>,vs>::type 
	  id7(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id3<T>,vs>::type 
	  id7(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id7<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id5(i,sz(res)) {
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
	template<int lev, class T> void id12(const T& t) {
		cerr << "\n\n" << ts_sep(id7<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	
}
 
inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}

vi trie_ch[1000005];
vi st, en;



int trie_par[1000005];
 
struct ACfixed { 

	static const int ASZ = 26;
	AR<int,26> to[1000005];
	int link[1000005];
	int max_suf[1000005];
	int cnt = 1;
	ACfixed() {
		id5(i,1000005) max_suf[i] = -1;
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
			if (max_suf[v] != -1) {
				int a = max_suf[link[v]]+1, b = max_suf[v]+1;
				trie_ch[a].pb(b);
				trie_par[b] = a;
			}
			if (max_suf[v] == -1 && link[v] != -1) {
				max_suf[v] = max_suf[link[v]];
			}
			id5(c,ASZ) {
				int u = to[v][c]; if (!u) continue;
				link[u] = link[v] == -1 ? 0 : to[link[v]][c];
				q.push(u); 
			}
			if (v) id5(c,ASZ) if (!to[v][c]) 
				to[v][c] = to[link[v]][c];
		}
	}
};


 
template<class T> struct RMQ { 

	int level(int x) { return 31-__builtin_clz(x); } 
	AR<int,1000005> jmp[20];
	

	

	void init(const vector<T>& v) {
		id5(i,sz(v)) jmp[0][i] = v[i];
		for (int j = 1; 1<<j <= sz(v); ++j) {
			id5(i,sz(jmp[j])) jmp[j][i] = min(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { 

		assert(l <= r); int d = level(r-l+1);
		return min(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return index(l,r); }
};
 

 


 
clock_t beg = clock();







 










 














 
ACfixed AC;
int N;
 

 
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
template<class T, int N> int id1(const BIT<T,N>& bit, T des) { 
	assert(des > 0);
	int ind = 0;
	for (int i = 1<<bits(N); i; i /= 2)
		if (ind+i <= N && bit.bit[ind+i].val < des)
			des -= bit.bit[ind += i].val;
	assert(ind < N); return ind+1;
}
 

namespace std {

template<class Fun>
class id10 {
	Fun fun_;
public:
	template<class T>
	explicit id10(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) id4(Fun &&fun) {
	return id10<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} 


BIT<int,1000005> bit;

int main() {
	setIO(); re(N);
 
	vs v(N);
	

	re(v);
 
	str tot; each(t,v) tot += t;
	id5(i,sz(v)) AC.add(i,v[i]);
	AC.init();
	st = en = vi(sz(tot)+1);
	{
		int cur_idx = 0;
		id4([&](auto self, int cur) -> void {
			dbg(cur,trie_ch[cur]);
			st[cur] = ++cur_idx;
			for (int nxt : trie_ch[cur]) {
				self(nxt);
			}
			en[cur] = cur_idx;
		})(0);
	}

	int ans = 0;
	id5(i,sz(v)) {
		vi suf(sz(v[i]),-1);
		{
			int ind = 0;
			id5(j,sz(v[i])) {
				char c = v[i][j]; ind = AC.to[ind][c-'a'];
				if (j == sz(v[i])-1) ind = AC.link[ind];
				if (ind != -1) suf[j] = AC.max_suf[ind];
			}
		}

		int mn = MOD;
		vi bads; set<int> cnds;
		id8(j,sz(v[i])) {
			int x = suf[j];
			if (x == -1) continue;
			assert(x < sz(v));
			if (j-sz(v[x]) < mn) { 

				mn = j-sz(v[x]); cnds.ins(x);
				x = trie_par[x+1]-1;
			} 
			if (x != -1) bads.pb(x);
		}

		for (int j: bads) bit.upd(st[j+1],1);
		for (int j: cnds) if (!bit.query(st[j+1],en[j+1])) ++ans;
		for (int j: bads) bit.upd(st[j+1],-1);
	}
	ps(ans);
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	

}
 
