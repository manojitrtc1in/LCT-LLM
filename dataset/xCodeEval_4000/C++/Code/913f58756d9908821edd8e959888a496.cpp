

























































































































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

ll powermod(ll a, ll b, ll m)
{
	if (b == 0) return 1;
	ull k = powermod(a, b / 2, m);
	k = k * k;
	k %= m;
	if (b & 1) k = (k * a) % m;
	return k;
}




bool isPrime(ull n, int iter = 5) 
{
    if (n < 4) return n == 2 || n == 3;
	if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 0; i < iter; i++) 
	{
        ull a = 2 + rand() % (n - 3);
        if (powermod(a, n - 1, n) != 1) return false;
    }
    return true;
}




struct Mint
{
	ll MOD = 1e9 + 7;
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
template<typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using reverse_pq = priority_queue<T, vector<T>, greater<T> >;
template<typename T> using matrix = vector<vector<T> >;
template<typename T> using rubik = vector<vector<vector<T> > >;






template<typename T> matrix<T> operator * (const matrix<T> &a, const matrix<T> &b) {
    if (SZ(a.x) == 0 || SZ(b.x) == 0) return matrix<T>(); 


    matrix<T> c(SZ(a.x), SZ(b[0]));
    FOR(i, 0, SZ(c.x) - 1) FOR(j, 0, SZ(c[0]) - 1)
    {
        FOR(k, 0, SZ(a[0]) - 1)
            c[i][j] += a[i][k] * b[k][j];
    }
    return c;
}

template<typename T> matrix<T> inverse(matrix<T> a) 
{
    assert(SZ(a.x) == SZ(a[0]));
    int n = SZ(a.x);

    FOR(i, 0, n - 1)
	{
        vector<T> tmp(n);
        tmp[i] = 1;
        a[i].insert(a[i].end(), tmp.begin(), tmp.end());
    }

    a.gauss();

    matrix<T> inv(n, n);
    FOR(i, 0, n - 1) FOR(j, 0, n - 1)
	{
        inv[i][j] = a[i][j+n];
    }
    return inv;
}















ld PI = 3.14159265358979323846;

ld eps = 1e-6;

ll M = 1e9 + 7;















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
	ll a, k;
	cin >> a >> k;
	deque<ll> C(a);
	cin >> C;
	SORT(C);
	map<ll, ll> s;
	for (auto &x : C) s[x]++;
	vec<ll> curr(a + 5);
	curr[0] = (s[0] > 0);
	FOR(i, 1, a)
	{
		curr[i] = curr[i - 1];
		if (s[i] != 0) curr[i]++;
	}
	ll mex = 0;
	FOR(i, 1, a)
	{
		ll lft = i - curr[i - 1];
		if (lft <= k)
		{
			mex = i;
		}
	}




	vec<ll> F;
	ll diff = max(0LL, mex);
	map<ll, ll> vst;
	for (auto &x : C)
	{
		if (vst[x]) continue;
		if (x < mex) continue;
		F.pb(s[x]);
		diff++;
		vst[x] = 1;
	}
	SORT(F);
	FOR(i, 0, F.size() - 1)
	{
		if (k >= F[i])
		{
			diff--;
			k -= F[i];
		}
		else break;
	}
	cout << diff - mex << '\n';


}

signed main()
{
	faster();
	Toggle()
		Process();
}















