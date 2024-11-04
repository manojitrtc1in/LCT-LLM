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
#define EACH(a,x) for (auto& a: x)

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
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { EACH(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { EACH(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }



#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	

	

	

	return ts((int)b);
	

}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(V<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { 

	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}



tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } 

tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }



void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL 

	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }


void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s = "") {
	unsyncIO(); setPrec();
	

	

	

	if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

}



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
	int get_kth(T des) { assert(des > 0);
		int ind = 0;
		for (int i = 1<<bits(N); i; i /= 2)
			if (ind+i <= N && bit[ind+i].val < des)
				des -= bit[ind += i].val;
		if (ind == N) return MOD;
		assert(ind < N); return ind+1;
	}
	int at_least(int des) {
		assert(des > 0);
		-- des;
		int tot = sum(des);
		return get_kth(tot+1);
	}
	int at_most(int des) {
		int tot = sum(des); if (tot == 0) return MOD;
		return get_kth(tot);
	}
}; 


















BIT<int,5000005> BA, BB;
BIT<ll,5000005> ZZ;
int N,M,Q;
vi A,B;
ll sum_A = 0;

pair<ll,int> at_least(ll dif) {
	

	if (dif > 5000004) return {0,0};
	ckmax(dif,0LL);
	return {ZZ.sum(5000004)-ZZ.sum(dif),M-BB.sum(dif)};
}

ll calc(ll init) {
	dbg("OOPS",A,B);
	

	vpi v; 
	

	

	


	

	

	

	

	ll ans = -INF;
	ll ad = max(-BA.get_kth(1),-BB.get_kth(1));
	

	

	auto get_all = [&](ll dif) {
		

		

		

		pair<ll,int> x = at_least(-dif);
		return x.s*dif+x.f;
	};
	
	auto calc_A = [&](ll dif) {
		ll sum = 0; 
		sum -= get_all(dif);
		

		

		

		sum += (N-1)*max(dif,ad);
		sum += dif;
		sum += sum_A;
		ckmax(ans,sum);
	};
	auto calc_B = [&](ll dif) {
		ll sum = 0; 
		sum -= get_all(dif);
		

		sum += N*max(dif,ad);
		sum += sum_A;
		ckmax(ans,sum);
	};
	auto A_around = [&](int z) {
		int t = BA.at_least(init+z);
		if (t != MOD) calc_A(init-t);
		t = BA.at_most(init+z);
		if (t != MOD) calc_A(init-t);
	};
	auto B_around = [&](int z) {
		int t = BB.at_least(init+z);
		if (t != MOD) calc_B(init-t);
		t = BB.at_most(init+z);
		if (t != MOD) calc_B(init-t);
	};
	
	auto deal_A = [&]() {
		calc_A(init-BA.get_kth(1));
		calc_A(init-BA.get_kth(N));
		A_around(-ad);
		FOR(i,N-2,N+3) if (1 <= i && i <= M) {
			A_around(BB.get_kth(i));
		}
	};
	auto deal_B = [&]() {
		calc_B(init-BB.get_kth(1));
		calc_B(init-BB.get_kth(M));
		B_around(-ad);
		FOR(i,N-2,N+3) if (1 <= i && i <= M) {
			B_around(BB.get_kth(i));
		}

		

		

	};
	deal_A();
	deal_B();
	
	
	

	
	

	

			
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	


	

	

	


	

	

	

	

	

	


	


	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	
	

	

	

	

	

	

	

	

	

	

	return ans;
}

int main() {
	setIO(); re(N,M,Q);
	A.rsz(N), B.rsz(M); 
	re(A,B);
	EACH(t,A) {
		++t;
		BA.upd(t,1);
		sum_A += t;
	}
	EACH(t,B) {
		++t;
		BB.upd(t,1);
		ZZ.upd(t,t);
	}
	F0R(i,Q) {
		int t; re(t);
		if (t <= 2) {
			int pos,x; re(pos,x); -- pos; 
			++x;
			if (t == 1) {
				BA.upd(A[pos],-1);
				sum_A -= A[pos];
				A[pos] = x;
				sum_A += A[pos];
				BA.upd(x,1);
			} else {
				ZZ.upd(B[pos],-B[pos]);
				BB.upd(B[pos],-1);
				B[pos] = x;
				BB.upd(x,1);
				ZZ.upd(B[pos],B[pos]);
			}
		} else {
			int x; re(x);
			ps(calc(x));
		}
	}
	
	

}


