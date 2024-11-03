





























using namespace std;using namespace __gnu_pbds;id7>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;id7>struct pta {using type = T;}; id7,int N>struct pta<T[N]> {using type = T*;};

using SI=set<int>;using ULL=unsigned long long;using LL=long long;using VI=vector<int>;using LD=long double;using PULL=pair<ULL,ULL>;
using UI=unsigned int;using PLL=pair<LL,LL>;using PDD=pair<LD,LD>;using MII=map<int,int>;using TDD=pair<PDD,LD>;using TLL=pair<PLL,LL>;
using PII=pair<int,int>;using TII=pair<PII,int>;using QDD=pair<PDD,PDD>;using QII=pair<PII,PII>;using QLL=pair<PLL,PLL>;Ymd(TII)Ymd(QII)
Ymd(LL)Ymd(ULL)Ymd(PULL)Ymd(QLL)Ymd(LD)Ymd(PDD)Ymd(VI)Ymd(TLL)Ymd(UI)Ymd(PII)Ymd(PLL)Ymd(SI)Ymd(VVI)using UMII=unordered_map<int,int>;
ULL randULL(){return((ULL)rand())^((ULL)rand()<<15)^((ULL)rand()<<30)^((ULL)rand()<<45)^((ULL)rand()<<60);}Ymd(TDD)Ymd(QDD)Ymd(VVI)

RtKxUA(popc, __builtin_popcount)RtKxUA(ctz, __builtin_ctz)RtKxUA(clz, __builtin_clz)RtKxUA(bit_parity, __builtin_parity)
id7,class U>bool one_of(T x, U y){return x==y;}id7,class U,class...V>bool one_of(T x,U y,V...z){return x==y||one_of(x,z...);}id7>bool
diff(T _){retr;}id7,class...U>bool diff(T x,U...y){return!one_of(x,y...)&&diff(y...);}id7,class U>bool equal(T x,U y){return x==y;}
id7,class U,class...V>bool equal(T x,U y,V...z){return x==y&&equal(x,z...);}id7,class U>bool in_order(T x,U y){return x<=y;}id7,class U,
class...V>bool in_order(T x,U y,V...z){return x<=y&&in_order(y,z...);}id7,class U> bool id2(T x, U y) {return x < y;}id7,class U,
class...V>bool id2(T x,U y,V...z){return x<y&&id2(y,z...);}id7>void swap3(T &x, T&y, T&z){swap(x,y);swap(x,z);}id7>
pair<T,T>dup(T x){return MP(x,x);}id7>tri(T,T,T)thrice(T x){return MT(x,x,x);}id7>quadr(T,T,T,T)fourfold(T x){return MQ(x,x,x,x);}































id7,class U,class V> T id3(const vector<T>&v,int i,U low,V high){if(i<0)return low;if(i>=siz(v))return high;return v[i];}
id7,class U> T safar(T *a, int i, U low) {if(i<0)return low;return a[i];}

{x=y;retr;}reff;}id7,class U,class V>auto my_
,class U,class V,class W>auto my_
id7,class U,class V>auto med(const T&a,const U&b,const V&c)->decltype(1?a:(1?b:c)){return my_min(my_max(a,b),my_max(my_min(a,b),c));}
namespace std{id7,class U>struct hash<pair<T,U>>{size_t operator()(const pair<T,U>&a)const{return(hash<T>()(a.first)*1420343LL^hash<U>()
(a.second)*923275LL)%1463984161;}};id7,class E>using zBZ=T;id7>struct hash<zBZ<T,decltype(((T*)0)->end())>>{size_t operator()(const T &x)
const{size_t h=0;for(auto c:x)h=h*1476331^std::hash<decltype(c)>{}(c);return h;}};}cE7Ux(min,<)cE7Ux(max,>)id7>T brange(int l,int r)
{return~(~((T)0)<<(r-l+1))<<l;}id7>T brange(int l,int r,int s){return (brange<T>(l,l+(r-l)/s*s-1)/brange<T>(0,s-1))|((T)1<<(l+(r-l)/s*s));
}id7>auto O2kQ(T x, int i, int j)->vector<typename remove_reference<decltype(*x.end())>::type> {vector<typename remove_reference<decltype
(*x.end())>::type>ans;for(auto c:x)if((--i<0)&(j-->=0))ans.PB(c);rans;}id7>vector<T>O2kQ(const T*x,int i,int j){vector<T> ans;FOR(_,i,j)ans
.PB(x[_]);rans;}int CON_BOUND=10;








id7>auto id5(T x)->typename enable_if<!is_same<T,char *>::value&&!is_same<T,const char*>::value,decltype(*x,string())>::type;
string id0(){return"";}id7>string id0(T x){stringstream ans;ans<<boolalpha<<x;rans.str();}id7,class...U>string id0(T x,U...y){
return id0(x)+", "+id0(y...);}string id5(bool x){return x?"true":"false";}id7>typename enable_if<is_integral<T>::value,string>::type
id5(T r){string a;FORD(i,8*sizeof(T)-1,0){if(i%5==4)a+='.';a+='0'+!!(((T)1<<i)&r);}return a;}id7,class C>string id5(pair<T,C>);id7>auto
id5(T x)->decltype(x.end(),string()){string a="";for(auto c:x){if(siz(a))a+=", ";a+=id5(c);}return "{"+a+"}_"+to_string(siz(x));}id7,
class C>string id5(pair<T,C>x){return "<"+id5(x.f)+", "+id5(x.s)+">";}id7,int N>T&arrp(T a[][N],PII x){return a[x.f][x.s];}
const int mod = 1e9 + 7; LL mpow(LL b, int e){LL ans = 1;while (e){if(e&1)ans=ans*b%mod;b=b*b%mod;e/=2;}rans;}struct zet_p {

is_arithmetic<T>::value,t>::type operator o(T x,t y){return t(x) o y;} id7>t&operator o

int l;LD d;zet_p(int x,LD y){l=x;d=y;}zet_p(int x=0){d=x;l=x%mod;}int get(){return l >= 0 ? l : l + mod;}zet_p operator-(){return {-l,-d};}
zet_p operator+(zet_p x){return{(x.l+l)%mod,x.d+d};}zet_p operator*(zet_p x){return{(int)((x.l*1ll*l)%mod),x.d*d};}
zet_p operator-(zet_p x){return{(l-x.l)%mod,d-x.d};}zet_p operator/(zet_p x){return{(int)((l*mpow(x.l,mod-2))%mod),d/x.d};}
};using frac_mod=zet_p;ostream&operator<<(ostream&ans,zet_p x){rans<<"["<<x.d<<":=="<<(x.l+mod)%mod<<"]";}

	<<boolalpha,::id1(x)

	<<boolalpha,::SIc7iN(
id7>void SIc7iN(const char*s, T x) {cerr<<s<<" = "<<x<<dec<<"\033[0m"<<endl;}id7,class...N>void SIc7iN(const char*s,T x,N...y){int d=0;
	while(*s){if(*s=='(')d++;ei(*s==')')d--;if(*s==','&&!d)break;cerr<<*s++;}cerr<<" = "<<x<<"; ";SIc7iN(s+1, y...);}

void id1(){cerr<<dec<<"\033[0m"<<endl;}id7,class...U>void id1(T x,U...y){cerr<<x<<"; ";id1(y...);}vector<stringstream>id8;struct
id6{id6(){id8.EB();}~id6(){id8.pb();}};const bool deb=1;void id4(int l,string fun){cerr<<"\033[1mSTACK "
"TRACE from ["<<fun<<"
void Co8VcQ(T x,C...y){id8.back()<<boolalpha<<x<<' ';Co8VcQ(y...);}

	exit(-1),0)



	"]\033[0m\033[1;"<<30+(l/8+l*3)%8<<"m ",::Co8VcQ(c)

int v;int get(){return v>=0?v:v+mod;}zet_p(LL x=0){v=x%mod;}zet_p operator+(zet_p x){return (v+x.v)%mod;}zet_p operator-(zet_p x){return
v-x.v;}zet_p operator*(zet_p x){return v*1ll*x.v;}zet_p operator/(zet_p a){return v*mpow(a.v,mod-2);}zet_p operator-(){return -v;}};struct
frac_mod {int n,d;frac_mod(int x=0){n=x%mod;d=1;}frac_mod(int x,int y){n=x;d=y;}frac_mod operator+(frac_mod x){return {(int)((x.d*1ll*n+d*
1ll*x.n)%mod),x.d*d%mod};}frac_mod operator-(frac_mod x){return {(int)((n*1ll*x.d-x.n*1ll*d)%mod),x.d*d%mod};}frac_mod operator*(frac_mod
x){return{(int)((n*(LL)x.n)%mod),(int)((d*(LL)x.d)%mod)};}frac_mod operator/(frac_mod x){return{(int)(n*(LL)x.d%mod),(int)(d*(LL)x.n%mod)}
;}int get(){int ans=n*mpow(d,mod-2)%mod;if(ans<0)ans+=mod;rans;}frac_mod operator-(){return{n,-d};}};mYInQ(frac_mod,+)mYInQ(frac_mod,-)
mYInQ(frac_mod,*)mYInQ(frac_mod,/)
const bool deb = false;






id7,class C>ostream&operator<<(ostream&ans,pair<T,C>x){rans<<"<"<<x.f<<", "<<x.s<<">";}id7>auto operator<<(ostream&o,T x)->typename
enable_if<!is_same<T,string>::value,decltype(x.end(),o)>::type{o<<"{";int i=0;for(auto c:x){if(i++==siz(x)-1||siz(x)<CON_BOUND+2||
i<CON_BOUND){if(i-1&&(i!=siz(x)||siz(x)<CON_BOUND+2))o<<", ";o<<c;}if(i==CON_BOUND&&siz(x)>CON_BOUND+1)o<<" ... ";}return o<<"}_"<<
x.size();}string b7Pe(string x){int dep=0;for(char c:x){for(char d:"([{")if(c==d)dep++;for(char d:"}])")if(c==d)dep--;for(char d:
"+-*/%^<>=&|?,")if(c==d&&!dep)return"("+x+")";}return x;}id7,class U>pair<U,T>pinv(pair<T,U>x){return MP(sf(x));}id7>struct Wt71{T c;int l,
r,L,R;};id7>ostream&operator<<(ostream&o,Wt71<T> M){o<<"\n";FOR(i,M.l,M.r){o<<"  "<<i<<": | ";FOR(j,M.L,M.R){o<<M.c[i][j]<<((j-M.L+1)%5?
" ":"; ");}o<<"\n";}return o;}id7>Wt71<T>q9cX(T a,int i,int j,int k,int q){return{a,i,j,k,q};}id7>string id5(Wt71<T> M){stringstream o;
FOR(i,M.l,M.r){o<<"  "<<i<<": | ";FOR(j,M.L,M.R){o<<id5(M.c[i][j])<<((j-M.L+1)%5?" ":"; ");}o<<"\n";}return o.str();}

MP(x.f o y.f,x.s o y.s);}id7,class B,class C>auto operator o(pair<T,B>x,C y)->pair<decltype(x.f o y),decltype(x.s o y)>{return MP(x.f o \
y,x.s o y);}id7,class C,class D>auto operator o(T x,pair<C, D>y)->pair<decltype(x o y.f),decltype(x o y.s)>{return MP(x o y.f,x o y.s);}

	x.s o y.s;return x;}id7,class B,class C>pair<T,B>&operator o(pair<T,B>&x,C y){x.f o y;x.s o y;return x;}

	id7,class B> pair <T,B> operator o(pair<T,B>&x,int _){return MP(x.f o,x.s o);}

	typename remove_reference<decltype(o x.s)>::type>{return MP(fs(o x));}




int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,
167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,
367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,
587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,
811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997},big_primes[]={1307533217,
1336158883,1339172111,1367797777,1376837461,1399436671,1426555723,1440115249,1444635091,1489833511,1553111299,1562150983,1587763421,16103\
62631,1652547823,1666107349,1700759471,1782116627,1797182767,1810742293,1818275363,1892099449,1904152361,1919218501,1940311097,1944830939,
1968936763,1977976447,1985509517,1990029359},gens[]={1,2,3,5,2,11,3,14,19,11,17,32,30,34,29,19,34,31,63,33,5,63,53,58,40,83,21,18,99,33,
106,40,85,109,40,77,91,120,105,91,79,53,182,10,184,48,48,150,168,72,65,46,31,216,101,134,163,147,93,42,69,7,151,308,112,12,227,185,214,305
,163,234,154,316,3,11,233,390,271,173,82,407,13,135,414,391,177,293,426,432,337,281,385,103,95,152,12,371,390,77,532,34,287,73,308,493,258
,549,528,411,12,283,614,596,622,309,91,511,287,433,585,123,2,170,183,341,459,322,333,337,507,718,82,517,396,315,565,48,362,617,776,425,584
,231,578,395,127,27,506,435,727,659,697,385,290,109,430,422,344,849,513,453,852,920,152,482,653,271},big_gens[]={661761153,1315209189,2356\
49158,80905954,861543922,677870461,332266749,1192707557,820697698,93737534,1395132003,176849700,1113502216,860516128,1543755630,328298286,
1219407972,1407392293,733053145,400000570,1081174233,847228024,1516266762,83276926,500618997,44975430,47827763,1411328206,151880843,19696\
955};LL vbig_primes[]={1223771071LL,2557943639LL,4625922079LL,8465729693LL,16196062793LL,32628322457LL,64355194333LL,128143942897LL,25672\
8067087LL,512368953949LL,1024440714547LL,2048302681847LL,4096121499499LL,8192933500519LL,16384652744209LL,32768255472209LL,6553600783264\
9LL,131072225217863LL,262144391360893LL,524288060819213LL,1048576249040491LL,2097152266756471LL,4194304028438527LL,8388608209001387LL,
16777216572671047LL,33554432072300339LL,67108864903274897LL,134217728402776373LL,268435456069367221LL,536870912016065747LL};const int inf
=1e9,NONE=-1;const LL INF=3e18;const char*sc2="%d%d",*sc3="%d%d%d",*sc4="%d%d%d%d",*pr2="%d %d\n",*pr3="%d %d %d\n",*pr4="%d %d %d %d\n";
VI factor(int x){VI ans; for(int p=2;p*p<=x;++p)while(x%p==0){ans.PB(p);x/=p;}if(x>1)ans.PB(x);rans;}k66C(+)k66C(-)k66C(/)k66C(*)k66C(%)
k66C(&)k66C(|)k66C(^)k66C(&&)k66C(||)WilQ(++)WilQ(--)yB_A(+=)yB_A(-=)yB_A(*=)yB_A(/=)yB_A(%=)yB_A(^=)yB_A(&=)yB_A(|=)xUk2(*)xUk2(~)xUk2(!)
xUk2(-)mYInQ(zet_p,+)mYInQ(zet_p,-)mYInQ(zet_p,*)mYInQ(zet_p,/) void bef0re_submIT();id7>struct v_J;id7> v_J<T> nGT4(T w, string n,bool b);

	b7Pe(id0(x))+" "
	nGT4(x)o y;}id7, class N> auto operator o(v_J<T> x, N y) -> v_J<decltype(RPr(x) o y)> {return x o nGT4(y);}
id7>T RPr(v_J<T> x);id7>T RPr(T x);id7>struct v_J{T v;string t;bool m;v_J<T>mask(){return v_J<T>{v,t,true};}template<class N>auto operator
[](N x)->v_J<Gea0(v[RPr(x)])>{return nGT4<Gea0(v[RPr(x)])>(v[RPr(x)],t+"["+id0(x)+"]", 0);}};id7>v_J<T>nGT4(T w,string n,bool b){return
v_J<T>{w,n,b};}id7>v_J<T>nGT4(T w,string n){return nGT4(w,n,false);}id7>v_J<T>nGT4(T w){return v_J<T>{w};}id7>ostream&operator<<(ostream&
ans,v_J<T>x){rans<<x.t<<(siz(x.t)?" = ":"")<<(x.m?id5(x.v):id0(x.v));}id7> T RPr(v_J<T> x){return x.v;}id7> T RPr(T x){return x;}FIm(+)
id7> v_J<T> nGT4(v_J<T> ans,string c="",int m=0){rans;}FIm(-)FIm(/)FIm(*)FIm(%)FIm(>>)FIm(<<)FIm(&)FIm(|)FIm(^)FIm(&&)FIm(||)FIm(==)FIm(!=)
FIm(>)FIm(<)FIm(<=)FIm(>=)void freo(string name){if(!deb){freopen((name+".in").c_str(),"r",stdin);
freopen((name+".out").c_str(),"w",stdout);}}


























id7>auto operator<<(ostream &ans,T x)->typename enable_if<!is_same<T,char *>::value&&!is_same<T,const char*>::value,
	decltype(*x,ans)>::type {rans << "[" << *x << "]";}
id7>auto id5(T x)->typename enable_if<!is_same<T,char *>::value&&!is_same<T,const char*>::value,decltype(*x,string())>::type {
	return "["+id5(*x)+"]";}


const int MN = 507, MV = 1e5 + 44;
int Less[MN];
int more[MN];
int val[MN];
zet_p dp[MV];
int main() {
	debug("Read all complier warnings!!!!!  ");
	debug("Complied on: " __DATE__ " " __TIME__);
	debug("LONG LONGS!!!!!  ", fun1((int), imie(0xd1617all * 0x200f1LL)));	
	debug(imie(MN), "to small MN => Runtime Error on test", MN % 181); 
	cerr << setprecision(10); 
	

	int n, q;
	LL t;
	scanf("%d%d%lld", &n, &q, &t);
	FOR(i, 1, n) scanf("%d", val + i);
	REP(_, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		more[b] = a;
		Less[a] = b;
	}
	int seen = 0;
	VI coins;
	FOR(i, 1, n)
		if (Less[i] == 0) {
			VI vals;
			int wh = i;
			do {
				vals.PB(val[wh]);
				wh = more[wh];
			}
			while (wh);
			debug_imie(vals);
			seen += siz(vals);
			REP(i, siz(vals))
				t -= i * vals[i];
			int sum = 0;
			FORD(i, siz(vals) - 1, 0) {
				sum += vals[i];
				coins.PB(sum);
			}
		}
	debug_imie(coins, t);
	if (seen != n || t < 0)
		die("0");
	dp[0] = 1;
	for (int x : coins)
		FOR(i, 0, MV - x - 1)
			dp[i + x] += dp[i];
	printf("%d\n", dp[t].get());
	bef0re_submIT();
}
void bef0re_submIT() {
	
	print_stack();
	debug("Before submit:!!!!!!!!!!!!!!!!"); 
	debug(imie(MN), "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!  ");
	debug("LONG LONGS!!!!! ");
	debug("Check if m, n aren't misused  ");
	debug("Make sure output format is right (including YES/NO vs Yes/No vs Tak/Nie, newlines vs spaces)");
	debug("Run with n = 1");
	debug("Make sure two ints aren't multiplied to get a long long");
	debug("Read all compiler warnings");
	debug("Output enough digits after decimal point (%.20Lf)");
	debug("Hereby I confirm that I have done all above (Ctrl + D)");
	while (deb && getchar() != EOF);
	exit(0);
}
