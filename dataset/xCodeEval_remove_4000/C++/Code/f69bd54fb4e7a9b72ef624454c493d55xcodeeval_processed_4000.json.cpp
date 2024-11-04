        



























































































































































using namespace std;



using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;















typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;



template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;








using uint = unsigned int;
using ull = unsigned long long;




















template<class Fun> class id0 {
Fun fun_;
public:
    template<class T> explicit id0(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) id1(Fun &&fun) { return id0<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
static priority_queue<P, Q, R> U;
U = M;
out << "{ ";
while(!U.empty())
	out << U.top() << " ", U.pop();
return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
static queue<P> U;
U = M;
out << "{"; string sep;
while(!U.empty()){
	out << sep << U.front(); sep = ", "; U.pop();
}
return (out << "}");
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T> using matrix = vector<vector<T> >;
template<typename T> using rubik = vector<vector<vector<T> > >;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}




template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}





template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
	input >> data.x >> data.y;
	return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
	for (T& x : data)
		input >> x;
	return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
	output << "(" << data.x << "," << data.y << ")";
	return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
	for (const T& x : data)
		output << x << " ";
	return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
	__int128 n = x;
	if (n == 0) {
		output << "0";
		return output;
	}
	if (n < 0) {
		n = -n;
		output << "-";
	}
	string s;
	while (n) {
		s += '0' + (n%10);
		n /= 10;
	}
	reverse(all(s));
	cout << s;
	return output;
}


ll __pow(ll x, ll y, int M) {ll res = 1;while(y>0){if(y&1) res = (res*x)%M; y>>=1; x = (x*x)%M;}return res%M;}
ll __pow(ll x, ll y) {ll res = 1;while(y>0){if(y&1) res = (res*x); y>>=1; x = (x*x);}return res;}
int mi(int x, int M) {return __pow(x, M-2, M);}
ll gcd(ll a, ll b) {if(b==0) return a; return gcd(b, a % b);}
int add(int a, int b, int M) {return (a+b) % M;}
int mul(int a, int b, int M) {return (a*b) % M;}
int sub(int a, int b, int M) {return (a-b+M) % M;}
void umax(int &a, int b) {a = max(a, b);}
void umin(int &a, int b) {a = min(a, b);}




const int maxn = 2e5+7;
vi adj[maxn];



void solve()
{
	
	
	string s; cin>>s;
	
	int n = sz(s);
	
	vl pref(n+2,0);
	
	ll w,q; cin>>w>>q;
	
	const int mod = 9;
	for(int i=0;i<n;i++)
	{
		pref[i+1] = (pref[i]+(s[i]-'0'))%9;
	}
	
	
	

	vpl d;
	for(int i=w;i<=n;i++)
	{
		int p = (pref[i] - pref[i-w]+9)%mod;
		d.pb({p,i-w+1});
	}
	
	

	
	vl cnt(10,0);
	vpl xp1,xp2;
	for(int i=0;i<sz(d);i++)
	{
		if(cnt[d[i].f] == 0)
		{
			cnt[d[i].f]++;
			xp1.pb({d[i].f,d[i].s});
			
		}
		else if(cnt[d[i].f] == 1)
		{
			cnt[d[i].f]++;
			xp2.pb({d[i].f,d[i].s});
		}
	}
	
	

	
	
	
	
	
	while(q--)
	{
		ll l,r,k; cin>>l>>r>>k;
		
		ll pj = (pref[r] - pref[l-1]+mod)%mod;
		
		

		
		bool good = 0;
		for(int j=0;j<sz(xp1);j++)
		{
			ll y = (k - (xp1[j].f*pj)%mod+(ll)(9e17))%mod;
			
			

			
			

			if(xp1[j].f == y and cnt[xp1[j].f] == 2)
			{
				for(int r=0;r<sz(xp2);r++)
				{
					
					if(xp2[r].f == y)
					{
						cout<<xp1[j].s<<" "<<xp2[r].s<<"\n";
						good = 1;
						break;
					}
					
				}
			}
			else if(xp1[j].f == y)
				continue;
			if(cnt[y] == 0)
				continue;
			for(int r=0;r<sz(xp1) and !good;r++)
			{
				if(r == j)
					continue;
				
				if(xp1[r].f == y)
				{
					cout<<xp1[j].s<<" "<<xp1[r].s<<"\n";
					good = 1;
					break;
				}
				
				
				
			}
			
			if(good)
				 break;
		}
		
		if(!good)
		{
			cout<<-1<<" "<<-1<<"\n";
		}
		
	}
	
	
	
	
	
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);
        

        

        

        

        

	int T;
	T=1;
	cin>>T;
		

	while(T--)
	{
		solve();
		
		
	}
	
	
	
	
}


	