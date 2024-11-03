

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

inline ll id18(ll a,ll b){ return -CEIL(-a,b); } 




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

template<ll MOD> struct id4{
	ll val;
	id4(ll v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	id4 operator - () const { return -val; }
	id4 operator + (const id4 &b) const { return val + b.val; }
	id4 operator - (const id4 &b) const { return val - b.val; }
	id4 operator * (const id4 &b) const { return val * b.val; }
	id4 operator / (const id4 &b) const { return id4(*this) /= b; }
	id4 operator + (ll b) const { return *this + id4(b); }
	id4 operator - (ll b) const { return *this - id4(b); }
	id4 operator * (ll b) const { return *this * id4(b); }
	friend id4 operator + (ll a,const id4 &b) { return b + a; }
	friend id4 operator - (ll a,const id4 &b) { return -b + a; }
	friend id4 operator * (ll a,const id4 &b) { return b * a; }
	friend id4 operator / (ll a,const id4 &b) { return id4(a)/b; }
	id4 &operator += (const id4 &b) { val=(val+b.val)%MOD; return *this; }
	id4 &operator -= (const id4 &b) { val=(val+MOD-b.val)%MOD; return *this; }
	id4 &operator *= (const id4 &b) { val=(val*b.val)%MOD; return *this; }
	id4 &operator /= (const id4 &b) {
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
	id4 &operator += (ll b) { return *this += id4(b); }
	id4 &operator -= (ll b) { return *this -= id4(b); }
	id4 &operator *= (ll b) { return *this *= id4(b); }
	id4 &operator /= (ll b) { return *this /= id4(b); }
	bool operator == (const id4 &b) const { return val == b.val; }
	bool operator != (const id4 &b) const { return val != b.val; }
	bool operator == (ll b) const { return *this == id4(b); }
	bool operator != (ll b) const { return *this != id4(b); }
	friend bool operator == (ll a,const id4 &b) { return id4(a) == b.val; }
	friend bool operator != (ll a,const id4 &b) { return id4(a) != b.val; }
	friend ostream &operator << (ostream &os,const id4 &a) { return os << a.val; }
	friend istream &operator >> (istream &is,id4 &a) { return is >> a.val; }
	static id4 Combination(ll a,ll b){
		chmin(b,a-b);
		if (b<0) return id4(0);
		id4 c = 1, d = 1;
		rep(i,0,b-1) c *= a-i;
		rep(i,0,b-1) d *= i+1;
		return c/d;
	}
	enum{modll=MOD};
};

template<class T,size_t S,class R> struct id11;
template<class T,size_t S,class R> struct id9{
	id11<T,S,R> *vw=nullptr;
	ll idx=INF;
	id9(){}
	id9(id11<T,S,R> *vw_,ll idx_):vw(vw_),idx(idx_){}
	id9(const id9<T,S,R> &it):vw(it.vw),idx(it.idx){}
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
	ll   operator- (const id9<T,S,R> &it)const{ return idx- it.idx; }
	bool operator< (const id9<T,S,R> &it)const{ return idx< it.idx; }
	bool operator> (const id9<T,S,R> &it)const{ return idx> it.idx; }
	bool operator<=(const id9<T,S,R> &it)const{ return idx<=it.idx; }
	bool operator>=(const id9<T,S,R> &it)const{ return idx>=it.idx; }
	bool operator!=(const id9<T,S,R> &it)const{ return idx!=it.idx; }
	bool operator==(const id9<T,S,R> &it)const{ return idx==it.idx; }
	using iterator_category = random_access_iterator_tag;
	using value_type = R;
	using difference_type = ll;
	using pointer = R*;
	using reference = R&;
};
template<class T,size_t S,class R> struct id11{
	using Sll=array<ll,S>;
	T &data; 

	Sll dsize; 

	Sll s=Sll(); 

	Sll d=Sll(); 

	ll len; 

	R &dummy; 

	R dummyj=R(); 

				  
	id11(T &v): data(v),dummy(dummyj){
		SetDsize(v,dsize);
		d[S-1]=1;
		len=dsize[S-1];
	}
	

	

	id11(T &v,Sll s,Sll e,Sll d): data(v),s(s),d(d),len(Len(s,e,d)),dummy(dummyj){
		SetDsize(v,dsize);
	}
	id11(T &v,Sll s,Sll d,ll len,R &id21): data(v),s(s),d(d),len(len),dummy(id21){
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
	template<class Q,size_t P,class O> auto &operator =(const id11<Q,P,O> &b){ return CpSeq(b); }
	template<class Q,size_t P,class O> auto &operator+=(const id11<Q,P,O> &b){ return PlSeq(b); }
	template<class Q,size_t P,class O> auto &operator-=(const id11<Q,P,O> &b){ return MnSeq(b); }
	template<class Q,size_t P,class O> auto &operator*=(const id11<Q,P,O> &b){ return PrSeq(b); }
	template<class Q,size_t P,class O> auto &operator/=(const id11<Q,P,O> &b){ return DvSeq(b); }
	template<class Q,size_t P,class O> auto &operator%=(const id11<Q,P,O> &b){ return RmSeq(b); }
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
	template<class Q,size_t P,class O> bool operator==(           const id11<Q,P,O> &b){ return eq(*this,b); }
	template<class Q>                  bool operator==(           const             Q &b){ return eq(*this,b); }
	template<class Q> friend           bool operator==(const Q &a,const id11<T,S,R> &b){ return eq(    a,b); }
	template<size_t Q>                 bool operator==(           const     char (&b)[Q]){ return eq(*this,string(b)); }
	template<class Q,size_t P,class O> bool operator!=(           const id11<Q,P,O> &b){ return !(*this==b); }
	template<class Q>                  bool operator!=(           const             Q &b){ return !(*this==b); }
	template<class Q> friend           bool operator!=(const Q &a,const id11<T,S,R> &b){ return !(    a==b); }
	template<class Q,size_t P,class O> bool operator< (           const id11<Q,P,O> &b){ return lt(*this,b); }
	template<class Q>                  bool operator< (           const             Q &b){ return lt(*this,b); }
	template<class Q> friend           bool operator< (const Q &a,const id11<T,S,R> &b){ return lt(    a,b); }
	template<class Q,size_t P,class O> bool operator> (           const id11<Q,P,O> &b){ return lt(b,*this); }
	template<class Q>                  bool operator> (           const             Q &b){ return lt(b,*this); }
	template<class Q> friend           bool operator> (const Q &a,const id11<T,S,R> &b){ return lt(b,a    ); }
	template<class Q,size_t P,class O> bool operator<=(           const id11<Q,P,O> &b){ return !(*this>b); }
	template<class Q>                  bool operator<=(           const             Q &b){ return !(*this>b); }
	template<class Q> friend           bool operator<=(const Q &a,const id11<T,S,R> &b){ return !(    a>b); }
	template<class Q,size_t P,class O> bool operator>=(           const id11<Q,P,O> &b){ return !(*this<b); }
	template<class Q>                  bool operator>=(           const             Q &b){ return !(*this<b); }
	template<class Q> friend           bool operator>=(const Q &a,const id11<T,S,R> &b){ return !(    a<b); }

	
	ll size() const { return len; }
	R &operator[](ll i){ return const_cast<R&>(OrgAt(s+d*i)); }
	const R &operator[](ll i) const { return OrgAt(s+d*i); }
	R &at(ll i){ if(i<0)i+=len; return (*this)[i]; }
	

	operator vector<R>(){ vector<R> v(len);  rep(i,0,len-1) v[i]=(*this)[i];  return v; }
	bool contains(R a){ rep(i,0,len-1) if((*this)[i]==a)return true;  return false; }
	auto begin(){ return id9<T,S,R>(this,0); }
	auto end(){ return id9<T,S,R>(this,len); }
	
	id11<T,S,R> &dmy(R id21) { dummy=id21; return *this; }

	template<class...Q> id11<T,S,R> &st(Q... s_){

		this->s=RevIfNeg(id13(s_...));
		this->len=AutoLen(this->s,this->d,this->dsize);
		return *this;
	}
	template<class...Q> id11<T,S,R> &en(Q... e_){

		this->len=Len(s, RevIfNeg(id13(e_...)), d);
		return *this;
	}
	template<class...Q> id11<T,S,R> &dir(Q... d_){

		this->d=id13(d_...);
		this->len=AutoLen(this->s,this->d,this->dsize);
		return *this;
	}
	template<class...Q>
	id11<T,S,R> &mv(Q... s_){ this->s+=id13(s_...); return *this; }

	id11<T,S,R> &size(ll len_) { len=len_; return *this; }

	template<class Q> id11<T,S,R> &size(Q &v){ len=(ll)v.size(); return *this; }

	id11<T,S,R> &rev() { s+=d*(len-1); d*=-1; return *this; }


	
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
	
	template<class...Q> static Sll id13(Q... args){ return id0(0,args...); }
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
	typedef id9<T,S,R> iterator;
	using value_type = R;
};
template<class Q> using V   = vector<Q>;
template<class Q> using VV  = V<V<Q>>;
template<class Q> using VVV = V<V<V<Q>>>;
template<class T>         id11(    VVV<T>      ) -> id11<    VVV<T>,3,T>;
template<class T>         id11(     VV<T>      ) -> id11<     VV<T>,2,T>;
template<class T>         id11(      V<T>      ) -> id11<      V<T>,1,T>;
;                         id11(VV<string>      ) -> id11<VV<string>,3,char>;
;                         id11( V<string>      ) -> id11< V<string>,2,char>;
;                         id11(   string       ) -> id11<   string ,1,char>;
template<class T,class S> id11(    VVV<T>,S,S,S) -> id11<    VVV<T>,3,T>;
template<class T,class S> id11(     VV<T>,S,S,S) -> id11<     VV<T>,2,T>;
template<class T,class S> id11(      V<T>,S,S,S) -> id11<      V<T>,1,T>;
template<class S>         id11(VV<string>,S,S,S) -> id11<VV<string>,3,char>;
template<class S>         id11( V<string>,S,S,S) -> id11< V<string>,2,char>;
template<class S>         id11(   string ,S,S,S) -> id11<   string ,1,char>;


template<class VIEW2D> struct id12{
	VIEW2D *vw=nullptr;
	ll idx=INF;
	id12(){}
	id12(VIEW2D *vw_,ll idx_):vw(vw_),idx(idx_){}
	id12(const id12 &it):vw(it.vw),idx(it.idx){}
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
	ll   operator- (const id12 &it)const{ return idx- it.idx; }
	bool operator< (const id12 &it)const{ return idx< it.idx; }
	bool operator> (const id12 &it)const{ return idx> it.idx; }
	bool operator<=(const id12 &it)const{ return idx<=it.idx; }
	bool operator>=(const id12 &it)const{ return idx>=it.idx; }
	bool operator!=(const id12 &it)const{ return idx!=it.idx; }
	bool operator==(const id12 &it)const{ return idx==it.idx; }
	ll x(ll i)const{ return i/vw->leny(); }
	ll y(ll i)const{ return i%vw->leny(); }
	using iterator_category = random_access_iterator_tag;
	using value_type = typename VIEW2D::value_type;
	using difference_type = ll;
	using pointer = value_type*;
	using reference = value_type&;
};


template<class T,size_t S,class R> struct id5{
	using Sll=array<ll,S>;
	T &data; 

	Sll dsize; 

	Sll s=Sll(); 

	Sll dx=Sll(); 

	Sll dy=Sll(); 

	ll xl; 

	ll yl; 

	R dummy=R(); 

				 
	id5(T &v): data(v){
		id11<T,S,R>::SetDsize(v,dsize);
		dx[S-2]=1;
		dy[S-1]=1;
		xl=dsize[S-2];
		yl=dsize[S-1];
	}
	
	

	

	

	

	
	ll size() const { return xl; }
	array<ll,2> shape() const { return {xl,yl}; }
	ll lenx() const { return xl; }
	ll leny() const { return yl; }
	

	id11<T,S,R> operator[](ll i){ return id11(data,s+dx*i,dy,yl,dummy); }
	const id11<T,S,R> operator[](ll i) const { return id11(data,s+dx*i,dy,yl,dummy); }
	R &at(ll i,ll j){ if(i<0)i+=xl;  if(j<0)j+=yl;  return (*this)[i][j]; }
	

	

	

	

	

	operator vector<vector<R>>(){
		vector<vector<R>> v(xl);
		rep(i,0,xl-1) v[i]=(*this)[i];  return v;
	}
	auto begin(){ return id12(this,0); }
	auto end(){ return id12(this,xl*yl); }

	void dump(){ ::dump(tovv()); }

	
	id5<T,S,R> &dmy(R id21) { dummy=id21; return *this; }

	template<class...Q> id5<T,S,R> &st(Q... s_){

		this->s=RevIfNeg(id11<T,S,R>::id13(s_...));
		this->xl=id11<T,S,R>::AutoLen(this->s,this->dx,this->dsize);
		this->yl=id11<T,S,R>::AutoLen(this->s,this->dy,this->dsize);
		return *this;
	}
	template<class...Q> id5<T,S,R> &dirx(Q... d_){

		this->dx=id11<T,S,R>::id13(d_...);
		this->xl=id11<T,S,R>::AutoLen(this->s,this->dx,this->dsize);
		return *this;
	}
	template<class...Q> id5<T,S,R> &diry(Q... d_){

		this->dy=id11<T,S,R>::id13(d_...);
		this->yl=id11<T,S,R>::AutoLen(this->s,this->dy,this->dsize);
		return *this;
	}
	template<class...Q> id5<T,S,R> &mv(Q... s_){

		this->s += id11<T,S,R>::id13(s_...);
		return *this;
	}
	id5<T,S,R> &lenx(ll xl_) { xl=xl_; return *this; }
	id5<T,S,R> &leny(ll yl_) { yl=yl_; return *this; }
	id5<T,S,R> &shape(ll xl_,ll yl_) { xl=xl_; yl=yl_; return *this; }
	template<class Q> id5<T,S,R> &shape(Q &v) { xl=v.lenx(); yl=v.leny(); return *this; }
	id5<T,S,R> &rot90 () { s+=dx*(xl-1); swap(xl,yl); swap(dx,dy); dy*=-1; return *this; }
	id5<T,S,R> &rot270() { s+=dy*(yl-1); swap(xl,yl); swap(dx,dy); dx*=-1; return *this; }
	id5<T,S,R> &rot180() { s+=dx*(xl-1)+dy*(yl-1); dx*=-1; dy*=-1; return *this; }
	id5<T,S,R> &revx() { s+=dx*(xl-1); dx*=-1; return *this; }
	id5<T,S,R> &revy() { s+=dy*(yl-1); dy*=-1; return *this; }
	id5<T,S,R> &swapxy() { swap(xl,yl); swap(dx,dy); return *this; }


	
	Sll RevIfNeg(Sll pos){

		rep(i,0,S-1)  if (pos[i]<0) pos[i]+=dsize[i];
		return pos;
	}
	using value_type = R;
};
template<class T> id5(    VVV<T>) -> id5<    VVV<T>,3,T>;
template<class T> id5(     VV<T>) -> id5<     VV<T>,2,T>;
;                 id5(VV<string>) -> id5<VV<string>,3,char>;
;                 id5( V<string>) -> id5< V<string>,2,char>;




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







using mll = id4<MODLL>;
using vmll    = std::vector<mll>;
using vvmll   = std::vector<vmll>;
using vvvmll  = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;










namespace atcoder {
namespace internal {




int id8(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}




int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}
}  

}  






namespace atcoder {
namespace internal {




constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}






struct barrett {
    unsigned int _m;
    unsigned long long im;
    

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    

    unsigned int umod() const { return _m; }
    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        

        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};






constexpr long long id20(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}








constexpr bool id19(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (long long a : {2, 7, 61}) {
        long long t = d;
        long long y = id20(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = id19(n);




constexpr std::pair<long long, long long> id3(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  

                       

                       

                       

                       

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}






constexpr int id15(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id20(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id15(m);
}  

}  






namespace atcoder {
namespace internal {
template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};
}  

}  








namespace atcoder {
namespace internal {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};






struct id17 {
public:
    id17(int n) : _n(n) {}
    int num_vertices() { return _n; }
    void add_edge(int from, int to) { edges.push_back({from, {to}}); }
    

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }
    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }
private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
}  

}  








namespace atcoder {
namespace internal {

template <class T>
using is_signed_int128 =
typename std::conditional<std::is_same<T, __int128_t>::value ||
    std::is_same<T, __int128>::value,
    std::true_type,
    std::false_type>::type;
template <class T>
using is_unsigned_int128 =
typename std::conditional<std::is_same<T, __uint128_t>::value ||
    std::is_same<T, unsigned __int128>::value,
    std::true_type,
    std::false_type>::type;
template <class T>
using make_unsigned_int128 =
typename std::conditional<std::is_same<T, __int128_t>::value,
    __uint128_t,
    unsigned __int128>;
template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
    is_signed_int128<T>::value ||
    is_unsigned_int128<T>::value,
    std::true_type,
    std::false_type>::type;
template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
    std::is_signed<T>::value) ||
    is_signed_int128<T>::value,
    std::true_type,
    std::false_type>::type;
template <class T>
using is_unsigned_int =
typename std::conditional<(is_integral<T>::value &&
    std::is_unsigned<T>::value) ||
    is_unsigned_int128<T>::value,
    std::true_type,
    std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
    std::make_unsigned<T>,
    std::common_type<T>>::type>::type;

template <class T> using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int =
typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
    std::true_type,
    std::false_type>::type;
template <class T>
using is_unsigned_int =
typename std::conditional<is_integral<T>::value &&
    std::is_unsigned<T>::value,
    std::true_type,
    std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
    std::make_unsigned<T>,
    std::common_type<T>>::type;

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
}  

}  









namespace atcoder {
struct id17 {
public:
    id17() : internal(0) {}
    id17(int n) : internal(n) {}
    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }
    std::vector<std::vector<int>> scc() { return internal.scc(); }
private:
    internal::id17 internal;
};
}  








namespace atcoder {








struct two_sat {
public:
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}
    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }
private:
    int _n;
    std::vector<bool> _answer;
    internal::id17 scc;
};
}  



using namespace atcoder;



struct id1{
	atcoder::two_sat ts;
	vector<tuple<ll,bool,ll,bool>> id6,id16;
	id1(){}
	id1(ll n): ts((int)n) {}
	void addclause(ll i,bool f,ll j,bool g){ 

		ts.add_clause((int)i,f,(int)j,g);
		id6.emplace_back(i,f,j,g);
	}
	void addimplication(ll i,bool f,ll j,bool g){ 

		ts.add_clause((int)i,!f,(int)j,g);
		id16.emplace_back(i,f,j,g);
	}
	bool satisfiable() { return ts.satisfiable(); }
	vector<bool> answer() { return ts.answer(); }

	void dumpcore(vector<tuple<ll,bool,ll,bool>> &v,ll kind){
		static const char nt[2][9]={"￢","  "};
		static const char c[2][9]={"or","→"};
		char str[101];
		for (auto&&[i,f,j,g]: v){
			snprintf(str,100,"%sx%d %s %sx%d\n",nt[f],(int)i,c[kind],nt[g],(int)j);
			cerr << string(str);
		}
	}
	void dump(bool id2=false){
		auto v=id6;
		sort(v.begin(),v.end());
		if (id2) for (auto&&[i,f,j,g]:v) f=!f;
		dumpcore(v,id2);
		v=id16;
		sort(v.begin(),v.end());
		dumpcore(v,1);
	}

	void dump(bool id2=false){}

};


struct id10{
	vll par,rank,size;
	ll g;
	id10(ll num): par(num),rank(num),size(num,1),g(num){
		rep(i,0,num-1) par[i] = i;
	}
	bool Same(ll x,ll y) { return Root(x) == Root(y); }
	ll Root(ll x) { return (par[x] == x) ? x : par[x]=Root(par[x]); }
	ll Size(ll x){ return size[Root(x)]; }
	ll grpnm() { return g; }
	void Unite(ll x,ll y){
		x = Root(x);
		y = Root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else                   par[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
		size[x] = size[y] = size[x] + size[y];
		g--;
	}
};


vvll *pa;
vvll to;
vll sgs;

void dfs(ll v,ll p=-1){
	vvll &a=*pa;
	if (p!=-1){
		ll vv=v,pp=p;
		if (vv>pp)swap(vv,pp);
		if (a[vv][pp]>a[pp][vv]) sgs[v]=-sgs[p];
		else                     sgs[v]= sgs[p];
	}
	each(u,to[v]){
		if (u==p)continue;
		dfs(u,v);
	}
}

auto solve(
	ll n,vvll &a
){
	id10 uft(n);
	vpll uv;
	rep(i,0,n-1){
		rep(j,i+1,n-1){
			if (a[i][j]!=a[j][i]){
				if (uft.Same(i,j))continue;
				uft.Unite(i,j);
				uv.emplace_back(i,j);
			}
		}
	}

	auto makeGraph=[](ll n,vector<pair<ll,ll>> &ab,bool isDirected){
		vvll to(n);
		for (auto [a,b]:ab){
			to[a].push_back(b);
			if (!isDirected) to[b].push_back(a);
		}
		return to;
	};
	to=makeGraph(n,uv,false);

	sgs.assign(n,0);
	pa=&a;
	rep(v,0,n-1){
		if (sgs[v]!=0)continue;
		sgs[v]=1;
		dfs(v);
	}
	vvll ans=a;
	rep(i,0,n-1){
		rep(j,i+1,n-1){
		    if (sgs[i]==-1) swap(ans[i][j],ans[j][i]);
		    if (sgs[j]==-1) swap(ans[i][j],ans[j][i]);
		}
	}

	return ans;
}














































































































































































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


auto id7(
	ll n,vvll &a
){
	vvll ans=a;
	for (bll s=0; s[n]==0; s++){
		vvll b=a;
		rep(i,0,n-1){
			rep(j,i+1,n-1){
				if (s[i]) swap(b[i][j],b[j][i]);
				if (s[j]) swap(b[i][j],b[j][i]);
			}
		}
		chmin(ans,b);
	}

	return ans;
}

void solvecomp(
	ll n,vvll &a
){
	auto coutans=[](auto ans){
		
		each(e,ans) cout << e << '\n';
	};

	auto ans=solve(
		n,a
	);
	coutans(ans);

	cout << "- - - - -\n";
	auto an2=id7(
		n,a
	);
	coutans(an2);
	cout << "================\n";
	if (ans!=an2){
		cout << "============ input =============\n";
		
		cout << n << '\n';
		each(e,a) cout << e << '\n';

		cout << "============ input end =========\n\n================\n";
		getchar();  rep(i,0,10000000000) i++;

	}

}

void id14(){
	
	ll n;
	cin >> n;
	vector<vector<ll>> a;
	a.resize(n,vector<ll>(n));
	rep(i,0,n-1)rep(j,0,n-1){ ll a__; cin>>a__; a[i][j]=a__; }

	solvecomp(
		n,a
	);
}



struct rndutil{
	mt19937 mt;
	rndutil():mt(0){}
	ll val(ll a,ll b){ return mt()%(b-a+1)+a; }

	vll ary(ll n,ll a,ll b){

		vll v(n);
		for (ll i=0;i<n;++i) v[i]=this->val(a,b);
		return v;
	}
	vll sample(ll n,ll a,ll b){

		ll len=b-a+1;
		assert(n<=len);
		vll v(len);
		iota(v.begin(),v.end(),a);
		for (ll i=0;i<n;++i) swap(v[i],v[this->val(i,len-1)]);
		v.resize(n);
		return v;
	}
	pll range(ll a,ll b,ll m=1){ 

		while (true){
			ll l=this->val(a,b+1),r=this->val(a,b+1);
			if (r-l<m)continue;
			return {l,r-1};
		}
	}
	pair<ll,vpll> graph(ll n){ 

		while (true){
			vpll uv;
			id10 uft(n);
			for (ll v=0;v<n;++v) for (ll u=v+1;u<n;++u){
				if (this->val(1,n*(n-1)/2)>=n)continue;

				uv.emplace_back(v,u);
				uft.Unite(v,u);
			}
			if (uft.grpnm()==1) return {(ll)uv.size(),uv};
		}
	}
	vpll tree(ll n){ 

		vpll uv;
		id10 uft(n);
		while (uft.grpnm()>1){
			ll u=this->val(0,n-1),v=this->val(0,n-1);
			if (uft.Same(u,v)) continue;
			if (u>v)swap(u,v);
			uft.Unite(u,v);
			uv.emplace_back(u,v);
		}
		return uv;
	}
	struct id10{
		vll par,rank,size;
		ll g;
		id10(ll num): par(num),rank(num),size(num,1),g(num){
			rep(i,0,num-1) par[i] = i;
		}
		bool Same(ll x,ll y) { return Root(x) == Root(y); }
		ll Root(ll x) { return (par[x] == x) ? x : par[x]=Root(par[x]); }
		ll Size(ll x){ return size[Root(x)]; }
		ll grpnm() { return g; }
		void Unite(ll x,ll y){
			x = Root(x);
			y = Root(y);
			if (x == y) return;
			if (rank[x] < rank[y]) par[x] = y;
			else                   par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
			size[x] = size[y] = size[x] + size[y];
			g--;
		}
	};
};



void generand(){
	rndutil ru;

	rep(q,0,INF){
		
		ll n=ru.val(5,6);
		vvll a;
		rep(i,0,n-1){
			a.push_back(ru.ary(n,1,2));
		}

		solvecomp(
			n,a
		);
	}
}




int main(){

	id14();
	


	ll t;  cin >> t;
	rep(i,0,t-1){
		id14();
		

	}

	cerr << timeget() <<"ms"<< '\n';
	return 0;
}
