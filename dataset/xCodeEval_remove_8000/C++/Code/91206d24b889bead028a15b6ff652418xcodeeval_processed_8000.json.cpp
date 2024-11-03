﻿

using namespace atcoder;





using namespace atcoder;


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

inline ll id9(ll a,ll b){ return -CEIL(-a,b); } 




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

template<ll MOD> struct id2{
	ll val;
	id2(ll v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	id2 operator - () const { return -val; }
	id2 operator + (const id2 &b) const { return val + b.val; }
	id2 operator - (const id2 &b) const { return val - b.val; }
	id2 operator * (const id2 &b) const { return val * b.val; }
	id2 operator / (const id2 &b) const { return id2(*this) /= b; }
	id2 operator + (ll b) const { return *this + id2(b); }
	id2 operator - (ll b) const { return *this - id2(b); }
	id2 operator * (ll b) const { return *this * id2(b); }
	friend id2 operator + (ll a,const id2 &b) { return b + a; }
	friend id2 operator - (ll a,const id2 &b) { return -b + a; }
	friend id2 operator * (ll a,const id2 &b) { return b * a; }
	friend id2 operator / (ll a,const id2 &b) { return id2(a)/b; }
	id2 &operator += (const id2 &b) { val=(val+b.val)%MOD; return *this; }
	id2 &operator -= (const id2 &b) { val=(val+MOD-b.val)%MOD; return *this; }
	id2 &operator *= (const id2 &b) { val=(val*b.val)%MOD; return *this; }
	id2 &operator /= (const id2 &b) {
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
	id2 &operator += (ll b) { return *this += id2(b); }
	id2 &operator -= (ll b) { return *this -= id2(b); }
	id2 &operator *= (ll b) { return *this *= id2(b); }
	id2 &operator /= (ll b) { return *this /= id2(b); }
	bool operator == (const id2 &b) const { return val == b.val; }
	bool operator != (const id2 &b) const { return val != b.val; }
	bool operator == (ll b) const { return *this == id2(b); }
	bool operator != (ll b) const { return *this != id2(b); }
	friend bool operator == (ll a,const id2 &b) { return id2(a) == b.val; }
	friend bool operator != (ll a,const id2 &b) { return id2(a) != b.val; }
	friend ostream &operator << (ostream &os,const id2 &a) { return os << a.val; }
	friend istream &operator >> (istream &is,id2 &a) { return is >> a.val; }
	static id2 Combination(ll a,ll b){
		chmin(b,a-b);
		if (b<0) return id2(0);
		id2 c = 1, d = 1;
		rep(i,0,b-1) c *= a-i;
		rep(i,0,b-1) d *= i+1;
		return c/d;
	}
	enum{modll=MOD};
};

template<class T,size_t S,class R> struct id5;
template<class T,size_t S,class R> struct id4{
	id5<T,S,R> *vw=nullptr;
	ll idx=INF;
	id4(){}
	id4(id5<T,S,R> *vw_,ll idx_):vw(vw_),idx(idx_){}
	id4(const id4<T,S,R> &it):vw(it.vw),idx(it.idx){}
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
	ll   operator- (const id4<T,S,R> &it)const{ return idx- it.idx; }
	bool operator< (const id4<T,S,R> &it)const{ return idx< it.idx; }
	bool operator> (const id4<T,S,R> &it)const{ return idx> it.idx; }
	bool operator<=(const id4<T,S,R> &it)const{ return idx<=it.idx; }
	bool operator>=(const id4<T,S,R> &it)const{ return idx>=it.idx; }
	bool operator!=(const id4<T,S,R> &it)const{ return idx!=it.idx; }
	bool operator==(const id4<T,S,R> &it)const{ return idx==it.idx; }
	using iterator_category = random_access_iterator_tag;
	using value_type = R;
	using difference_type = ll;
	using pointer = R*;
	using reference = R&;
};
template<class T,size_t S,class R> struct id5{
	using Sll=array<ll,S>;
	T &data; 

	Sll dsize; 

	Sll s=Sll(); 

	Sll d=Sll(); 

	ll len; 

	R &dummy; 

	R dummyj=R(); 

				  
	id5(T &v): data(v),dummy(dummyj){
		SetDsize(v,dsize);
		d[S-1]=1;
		len=dsize[S-1];
	}
	

	

	id5(T &v,Sll s,Sll e,Sll d): data(v),s(s),d(d),len(Len(s,e,d)),dummy(dummyj){
		SetDsize(v,dsize);
	}
	id5(T &v,Sll s,Sll d,ll len,R &id10): data(v),s(s),d(d),len(len),dummy(id10){
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
	template<class Q,size_t P,class O> auto &operator =(const id5<Q,P,O> &b){ return CpSeq(b); }
	template<class Q,size_t P,class O> auto &operator+=(const id5<Q,P,O> &b){ return PlSeq(b); }
	template<class Q,size_t P,class O> auto &operator-=(const id5<Q,P,O> &b){ return MnSeq(b); }
	template<class Q,size_t P,class O> auto &operator*=(const id5<Q,P,O> &b){ return PrSeq(b); }
	template<class Q,size_t P,class O> auto &operator/=(const id5<Q,P,O> &b){ return DvSeq(b); }
	template<class Q,size_t P,class O> auto &operator%=(const id5<Q,P,O> &b){ return RmSeq(b); }
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
	template<class Q,size_t P,class O> bool operator==(           const id5<Q,P,O> &b){ return eq(*this,b); }
	template<class Q>                  bool operator==(           const             Q &b){ return eq(*this,b); }
	template<class Q> friend           bool operator==(const Q &a,const id5<T,S,R> &b){ return eq(    a,b); }
	template<size_t Q>                 bool operator==(           const     char (&b)[Q]){ return eq(*this,string(b)); }
	template<class Q,size_t P,class O> bool operator!=(           const id5<Q,P,O> &b){ return !(*this==b); }
	template<class Q>                  bool operator!=(           const             Q &b){ return !(*this==b); }
	template<class Q> friend           bool operator!=(const Q &a,const id5<T,S,R> &b){ return !(    a==b); }
	template<class Q,size_t P,class O> bool operator< (           const id5<Q,P,O> &b){ return lt(*this,b); }
	template<class Q>                  bool operator< (           const             Q &b){ return lt(*this,b); }
	template<class Q> friend           bool operator< (const Q &a,const id5<T,S,R> &b){ return lt(    a,b); }
	template<class Q,size_t P,class O> bool operator> (           const id5<Q,P,O> &b){ return lt(b,*this); }
	template<class Q>                  bool operator> (           const             Q &b){ return lt(b,*this); }
	template<class Q> friend           bool operator> (const Q &a,const id5<T,S,R> &b){ return lt(b,a    ); }
	template<class Q,size_t P,class O> bool operator<=(           const id5<Q,P,O> &b){ return !(*this>b); }
	template<class Q>                  bool operator<=(           const             Q &b){ return !(*this>b); }
	template<class Q> friend           bool operator<=(const Q &a,const id5<T,S,R> &b){ return !(    a>b); }
	template<class Q,size_t P,class O> bool operator>=(           const id5<Q,P,O> &b){ return !(*this<b); }
	template<class Q>                  bool operator>=(           const             Q &b){ return !(*this<b); }
	template<class Q> friend           bool operator>=(const Q &a,const id5<T,S,R> &b){ return !(    a<b); }

	
	ll size() const { return len; }
	R &operator[](ll i){ return const_cast<R&>(OrgAt(s+d*i)); }
	const R &operator[](ll i) const { return OrgAt(s+d*i); }
	R &at(ll i){ if(i<0)i+=len; return (*this)[i]; }
	

	operator vector<R>(){ vector<R> v(len);  rep(i,0,len-1) v[i]=(*this)[i];  return v; }
	bool contains(R a){ rep(i,0,len-1) if((*this)[i]==a)return true;  return false; }
	auto begin(){ return id4<T,S,R>(this,0); }
	auto end(){ return id4<T,S,R>(this,len); }
	
	id5<T,S,R> &dmy(R id10) { dummy=id10; return *this; }

	template<class...Q> id5<T,S,R> &st(Q... s_){

		this->s=RevIfNeg(id7(s_...));
		this->len=AutoLen(this->s,this->d,this->dsize);
		return *this;
	}
	template<class...Q> id5<T,S,R> &en(Q... e_){

		this->len=Len(s, RevIfNeg(id7(e_...)), d);
		return *this;
	}
	template<class...Q> id5<T,S,R> &dir(Q... d_){

		this->d=id7(d_...);
		this->len=AutoLen(this->s,this->d,this->dsize);
		return *this;
	}
	template<class...Q>
	id5<T,S,R> &mv(Q... s_){ this->s+=id7(s_...); return *this; }

	id5<T,S,R> &size(ll len_) { len=len_; return *this; }

	template<class Q> id5<T,S,R> &size(Q &v){ len=(ll)v.size(); return *this; }

	id5<T,S,R> &rev() { s+=d*(len-1); d*=-1; return *this; }


															   
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
	
	template<class...Q> static Sll id7(Q... args){ return id0(0,args...); }
	template<class...Q> static Sll id0(ll i,ll first,Q... rest) {
		Sll sll = (i==S-1) ? Sll() : id0(i+1,rest...);
		sll[i]=first;
		return sll;
	}
	static Sll id0(ll i){ return Sll(); }
	
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
	typedef id4<T,S,R> iterator;
	using value_type = R;
};
template<class Q> using V   = vector<Q>;
template<class Q> using VV  = V<V<Q>>;
template<class Q> using VVV = V<V<V<Q>>>;
template<class T>         id5(    VVV<T>      ) -> id5<    VVV<T>,3,T>;
template<class T>         id5(     VV<T>      ) -> id5<     VV<T>,2,T>;
template<class T>         id5(      V<T>      ) -> id5<      V<T>,1,T>;
;                         id5(VV<string>      ) -> id5<VV<string>,3,char>;
;                         id5( V<string>      ) -> id5< V<string>,2,char>;
;                         id5(   string       ) -> id5<   string ,1,char>;
template<class T,class S> id5(    VVV<T>,S,S,S) -> id5<    VVV<T>,3,T>;
template<class T,class S> id5(     VV<T>,S,S,S) -> id5<     VV<T>,2,T>;
template<class T,class S> id5(      V<T>,S,S,S) -> id5<      V<T>,1,T>;
template<class S>         id5(VV<string>,S,S,S) -> id5<VV<string>,3,char>;
template<class S>         id5( V<string>,S,S,S) -> id5< V<string>,2,char>;
template<class S>         id5(   string ,S,S,S) -> id5<   string ,1,char>;


template<class VIEW2D> struct id6{
	VIEW2D *vw=nullptr;
	ll idx=INF;
	id6(){}
	id6(VIEW2D *vw_,ll idx_):vw(vw_),idx(idx_){}
	id6(const id6 &it):vw(it.vw),idx(it.idx){}
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
	ll   operator- (const id6 &it)const{ return idx- it.idx; }
	bool operator< (const id6 &it)const{ return idx< it.idx; }
	bool operator> (const id6 &it)const{ return idx> it.idx; }
	bool operator<=(const id6 &it)const{ return idx<=it.idx; }
	bool operator>=(const id6 &it)const{ return idx>=it.idx; }
	bool operator!=(const id6 &it)const{ return idx!=it.idx; }
	bool operator==(const id6 &it)const{ return idx==it.idx; }
	ll x(ll i)const{ return i/vw->leny(); }
	ll y(ll i)const{ return i%vw->leny(); }
	using iterator_category = random_access_iterator_tag;
	using value_type = typename VIEW2D::value_type;
	using difference_type = ll;
	using pointer = value_type*;
	using reference = value_type&;
};


template<class T,size_t S,class R> struct id3{
	using Sll=array<ll,S>;
	T &data; 

	Sll dsize; 

	Sll s=Sll(); 

	Sll dx=Sll(); 

	Sll dy=Sll(); 

	ll xl; 

	ll yl; 

	R dummy=R(); 

				 
	id3(T &v): data(v){
		id5<T,S,R>::SetDsize(v,dsize);
		dx[S-2]=1;
		dy[S-1]=1;
		xl=dsize[S-2];
		yl=dsize[S-1];
	}
	
	

	

	

	

	
	ll size() const { return xl; }
	array<ll,2> shape() const { return {xl,yl}; }
	ll lenx() const { return xl; }
	ll leny() const { return yl; }
	

	id5<T,S,R> operator[](ll i){ return id5(data,s+dx*i,dy,yl,dummy); }
	const id5<T,S,R> operator[](ll i) const { return id5(data,s+dx*i,dy,yl,dummy); }
	R &at(ll i,ll j){ if(i<0)i+=xl;  if(j<0)j+=yl;  return (*this)[i][j]; }
	

	

	

	

	

	operator vector<vector<R>>(){
		vector<vector<R>> v(xl);
		rep(i,0,xl-1) v[i]=(*this)[i];  return v;
	}
	auto begin(){ return id6(this,0); }
	auto end(){ return id6(this,xl*yl); }

	void dump(){ ::dump(tovv()); }

	
	id3<T,S,R> &dmy(R id10) { dummy=id10; return *this; }

	template<class...Q> id3<T,S,R> &st(Q... s_){

		this->s=RevIfNeg(id5<T,S,R>::id7(s_...));
		this->xl=id5<T,S,R>::AutoLen(this->s,this->dx,this->dsize);
		this->yl=id5<T,S,R>::AutoLen(this->s,this->dy,this->dsize);
		return *this;
	}
	template<class...Q> id3<T,S,R> &dirx(Q... d_){

		this->dx=id5<T,S,R>::id7(d_...);
		this->xl=id5<T,S,R>::AutoLen(this->s,this->dx,this->dsize);
		return *this;
	}
	template<class...Q> id3<T,S,R> &diry(Q... d_){

		this->dy=id5<T,S,R>::id7(d_...);
		this->yl=id5<T,S,R>::AutoLen(this->s,this->dy,this->dsize);
		return *this;
	}
	template<class...Q> id3<T,S,R> &mv(Q... s_){

		this->s += id5<T,S,R>::id7(s_...);
		return *this;
	}
	id3<T,S,R> &lenx(ll xl_) { xl=xl_; return *this; }
	id3<T,S,R> &leny(ll yl_) { yl=yl_; return *this; }
	id3<T,S,R> &shape(ll xl_,ll yl_) { xl=xl_; yl=yl_; return *this; }
	template<class Q> id3<T,S,R> &shape(Q &v) { xl=v.lenx(); yl=v.leny(); return *this; }
	id3<T,S,R> &rot90 () { s+=dx*(xl-1); swap(xl,yl); swap(dx,dy); dy*=-1; return *this; }
	id3<T,S,R> &rot270() { s+=dy*(yl-1); swap(xl,yl); swap(dx,dy); dx*=-1; return *this; }
	id3<T,S,R> &rot180() { s+=dx*(xl-1)+dy*(yl-1); dx*=-1; dy*=-1; return *this; }
	id3<T,S,R> &revx() { s+=dx*(xl-1); dx*=-1; return *this; }
	id3<T,S,R> &revy() { s+=dy*(yl-1); dy*=-1; return *this; }
	id3<T,S,R> &swapxy() { swap(xl,yl); swap(dx,dy); return *this; }


																	   
	Sll RevIfNeg(Sll pos){

		rep(i,0,S-1)  if (pos[i]<0) pos[i]+=dsize[i];
		return pos;
	}
	using value_type = R;
};
template<class T> id3(    VVV<T>) -> id3<    VVV<T>,3,T>;
template<class T> id3(     VV<T>) -> id3<     VV<T>,2,T>;
;                 id3(VV<string>) -> id3<VV<string>,3,char>;
;                 id3( V<string>) -> id3< V<string>,2,char>;




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







using mll = id2<MODLL>;
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



template<class T> inline T POW(T a,ll n){ T r=1; for (; n>0; n>>=1,a*=a){ if (n&1)r*=a; } return r; }
inline ll POW(int a,ll n){ return POW((ll)a,n); }



ll dumpW = 5;
template<class T> void dump(vector<T> &v){
	rep(i,0,sz(v)-1) { cerr << ((i==0)?"[":" ") << setw(dumpW) << v[i]; }  cerr << "]";
}
void dump(vll &v){
	rep(i,0,sz(v)-1) {
		cerr << ((i==0)?"[":" ") << setw(dumpW);
		if (v[i] == INF) cerr << "INF";
		else if (v[i] == -INF) cerr << "-INF";
		else                   cerr << v[i];
	}  cerr << "]";
}
template<class T> void dump(vector<vector<T>> &v){
	ll N=(ll)v.size();  string d[2][2]={{" ", "["},  {"\n", "]\n"}};
	rep(i,0,N-1) { cerr << d[0][i==0];  dump(v[i]);  cerr << d[1][i==N-1]; }
}
template<class T> void dump(vector<vector<vector<T>>> &v){
	ll N=(ll)v.size();  string d[2]={"  <", "[ <"};
	rep(i,0,N-1) { cerr << d[i==0] << i << ">\n"; dump(v[i]); }  cerr << "]\n";
}
template<class T> void dump(vector<vector<vector<vector<T>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ---<", "[ ---<"};
	rep(i,0,N-1) { cerr << d[i==0] << i << ">---\n"; dump(v[i]); }  cerr << "]\n";
}
template<class T> void dump(vector<vector<vector<vector<vector<T>>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ======<", "[ ======<"};
	rep(i,0,N-1) { cerr << d[i==0] << i << ">======\n"; dump(v[i]); }  cerr << "]\n";
}
template<class T,class S> void dump(map<T,S> &m){
	for (auto e: m) cout << e.first << " : " << e.second << '\n';
}

template<class T> void dump(T &v){}


void id8()
{
	ll n;
	cin >> n;
	string str;
	cin >> str;
	ll q;
	cin >> q;
	vector<string> t;
	rep(i,0,q-1){ string t__; cin>>t__; t.push_back(t__); }


	ll M=7;

	ll M=17;

	ll MM=1ll<<M;

	vvmll value;

	value.resize(M+1,vmll(n,1));
	rep(k,1,M){
		mll kinv=mll(1)/k;
		rep(c,1,n-1){
			value[k][c]=value[k][c-1]*kinv;
		}
	}

	vvmll mebi;
	mebi.resize(M+1,vmll(MM));


	

	{
		rep(i,0,n-1){
			rep(k,1,M) mebi[k][0]+=1;

			bll s=0;
			ll cnt=0;
			rep(di,1,n-1){
				ll l=i-di,r=i+di;
				if (l<0 or n-1<r)break;
				if (str[l]=='?' and str[r]=='?'){
					cnt++;
				}
				else if (str[l]=='?' or str[r]=='?'){
					cnt++;
					char cc=str[l];
					if (cc=='?') cc=str[r];
					s[cc-'a']=1;
				}
				else if (str[l]==str[r]){}

				else break; 


				rep(k,1,M) mebi[k][s]+=value[k][cnt];
			}
		}
	}
	

	{
		rep(i,0,n-1){
			

			bll s=0;
			ll cnt=0;
			rep(di,0,n-1){
				ll l=i-di,r=i+1+di;
				if (l<0 or n-1<r)break;
				if (str[l]=='?' and str[r]=='?'){
					cnt++;
				}
				else if (str[l]=='?' or str[r]=='?'){
					cnt++;
					char cc=str[l];
					if (cc=='?') cc=str[r];
					s[cc-'a']=1;
				}
				else if (str[l]==str[r]){}

				else break; 


				rep(k,1,M) mebi[k][s]+=value[k][cnt];
			}
		}
	}

	auto id1= [](vmll &g, ll N){
		REP(i, N) REP(s, 1LL<<N){
			bll b=s;
			if (b[i]==1) g[s] += g[b.off(i)];
		}
	};

	rep(k,1,M){
		id1(mebi[k],M);
	}

	ll qnm=count(all(str),'?');

	vmll ans;
	rep(i,0,q-1){
		bll b;
		string &st=t[i];
		for (auto&& ccc: st){
			b[ccc-'a']=1;
		}
		ll k=b.count();
		ans.push_back(mebi[k][b]*POW(mll(k),qnm));
	}
	each(e,ans) cout << e << '\n';

	return;
}




int main(){

	id8();
	


	ll t;  cin >> t;
	rep(i,0,t-1){
		id8();
		

	}

	cerr << timeget() <<"ms"<< '\n';
	return 0;
}
