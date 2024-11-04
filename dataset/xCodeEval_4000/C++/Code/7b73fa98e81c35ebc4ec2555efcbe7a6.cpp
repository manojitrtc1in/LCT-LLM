#include "bits/stdc++.h"
#if 0
#define MODLL (1000000007LL)
#else
#define MODLL (998244353LL)
#endif

using namespace std;


using     ll=long long;     using   dd=double;     
using    vll=vector<   ll>; using  vdd=vector< dd>;
using   vvll=vector<  vll>; using vvdd=vector<vdd>;
using  vvvll=vector< vvll>; using vvvdd=vector<vvdd>;
using vvvvll=vector<vvvll>;
using   pll=pair<ll,ll>;  using   tll=tuple<ll,ll,ll>; using   qll=tuple<ll,ll,ll,ll>;
using  vpll=vector< pll>; using  vtll=vector< tll>;    using  vqll=vector< qll>;
using vvpll=vector<vpll>; using vvtll=vector<vtll>;    using vvqll=vector<vqll>;
constexpr ll INF = 1LL << 60;
struct Fast{ Fast(){ cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(numeric_limits<double>::max_digits10); } } fast;
#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define REP(i, N) REPS(i, 0, (N)-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, (N)-1)
#define EXPAND( x ) x

#define overload3(_1,_2,_3,name,...) name
#define overload4(_1,_2,_3,_4,name,...) name
#define overload5(_1,_2,_3,_4,_5,name,...) name
#define rep3(i, S, E)    for (ll i = (S); i <= (E); i++)
#define rep4(i, S, E, t) for (ll i = (S); i <= (E); i+=(t))
#define rep(...) EXPAND(overload4(__VA_ARGS__,rep4,rep3,_,_)(__VA_ARGS__))
#define dep3(i, E, S)    for (ll i = (E); i >= (S); i--)
#define dep4(i, E, S, t) for (ll i = (E); i >= (S); i-=(t))
#define dep(...) EXPAND(overload4(__VA_ARGS__, dep4, dep3,_,_)(__VA_ARGS__))
#define each2(e,v) for (auto && e:v)
#define each3(a,b,v) for (auto &&[a,b]:v)
#define each4(a,b,c,v) for (auto &&[a,b,c]:v)
#define each5(a,b,c,d,v) for (auto &&[a,b,c,d]:v)
#define each(...) EXPAND(overload5(__VA_ARGS__,each5,each4,each3,each2,_)(__VA_ARGS__))
#define ALL1(v)     (v).begin(),     (v).end()
#define ALL2(v,E)   (v).begin(),     (v).begin()+((E)+1)
#define ALL3(v,S,E) (v).begin()+(S), (v).begin()+((E)+1)
#define ALL(...) EXPAND(overload3(__VA_ARGS__, ALL3, ALL2, ALL1)(__VA_ARGS__))
#define all ALL
#define RALL1(v)     (v).rbegin(),     (v).rend()
#define RALL2(v,E)   (v).rbegin(),     (v).rbegin()+((E)+1)
#define RALL3(v,S,E) (v).rbegin()+(S), (v).rbegin()+((E)+1)
#define RALL(...) EXPAND(overload3(__VA_ARGS__, RALL3, RALL2, RALL1)(__VA_ARGS__))
#define rall RALL
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmax(m,v[i]); return m; }
template<class T> inline T MinE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmin(m,v[i]); return m; }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v,0,(ll)v.size()-1); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v,0,(ll)v.size()-1); }
template<class T> inline auto maxe(T &&v,ll S,ll E){ return *max_element(ALL(v,S,E)); }
template<class T> inline auto maxe(T &&v){ return *max_element(ALL(v)); }
template<class T> inline auto mine(T &&v,ll S,ll E){ return *min_element(ALL(v,S,E)); }
template<class T> inline auto mine(T &&v){ return *min_element(ALL(v)); }
template<class T> inline T Sum(vector<T> &v,ll S,ll E){ T s=T(); rep(i,S,E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v) { return Sum(v,0,v.size()-1); }
template<class T,class U=typename remove_reference<T>::type::value_type>
inline U sum(T &&v,ll S,ll E) {return accumulate(all(v,S,E),U());}
template<class T> inline auto sum(T &&v) {return sum(v,0,v.end()-v.begin()-1);}
template<class T> inline ll sz(T &&v){ return (ll)v.size(); }
inline ll CEIL(ll a,ll b){ return (a<0) ? -(-a/b) : (a+b-1)/b; } 

inline ll FLOOR(ll a,ll b){ return -CEIL(-a,b); } 


												  

template<class T,class S> inline pair<T,S>& operator+=(pair<T,S> &a,const pair<T,S> &b){ a.first+=b.first; a.second+=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator-=(pair<T,S> &a,const pair<T,S> &b){ a.first-=b.first; a.second-=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator*=(pair<T,S> &a,const pair<T,S> &b){ a.first*=b.first; a.second*=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator/=(pair<T,S> &a,const pair<T,S> &b){ a.first/=b.first; a.second/=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator%=(pair<T,S> &a,const pair<T,S> &b){ a.first%=b.first; a.second%=b.second; return a; }
template<class T,class S,class R> inline pair<T,S>& operator+=(pair<T,S> &a,R b){ a.first+=b; a.second+=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator-=(pair<T,S> &a,R b){ a.first-=b; a.second-=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator*=(pair<T,S> &a,R b){ a.first*=b; a.second*=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator/=(pair<T,S> &a,R b){ a.first/=b; a.second/=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator%=(pair<T,S> &a,R b){ a.first%=b; a.second%=b; return a; }
template<class T,class S,class R> inline pair<T,S> operator+(const pair<T,S> &a,R b){ pair<T,S> c=a; return c+=b; }
template<class T,class S,class R> inline pair<T,S> operator-(const pair<T,S> &a,R b){ pair<T,S> c=a; return c-=b; }
template<class T,class S,class R> inline pair<T,S> operator*(const pair<T,S> &a,R b){ pair<T,S> c=a; return c*=b; }
template<class T,class S,class R> inline pair<T,S> operator/(const pair<T,S> &a,R b){ pair<T,S> c=a; return c/=b; }
template<class T,class S,class R> inline pair<T,S> operator%(const pair<T,S> &a,R b){ pair<T,S> c=a; return c%=b; }
template<class T,class S,class R> inline pair<T,S> operator-(R b,const pair<T,S> &a){ pair<T,S> c=-a; return c+=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a,const pair<T,S> &b){ pair<T,S> c=a; return c-=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a){ pair<T,S> c=a; return c*=(-1); }
template<class T,class S> inline ostream &operator<<(ostream &os,const pair<T,S> &a){ return os << a.first << ' ' << a.second; }



template<class T> inline vector<T>& operator+=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]+=b[i];  return a; }
template<class T> inline vector<T>& operator-=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]-=b[i];  return a; }
template<class T> inline vector<T>& operator*=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]*=b[i];  return a; }
template<class T> inline vector<T>& operator/=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]/=b[i];  return a; }
template<class T> inline vector<T>& operator%=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]%=b[i];  return a; }
template<class T,class S> inline vector<T>& operator+=(vector<T> &a,S b){ for (T &e: a) e+=b;  return a; }
template<class T,class S> inline vector<T>& operator-=(vector<T> &a,S b){ for (T &e: a) e-=b;  return a; }
template<class T,class S> inline vector<T>& operator*=(vector<T> &a,S b){ for (T &e: a) e*=b;  return a; }
template<class T,class S> inline vector<T>& operator/=(vector<T> &a,S b){ for (T &e: a) e/=b;  return a; }
template<class T,class S> inline vector<T>& operator%=(vector<T> &a,S b){ for (T &e: a) e%=b;  return a; }
template<class T,class S> inline vector<T> operator+(const vector<T> &a,S b){ vector<T> c=a; return c+=b; }
template<class T,class S> inline vector<T> operator-(const vector<T> &a,S b){ vector<T> c=a; return c-=b; }
template<class T,class S> inline vector<T> operator*(const vector<T> &a,S b){ vector<T> c=a; return c*=b; }
template<class T,class S> inline vector<T> operator/(const vector<T> &a,S b){ vector<T> c=a; return c/=b; }
template<class T,class S> inline vector<T> operator%(const vector<T> &a,S b){ vector<T> c=a; return c%=b; }
template<class T,class S> inline vector<T> operator-(S b,const vector<T> &a){ vector<T> c=-a; return c+=b; }
template<class T> inline vector<T> operator-(const vector<T> &a,const vector<T> &b){ vector<T> c=a; return c-=b; }
template<class T> inline vector<T> operator-(const vector<T> &a){ vector<T> c=a; return c*=(-1); }
template<class T> inline ostream &operator<<(ostream &os,const vector<T> &a){ for (ll i=0; i<(ll)a.size(); i++) os<<(i>0?" ":"")<<a[i];  return os; }



template<class T,size_t S> inline array<T,S>& operator+=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]+=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator-=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]-=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator*=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]*=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator/=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]/=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator%=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]%=b[i];  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator+=(array<T,S> &a,R b){ for (T &e: a) e+=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator-=(array<T,S> &a,R b){ for (T &e: a) e-=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator*=(array<T,S> &a,R b){ for (T &e: a) e*=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator/=(array<T,S> &a,R b){ for (T &e: a) e/=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator%=(array<T,S> &a,R b){ for (T &e: a) e%=b;  return a; }
template<class T,size_t S,class R> inline array<T,S> operator+(const array<T,S> &a,R b){ array<T,S> c=a; return c+=b; }
template<class T,size_t S,class R> inline array<T,S> operator-(const array<T,S> &a,R b){ array<T,S> c=a; return c-=b; }
template<class T,size_t S,class R> inline array<T,S> operator*(const array<T,S> &a,R b){ array<T,S> c=a; return c*=b; }
template<class T,size_t S,class R> inline array<T,S> operator/(const array<T,S> &a,R b){ array<T,S> c=a; return c/=b; }
template<class T,size_t S,class R> inline array<T,S> operator%(const array<T,S> &a,R b){ array<T,S> c=a; return c%=b; }
template<class T,size_t S,class R> inline array<T,S> operator-(R b,const array<T,S> &a){ array<T,S> c=-a; return c+=b; }
template<class T,size_t S> inline array<T,S> operator-(const array<T,S> &a,const array<T,S> &b){ array<T,S> c=a; return c-=b; }
template<class T,size_t S> inline array<T,S> operator-(const array<T,S> &a){ array<T,S> c=a; return c*=(-1); }
template<class T,size_t S> inline ostream &operator<<(ostream &os,const array<T,S> &a){ for (ll i=0; i<(ll)S; i++) os<<(i>0?" ":"")<<a[i];  return os; }

template<ll MOD> struct mll_{
	ll val;
	mll_(ll v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	mll_ operator - () const { return -val; }
	mll_ operator + (const mll_ &b) const { return val + b.val; }
	mll_ operator - (const mll_ &b) const { return val - b.val; }
	mll_ operator * (const mll_ &b) const { return val * b.val; }
	mll_ operator / (const mll_ &b) const { return mll_(*this) /= b; }
	mll_ operator + (ll b) const { return *this + mll_(b); }
	mll_ operator - (ll b) const { return *this - mll_(b); }
	mll_ operator * (ll b) const { return *this * mll_(b); }
	friend mll_ operator + (ll a,const mll_ &b) { return b + a; }
	friend mll_ operator - (ll a,const mll_ &b) { return -b + a; }
	friend mll_ operator * (ll a,const mll_ &b) { return b * a; }
	friend mll_ operator / (ll a,const mll_ &b) { return mll_(a)/b; }
	mll_ &operator += (const mll_ &b) { val=(val+b.val)%MOD; return *this; }
	mll_ &operator -= (const mll_ &b) { val=(val+MOD-b.val)%MOD; return *this; }
	mll_ &operator *= (const mll_ &b) { val=(val*b.val)%MOD; return *this; }
	mll_ &operator /= (const mll_ &b) {
		ll c=b.val,d=MOD,u=1,v=0;
		while (d){
			ll t = c / d;
			c -= t * d; swap(c,d);
			u -= t * v; swap(u,v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll_ &operator += (ll b) { return *this += mll_(b); }
	mll_ &operator -= (ll b) { return *this -= mll_(b); }
	mll_ &operator *= (ll b) { return *this *= mll_(b); }
	mll_ &operator /= (ll b) { return *this /= mll_(b); }
	bool operator == (const mll_ &b) const { return val == b.val; }
	bool operator != (const mll_ &b) const { return val != b.val; }
	bool operator == (ll b) const { return *this == mll_(b); }
	bool operator != (ll b) const { return *this != mll_(b); }
	friend bool operator == (ll a,const mll_ &b) { return mll_(a) == b.val; }
	friend bool operator != (ll a,const mll_ &b) { return mll_(a) != b.val; }
	friend ostream &operator << (ostream &os,const mll_ &a) { return os << a.val; }
	friend istream &operator >> (istream &is,mll_ &a) { return is >> a.val; }
	static mll_ Combination(ll a,ll b){
		chmin(b,a-b);
		if (b<0) return mll_(0);
		mll_ c = 1;
		rep(i,0,b-1) c *= a-i;
		rep(i,0,b-1) c /= i+1;
		return c;
	}
	enum{modll=MOD};
};
#if 1
using mll = mll_<MODLL>;
using vmll    = std::vector<mll>;
using vvmll   = std::vector<vmll>;
using vvvmll  = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;
#endif




void cin2solve()
{
	ll n;
	cin >> n;
	vll ans(n);
	iota(all(ans),2);
	cout << ans << '\n';
}



int main(){
	using namespace chrono;
	auto st=system_clock::now();
#if 0
	cin2solve();
	

#else
	ll t;  cin >> t;
	rep(i,0,t-1){
		cin2solve();
		

	}
#endif
	ll ms=duration_cast<microseconds>(system_clock::now()-st).count()/1000;
	cerr << ms <<"ms"<< '\n';
	return 0;
}
