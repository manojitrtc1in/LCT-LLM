
#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
































































































#include <bits/stdc++.h>

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>

using namespace std;

#define ll long long
#define ull unsigned long long
#define itn int
#define endl edl
#define edl '\n'
#define R register
#define rr R ll
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fr front
#define re rear
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define mk make_pair
#define pk pop_back
#define bk back
#define db double
#define ld long double
#define mem(a,b) memset(a,b,sizeof(a));
#define mem0(x) memset(x,0,sizeof(x))
#define BI basic_string<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


#define SUM(p) accumulate(all(p), 0LL)
#define MIN(p) (*min_element(all(p)))
#define MAX(p) (*max_element(all(p)))
#define vi vector<ll> 
#define vvi vector<vector<vi>>
#define vpi vector<pll>
#define pq priority_queue<ll>  
#define pqg priority_queue<ll, vector<ll>, greater<ll> >  
#define ppq priority_queue<pll>  
#define ppqg priority_queue<pll, vector<pll>, greater<pll> >
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define con continue
#define trailing0 __buitlin_ctzll
#define leading0 __buitlin_clzll
#define binary1(x) __builtin_popcountll(x)
#define binary0(x) __lg(x) + 1 - binary1(x)
#define trailing1pos __builtin_ffs
#define TLE ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SPO(i) fixed<<setprecision(i)
#define sqr(x) (x)*(x)
#define daxie(s) transform(all(s), s.begin(), ::toupper)  
#define xiaoxie(s) transform(all(s), s.begin(), ::tolower)  
#define llen(s) int(s.length())
#define gg greater<int>()
#define edll cout<<edl
#define PI acos(-1)
#define falg flag
#define MOD(x) ((x%mod)+mod)%mod
#define ACACACAKAKAK Saitohimea__solve
#define rep(i, l, r) for (ll i = l; i <= (r); ++i)
#define per(i, r, l) for (ll i = r; i >= (l); --i)
#define i128 = __int128_t;

template <typename T> ll sz(const T &x) { return x.size(); }
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

inline void YES(){cout<<"YES"<<'\n';}
inline void NO(){cout<<"NO"<<'\n';}
inline void Yes(){cout<<"Yes"<<'\n';}
inline void No(){cout<<"No"<<'\n';}
inline void yes(){cout<<"yes"<<'\n';}
inline void no(){cout<<"no"<<'\n';}
inline void OUT(string s){cout<<s<<"\n";}
inline void OUT(ll x){cout<<x<<"\n";}
inline void OUT(char x){cout<<x<<"\n";}
inline void OUT(int x){cout<<x<<"\n";}
inline void vicin(vi &x,ll l,ll r){for(ll i=l;i<r;++i) cin >> x[i];}
inline void vicout(vi x){for(ll i=0;i<sz(x);++i) cout<<x[i]<<" ";}
inline ll bitnum(ll x){if(x == 0) return 1;return __lg(x) + 1;} 


inline ll lowbit(ll x) {return ((x)&(-x));}
inline ll qpow(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
mt19937 mrand(random_device{}()); 

constexpr ll mod=998244353;



int rnd(ll x) { return mrand() % x;}
inline ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
inline ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
inline float Mysqrt(float x){if(x==0) return 0;float result=x;float xhalf=0.5f*result;int i=*(int*)&result;i=0x5f375a86-(i>>1);
result=*(float*)&i;result=result*(1.5f-xhalf*result*result);result=result*(1.5f-xhalf*result*result);return 1.0f/result;}
bool isprimegenhao (ll x) {for (ll i = 2; i * i <= x; ++i) if (x % i == 0) return 0; return 1;}
namespace IO_Plus
{
    #define chargs 100000
    char obuf[1 << 21], *p3 = obuf;
    inline char gc () { static char buf[chargs], *p1 = buf, *p2 = buf; return p1 == p2 && (p2 = (p1 = buf) + fread (buf, 1, chargs, stdin), p1 == p2) ? EOF : *p1++; }
    inline void pc (char x) { putchar(x); }
    inline void read (char ch) { ch = gc (); }
    inline void read (char *s) { char ch = gc (); while (ch != ' ' && ch != '\n') *s++ = ch, ch = gc (); }
    inline void read (int &x) { x = 0; bool f = 0; char ch = gc (); while (ch < '0' || ch > '9') f |= ch == '-', ch = gc (); while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc (); x = f ? ~x + 1 : x; }
    inline void read (double &x) { x = 0; bool f = 0; char ch = gc (); while (ch < '0' || ch > '9') f |= ch == '-', ch = gc (); while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = gc (); if (ch == '.') { double tmp = 1; ch = getchar(); while(ch >= '0' && ch <= '9') tmp /= 10.0, x += tmp * (ch ^ 48), ch = gc (); } x = f ? -x : x; }
    inline void read (long long &x) { x = 0; bool f = 0; char ch = gc (); while (ch < '0' || ch > '9') f |= ch == '-', ch = gc (); while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc (); x = f ? ~x + 1 : x; }
    inline void print (char ch) { pc (ch); }
    inline void print (char *s) { while (*s) pc (*s++); }
    inline void print (int x) { static char c[11]; unsigned p = 0; if (x < 0) pc ('-'), x = ~x + 1; if (!x) { pc ('0'); return ; } while (x) c[++p] = x % 10 ^ 48, x /= 10; while (p) pc (c[p]), --p; }
    inline void print (double x, int y = 2) { static int mul[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}; if (x < -1e-12) pc ('-'), x = -x; x *= mul[y]; int x1 = (int)floor (x); if (x - floor(x) >= 0.5) ++x1; int x2 = x1 / mul[y], x3 = x1 - x2 * mul[y]; print (x2); pc ('.'); for (size_t i = 1; x3 * mul[i] < mul[y]; ++i) pc ('0'); print (x3); }
    inline void print (long long x) { static char c[20]; unsigned p = 0; if (x < 0) pc ('-'), x = ~x + 1; if (!x) { pc ('0'); return ; } while (x) c[++p] = x % 10 ^ 48, x /= 10; while (p) pc (c[p]), --p; }
    template <class T, class... U> inline void read (T &x, U &...t) { read (x), read (t...); }
    template <class T, class... U> inline void print (T x, U ...t) { print (x), print (t...); }
}
using namespace IO_Plus;
#define FNV_prime 16777619U
template<typename T>
struct myhash {
    size_t operator ()(const T& _Keyval) const {
        size_t ret, val = FNV_prime;
        unsigned char* p = (unsigned char*)&_Keyval;
        for (int i = 0; i < sizeof(T); i++) val ^= (size_t)p[i], val *= FNV_prime;
        ret = FNV_prime; p = (unsigned char*)&val;
        for (int i = 0; i < sizeof(size_t); i++) ret *= FNV_prime, ret ^= (size_t)p[i];
        return ret;
    }
};
template < typename A, typename B>
class mymap : public unordered_map<A, B, myhash<A>> {  };
inline void namuxipiluipo () {
    #ifdef ONLINE_JUDGE
    #else
        freopen("D:\\ntr.in","r",stdin);
        freopen("D:\\ntr.out","w",stdout);
    #endif
}
inline ll mmax(ll a,ll b) {if(a>b) return a; else return b;}
inline ll mmin(ll a,ll b){if(a<b) return a; else return b;}
inline ll aabs(ll a,ll b){if(a-b<0) return -(a-b); else return a-b;}

ll dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
constexpr ll inf = 0x3f3f3f3f;

constexpr ll maxn = 1e6 + 200;

ll fa[5000100];
inline ll find(ll x){if(x == fa[x]) return x;return fa[x] = find(fa[x]);}












inline void ACACACAKAKAK () {		

	

	

	

	


	

	

	

	

	

	

	

	



	

	

	

	

	

	

	


	

	



	

	int n;
	cin >> n;
	string s;
	cin >> s;

	vi id(n + 1);
	int cnt = 0;
	rep(i, 0, n - 1) if (s[i] == '2') id[i] = cnt++;
	if (cnt == 1 || cnt == 2) {
		NO();
		return;
	}

	YES();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) cout << 'X';
			else if (s[i] == '2' && s[j] == '2' && (id[i] + 1) % cnt == id[j])
				cout << '+';
			else if (s[i] == '2' && s[j] == '2' && (id[j] + 1) % cnt == id[i])
				cout << '-';
			else cout << '=';
		}
		edll;
	}
}
signed main () {TLE; namuxipiluipo(); int __; __ = 1;
    cin >> __;
    while (__-- > 0) Saitohimea__solve(); 
    return 0;}