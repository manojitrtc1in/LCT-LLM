




using namespace std;
const int MOD = 1e9 + 7;
const bool local = 

true;

false;





















using LL=long long;using PII=pair<int,int>;using VI=vector<int>;using SI=set<int>;
using MII=map<int,int>;using UMII=unordered_map<int, int>;using LD=long double;using TII=
pair<PII,int>;using QII=pair<PII,PII>;using UI=unsigned int;using ULL=unsigned long long;

	using MI





	id0(P
id1(LL) id1(LD) id0(PII) id0(TII) id0(QII) id1(VI) id1(SI) id1(UI) id1(ULL)
bvt(popc,__builtin_popcount)bvt(ctz,__builtin_ctz)bvt(clz,__builtin_clz)bvt(bit_parity,__builtin_parity)




sim,class N>bool mini(T&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(T&o,N h){if(o<h)ros=h,1;return 0;}



sim,class N oor pair<T,N>u){ros<<"<"<<u.f<<", "<<u.s<<">" bnt pta{using t=T;};sim,int N>struct pta<T[N]>{using t=T*;};
sim,typename=typename enable_if<!is_same<T,string>::value,urs(T().end())>::type oor
T u){int c=0;o<<"{";for(auto e:u)o<<", "+2*!c++<<e;ros<<"}";}
int mpow(int b, int e) {int o = 1; while (e) {if (e & 1)o = o * 1ll * b % MOD;b = b * 1ll * b % MOD;e /= 2;}ros;}
void dor(){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(T x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);} const bool deb =

  sim> typename enable_if<is_arithmetic<T>::value, N>::type operator O(T o, N x) {return N(o) O x;} \
  sim> typename enable_if<is_arithmetic<T>::value || is_same<T,N>::value, N&>::type operator O

true;



sim>string bte(T u){stringstream o;o<<u;ros.str()bnt nep;sim>T yyo(nep<T>);sim>nep<T>ngy(T v,string c,int m=0);sim>T yyo(T o){ros bnt
nep{T v;string c;int m; nep<T>mask(){return ngy(v,c,1);}

template<zub([],v[yyo(u)],N)c+"["+bte(u)+"]",rcu};sim>nep<T>ngy(T v,string c,int m){return nep<T>{v,c,m};}
sim>T yyo(nep<T> o){ros.v;}sim>int uhn(T){return 0;}sim>int uhn(nep<T>o){ros.m;}

ccy(,bitset<8*sizeof(T)>(u))ccy(!,u)sim,class N> string ema(pair<T,N> o) {return "<" + ema(o.f) + ", " + ema(o.s) + ">";}

sim>string bte(nep<T>o){ros.c+" = "+(o.m?ema(o.v):bte(o.v));}sim oor nep<T>m){ros<<bte(rcu sim>nep<T>ngy(nep<T>o,string c="",int m=0){ros;}








vector <stringstream> lif;struct prux {prux() {lif.EB();}~prux() {lif.pop_back();}};



  "
void siw(){};sim, class...N> void siw(T x, N...y) {lif.back() << x << "; ";siw(y...);}


sim> struct tqaz{T a;int u,d,l,r;};sim> tqaz<T> zaqt(T a,int u,int d,int l,int r){return tqaz<T>{a,u,d,l,r};}


stringstream o;VI M;FOR(j,x.l,x.r){int m=0;FOR(i,x.u,x.d)maxi(m, siz(t[i-x.u][j-x.l]));M.PB(m);}FOR(i,x.u,x.d){o<<"\n\t["<<i<<"] ";\
FOR(j,x.l,x.r){REP(_, M[j-x.l]-siz(t[i-x.u][j-x.l]))o<<" ";o<<t[i-x.u][j-x.l]<<((j+1)%5?", ":"; ");}}ros.str() + "\n";}
void nfl() {for (auto &s : lif)cerr << "  " << s.str() << "\033[m" << endl;} ckx(+) ckx(-) ckx(!) ckx(~) avc(bte) avc(ema)
struct zet_p {int o;LD v;zet_p(LL x=0):o(x%MOD),v(x){} zet_p(LL x, LD y):o(x%MOD),v(y){} int get(){ros>=0?o:o+MOD;}
  zet_p operator+(zet_p a) {return zet_p(o+a.o,v+a.v);}
  zet_p operator-(zet_p a) {return zet_p(o-a.o,v-a.v);}
  zet_p operator*(zet_p a) {return zet_p(o*1ll*a.o,v*a.v);}
  zet_p operator/(zet_p a) {assert(a.o != 0); return zet_p(o*1ll*mpow(a.o, MOD-2),v/a.v);}
  bool operator==(zet_p a) {return (o-a.o)%MOD == 0;}};
ostream&operator<<(ostream &o, zet_p u) {ros<<"["<<u.o<<" @ "<<u.v<<"]";}using frac_mod = zet_p;

false;
struct zet_p {int o;int get(){ros>=0?o:o+MOD;}zet_p(LL x=0):o(x%MOD){}zet_p(int x):o(x%MOD){}
  zet_p operator+(zet_p a) {return zet_p(o+a.o);}
  zet_p operator-(zet_p a) {return zet_p(o-a.o);}
  zet_p operator*(zet_p a) {return zet_p(o*1ll*a.o);}
  zet_p operator/(zet_p a) {return zet_p(o*1ll*mpow(a.o, MOD - 2));}
  bool operator==(zet_p a) {return (o-a.o)%MOD == 0;}};
struct frac_mod {int o,m;int get(){return (o*1ll*mpow(m,MOD-2)%MOD+MOD)%MOD;}frac_mod(int x=0):o(x%MOD),m(1){}frac_mod(LL x):o(x%MOD),m(1){}
  frac_mod(LL a,LL b):o(a),m(b){}
  frac_mod operator+(frac_mod a){return frac_mod(o*1ll*a.m+m*1ll*a.o,m*a.m);}
  frac_mod operator-(frac_mod a){return frac_mod(o*1ll*a.m-m*1ll*a.o,m*a.m);}
  frac_mod operator*(frac_mod a){return frac_mod(o*1ll*a.o,m*1ll*a.m);}
  frac_mod operator/(frac_mod a){return frac_mod(o*1ll*a.m,m*1ll*a.o);}
  bool operator==(frac_mod a) {return (o * 1ll * a.m - m * 1ll * a.o) % MOD == 0;}};
acv(frac_mod, +) acv(frac_mod, -) acv(frac_mod, *) acv(frac_mod, /)




acv(zet_p, +) acv(zet_p, -) acv(zet_p, *) acv(zet_p, /)


sim,class S,class N,class=typename enable_if<!is_base_of<ios_base,typename remove_reference<T>::type>::value>::type>nok\
(o,T,pair<S u N>, p o y.f, p o y.s) sim, class S, class N> nok(o, pair<S u N>, T, p.f o y, p.s o y)

	pair <T,S> & operator r
	sim, class S, class N> pair <T,S> &operator r


clp(+) clp(-) clp(*) clp(/) clp(%) clp(^) clp(|) clp(>>) clp(<<) clp(&) pcg(&&) pcg(||) syd(-) syd(+) syd(~) syd(!)

sim> int dud(T &, T&);sim> char dud(T x, ...);

	sim, class N> static T c get1(pair <T, N> c o){ros.f;}\
	sim, class N> static N c get2(pair <T, N> c o){ros.s;}\
	sim, class N, class S> static T c get1(tri(T, N, S) c o){ros.f.f;}\
	sim, class N, class S> static N c get2(tri(T, N, S) c o){ros.f.s;}\
	sim, class N, class S> static S c get3(tri(T, N, S) c o){ros.s;}\
	sim, class N, class S, class H> static S c get3(quadr(T, N, S, H) c o){ros.s.f;}\
	sim, class N, class S, class H> static H c get4(quadr(T, N, S, H) c o){ros.s.s;}\
};
template <class X> struct qul muf()
template <> struct qul <int> muf(&)




sim, class N> using gyv = T;
namespace std {sim, class N> struct hash<pair<T,N>>{size_t operator()(const pair<T,N>&u)const {
      return hash<T>()(u.f) * 440624741ULL ^ hash<N>()(u.s);}};
  sim> struct hash<gyv<T, decltype(((T*)0)->end())>> {size_t operator()(const T& u) const {size_t o = 505347433;
for (auto e : u)o = hash<urs(e)>()(e) ^ o * 277953755ULL;ros;}};}

const int MN = 1e6 + 44;
void PdAYB7V() {
	print_stack();
	debug(imie(MN) * 1ll * imie(MOD), "make sure it is right!!!!");
	debug("make sure m, n aren't misused");
	debug("long longs!!!!!!!!!!!!!!!!!!!");
	debug("run with m, n = 1");
	debug("make sure bounds on values aren't misused");
	debug("Check time/memory limit");
	while (getchar() != EOF);
	exit(0);
}
int main() {
	
	atexit(PdAYB7V);
	
	int n, m;
	scanf("%d%d", &n, &m);
	LL msum = 0, Msum = 0;
	REP(i, n)
		Msum += i;
	REP(i, n)
		msum += abs(i - n / 2);
	LL ans = 0;
	REP(i, m) {
		int x, d;
		scanf("%d%d", &x, &d);
		ans += x * 1ll * n + max(d * msum, d * Msum);
	}
	printf("%.10Lf\n", ans / (LD) n);
}

