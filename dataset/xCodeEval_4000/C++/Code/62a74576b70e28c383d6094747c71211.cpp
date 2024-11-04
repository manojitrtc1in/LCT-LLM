#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define tc int test_case; cin >> test_case; while(test_case--)
#define yn(s) ps(s ? "YES" : "NO")
#define fir(i, a, b) for (auto i = (a); i <= (b); ++i) 

#define rif(i, a, b) for (auto i = (a); i >= (b); --i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define per(i, n) for (int i = (n) - 1; i >= 0; --i)
#define flr(x, a) for (auto &x : a)
#define rei(a...) int a; re(a)
#define rel(a...) ll a; re(a)
#define revi(a, n) int n; re(n); vi a(n); re(a)
#define revl(a, n) int n; re(n); vl a(n); re(a)
#define msz(a) memset((a), 0, sizeof(a))  

#define msm(a) memset((a), -1, sizeof(a)) 

#define in begin()
#define en end()
#define rin rbegin()
#define ren rend()
#define all(v) (v).in, (v).en 

#define rall(v) (v).rin, (v).ren
#define sz size()
#define mt empty()
#define sb(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; }) 

#define rsz resize 

#define acc accumulate
#define fi first
#define se second
#define pb push_back
#define ins insert
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using si = set<int>;
using sl = set<ll>;
using msi = multiset<int>;
using qi = queue<int>;
using ql = queue<ll>;
using pqi = priority_queue<int>;
using pql = priority_queue<ll>;

template<class... T> inline auto min(T... a) { return min({a...}); }
template<class T> inline auto min(T a, T b, T c) { return min({a, b, c}); } 

template<class T> inline auto min(T *a, T *b) { return *min_element(a, b); } 

template<class T> inline auto min(vector<T> &v) { return *min_element(all(v)); }

template<class... T> inline auto max(T... a) { return max({a...}); }
template<class T> inline auto max(T a, T b, T c) { return max({a, b, c}); } 

template<class T> inline auto max(T *a, T *b) { return *max_element(a, b); } 

template<class T> inline auto max(vector<T> &v) { return *max_element(all(v)); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<class T> bool uin(T &u, T &v, T a, T b) { return v - u > b - a ? (u = a, v = b, true) : false; }
template<class T> bool uax(T &u, T &v, T a, T b) { return v - u < b - a ? (u = a, v = b, true) : false; }

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);
    

	template<class T> void re(T& x) { cin >> x; } 

	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); } 

	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...);
    } 


    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); } 

	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    

	template<class T> void re(vector<T>& a) { rep(i,a.sz) re(a[i]); } 

    

	template<class T, size_t SZ> void re(array<T,SZ>& a) { rep(i,SZ) re(a[i]); } 

    

}
 
using namespace input;
 
namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; } 

	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...);
    } 

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); 

		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } 

	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	} 

	
	void pc() { pr("]\n"); } 

	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
    

}
 
using namespace output;

inline int bs(bool (*valid)(int), int l, int r, bool order = 1) 

{															

	l--, r++;
	if(!order)
		swap(l, r);
	while(abs(r - l) > 1)
	{
		int mid = (l + r) >> 1; 

		if(valid(mid))          

			r = mid;
		else
			l = mid;
	}
	valid(r);
	return r;
}

inline void ret(vi*&&v,int n) 

{
	rep(i,n)
	{
		rei(a,b);
		v[a].pb(b);
		v[b].pb(a);
	}
}

struct dsu
{
	vector<int> p;
	dsu(int n) { p.resize(n + 1); }
	inline int get(int x) { return p[x] ? p[x] = get(p[x]) : x; }
	inline bool mrg(int x, int y) { return get(x) == get(y) ? false : p[get(x)] = get(y); }
};

template<class T> 

struct bit
{
	vector<T> t; 

	bit(int n) { t.resize(n+1); } 

	inline void upd(int i, T x) 

	{
		for(;i<t.size();i+=i&-i) 

			t[i]+=x;
	}
	inline T q(int i)
	{
		T r=0;
		for(;i;i-=i&-i)
			r+=t[i];
		return r;
	}
};

inline vector<int>ff(string p) 

{
	vector<int>f(p.size());
	for(int c=0,i=1;i<p.size();++i)
	{
		while(c&&p[i]!=p[c])
			c=f[c-1];
		if(p[i]==p[c])
			f[i]=++c;
	}
	return f;
}
inline optional<vector<int>>kmp(string t,string p) 

{
	vector<int>a,f=ff(p);
	for(int c=0,i=0;i<t.size();++i)
	{
		while(c&&t[i]!=p[c])
			c=f[c-1];
		if(t[i]==p[c])
			c==p.size()-1?a.push_back(i-c+1),c=f[c]:c++;
	}
	if(a.empty())
		return{};
	return a;
}

template<class T>
inline void suv(vector<T>&v) 

{
	unordered_set<T>s;
	for(T&i:v)
		s.insert(i);
	v.assign(all(s)),sort(all(v));
}

inline void gp(vector<int>&v,int n) 

{
	for(int i=2;i<=n;++i)
	{
		for(int j=2;j*j<=i;++j)
			if(i%j==0)
				goto end;
		v.push_back(i);
	end:;
	}
}
inline void gp(vector<int>&v) 

{
	int n=v.size();
	v.clear();
	for(int i=2;v.size()<n;++i)
	{
		for(int j=2;j*j<=i;++j)
			if(i%j==0)
				goto end;
		v.push_back(i);
	end:;
	}
}

const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};
const char dc[] = "UDLR";
const int M = 1e9 + 7;

const ll lnf = 1e18 + 3;     

const int inf = 1e9 + 3;     

const int nax = 1.1e6 + 5; 

#pragma region
struct lst {
	lst *l = 0, *r = 0;
	int lo, hi;
	ll mset = lnf, madd = 0, val = -lnf;
	lst(int lo,int hi):lo(lo),hi(hi){} 

	lst(vector<ll>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new lst(v, lo, mid); r = new lst(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -lnf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != lnf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new lst(lo, mid); r = new lst(mid, hi);
		}
		if (mset != lnf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = lnf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

typedef decay<decltype(M)>::type T;
struct mi { 

	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) { 
		val = (-M <= v && v <= M) ? v : v % M;
		if (val < 0) val += M;
	}
	

		

	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
   
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }
 
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= M) val -= M; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += M; 
		return *this; }
	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%M; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(a != 0); return pow(a,M-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	

	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
 
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
 
vi invs, fac, ifac;
void genFac(int SZ) { 

	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	fir(i,2,SZ-1) invs[i] = M-(ll)M/i*invs[M%i]%M;
	fir(i,1,SZ-1) {
		fac[i] = (ll)fac[i-1]*i%M;
		ifac[i] = (ll)ifac[i-1]*invs[i]%M;
	}
}
ll comb(int a, int b) { 

	if (a < b || b < 0) return 0;
	return (ll)fac[a]*ifac[b]%M*ifac[a-b]%M;
}
int pow(ll a,ll n,int m=M)
{
	int ret=1;
	for(;n;n>>=1,a=a*a%m)
		if(n&1)
			ret=ret*a%m;
	return ret;
}
#pragma endregion
vector<pair<int,ll> > monsters[nax];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	vector<ll> wcost(nax, -lnf);
	vector<ll> bcost(nax, -lnf);
	int n, m, p;
	cin >> n >> m >> p; 

	rep(i,n)
	{
		rel(a,c);
		uax(wcost[--a], -c); 

	}
	rep(i,m)
	{
		rel(b,c);
		uax(bcost[--b], -c); 

	} 

	lst segtree(wcost, 0, nax); 

	rep(i,p)
	{
		rel(x,y,z);
		monsters[y].pb({x, z}); 

	}
	ll best = -lnf;
	rep(i,nax)
	{
		for(auto a : monsters[i]) 

			segtree.add(a.first, nax, a.second); 

		uax(best, segtree.query(0, nax) + bcost[i]); 

	} 

	cout << best << '\n';
}
















































