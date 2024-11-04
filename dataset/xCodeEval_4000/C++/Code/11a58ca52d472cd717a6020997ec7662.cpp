#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE 1
	#include <boost/stacktrace.hpp>
	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::reverse_iterator first, const typename std::vector<T>::reverse_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_iterator first, const typename std::vector<T>::const_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_reverse_iterator first, const typename std::vector<T>::const_reverse_iterator last) : std::vector<T>(first, last) {}
			T& operator[](size_t n) {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void catch_SIGSEGV([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif
#ifdef LOCAL_DEV
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {
		s << "\\\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << ":" << __LINE__ << " (" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
#else
	#define debug(...) do {} while (false)
#endif


using ll = long long;
constexpr int INF = (ll)1e9 + 7; 





constexpr ll MOD = 998244353; 

constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }




inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y){ ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
inline constexpr ll invmod(ll a, ll m = MOD){ ll x = 0, y = 0; extgcd(a, m, x, y); return (x + m) % m; }
class Modint{
public:
	ll _num;
	constexpr Modint() : _num() { _num = 0; }
	constexpr Modint(ll x) : _num() { _num = x % MOD; if(_num < 0) _num += MOD; }
	inline constexpr Modint operator= (int x){ _num = x % MOD; if(_num<0) _num += MOD; return *this; }
	inline constexpr Modint operator= (ll x){ _num = x % MOD; if(_num<0) _num += MOD; return *this; }
	

	inline constexpr Modint operator+ (int x){ return Modint(_num + x); }
	inline constexpr Modint operator+ (ll x){ return Modint(_num + x); }
	inline constexpr Modint operator+ (Modint x){ ll a = _num + x._num; if(a >= MOD) a -= MOD; return Modint{a}; }
	inline constexpr Modint operator+=(int x){ _num += x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator+=(ll x){ _num += x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator+=(Modint x){ _num += x._num; if(_num >= MOD) _num -= MOD; return *this; }
	inline constexpr Modint operator++(){ _num++; if(_num == MOD) _num = 0; return *this; }
	inline constexpr Modint operator- (int x){ return Modint(_num - x); }
	inline constexpr Modint operator- (ll x){ return Modint(_num - x); }
	inline constexpr Modint operator- (Modint x){ ll a = _num - x._num; if(a < 0) a += MOD; return Modint{a}; }
	inline constexpr Modint operator-=(int x){ _num -= x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator-=(ll x){ _num -= x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator-=(Modint x){ _num -= x._num; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator--(){ _num--; if(_num == -1) _num = MOD - 1; return *this; }
	inline constexpr Modint operator* (int x){ return Modint(_num * (x % MOD)); }
	inline constexpr Modint operator* (ll x){ return Modint(_num * (x % MOD)); }
	inline constexpr Modint operator* (Modint x){ return Modint{_num * x._num % MOD}; }
	inline constexpr Modint operator*=(int x){ _num *= Modint(x); _num %= MOD; return *this; }
	inline constexpr Modint operator*=(ll x){ _num *= Modint(x); _num %= MOD; return *this; }
	inline constexpr Modint operator*=(Modint x){ _num *= x._num; _num %= MOD; return *this; }
	inline constexpr Modint operator/ (int x){ return Modint(_num * invmod(Modint(x), MOD)); }
	inline constexpr Modint operator/ (ll x){ return Modint(_num * invmod(Modint(x), MOD)); }
	inline constexpr Modint operator/ (Modint x){ return Modint{_num * invmod(x._num, MOD) % MOD}; }
	inline constexpr Modint operator/=(int x){ _num *= invmod(Modint(x), MOD); _num %= MOD; return *this; }
	inline constexpr Modint operator/=(ll x){ _num *= invmod(Modint(x), MOD); _num %= MOD; return *this; }
	inline constexpr Modint operator/=(Modint x){ _num *= invmod(x._num, MOD); _num %= MOD; return *this; }
	inline constexpr Modint pow(ll n){ ll i = 1, x = n>=0 ? n : -n; Modint ans = 1, cnt = n>=0 ? *this : Modint(1) / *this; while(i <= x){ if(x & i){ ans *= cnt; x ^= i; } cnt *= cnt; i *= 2; } return ans; }
	inline constexpr operator ll() const { return _num; }
	inline constexpr static ll get_mod() { return MOD; }
};
inline std::istream& operator>>(std::istream &s, Modint &x){ ll t; s>>t; x=t; return s; }
vector<Modint> fac(1, 1), inv(1, 1);
inline void reserve(size_t a){
	if(fac.size() >= a) return;
	if(a < fac.size() * 2) a = fac.size() * 2;
	if(a >= (size_t)MOD) a = MOD;
	while(fac.size() < a) fac.push_back(fac.back() * ll(fac.size()));
	inv.resize(fac.size());
	inv.back() = Modint(1) / fac.back();
	for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
inline Modint factorial(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
inline Modint nPk_loop(ll n, ll k){ if(n<k) return 0; Modint val(1); for(ll i=n;i>(n-k);i--)val*=i; return val; }
inline Modint nCk_loop(ll n, ll k){ if(n<k) return 0; Modint val(1); k=min(k,n-k); for(ll i=n;i>(n-k);i--)val*=i; for(ll i=k;i>1;i--)val/=i; return val; };
inline Modint nPk(ll n, ll k){ if(k < 0 || n < k) return 0; if(n>=(ll)1e7) return nPk_loop(n, k); reserve(n + 1); return fac[n] * inv[n - k]; }
inline Modint nCk(ll n, ll k){ if(k < 0 || n < k) return 0; if(n>=(ll)1e7) return nCk_loop(n, k); reserve(n + 1); return fac[n] * inv[k] * inv[n - k]; }
inline Modint nHk(ll n, ll k){ return nCk(n + k - 1, k); } 



template<typename T>
class DancingLinks{
public:
	struct node{
		T data;
		array<pair<ll,ll>,4> links={pair<ll,ll>(INF,INF),pair<ll,ll>(INF,INF),pair<ll,ll>(INF,INF),pair<ll,ll>(INF,INF)};
	};

	

	map<pair<ll,ll>,node> nodemap;
	

	

	array<map<ll,set<ll>>,2> xyset;

	DancingLinks(){}

	bool exist(ll x, ll y){
		return nodemap.find({x,y}) != nodemap.end();
	}
	bool exist(const pair<ll,ll>& xy){
		return exist(xy.first, xy.second);
	}

	void update(ll x, ll y, ll val){
		if(exist(x,y)){
			nodemap[{x,y}].data=val;
			return;
		}
		node n;
		n.data=val;
		ll arr[2]={x,y};
		for(ll i=0; i<2; i++){
			auto it=xyset[i][arr[(i+1)%2]].lower_bound(arr[i]);
			if(it != xyset[i][arr[(i+1)%2]].end()){
				pair<ll,ll> pr={*it, arr[(i+1)%2]};
				if(i==1)swap(pr.first, pr.second);
				n.links[i]=pr;
				nodemap[pr].links[i+2]={x,y};
			}
			if(it != xyset[i][arr[(i+1)%2]].begin()){
				advance(it, -1);
				pair<ll,ll> pr={*it, arr[(i+1)%2]};
				if(i==1)swap(pr.first, pr.second);
				n.links[i+2]=pr;
				nodemap[pr].links[i]={x,y};
			}
		}
		nodemap[{x,y}]=n;
		xyset[0][y].insert(x);
		xyset[1][x].insert(y);
	}
	void update(const pair<ll,ll>& xy){
		update(xy.first, xy.second);
	}

	void erase(ll x, ll y){
		if(!exist(x,y)) return;
		for(ll i=0; i<4; i++){
			auto n=nodemap[{x,y}];
			if(exist(n.links[i])){
				nodemap[n.links[i]].links[(i+2)%4]=n.links[(i+2)%4];
			}
		}
		nodemap.erase(nodemap.find({x,y}));
		xyset[0][y].erase(x);
		xyset[1][x].erase(y);
	}
	void erase(const pair<ll,ll>& xy){
		erase(xy.first, xy.second);
	}

	T query(ll x, ll y){
		if(!exist(x,y)) return T();
		return nodemap[{x,y}].data;
	}
	T query(const pair<ll,ll>& xy){
		return query(xy.first, xy.second);
	}

	pair<ll,ll> position(ll x, ll y, ll index){
		return nodemap[{x,y}].links[index];
	}
	pair<ll,ll> position(const pair<ll,ll>& xy, ll index){
		return position(xy.first, xy.second, index);
	}	
};




void solve() {
	ll N,K;
	cin>>N>>K;
	vector<ll> a(N);
	rep(i,N)cin>>a[i];
	vector<ll> b(K);
	rep(i,K)cin>>b[i];
	debug(a);
	debug(b);
	DancingLinks<ll> dl;
	rep(i,N)dl.update(i,0,a[i]);

	Modint ans=1;
	vector<bool> canremove(N+1,true);
	rep(i,K)canremove[b[i]]=false;

	vector<ll> index(N+1,-1);
	rep(i,N)index[a[i]]=i;

	rep(i,K){
		ll idx=index[b[i]];
		debug(i,b[i],idx);
		if(idx<0){
			p(0);return;
		}
		ll count=0;
		pair<ll,ll> ap=dl.position(idx, 0, 0);
		pair<ll,ll> bp=dl.position(idx, 0, 2);
		bool x[2]={false,false};
		if(ap!=pair<ll,ll>({INF,INF})){
			ll t=dl.query(ap);
			debug(ap,t);
			if(canremove[t])count++,x[0]=true;
		}
		if(bp!=pair<ll,ll>({INF,INF})){
			ll t=dl.query(bp);
			debug(bp,t);
			if(canremove[t])count++,x[1]=true;
		}
		debug(x[0],x[1]);
		if(count==0){
			p(0);return;
		}
		ans*=count;
		canremove[b[i]]=true;
		if(x[0]){
			dl.erase(ap);
		}else if(x[1]){
			dl.erase(bp);
		}
	}
	p(ans);
}

signed main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	ll Q; cin >> Q; while(Q--)solve();
	

	return 0;
}
