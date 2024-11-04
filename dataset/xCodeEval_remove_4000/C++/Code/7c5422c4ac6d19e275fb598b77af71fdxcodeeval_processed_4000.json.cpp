


using namespace std;



















using PII=pair<int,int>;using VI=vector<int>;using LL=long long;using PLL=pair<LL,LL>;using LD=long double;using VPII=vector<PII>;using
PDD=pair<LD,LD>;using VPLL=vector<PLL>;using VVI=vector<VI>;using VPDD=vector<PDD>;using SI=set<int>;using SPII=set<PII>;using MII=map<int
,int>;using SLL=set<LL>;using MLL=map<LL,LL>;using QII=pair<PII,PII>;using VQII=vector<QII>;using ULL=unsigned long long;using VLL=vector<
LL>;using VULL=vector<ULL>;using PULL=pair<ULL,ULL>;using SULL=set<ULL>;using MULL=map<ULL,ULL>;using UI=unsigned int;using TII=pair<PII,
int>;using VTII=vector<TII>;using STII=set<TII>;using TLL=pair<PLL,LL>; using QLL=pair<PLL,PLL>;using VLD=vector<LD>;using SVI=set<VI>;
ULL randULL(){return((ULL)rand())^((ULL)rand()<<15)^((ULL)rand()<<30)^((ULL)rand()<<45)^((ULL)rand()<<60);}

RtKxUA(popc, __builtin_popcount)RtKxUA(ctz, __builtin_ctz)RtKxUA(clz, __builtin_clz)RtKxUA(bit_parity, __builtin_parity)



id8,class U>bool one_of(T x, U y){return x==y;}id8,class U,class...V>bool one_of(T x,U y,V...z){return x==y||one_of(x,z...);}id8>bool
diff(T _){return true;}id8,class...U>bool diff(T x,U...y){return!in(x,y...)&&diff(y...);}id8,class U>bool equal(T x,U y){return x==y;}
id8,class U,class...V>bool equal(T x,U y,V...z){return x==y&&equal(x,z...);}id8,class U>bool in_order(T x,U y){return x<=y;}id8,class U,
class...V>bool in_order(T x,U y,V...z){return x<=y&&in_order(y,z...);}id8,class U> bool id3(T x, U y) {return x < y;}id8,class U,
class...V>bool id3(T x,U y,V...z){return x<y&&id3(y,z...);}id8>void swap3(T &x, T&y, T&z){swap(x,y);swap(x,z);}id8>
pair<T,T>dup(T x){return MP(x,x);}id8>tri(T,T,T)thrice(T x){return MT(x,x,x);}












id8,class U,class V> T id5(const vector<T>&v,int i,U low,V high){if(i<0)return low;if(i>=siz(v))return high;return v[i];}
id8,class U> T safar(T *a, int i, U low) {if(i<0)return low;return a[i];}

o x)x=y;}id8,class U,class V>auto my_
,class V,class W>auto my_
id8,class U,class V>auto med(const T&a,const U&b,const V&c)->decltype(1?a:(1?b:c)){return my_min(my_max(a,b),my_max(my_min(a,b),c));}
namespace std{id8,class U>struct hash<pair<T,U>>{size_t operator()(const pair<T,U>&a)const{return(hash<T>()(a.first)*1420343LL^hash<U>()
(a.second)*923275LL)%1463984161;}};}cE7Ux(min,<)cE7Ux(max,>)id8>T brange(int l,int r){return~(~((T)0)<<(r-l+1))<<l;}id8>T brange(int l,int
r,int s){return (brange<T>(l,l+(r-l)/s*s-1)/brange<T>(0,s-1))|((T)1<<(l+(r-l)/s*s));}int CON_BOUND=10;








string id0(){return"";}id8>string id0(T x){stringstream os;os<<boolalpha<<x;return os.str();}id8,class...U>string id0(T x,U...y){
return id0(x)+", "+id0(y...);}string id6(bool x){return x?"true":"false";}id8>typename enable_if<is_integral<T>::value,string>::type
id6(T r){string a;FORD(i,8*sizeof(T)-1,0){if(i%5==4)a+='.';a+='0'+!!(((T)1<<i)&r);}return a;}id8,class C>string id6(pair<T,C>);id8>auto
id6(T x)->decltype(x.begin(),string()){string a="";for(auto c:x){if(siz(a))a+=", ";a+=id6(c);}return "{"+a+"}_"+to_string(siz(x));}id8,
class C>string id6(pair<T,C>x){return "<"+id6(x.f)+", "+id6(x.s)+">";}



void id2(){cerr<<dec<<"\033[0m"<<endl;}id8,class...U>void id2(T x,U...y){cerr<<x;id2(y...);}vector<stringstream>id9;struct
id7{id7(){id9.EB();}~id7() {id9.pop_back();}};const bool deb=true;void id4(int l,string fun){cerr<<
"STACK TRACE from ["<<fun<<":"<<l<<"]"<< endl;for(auto&x:id9)cerr<<"  "<<x.str()<<dec<<"\033[0m"<<endl;}void id10(){}id8,class...C>
void id10(T x,C...y){id9.back()<<x;id10(y...);}





const bool deb = false;





id8,class C>ostream&operator<<(ostream&os,pair<T,C>x){return os<<"<"<<x.f<<", "<<x.s<<">";}id8>auto operator<<(ostream&os,T x)->typename
enable_if<!is_same<T,string>::value,decltype(x.end(),os)>::type{os<<"{";int i=0;for(auto c:x){if(i++==siz(x)-1||siz(x)<CON_BOUND+2||
i<CON_BOUND){if(i-1&&(i!=siz(x)||siz(x)<CON_BOUND+2))os<<", ";os<<c;}if(i==CON_BOUND&&siz(x)>CON_BOUND+1)os<<" ... ";}return os<<"}_"<<
x.size();}string b7Pe(string x){int dep=0;for(char c:x){for(char d:"([{")if(c==d)dep++;for(char d:"}])")if(c==d)dep--;for(char d:
"+-*/%^<>=&|?,")if(c==d&&!dep)return"("+x+")";}return x;}id8,class U>pair<U,T>pinv(pair<T,U>x){return MP(sf(x));}






























	h(x), ")) = ", 







		k, 













MP(x.f o y.f,x.s o y.s);}id8,class B,class C>auto operator o(pair<T,B>x,C y)->pair<decltype(x.f o y),decltype(x.s o y)>{return MP(x.f o \
y,x.s o y);}id8,class C,class D>auto operator o(T x,pair<C, D>y)->pair<decltype(x o y.f),decltype(x o y.s)>{return MP(x o y.f,x o y.s);}

	x.s o y.s;return x;}id8,class B,class C>pair<T,B>&operator o(pair<T,B>&x,C y){x.f o y;x.s o y;return x;}

	id8,class B> pair <T,B> operator o(pair<T,B>&x,int _){return MP(x.f o,x.s o);}

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
=1e9,NONE=-1;const LL llinf=3e18;const char*sc2="%d%d",*sc3="%d%d%d",*sc4="%d%d%d%d",*pr2="%d %d\n",*pr3="%d %d %d\n",*pr4="%d %d %d %d\n";
VI factor(int x){VI ans; for(int p=2;p*p<=x;++p)while(x%p==0){ans.PB(p);x/=p;}if(x>1)ans.PB(x);return ans;}void fixmod(int &a,int m){a%=m;
if(a<0)a+=m;}VI get_vi(int l=-1){l+1||scanf("%d",&l);VI a(l);REP(i,l)scanf("%d",&a[i]);return a;}VPII id1(int l=-1){l+1||scanf("%d",&l
);VPII a(l);REP(i,l)scanf(sc2,fs(&a[i]));return a;}k66C(+)k66C(-)k66C(/)k66C(*)k66C(%)k66C(&)k66C(|)k66C(^)k66C(&&)k66C(||)WilQ(++)WilQ(--)
yB_A(+=)yB_A(-=)yB_A(*=)yB_A(/=)yB_A(%=)yB_A(^=)yB_A(&=)yB_A(|=)xUk2(*)xUk2(~)xUk2(!)xUk2(-)

const int MN = 1e5 + 44;


int t[MN], v[MN];
int main() {
	debug("Complied on: " __DATE__ " " __TIME__);
	debug("LONG LONGS!!!!!  ", funop((int), 0xd1617all, *, 0x200f1LL));
	debug(fun(factor, MN), range(primes, 6, 9), "to small MN => Runtime Error on test ", MN % 181);
	[](){}();
	

	set <pair <LL, int> > snows;
	LL decr = 0;
	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", v + i);
	REP(i, n)
		scanf("%d", t + i);
	REP(i, n) {
		snows.insert(MP(v[i] + decr, i));
		LL today = 0;
		while (!snows.empty() && snows.begin()->f - decr <= t[i]) {
			today += snows.begin()->f - decr;
			snows.erase(snows.begin());
		}
		today += t[i] * 1ll * siz(snows);
		decr += t[i];
		printf("%lld ", today);
		debug(name(snows));
	}
	printf("\n");
	
	debug(name(MN), "MAKE SURE IT IS RIGHT!!!!!!!!!!!!!!!!!!!!!!!!  ", nmask(MN));
	debug("LONG LONGI!!!!!  ", oper(111111 * 111111, ==, 111111LL * 111111LL), name((int)0xB060051A));
}
