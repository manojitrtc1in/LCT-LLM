





 




































































































 










 


 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 


 
	using ll = long long;
	using ld = long double;
	using ull = unsigned long long;
	#define pb push_back
	#define eb emplace_back
	#define f first
	#define mp make_pair
	#define s second
	#define p pair
	#define all(C) C.begin(), C.end()
	#define Toggle() int N; cin>>N; cin.ignore(); while(N--)
	#define SZ(a) (ll)a.size()
	#define FOR(i,a,b) for (ll i=(ll)a; i<=(ll)b; i++)
	#define FOR2(i,a,b) for (ll i=(ll)a; i<=(ll)b; ++i)
	#define FORD(i,a,b) for (ll i=(ll)a; i>=(ll)b; i--)
	#define reset(C) memset(C,0,sizeof(C))
	#define vec vector
	#define Rubik(x) Matrix<vector<x> >
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 


 
using namespace std;
using namespace __gnu_pbds;


 










 
multiset<ll> LIS(vector<ll> A)
{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.upper_bound(A[i]);
		if (it != S.end()) S.erase(it);
	}
	return S;
}
 
multiset<ll> LSIS(vector<ll> A) 

{
	ll a = A.size();
	multiset<ll> S;
	multiset<ll>::iterator it;
	FOR(i, 0, a - 1)
	{
		S.insert(A[i]);
		it = S.lower_bound(A[i]);
		it++;
		if (it != S.end()) S.erase(it);
	}
	return S;
}



 
mt19937_64 Rng(chrono::steady_clock::now().time_since_epoch().count());
 
static const ll FIXED_RANDOM = Rng(); 

 
ll Rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(Rng);}
 



ll gcd(ll a, ll b) {if (a == 0) return(b); return(gcd(b % a, a));}
 
ll extGcd(ll a, ll b, ll& x, ll& y) 

{
	if(a==0)
	{
		x=0;y=1;
		return(b);
	}
	ll a1, b1, c, x1, y1, rst;
	a1 = b % a; b1 = a; c = b / a;
	rst = extGcd(a1, b1, x1, y1);
	x = y1 - c * x1; y = x1;
	return(rst);
}
 
ll powermod(ll a, ll b, ll mod)
{
    ll ans=1;
    a=a%mod;
    while(b>0)
    {
        if(b%2==1) ans=(ans*a)%mod;
        b=b/2;
        a=(a*a)%mod;
    }
    return ans;
}
 



ll calculateJacobian(long long a, long long n) 

{
    if (!a)
        return 0;

 
    ll ans = 1;
    if (a < 0)
    {
        a = -a; 

        if (n % 4 == 3)
            ans = -ans; 

    }
 
    if (a == 1)
        return ans;

 
    while (a)
    {
        if (a < 0)
        {
            a = -a;

            if (n % 4 == 3)
                ans = -ans;

        }
 
        while (a % 2 == 0)
        {
            a = a / 2;
            if (n % 8 == 3 || n % 8 == 5)
                ans = -ans;
 
        }
 
        swap(a, n);
 
        if (a % 4 == 3 && n % 4 == 3)
            ans = -ans;
        a = a % n;
 
        if (a > n / 2)
            a = a - n;
 
    }
 
    if (n == 1)
        return ans;
 
    return 0;
}

bool solovoyStrassen(ll p, int iterations) 

{
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;
 
    for (int i = 0; i < iterations; i++)
    {
        

        long long a = Rand(0, p - 1);
        long long jacobian = (p + calculateJacobian(a, p)) % p;
        long long mod = powermod(a, (p - 1) / 2, p);
 
        if (!jacobian || mod != jacobian)
            return false;
    }
    return true;
}
 


 
struct Mint
{
	ll MOD = 998244353;
	ll val;
	bool operator==(const Mint& other) {return val == other.val;}
	Mint operator+(const Mint& other) {ll res = val + other.val; while(res >= MOD) res -= MOD; while(res < 0) res += MOD; return Mint(res);}
	Mint operator-(const Mint& other) {ll res = val - other.val; while(res >= MOD) res -= MOD; while(res < 0) res += MOD; return Mint(res);}
	Mint operator*(const Mint& other) {return Mint((val * 1ll * other.val) % MOD);}
	Mint operator+=(const Mint& other) {val += other.val; while(val >= MOD) val -= MOD; while(val < 0) val += MOD; return val;}
	Mint operator-=(const Mint& other) {val -= other.val; while(val >= MOD) val -= MOD; while(val < 0) val += MOD; return val;}
	Mint operator*=(const Mint& other) {return val = (val * 1ll * other.val) % MOD;}
	Mint pow(ll y) {Mint z(1); Mint x(val); while(y > 0) {if(y % 2 == 1) z = z * x; x = x * x; y /= 2;} return z;}
	Mint operator/(const Mint& other) {return Mint(val) * Mint(other.val).pow(MOD - 2);}
	Mint() {val = 0;};
	Mint(ll x) {x %= MOD; while(x < 0) x += MOD; val = x;};
};
 
ostream& operator<<(ostream& out, const Mint& x) {return out << x.val;}
 


 
 


 
template<typename T> void getVector(T &a) {for (auto &x : a) cin >> x;}
template<typename T> void printVector(T &a) {for (auto &x: a) cout << x << ' ';}
template<typename T> void revrs(T &a) {reverse(a.begin(), a.end());}
template<typename T> void SORT(T &a) {sort(a.begin(), a.end());}
template<typename T> void SORTD(T &a) {sort(a.rbegin(), a.rend());}
#define SORTC(a, cmp) sort(a.begin(), a.end(), cmp)
template<typename T> T maxOf(T &a) {return max_element(a.begin(), a.end()) - a.begin();}
template<typename T> T minOf(T &a) {return min_element(a.begin(), a.end()) - a.begin();}
template<typename T> T Merge(T &a, T &b) {T c; merge(all(a), all(b), c.begin()); return c;}
template<typename T> void Fill(vector<T> &a, T k) {fill(a.begin(), a.end(), k);}
template<typename T> void Fill(deque<T> &a, T k) {fill(a.begin(), a.end(), k);}
template<typename T> void tlw(T &a) {for(int i=0; i<(sizeof(a)/sizeof(a[0])); i++) a[i] = tolower(a[i]);}
template<typename T> void tup(T &a) {for(int i=0; i<(sizeof(a)/sizeof(a[0])); i++) a[i] = toupper(a[i]);}
template<typename T> void Unique(T &a) {a.erase(unique(a.begin(), a.end()), a.end());}
template<typename T1, typename T2> ostream& operator<<(ostream& out, const p<T1, T2>& x) {return out << x.f << ' ' << x.s;}
template<typename T1, typename T2> istream& operator>>(istream& in, p<T1, T2>& x) {return in >> x.f >> x.s;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> istream& operator>>(istream& in, deque<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, deque<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> using treap = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using multitreap = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using reverse_pq = priority_queue<T, vector<T>, greater<T> >;
template<typename T> using matrix = vector<vector<T> >;
template<typename T> using rubik = vector<vector<vector<T> > >;
 



template<typename T> matrix<T> operator * (const matrix<T> &a, const matrix<T> &b) {
    if (SZ(a) == 0 || SZ(b) == 0) return matrix<T>(); 

 
    matrix<T> c(SZ(a), vec<ll> (SZ(b[0])));
    FOR(i, 0, SZ(c) - 1) FOR(j, 0, SZ(c[0]) - 1)
    {
        FOR(k, 0, SZ(a[0]) - 1)
            c[i][j] += a[i][k] * b[k][j];
    }
    return c;
}
 






const ll st_size = 1e6;

struct node {
    ll TREE[st_size * 2];
    ll range[st_size * 2];
    ll lazy[st_size], h;
    
    node() { refresh(); }
    
    void refresh() {
        h = sizeof(int) * 8 - __builtin_clz(st_size);

        FOR(i, 0, st_size-1) lazy[i] = 0;
        FOR(i, 0, 2*st_size-1) TREE[i] = 0;
        
        FOR(i, 0, st_size - 1) {
            range[i + st_size] = 1;
        }
        
        FORD(i, st_size - 1, 1) {
            range[i] = range[i << 1] + range[i << 1 | 1];
        }
    }
    
    void build(ll idx)
    {
        while (idx >>= 1)
        {
            TREE[idx] = lazy[idx] * range[idx] + TREE[idx << 1] + TREE[idx << 1 | 1];
        }
    }
    
    void update(ll l, ll r, ll num)
    {
        ll l0 = l += st_size, r0 = r += st_size;
        for (r++; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) apply(l++, num);
            if (r & 1) apply(--r, num);
        }
        build(l0); build(r0);
    }
    
    void apply(ll idx, ll num) 
    {
        TREE[idx] += num * range[idx];
        if (idx < st_size) lazy[idx] += num;
    }
    
    void push(ll idx)
    {
        for (int i = h; i > 0; --i) {
            int k = idx >> i;
            if (lazy[k] != 0) {
                apply(k << 1,     lazy[k]);
                apply(k << 1 | 1, lazy[k]);
            }
            lazy[k] = 0;
        }
    }
    
    ll query(ll l, ll r)
    {
        ll ans = 0;
        push(l += st_size), push(r += st_size);
        for (r++; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans += TREE[l++];
            if (r&1) ans += TREE[--r];
        }
        return ans;
    }
};



 


 
class BinoCoeff{
	ll M;
	ll frac[3000000];
	ll inv[3000000];
	
	public:
		BinoCoeff()
		{
			
		}
		
		BinoCoeff(ll x)
		{
			M = x;
			frac[0] = 1;
			inv[0] = 1;
			FOR(i, 1, 3000000)
			{
				frac[i] = frac[i - 1] * i % M;
			}
			inv[3000000] = powermod(frac[3000000], M - 2, M);
			FORD(i, 3000000, 1)
			{
				inv[i - 1] = inv[i] * i % M;
			}
		}
		
		ll nCr(ll n, ll r)
		{
			return ((frac[n] * inv[r]) % M) * inv[n - r] % M;
		}
};
 


 










 
ld PI = 3.14159265358979323846;
 
ld eps = 1e-6;
 
ll M = 998244353;
 










 
bool __isprime(ll x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	if (x == 3) return true;
	if (x % 3 == 0) return false;
	ll t = 1;
	for (ll i = 5; i * i <= x; i += 2 * (1 + t))
	{
		if (x % i == 0) return false;
		t = 1 - t;
	}
	return true;
}

void Process()
{
	ll a;
	cin >> a;
	vec<ll> C(a);
	cin >> C;
	vec<p<ll, ll> > ans;
	ll l = 0;
	ll curr = 0;
	ll turn = 1;
	FOR(i, 0, a - 1)
	{
		curr += turn * C[i];
		if (curr == 0)
		{
			ans.pb({l + 1, i + 1});
			curr = 0;
			turn = 1;
			l = i + 1;
		}
		else
		{
			turn *= -1;
			if (abs(curr) == 2)
			{
				if (curr / C[i] == 2)
				{
					ans.pb({l + 1, i - 1});
					ans.pb({i, i + 1});
				}
				else
				{
					ans.pb({l + 1, i});
					ans.pb({i + 1, i + 1});
				}
				turn = 1;
				l = i + 1;
				curr = 0;
			}
		}
	}
	if (curr != 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << ans.size() << '\n';
		for (auto &x : ans)
		{
			cout << x << '\n';
		}
	}
}

signed main()
{
	faster();
	Toggle()
		Process();
}
 














