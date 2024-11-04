








































using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}







void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}

template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}

template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return re;}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return re;}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return re;}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return g;}
vv<int> readG(const int &n){ return readG(n,n-1);}
vv<int> readD(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); } return g;}
vv<int> readD(const int &n){ return readD(n,n-1);}
template<class T> vv<pair<int,T>> readG(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); g[b].eb(a,c);} return g;}
template<class T> vv<pair<int,T>> readG(const int &n){ return readG<T>(n,n-1);}
template<class T> vv<pair<int,T>> readD(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); } return g;}
template<class T> vv<pair<int,T>> readD(const int &n){ return readD<T>(n,n-1);}
template<class T> bool erase(multiset<T> &st, const T &v){if(cauto it=st.find(v); it==st.end()) return false; else{ st.erase(it); return true;}}

template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
template<class Tuple, size_t... Is> void id1(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ id1(is, t, index_sequence_for<Args...>{}); return is;}


struct sorted_impl{template<class T>friend vector<T>operator-(vector<T>a,sorted_impl){sort(all(a));return a;}}sorted;struct reversed_impl{template<class T>friend vector<T>operator-(vector<T> a,reversed_impl){reverse(all(a));return a;}}reversed;struct distinct_impl{template<class T>friend vector<T>operator-(vector<T> a,distinct_impl){sort(all(a));UNIQUE(a);return a;}}distinct;template<class S>struct sortedWith{const S f;sortedWith(const S &f):f(f){}template<class T>friend vector<T>operator-(vector<T> a,const sortedWith&b){sort(all(a),[&](cauto&i,cauto&j){return b.f(i)<b.f(j);});return a;}};
template<class T>int operator/(const T&v,const vector<T>&vs){return lower_bound(all(vs),v)-vs.begin();}
vector<int> Inds(const int n){vector<int> inds(n);iota(all(inds),0);return inds;}
const ll MOD=1e9+7; 


ll id2(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod=MOD> struct ModInt{
  int v;
  ModInt(int v=0):v(v){}
  ModInt operator+(const ModInt &n)const{return v+n.v<mod ? v+n.v : v+n.v-mod;}
  ModInt operator-(const ModInt &n)const{return v-n.v<0 ? v-n.v+mod : v-n.v;}
  ModInt operator*(const ModInt &n)const{return int(ll(v)*n.v%mod);}
  ModInt operator/(const ModInt &n)const{return int(ll(v)*id2(n.v%mod,-1,mod)%mod);}
  ModInt operator+(const int &n)const{return v+n<mod ? v+n : v+n-mod;}
  ModInt operator-(const int &n)const{return v-n<0 ? v-n+mod : v-n;}
  ModInt operator*(const ll &n)const{return int(ll(v)*(n%mod)%mod);}
  ModInt operator/(const ll &n)const{return int(ll(v)*id2(n%mod,-1,mod)%mod);}
  ModInt& operator+=(const ModInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const ModInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ModInt &n){v=ll(v)*n.v%mod; return *this;}
  ModInt& operator/=(const ModInt &n){v=ll(v)*id2(n.v,-1,mod)%mod; return *this;}
  ModInt& operator+=(const int &n){v+=n; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const int &n){v-=n; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  ModInt& operator/=(const ll &n){v=ll(v)*id2(n,-1,mod)%mod; return *this;}
	bool operator==(const ModInt &n)const{return v==n.v;};
	bool operator!=(const ModInt &n)const{return v!=n.v;};
	ModInt& operator++(){ return operator+=(1); }
	ModInt& operator--(){ return operator-=(1); }
	ModInt operator++(int i){ ModInt tmp(*this); operator++(); return tmp; }
	ModInt operator--(int i){ ModInt tmp(*this); operator--(); return tmp; }
};

class id6{
public:
	unordered_map<int,pii> dict;
	id6(int n){
		rep(p,n+1)reps(q,1,n+1)if(__gcd(p,q)==1){
			dict[int(1ll*p*id2(q,-1)%MOD)]=pii(p,q);
			dict[int(MOD-1ll*p*id2(q,-1)%MOD)]=pii(-p,q);
		}
	}
} id3(1000);
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){if(id3.dict.count(n.v)) os<<n.v, cerr<<"("<<id3.dict[n.v].X<<"/"<<id3.dict[n.v].Y<<")";else os<<n.v;return os;};

template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){return os<<n.v;};

template<int mod> ModInt<mod> operator+(const ll &n,const ModInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> ModInt<mod> operator-(const ll &n,const ModInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> ModInt<mod> operator*(const ll &n,const ModInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> ModInt<mod> operator/(const ll &n,const ModInt<mod> &m){return ModInt<mod>(n%mod)/m;}
typedef ModInt<MOD> mint;
template <int mod> ModInt<mod> modpow(ModInt<mod> r,ll n){ ModInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class id0{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  id0(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} id4(1123456);
using pmm=pair<mint,mint>;
mint modpow(ll r,ll n){ return (int)id2(r,n);}

const int SQ=512;
const int BK=212345/SQ+3;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto q=read();
	auto vs=readV(n);
	cauto qs=readV<tuple<int,int,int>>(q,{1,0,0});
	for(auto &v:vs) ((v%=MOD)+=MOD)%=MOD;
	vv<int> mo(BK);
	rep(i,q) mo[get<0>(qs[i])/SQ].eb(i);
	cauto zip=vs-distinct;
	for(auto &v:vs) v=v/zip;
	vector<int> cnt(zip.size());
	mint sum0=0,sum1=0,sum2=0,sum3=0;
	cauto add=
		[&](const int &vi){
			out("add",vi,1);
			if(++cnt[vi]==1){
				mint tmp=1;
				sum0+=1;
				tmp*=zip[vi];
				sum1+=tmp;
				tmp*=zip[vi];
				sum2+=tmp;
				tmp*=zip[vi];
				sum3+=tmp;
			}
		};
	cauto rem=
		[&](const int &vi){
			out("rem",vi,1);
			if(--cnt[vi]) return;
			mint tmp=1;
			sum0-=1;
			tmp*=zip[vi];
			sum1-=tmp;
			tmp*=zip[vi];
			sum2-=tmp;
			tmp*=zip[vi];
			sum3-=tmp;
		};
	vector<int> re(q);
	rep(bk,BK){
		sort(all(mo[bk]),[&](cauto &i,cauto &j){ return get<1>(qs[i])<get<1>(qs[j]);});
		sum0=sum1=sum2=sum3=0;
		int l=bk*SQ,r=l;
		for(cauto i:mo[bk]){
			cauto &[L,R,D]=qs[i];
			for(;r<R;++r) add(vs[r]);
			for(;L<l;--l) add(vs[l-1]);
			for(;l<L;++l) rem(vs[l]);
			const mint d=D;
			cauto n=sum0;
			cauto a=(sum1-(n-1)*n*d*inv[2])/n;
			cauto id7=n*a*a+2*a*d*n*(n-1)*inv[2]+d*d*(n-1)*n*(2*n-1)*inv[6];
			cauto id5=n*a*a*a
				+3*a*a*d*n*(n-1)*inv[2]
				+3*a*d*d*(n-1)*n*(2*n-1)*inv[6]
				+1*d*d*d*n*n*(n-1)*(n-1)*inv[4];
			out(L,R,l,r,sum1,n,a,d,id7,sum2,id5,sum3,1);
			if(sum2==id7 && sum3==id5) re[i]=1;
		}
		reps(i,l,r) --cnt[vs[i]];
	}
	out(re,1);
	for(cauto &v:re) cout<<(v?"Yes":"No") NL;
	return 0;
}
