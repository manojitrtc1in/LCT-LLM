
























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












int a[100010];
ll b[100010];
vector<pii> pl[100110];
vector<pii> mn[100110];
pii eval[100110];
bool ev[100010];
bool incr[100100];
struct cmp{
	bool operator()(const int x, const int y) {
		ll valx = b[x];
		ll incx = pl[x].empty() ? 0 : pl[x].back().first;
		ll mulx = mn[x].empty() ? 0 : mn[x].back().first;

		ll valy = b[y];
		ll incy = pl[y].empty() ? 0 : pl[y].back().first;
		ll muly = mn[y].empty() ? 0 : mn[y].back().first;

		ll ax, bx;
		if (mulx == 0 || valx <= INF && incx + valx > mulx * valx){
			ax = valx + incx;
			bx = valx;
		}
		else {
			ax = mulx;
			bx = 1;
		}

		ll ay, by;
		if (muly == 0 || valy <= INF && incy + valy > muly * valy){
			ay = valy + incy;
			by = valy;
		}
		else {
			ay = muly;
			by = 1;
		}













		if (ax > bx && ay > by){
			ll t = min(ax / bx, ay / by);
			ax -= t * bx;
			ay -= t * by;
		}

		return ax * by > bx * ay;
	}
};
multiset<int, cmp> s;
int main()
{
	ios_base::sync_with_stdio(0);
	int k, n, m;
	cin >> k >> n >> m;
	FI(k) cin >> a[i], b[i] = a[i];
	FI(n){
		int t, j, b;
		cin >> t >> j >> b;
		--j;
		if (t == 1){
			ev[i] = true;
			eval[j] = max(eval[j], pii( b, i ));
		}
		else if (t == 2){
			pl[j].push_back({ b, i });
			incr[i] = true;
		}
		else if (t == 3){
			if (b != 1)
			mn[j].push_back({ b, i });
		}
	}
	FI(k){
		if (eval[i].first > a[i]){
			pl[i].push_back({eval[i].first - a[i], eval[i].second});
		}
		if (pl[i].empty() && mn[i].empty()) continue;
		sort(all(pl[i]));
		sort(all(mn[i]));
		s.insert(i);
	}
	vector<int> ans;

	while (!s.empty() && ans.size() < m){














		auto it = s.begin();
		int x = *it;
		s.erase(it);

		ll valx = b[x];
		ll incx = pl[x].empty() ? 0 : pl[x].back().first;
		ll mulx = mn[x].empty() ? 0 : mn[x].back().first;

		if (mulx == 0 || valx <= INF && incx + valx > mulx * valx){
			b[x] += pl[x].back().first;
			ans.push_back(pl[x].back().second);
			pl[x].pop_back();
		}
		else {
			ans.push_back(mn[x].back().second);
			mn[x].pop_back();
		}
		if (pl[x].empty() && mn[x].empty()) continue;
		s.insert(x);
	}
	cout << ans.size() << endl;
	vector<int> a, b, c;
	for (int x : ans){
		if (ev[x]){
			a.push_back(x);
		}
		else if (incr[x]){
			b.push_back(x);
		}
		else {
			c.push_back(x);
		}
	}
	for (auto v : { a, b, c }){
		for (auto x : v){
			cout << x + 1 << ' ';
		}
	}
	cout << endl;
	return 0;
}
