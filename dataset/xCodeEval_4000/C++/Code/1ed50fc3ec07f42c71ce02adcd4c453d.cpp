        
























































































































#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iomanip>
#include <cstring>



using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
 
using namespace __gnu_pbds;
 
template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;




 
 
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")


#pragma GCC optimize("unroll-loops")
 
 
 
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define lim numeric_limits
using uint = unsigned int;
using ull = unsigned long long;
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define inf (1ll<<60)
#define debug(x) cerr<< #x <<" = "<<x<<"\n"
#define debug2(x,y) cerr<< #x <<" = "<<x<<" , "<< #y <<" = "<<y<<"\n"






template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
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
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
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
 
 
ll query(string s)
{
	cout<<"? "<<s<<endl;
	ll x; cin>>x;
	return x;
}
void solve()
{
	int n,m; cin>>n>>m;
	
	vpl edges;
	
	map<ll,ll> wt;
	
	string s = string(m,'0');
	
	
	for(int i=1;i<=m;i++)
	{
		if(i-2>=0)
			s[i-2] = '0';
		s[i-1] = '1';
		
		ll p = query(s);
		
		
		wt[i] = p;
		
		edges.pb({p,i});
		
	}
	
	sort(all(edges));
	
	
	if(m == 1)
	{
		
		cout<<"! "<<edges[0].f<<endl;
		return;
	}
	else if(n==2)
	{
		cout<<"! "<<edges[0].f<<endl;
		return;
	}
	
	int p1 = edges[0].s;
	int p2 = edges[1].s;
	
	ll psum = edges[0].f+edges[1].f;
	
	
	string a = string(m,'0');
	
	a[p1-1] = '1', a[p2-1]  = '1';
	int prev = -1;
	vpl good;
	
	
	trav(j,edges)
	{
		
		int i = j.s;
		if(i == p1 or i == p2)
			continue;
		
		

		

		

		

		
		a[i-1] = '1';
		
		ll x = query(a);
		
		if(x == psum+wt[i])
		{
			good.pb({wt[i],i});
			psum+=wt[i];
		}
		else
		{
			a[i-1]='0';
		}
		
		
		
		

		
		
	}
	
	

	

	

	

	

	

	
	
	cout<<"! "<<psum<<endl;
	
	
	
	
	
	
	
	
 
 
}
signed main()
	{
		std::ios::sync_with_stdio(false);
		cin.tie(0);
		cin.exceptions(cin.failbit);
        

        

        

        

        

		int T;
		T=1;
		

		

		while(T--)
		{
			solve();
			
 
		}
			
			
		
		
	}
 
 
	