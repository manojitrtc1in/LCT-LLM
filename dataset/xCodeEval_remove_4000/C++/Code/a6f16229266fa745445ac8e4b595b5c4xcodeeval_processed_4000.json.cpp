
























using namespace std;








using namespace std::tr1;


































double __begin;



typedef long long ll;
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
template<class T>
inline void cinarr(T a, int n){ for (int i=0;i<n;++i) cin >> a[i];}











char a[1010][1010];
int r[1010][1010]; 
int d[1010][1010];
vector<pii> v;
char draw[1010][1010];
int n, m;
int sx, sy;
bool check(int w, int h, vector<int> way){
	FI(n + 2)
		FJ(m + 2)
		draw[i][j] = '.';
	int x = sx;
	int y = sy;
	for (int i = x; i < x + h; ++i){
		for (int j = y; j < y + w; ++j){
			draw[i][j] = 'X';
		}
	}
	for (int t : way){
		if (t == 0)
		{
			for (int j = y; j < y + w; ++j){
				draw[x + h][j] = 'X';
				if (a[x + h][j] != 'X')
				{
					return false;
				}
			}
			++x;
		}
		else
		{
			for (int i = x; i < x + h; ++i){
				draw[i][y + w] = 'X';
				if (a[i][y + w] != 'X'){
					return false;
				}
			}
			++y;
		}
	}
	FI(n + 2)
		FJ(m + 2)
		if (draw[i][j] != a[i][j]) return false;
	return true;
}
int main()
{
	cin >> n >> m;
	FI(n + 2)
		FJ(m + 2)
		a[i][j] = '.';
	for (int i = 1; i <= n; ++i){
		cin >> (a[i] + 1);
		a[i][m + 1] = '.';
	}

	vector<int> way1;
	vector<int> way2;
	int qw(1), qh(1);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (a[i][j] == 'X'){
				sx = i;
				sy = j;
				int x = i;
				int y = j;
				while (a[x][y + 1] == 'X')++y, qw++;
				while (a[x][y] == 'X'){
					if (a[x][y + 1] == 'X') ++y, way1.push_back(1);
					else ++x, way1.push_back(0);
				}

				x = i;
				y = j;
				while (a[x + 1][y] == 'X') ++x, qh++;
				while (a[x][y] == 'X'){
					if (a[x+1][y] == 'X') ++x, way2.push_back(0);
					else ++y, way2.push_back(1);
				}


				goto next_try;
			}
		}
	}
next_try:
	int aw(1), ah(1);

	int minx = 1;
	int miny = 1;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (a[i][j] == 'X'){
				r[i][j] = r[i][j - 1];
				d[i][j] = d[i - 1][j];
				v.push_back({ j - r[i][j], i - d[i][j] });
				pii p = v.back();
				if (p.first > qw){
					aw = max(aw, p.second);
				}
				if (p.second > qh){
					ah = max(ah, p.first);
				}
			}
			else
				r[i][j] = j,
				d[i][j] = i;
		}
	}
	for (int i = 0; i < aw && !way1.empty(); ++i)
		way1.pop_back();
	for (int i = 0; i < ah && !way2.empty(); ++i)
		way2.pop_back();
	if (!check(qw, aw, way1)) qw = -1;
	if (!check(ah, qh, way2)) ah = -1;
	if (qw == -1 && ah == -1)
	{
		puts("-1");
	}
	else if (qw == -1 || ah != -1 && ah * qh < aw * qw)
	{
		cout << ah * qh << endl;
	}
	else
	{
		cout << qw * aw << endl;
	}
	return 0;
}
