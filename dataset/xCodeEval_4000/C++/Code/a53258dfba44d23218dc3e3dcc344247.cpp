#if defined(MYLOCAL)
#   include "mylocal.h"
using namespace atcoder;
#else
#   pragma GCC optimize("Ofast")
#   include "bits/stdc++.h"
#   if __has_include(<atcoder/all>)
#       include <atcoder/all>
using namespace atcoder;
#   endif
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
using namespace chrono;
struct{
	system_clock::time_point st = system_clock::now();
	ll operator()()const{return duration_cast<microseconds>(system_clock::now()-st).count()/1000;}
} timeget;
constexpr ll INF = 1001001001001001001;
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



template<class T,class S,class R> inline ostream &operator<<(ostream &os,const tuple<T,S,R> &a){ return os << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a); }
template<class T,class S,class R,class Q> inline ostream &operator<<(ostream &os,const tuple<T,S,R,Q> &a){ return os << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << ' ' << get<3>(a); }



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
		mll_ c = 1, d = 1;
		rep(i,0,b-1) c *= a-i;
		rep(i,0,b-1) d *= i+1;
		return c/d;
	}
	enum{modll=MOD};
};

template<class T,size_t S,class R> struct view1d;
template<class T,size_t S,class R> struct view1dIter{
	view1d<T,S,R> *vw=nullptr;
	ll idx=INF;
	view1dIter(){}
	view1dIter(view1d<T,S,R> *vw_,ll idx_):vw(vw_),idx(idx_){}
	view1dIter(const view1dIter<T,S,R> &it):vw(it.vw),idx(it.idx){}
	R &operator*()          { return (*vw)[idx]; }
	R &operator*()     const{ return (*vw)[idx]; }
	R &operator[](ll i)     { return (*vw)[idx+i]; }
	R &operator[](ll i)const{ return (*vw)[idx+i]; }
	auto &operator++(){ idx++; return *this; }
	auto &operator--(){ idx--; return *this; }
	auto operator++(int){ auto it=*this; idx++; return it; }
	auto operator--(int){ auto it=*this; idx--; return it; }
	auto &operator+=(ll n){ idx+=n; return *this; }
	auto &operator-=(ll n){ idx-=n; return *this; }
	auto operator+(ll n){ auto it=*this; return it+=n; }
	auto operator-(ll n){ auto it=*this; return it-=n; }
	ll   operator- (const view1dIter<T,S,R> &it)const{ return idx- it.idx; }
	bool operator< (const view1dIter<T,S,R> &it)const{ return idx< it.idx; }
	bool operator> (const view1dIter<T,S,R> &it)const{ return idx> it.idx; }
	bool operator<=(const view1dIter<T,S,R> &it)const{ return idx<=it.idx; }
	bool operator>=(const view1dIter<T,S,R> &it)const{ return idx>=it.idx; }
	bool operator!=(const view1dIter<T,S,R> &it)const{ return idx!=it.idx; }
	bool operator==(const view1dIter<T,S,R> &it)const{ return idx==it.idx; }
	using iterator_category = random_access_iterator_tag;
	using value_type = R;
	using difference_type = ll;
	using pointer = R*;
	using reference = R&;
};
template<class T,size_t S,class R> struct view1d{
	using Sll=array<ll,S>;
	T &data; 

	Sll dsize; 

	Sll s=Sll(); 

	Sll d=Sll(); 

	ll len; 

	R &dummy; 

	R dummyj=R(); 

				  
	view1d(T &v): data(v),dummy(dummyj){
		SetDsize(v,dsize);
		d[S-1]=1;
		len=dsize[S-1];
	}
	

	

	view1d(T &v,Sll s,Sll e,Sll d): data(v),s(s),d(d),len(Len(s,e,d)),dummy(dummyj){
		SetDsize(v,dsize);
	}
	view1d(T &v,Sll s,Sll d,ll len,R &dmy_): data(v),s(s),d(d),len(len),dummy(dmy_){
		SetDsize(v,dsize);
	}

	
	template<class Q> auto &operator =(const Q &b){ rep(i,0,len-1) (*this)[i] =b; return *this; }
	template<class Q> auto &operator+=(const Q &b){ rep(i,0,len-1) (*this)[i]+=b; return *this; }
	template<class Q> auto &operator-=(const Q &b){ rep(i,0,len-1) (*this)[i]-=b; return *this; }
	template<class Q> auto &operator*=(const Q &b){ rep(i,0,len-1) (*this)[i]*=b; return *this; }
	template<class Q> auto &operator/=(const Q &b){ rep(i,0,len-1) (*this)[i]/=b; return *this; }
	template<class Q> auto &operator%=(const Q &b){ rep(i,0,len-1) (*this)[i]%=b; return *this; }
	auto &operator =(const string &b){ return CpSeq(b); }
	template<size_t Q> auto &operator =(const char (&b)[Q]){ return *this=string(b); }
	template<class Q> auto &operator =(const vector<Q> &b){ return CpSeq(b); }
	template<class Q> auto &operator+=(const vector<Q> &b){ return PlSeq(b); }
	template<class Q> auto &operator-=(const vector<Q> &b){ return MnSeq(b); }
	template<class Q> auto &operator*=(const vector<Q> &b){ return PrSeq(b); }
	template<class Q> auto &operator/=(const vector<Q> &b){ return DvSeq(b); }
	template<class Q> auto &operator%=(const vector<Q> &b){ return RmSeq(b); }
	template<class Q,size_t P,class O> auto &operator =(const view1d<Q,P,O> &b){ return CpSeq(b); }
	template<class Q,size_t P,class O> auto &operator+=(const view1d<Q,P,O> &b){ return PlSeq(b); }
	template<class Q,size_t P,class O> auto &operator-=(const view1d<Q,P,O> &b){ return MnSeq(b); }
	template<class Q,size_t P,class O> auto &operator*=(const view1d<Q,P,O> &b){ return PrSeq(b); }
	template<class Q,size_t P,class O> auto &operator/=(const view1d<Q,P,O> &b){ return DvSeq(b); }
	template<class Q,size_t P,class O> auto &operator%=(const view1d<Q,P,O> &b){ return RmSeq(b); }
	template<class Q> auto &CpSeq(const Q &b){ rep(i,0,min(sz(b),len)-1) (*this)[i] =b[i]; return *this; }
	template<class Q> auto &PlSeq(const Q &b){ rep(i,0,min(sz(b),len)-1) (*this)[i]+=b[i]; return *this; }
	template<class Q> auto &MnSeq(const Q &b){ rep(i,0,min(sz(b),len)-1) (*this)[i]-=b[i]; return *this; }
	template<class Q> auto &PrSeq(const Q &b){ rep(i,0,min(sz(b),len)-1) (*this)[i]*=b[i]; return *this; }
	template<class Q> auto &DvSeq(const Q &b){ rep(i,0,min(sz(b),len)-1) (*this)[i]/=b[i]; return *this; }
	template<class Q> auto &RmSeq(const Q &b){ rep(i,0,min(sz(b),len)-1) (*this)[i]%=b[i]; return *this; }
	

	

	

	template<class Q,class P> static bool eq(const Q &a,const P &b){
		if ((ll)a.size()!=(ll)b.size()) return false;
		rep(i,0,(ll)a.size()-1){
			if (a[i]!=b[i]) return false;
		}
		return true;
	}
	template<class Q,class P> static bool lt(const Q &a,const P &b){
		ll n=min((ll)a.size(),(ll)b.size());
		rep(i,0,n-1){
			if (a[i]<b[i])return true;
			if (a[i]>b[i])return false;
		}
		return (ll)a.size()<(ll)b.size();
	}
	template<class Q,size_t P,class O> bool operator==(           const view1d<Q,P,O> &b){ return eq(*this,b); }
	template<class Q>                  bool operator==(           const             Q &b){ return eq(*this,b); }
	template<class Q> friend           bool operator==(const Q &a,const view1d<T,S,R> &b){ return eq(    a,b); }
	template<size_t Q>                 bool operator==(           const     char (&b)[Q]){ return eq(*this,string(b)); }
	template<class Q,size_t P,class O> bool operator!=(           const view1d<Q,P,O> &b){ return !(*this==b); }
	template<class Q>                  bool operator!=(           const             Q &b){ return !(*this==b); }
	template<class Q> friend           bool operator!=(const Q &a,const view1d<T,S,R> &b){ return !(    a==b); }
	template<class Q,size_t P,class O> bool operator< (           const view1d<Q,P,O> &b){ return lt(*this,b); }
	template<class Q>                  bool operator< (           const             Q &b){ return lt(*this,b); }
	template<class Q> friend           bool operator< (const Q &a,const view1d<T,S,R> &b){ return lt(    a,b); }
	template<class Q,size_t P,class O> bool operator> (           const view1d<Q,P,O> &b){ return lt(b,*this); }
	template<class Q>                  bool operator> (           const             Q &b){ return lt(b,*this); }
	template<class Q> friend           bool operator> (const Q &a,const view1d<T,S,R> &b){ return lt(b,a    ); }
	template<class Q,size_t P,class O> bool operator<=(           const view1d<Q,P,O> &b){ return !(*this>b); }
	template<class Q>                  bool operator<=(           const             Q &b){ return !(*this>b); }
	template<class Q> friend           bool operator<=(const Q &a,const view1d<T,S,R> &b){ return !(    a>b); }
	template<class Q,size_t P,class O> bool operator>=(           const view1d<Q,P,O> &b){ return !(*this<b); }
	template<class Q>                  bool operator>=(           const             Q &b){ return !(*this<b); }
	template<class Q> friend           bool operator>=(const Q &a,const view1d<T,S,R> &b){ return !(    a<b); }

	
	ll size() const { return len; }
	R &operator[](ll i){ return const_cast<R&>(OrgAt(s+d*i)); }
	const R &operator[](ll i) const { return OrgAt(s+d*i); }
	R &at(ll i){ if(i<0)i+=len; return (*this)[i]; }
	

	operator vector<R>(){ vector<R> v(len);  rep(i,0,len-1) v[i]=(*this)[i];  return v; }
	bool contains(R a){ rep(i,0,len-1) if((*this)[i]==a)return true;  return false; }
	auto begin(){ return view1dIter<T,S,R>(this,0); }
	auto end(){ return view1dIter<T,S,R>(this,len); }
	
	view1d<T,S,R> &dmy(R dmy_) { dummy=dmy_; return *this; }

	template<class...Q> view1d<T,S,R> &st(Q... s_){

		this->s=RevIfNeg(SllD(s_...));
		this->len=AutoLen(this->s,this->d,this->dsize);
		return *this;
	}
	template<class...Q> view1d<T,S,R> &en(Q... e_){

		this->len=Len(s, RevIfNeg(SllD(e_...)), d);
		return *this;
	}
	template<class...Q> view1d<T,S,R> &dir(Q... d_){

		this->d=SllD(d_...);
		this->len=AutoLen(this->s,this->d,this->dsize);
		return *this;
	}
	template<class...Q>
	view1d<T,S,R> &mv(Q... s_){ this->s+=SllD(s_...); return *this; }

	view1d<T,S,R> &size(ll len_) { len=len_; return *this; }

	template<class Q> view1d<T,S,R> &size(Q &v){ len=(ll)v.size(); return *this; }

	view1d<T,S,R> &rev() { s+=d*(len-1); d*=-1; return *this; }


															   
	template<class Q> inline static ll sz(Q &v){ return (ll)v.size(); }
	Sll RevIfNeg(Sll pos){

		rep(i,0,S-1)  if (pos[i]<0) pos[i]+=dsize[i];
		return pos;
	}
	static ll AutoLen(Sll s_,Sll d_,Sll dsz){

		Sll e=dsz-1;
		rep(i,0,S-1) e[i] *= (d_[i]>=0);

		return Len(s_,e,d_);
	}
	
	

	

	

	

	

	static ll Len(Sll s,Sll e,Sll d){
		ll ret=INF;
		rep(i,0,S-1) chmin(ret, Len1(s[i],e[i],d[i]));
		return ret;
	}
	static ll Len1(ll s,ll e,ll d){
		if (d==0) return INF;
		if (d<0){ s=-s; e=-e; d=-d; }
		if (s>e) return 0;
		return (e-s)/d+1;
	}
	
	template<class...Q> static Sll SllD(Q... args){ return SllRec(0,args...); }
	template<class...Q> static Sll SllRec(ll i,ll first,Q... rest) {
		Sll sll = (i==S-1) ? Sll() : SllRec(i+1,rest...);
		sll[i]=first;
		return sll;
	}
	static Sll SllRec(ll i){ return Sll(); }
	
	const R &OrgAt(Sll pos) const {
		rep(i,0,S-1){
			if (pos[i]<0 || dsize[i]<=pos[i]) return dummy;
		}
		return OrgAt_(data,pos);
	}
	template<class Q> using V   = vector<Q>;
	template<class Q> using VV  = V<V<Q>>;
	template<class Q> using VVV = V<V<V<Q>>>;
	using Vs  = V<string>;
	using VVs = VV<string>;
	using ll1 = array<ll,1>;
	using ll2 = array<ll,2>;
	using ll3 = array<ll,3>;
	auto &OrgAt_(V<R>   &dat,ll1 pos)const{ auto [i]    =pos; return dat[i]; }
	auto &OrgAt_(string &dat,ll1 pos)const{ auto [i]    =pos; return dat[i]; }
	auto &OrgAt_(VV<R>  &dat,ll2 pos)const{ auto [i,j]  =pos; return dat[i][j]; }
	auto &OrgAt_(Vs     &dat,ll2 pos)const{ auto [i,j]  =pos; return dat[i][j]; }
	auto &OrgAt_(VVV<R> &dat,ll3 pos)const{ auto [i,j,k]=pos; return dat[i][j][k]; }
	auto &OrgAt_(VVs    &dat,ll3 pos)const{ auto [i,j,k]=pos; return dat[i][j][k]; }
	
	static void SetDsize(V<R>   &dat,ll1 &dsz){ dsz={sz(dat)}; }
	static void SetDsize(string &dat,ll1 &dsz){ dsz={sz(dat)}; }
	static void SetDsize(VV<R>  &dat,ll2 &dsz){ dsz={sz(dat),sz(dat[0])}; }
	static void SetDsize(Vs     &dat,ll2 &dsz){ dsz={sz(dat),sz(dat[0])}; }
	static void SetDsize(VVV<R> &dat,ll3 &dsz){ dsz={sz(dat),sz(dat[0]),sz(dat[0][0])}; }
	static void SetDsize(VVs    &dat,ll3 &dsz){ dsz={sz(dat),sz(dat[0]),sz(dat[0][0])}; }
	typedef view1dIter<T,S,R> iterator;
	using value_type = R;
};
template<class Q> using V   = vector<Q>;
template<class Q> using VV  = V<V<Q>>;
template<class Q> using VVV = V<V<V<Q>>>;
template<class T>         view1d(    VVV<T>      ) -> view1d<    VVV<T>,3,T>;
template<class T>         view1d(     VV<T>      ) -> view1d<     VV<T>,2,T>;
template<class T>         view1d(      V<T>      ) -> view1d<      V<T>,1,T>;
;                         view1d(VV<string>      ) -> view1d<VV<string>,3,char>;
;                         view1d( V<string>      ) -> view1d< V<string>,2,char>;
;                         view1d(   string       ) -> view1d<   string ,1,char>;
template<class T,class S> view1d(    VVV<T>,S,S,S) -> view1d<    VVV<T>,3,T>;
template<class T,class S> view1d(     VV<T>,S,S,S) -> view1d<     VV<T>,2,T>;
template<class T,class S> view1d(      V<T>,S,S,S) -> view1d<      V<T>,1,T>;
template<class S>         view1d(VV<string>,S,S,S) -> view1d<VV<string>,3,char>;
template<class S>         view1d( V<string>,S,S,S) -> view1d< V<string>,2,char>;
template<class S>         view1d(   string ,S,S,S) -> view1d<   string ,1,char>;


template<class VIEW2D> struct view2dIter{
	VIEW2D *vw=nullptr;
	ll idx=INF;
	view2dIter(){}
	view2dIter(VIEW2D *vw_,ll idx_):vw(vw_),idx(idx_){}
	view2dIter(const view2dIter &it):vw(it.vw),idx(it.idx){}
	auto &operator*()          { return (*vw)[x(idx)][y(idx)]; }
	auto &operator*()     const{ return (*vw)[x(idx)][y(idx)]; }
	auto &operator[](ll i)     { return (*vw)[x(idx+i)][y(idx+i)]; }
	auto &operator[](ll i)const{ return (*vw)[x(idx+i)][y(idx+i)]; }
	auto &operator++(){ idx++; return *this; }
	auto &operator--(){ idx--; return *this; }
	auto operator++(int){ auto it=*this; idx++; return it; }
	auto operator--(int){ auto it=*this; idx--; return it; }
	auto &operator+=(ll n){ idx+=n; return *this; }
	auto &operator-=(ll n){ idx-=n; return *this; }
	auto operator+(ll n){ auto it=*this; return it+=n; }
	auto operator-(ll n){ auto it=*this; return it-=n; }
	ll   operator- (const view2dIter &it)const{ return idx- it.idx; }
	bool operator< (const view2dIter &it)const{ return idx< it.idx; }
	bool operator> (const view2dIter &it)const{ return idx> it.idx; }
	bool operator<=(const view2dIter &it)const{ return idx<=it.idx; }
	bool operator>=(const view2dIter &it)const{ return idx>=it.idx; }
	bool operator!=(const view2dIter &it)const{ return idx!=it.idx; }
	bool operator==(const view2dIter &it)const{ return idx==it.idx; }
	ll x(ll i)const{ return i/vw->leny(); }
	ll y(ll i)const{ return i%vw->leny(); }
	using iterator_category = random_access_iterator_tag;
	using value_type = typename VIEW2D::value_type;
	using difference_type = ll;
	using pointer = value_type*;
	using reference = value_type&;
};


template<class T,size_t S,class R> struct view2d{
	using Sll=array<ll,S>;
	T &data; 

	Sll dsize; 

	Sll s=Sll(); 

	Sll dx=Sll(); 

	Sll dy=Sll(); 

	ll xl; 

	ll yl; 

	R dummy=R(); 

				 
	view2d(T &v): data(v){
		view1d<T,S,R>::SetDsize(v,dsize);
		dx[S-2]=1;
		dy[S-1]=1;
		xl=dsize[S-2];
		yl=dsize[S-1];
	}
	
	

	

	

	

	
	ll size() const { return xl; }
	array<ll,2> shape() const { return {xl,yl}; }
	ll lenx() const { return xl; }
	ll leny() const { return yl; }
	

	view1d<T,S,R> operator[](ll i){ return view1d(data,s+dx*i,dy,yl,dummy); }
	const view1d<T,S,R> operator[](ll i) const { return view1d(data,s+dx*i,dy,yl,dummy); }
	R &at(ll i,ll j){ if(i<0)i+=xl;  if(j<0)j+=yl;  return (*this)[i][j]; }
	

	

	

	

	

	operator vector<vector<R>>(){
		vector<vector<R>> v(xl);
		rep(i,0,xl-1) v[i]=(*this)[i];  return v;
	}
	auto begin(){ return view2dIter(this,0); }
	auto end(){ return view2dIter(this,xl*yl); }
#if defined(_DEBUG)
	void dump(){ ::dump(tovv()); }
#endif
	
	view2d<T,S,R> &dmy(R dmy_) { dummy=dmy_; return *this; }

	template<class...Q> view2d<T,S,R> &st(Q... s_){

		this->s=RevIfNeg(view1d<T,S,R>::SllD(s_...));
		this->xl=view1d<T,S,R>::AutoLen(this->s,this->dx,this->dsize);
		this->yl=view1d<T,S,R>::AutoLen(this->s,this->dy,this->dsize);
		return *this;
	}
	template<class...Q> view2d<T,S,R> &dirx(Q... d_){

		this->dx=view1d<T,S,R>::SllD(d_...);
		this->xl=view1d<T,S,R>::AutoLen(this->s,this->dx,this->dsize);
		return *this;
	}
	template<class...Q> view2d<T,S,R> &diry(Q... d_){

		this->dy=view1d<T,S,R>::SllD(d_...);
		this->yl=view1d<T,S,R>::AutoLen(this->s,this->dy,this->dsize);
		return *this;
	}
	template<class...Q> view2d<T,S,R> &mv(Q... s_){

		this->s += view1d<T,S,R>::SllD(s_...);
		return *this;
	}
	view2d<T,S,R> &lenx(ll xl_) { xl=xl_; return *this; }
	view2d<T,S,R> &leny(ll yl_) { yl=yl_; return *this; }
	view2d<T,S,R> &shape(ll xl_,ll yl_) { xl=xl_; yl=yl_; return *this; }
	template<class Q> view2d<T,S,R> &shape(Q &v) { xl=v.lenx(); yl=v.leny(); return *this; }
	view2d<T,S,R> &rot90 () { s+=dx*(xl-1); swap(xl,yl); swap(dx,dy); dy*=-1; return *this; }
	view2d<T,S,R> &rot270() { s+=dy*(yl-1); swap(xl,yl); swap(dx,dy); dx*=-1; return *this; }
	view2d<T,S,R> &rot180() { s+=dx*(xl-1)+dy*(yl-1); dx*=-1; dy*=-1; return *this; }
	view2d<T,S,R> &revx() { s+=dx*(xl-1); dx*=-1; return *this; }
	view2d<T,S,R> &revy() { s+=dy*(yl-1); dy*=-1; return *this; }
	view2d<T,S,R> &swapxy() { swap(xl,yl); swap(dx,dy); return *this; }


																	   
	Sll RevIfNeg(Sll pos){

		rep(i,0,S-1)  if (pos[i]<0) pos[i]+=dsize[i];
		return pos;
	}
	using value_type = R;
};
template<class T> view2d(    VVV<T>) -> view2d<    VVV<T>,3,T>;
template<class T> view2d(     VV<T>) -> view2d<     VV<T>,2,T>;
;                 view2d(VV<string>) -> view2d<VV<string>,3,char>;
;                 view2d( V<string>) -> view2d< V<string>,2,char>;




template<class ZIP> struct zipIter{
	ZIP *z=nullptr;
	ll idx=INF;
	zipIter(){}
	zipIter(ZIP *z_,ll idx_):z(z_),idx(idx_){}
	zipIter(const zipIter<ZIP> &it):z(it.z),idx(it.idx){}
	auto operator*()          { return (*z)[idx]; }

	auto operator*()     const{ return (*z)[idx]; }

	auto operator[](ll i)     { return (*z)[idx+i]; }

	auto operator[](ll i)const{ return (*z)[idx+i]; }

	auto &operator++(){ idx++; return *this; }
	auto &operator--(){ idx--; return *this; }
	auto operator++(int){ auto it=*this; idx++; return it; }
	auto operator--(int){ auto it=*this; idx--; return it; }
	auto &operator+=(ll n){ idx+=n; return *this; }
	auto &operator-=(ll n){ idx-=n; return *this; }
	auto operator+(ll n){ auto it=*this; return it+=n; }
	auto operator-(ll n){ auto it=*this; return it-=n; }
	ll   operator- (const zipIter<ZIP> &it)const{ return idx- it.idx; }
	bool operator< (const zipIter<ZIP> &it)const{ return idx< it.idx; }
	bool operator> (const zipIter<ZIP> &it)const{ return idx> it.idx; }
	bool operator<=(const zipIter<ZIP> &it)const{ return idx<=it.idx; }
	bool operator>=(const zipIter<ZIP> &it)const{ return idx>=it.idx; }
	bool operator!=(const zipIter<ZIP> &it)const{ return idx!=it.idx; }
	bool operator==(const zipIter<ZIP> &it)const{ return idx==it.idx; }
	using iterator_category = random_access_iterator_tag;
	using value_type = typename ZIP::value_type;
	using difference_type = ll;
	using pointer = value_type*;
	using reference = value_type&;
};

template<class T,class S> struct zip2{
	T &t; S &s;
	zip2(T &t_,S &s_):t(t_),s(s_){}
	ll size() const { return t.end()-t.begin(); }
	auto operator[](ll i)     { return make_pair(ref(t.begin()[i]),ref(s.begin()[i])); }
	auto operator[](ll i)const{ return make_pair(ref(t.begin()[i]),ref(s.begin()[i])); }
	auto begin(){ return zipIter(this,0); }
	auto end(){ return zipIter(this,size()); }
	using value_type = pair<typename T::value_type,typename S::value_type>;
};
template<class T,class S,class R> struct zip3{
	T &t; S &s; R &r;
	zip3(T &t_,S &s_,R &r_):t(t_),s(s_),r(r_){}
	ll size() const { return t.end()-t.begin(); }
	auto operator[](ll i)     { return make_tuple(ref(t.begin()[i]),ref(s.begin()[i]),ref(r.begin()[i])); }
	auto operator[](ll i)const{ return make_tuple(ref(t.begin()[i]),ref(s.begin()[i]),ref(r.begin()[i])); }
	auto begin(){ return zipIter(this,0); }
	auto end(){ return zipIter(this,size()); }
	using value_type = tuple<typename T::value_type,typename S::value_type,typename R::value_type>;
};


#if 0
#define MODLL (1000000007LL)
#else
#define MODLL (998244353LL)
#endif
using mll = mll_<MODLL>;
using vmll    = std::vector<mll>;
using vvmll   = std::vector<vmll>;
using vvvmll  = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;





struct bll{ 

	ll s;
	bll(ll s_=0): s(s_){}
	struct ref {
		bll &b; const ll msk;
		ref(bll &b_,ll pos):b(b_),msk(1LL<<pos){}
		operator bool() const { return b.s&msk; }
		ref &operator=(bool x){ if (x) b.s|=msk; else b.s&=~msk; return *this; }
	};
	ref operator[](ll pos){ return ref(*this,pos); }
	bool operator[](ll pos) const { return (s>>pos)&1; }
	bll &operator=(ll b){ s=b; return *this; }
	bll operator++(int){ bll b(*this); s++; return b; }
	bll operator--(int){ bll b(*this); s--; return b; }
	operator ll() const noexcept { return s; }
	bll &on(ll l,ll r){ s|= rangemask(l,r); return *this; }
	bll &off(ll l,ll r){ s&=~rangemask(l,r); return *this; }
	bll &flip(ll l,ll r){ s^= rangemask(l,r); return *this; }
	bll &on(ll i){ s|= (1LL<<i); return *this; }
	bll &off(ll i){ s&=~(1LL<<i); return *this; }
	bll &flip(ll i){ s^= (1LL<<i); return *this; }
	static ll rangemask(ll l,ll r){ return (1LL<<(r+1))-(1LL<<l); }
	ll msbit()const{
		for (ll o=63,x=-1;;){
			ll m=(o+x)/2;
			if (s < (1LL<<m)) o=m; else x=m;
			if (o-x==1) return x;
		}
	}
	ll lsbit()const{ return bll(lsb()).msbit(); }
	ll msb()const{ ll pos=msbit(); return (pos<0) ? 0LL : 1LL<<pos; }
	ll lsb()const{ return s&-s; }
	ll count()const{ return bitset<64>(s).count(); }
	vll idxes()const{
		vll v;
		for (ll i=0,t=s; t; t>>=1,i++) if (t&1)v.push_back(i);
		return v;
	}
};



template<class T> struct cumulativesum{
	ll n=0;  vector<T> c;
	cumulativesum():c(1){}
	template<class S> cumulativesum(S &&v): n((ll)v.size()),c(n+1) { Ini(v); }
	template<class S> void init(S &&v){ n=(ll)v.size(); c.resize(n+1); Ini(v); }
	void add(T x) { n++; c.push_back(c.back()+x); }
	T operator()(ll l,ll r){ return c[max(min(n,r+1),0LL)]-c[min(max(0LL,l),n)]; }
	pll flooridx(T x){
		ll i=upper_bound(c.begin(),c.end(),x)-c.begin()-1;
		return {i-1, (i==-1)?-INF:c[i]};
	}
	pll ceilidx(T x){
		ll i=lower_bound(c.begin(),c.end(),x)-c.begin();
		return {i-1, (i==n+1)?INF:c[i]};
	}
	T mx(){

		T mn=T(),samx=0;
		for (ll i=1;i<=n;++i){
			chmax(samx,c[i]-mn);
			chmin(mn,c[i]);
		}
		return samx;
	}
	template<class S> void Ini(S &&v) { for (ll i=0;i<n;++i) c[i+1]=c[i]+v[i]; }
};
template<class S> cumulativesum(S)->cumulativesum<typename remove_reference<S>::type::value_type>;


template <class T, class E> struct LazySegmentTree{
	using F = function<T(T, T)>;
	using G = function<T(T, E)>;
	using H = function<E(E, E)>;
	F f; 

	G g; 

	H h; 

	T ti; 

	E ei; 

	ll n=1; 

	vector<T> dat;
	vector<E> laz;
	LazySegmentTree() {}
	LazySegmentTree(vector<T> &v, F f, G g, H h, T ti, E ei) { Init(v, f, g, h, ti, ei); }
	void Init(vector<T> &v, F f, G g, H h, T ti, E ei){
		this->f=f; this->g=g; this->h=h; this->ti=ti; this->ei=ei;
		while (n<(ll)v.size()) n<<=1;
		dat.resize(2*n-1, ti);
		laz.resize(2*n-1, ei);
		for (ll i=0; i<(ll)v.size(); i++) dat[n-1+i] = v[i];
		for (ll i=n-2; i>=0; i--) dat[i] = f(dat[2*i+1], dat[2*i+2]);
	}
	void set(ll i,E x){ set(i,i,x); }
	void set(ll a, ll b, E x){ Set(a, b+1, x, 0, 0, n); } 

	void Set(ll a, ll b, E x, ll k, ll l, ll r){ 

		if (r<=a || b<=l) eval(k); 

		else if (a<=l && r<=b){ 

			laz[k] = h(laz[k], x);
			eval(k); 

		}
		else { 

			eval(k); 

			Set(a, b, x, k*2+1, l, (l+r)/2);
			Set(a, b, x, k*2+2, (l+r)/2, r);
			dat[k] = f(dat[k*2+1], dat[k*2+2]);
		}
	}
	T operator [] (ll i) { return get(i,i); }
	T get(ll a, ll b) { return Get(a, b+1, 0, 0, n); }

	T Get(ll a, ll b, ll k, ll l, ll r){ 

		if (r<=a || b<=l) return ti; 

		eval(k); 

		if (a<=l && r<=b) return dat[k];

		return f(Get(a, b, k*2+1, l, (l+r)/2), Get(a, b, k*2+2, (l+r)/2, r));
		

	}
	template<class C> ll searchl(ll a,ll b,C c){

		auto [pos,ignore]=SearchL(a,c,ti,0,0,n);  return min(pos,b+1); }
	template<class C> ll searchr(ll a,ll b,C c){

		auto [pos,ignore]=SearchR(b+1,c,ti,0,0,n);  return max(pos,a-1); }
	template<class C> pair<ll,T> SearchL(ll a,C c,T s,ll k,ll l,ll r){
		if (r<=a) return {r,s};
		eval(k);
		T ss=f(s,dat[k]);
		if (a<=l && !c(ss)) return {r,ss};

		if (n-1 <= k) return {l,s};

		ll pos, m=(l+r)/2;
		;           tie(pos,s)=SearchL(a,c,s,2*k+1,l,m);
		if (pos==m) tie(pos,s)=SearchL(a,c,s,2*k+2,m,r);
		return {pos,s};
	}
	template<class C> pair<ll,T> SearchR(ll b,C c,T s,ll k,ll l,ll r){
		if (b<=l) return {l-1,s};
		eval(k);
		T ss=f(dat[k],s);
		if (r<=b && !c(ss)) return {l-1,ss};

		if (n-1 <= k) return {l,s};

		ll pos, m=(l+r)/2;
		;             tie(pos,s)=SearchR(b,c,s,2*k+2,m,r);
		if (pos==m-1) tie(pos,s)=SearchR(b,c,s,2*k+1,l,m);
		return {pos,s};
	}
	ll findpeakl(ll l,ll r){
		T m=get(l,r);
		return searchl(l,r, [&](T x){return f(x,m)==x;});
	}
	ll findpeakr(ll l,ll r){
		T m=get(l,r);
		return searchr(l,r, [&](T x){return f(x,m)==x;});
	}
	void eval(ll k){
		if (laz[k] == ei) return;
		if (k<=n-2){ 

			laz[k*2+1] = h(laz[k*2+1], laz[k]);
			laz[k*2+2] = h(laz[k*2+2], laz[k]);
		}
		

		dat[k] = g(dat[k], laz[k]);
		laz[k] = ei;
	}
#if defined(_DEBUG)
	void dump(char deli=' '){ for (ll i=0;i<n;i++) cerr<<(*this)[i]<<deli;  cerr<<'\n'; }
	void dump_tree(ll w=5){
		auto disp=[&](ll x){
			if (x==-INF) cerr << setw(w) << "-INF";
			else if (x== INF) cerr << setw(w) << "INF";
			else              cerr << setw(w) << x;
		};
		REP(i, n) for (ll k=i+n-1, m=1, p=1; k>=0; p=m, m*=k%2, k=(k==0)?-1:(k-1)/2){
			if (m){
				cerr << ((k<n-1)?" ┬ ":""); disp(dat[k]); cerr<<" /"; disp(laz[k]);
			}
			else{
				cerr << ((p&~m) ?" ┘ ":"");
			}
			if (k==0) cerr << '\n';
		} cerr << '\n';
	}
#else
	void dump(char deli=' '){}
	void dump_tree(ll w=5){}
#endif
};

void cin2solve()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> a;
	rep(i,0,n-1){ ll a__; cin>>a__; a.push_back(a__); }
	vector<ll> b;
	rep(i,0,n-1){ ll b__; cin>>b__; b.push_back(b__); }
	vector<pair<ll,ll>> lr;
	rep(i,0,m-1){ ll l; ll r; cin>>l>>r; lr.emplace_back(l-1,r-1); }

	vll c=a-b;
	cumulativesum cm(c);
	vll lrznm(m);
	multimap<ll,ll> mp;
	vll bf;
	rep(i,0,m-1){
		auto [l,r]=lr[i];
		if (cm.c[l]==0) lrznm[i]++;
		else mp.emplace(l,i);
		
		if (cm.c[r+1]==0) lrznm[i]++;
		else mp.emplace(r+1,i);
		if (lrznm[i]==2){
			bf.push_back(i);
		}
	}

	while (!bf.empty()){
		ll i=bf.back(); bf.pop_back();
		auto [l,r]=lr[i];

		auto it=mp.upper_bound(l);
		auto en=mp.upper_bound(r+1);
		while (it!=en){
			auto [pos,ii]=*it;
			lrznm[ii]++;
			if (lrznm[ii]==2){
				bf.push_back(ii);
			}
			it=mp.erase(it);
		}
	}

	vll im(n+1);
	auto imosset=[](vll &v,ll l,ll r,ll x){

		ll len=(ll)v.size();
		if (r<0 || len<=l) return;
		if (l<0) l=0;
		v[l]+=x;
		if (r+1<len) v[r+1]-=x;
	};
	auto imoscalc=[](vll &v){
		rep(i,1,(ll)v.size()-1) v[i]+=v[i-1];
	};
	rep(i,0,m-1){
		if (lrznm[i]<2){
			cout << "NO" << '\n'; return;
		}
		auto [l,r]=lr[i];
		imosset(im,l,r+1,1);
	}
	imoscalc(im);

	rep(pos,0,n){
		if (im[pos]>0 or cm.c[pos]==0) continue;
		cout << "No" << '\n'; return;
	}
	cout << "Yes" << '\n';

	return;
}





int main(){
#if 0
	cin2solve();
	

#else
	ll t;  cin >> t;
	rep(i,0,t-1){
		cin2solve();
		

	}
#endif
	cerr << timeget() <<"ms"<< '\n';
	return 0;
}

