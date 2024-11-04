
























using namespace std;








using namespace std::tr1;


































double __begin;



typedef unsigned long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(){};triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};


template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else return t1.b<t2.b;}
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }





















































inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));return((x >> 16) | (x << 16));}
inline int sign(int x){return (x >> 31) | (-x >> 31);}
inline bool id0(int x){return (x!=0 && (x&(x-1))==0);}







template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";cout<<endl;}








inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(int a,int b){return a/gcd(a,b)*(ll)b;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}
inline ll lcm(ll a,ll b,ll c){return lcm(lcm(a,b),c);}
inline ll lcm(int a,int b,int c){return lcm(lcm(a,b),(ll)c);}

inline ll max(ll a,ll b){return (a>b)?a:b;}
inline int max(int a,int b){return (a>b)?a:b;}
inline double max(double a,double b){return (a>b)?a:b;}
inline ll max(ll a,ll b,ll c){return max(a,max(b,c));}
inline int max(int a,int b,int c){return max(a,max(b,c));}
inline double max(double a,double b,double c){return max(a,max(b,c));}
inline ll min(ll a,ll b){return (a<b)?a:b;}
inline int min(int a,int b){return (a<b)?a:b;}
inline double min(double a,double b){return (a<b)?a:b;}
inline ll min(ll a,ll b,ll c){return min(a,min(b,c));}
inline int min(int a,int b,int c){return min(a,min(b,c));}
inline double min(double a,double b,double c){return min(a,min(b,c));}

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m;++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }













char a[1000200];
char b[1000200];
unsigned char aa[200200];
unsigned char bb[200200];
ull *al = (ull*)a;
ull *bl = (ull*)b;
char xx[8][200200], yy[8][200200];
struct trif{
	int a, b, c, d;
	trif(int _a, int _b, int _c, int _d){
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}
};
vector<trif> q[10][10];
int res[400001];
void make(ll *w, ll *s, int n, int z){
	for (int i = 0; i < n / 8; ++i){
		ll cur = s[i];
		ll prev = i ? s[i - 1] : 0;
		prev >>= 64 - z;
		w[i] = cur;
		w[i] <<= z;
		w[i] += prev;
	}
}
int cans[200010];

int main(){










































	gets(a);
	gets(b);
	char *sa = a;
	char *sb = b;
	int na = strlen(a);
	int nb = strlen(b);
	while (na & 63){
		a[na++] = '0';
	}
	while (nb & 63){
		b[nb++] = '0';
	}
	FI(64)
		a[na++] = '0',
		b[nb++] = '0';
	int qs;
	S(qs);
	for (int i = 0; i < qs; ++i){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		q[x & 7][y & 7].push_back(trif(x, y, z, i));
	}
	for (int i = 0; i < na; i += 8){
		uint t = 0;
		for (int j = 0; j < 8; ++j)
			if (a[i + j]=='1') t |= 1 << j;
		xx[0][i / 8] = t;
	}
	for (int i = 0; i < nb; i += 8){
		uint t = 0;
		for (int j = 0; j < 8; ++j)
			if (b[i + j]=='1') t |= 1 << j;
		yy[0][i / 8] = t;
	}
	na /= 8;
	nb /= 8;
	for (int st = 1; st < 8; ++st){
		make((ll*)xx[st], (ll*)xx[0], na, (8 - st) % 8);
		make((ll*)yy[st], (ll*)yy[0], nb, (8 - st) % 8);
	}
	for (int i = 0; i < 8; ++i){
		char *qx = xx[i];
		if (i > 0) ++qx;

		for (int j = 0; j < 8; ++j){
			char *qy = yy[j];
			if (j > 0) ++qy;

			for (int ps = 0; ps < q[i][j].size(); ++ps){
				trif p = q[i][j][ps];
				int bx = p.a;
				int by = p.b;
				int len = p.c;
				int ost = len & 63;
				len /= 64;
				bx /= 8;
				by /= 8;
				ll *x = (ll*)(qx + bx);
				ll *y = (ll*)(qy + by);
				int r = 0;
				for (int i = 0; i < len; ++i){
					r += bits_count(x[i]^y[i]);
				}
				len *= 64;
				for (int i = 0; i < ost; ++i){
					if (a[p.a + len + i] != b[p.b + len + i]){
						++r;
					}
				}
				res[p.d] = r;
				

			}
		}
	}
	for (int i = 0; i < qs; ++i){
		Prn(res[i]);
	}
	return 0;
}