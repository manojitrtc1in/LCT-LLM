#include "bits/stdc++.h"






#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define foru(i , a , b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define ford(i , a , b) for(ll i = (ll)(a) ; i >= (ll)(b) ; i--)
#define ain(a , n) for(int i = 0 ; i < (int)n ; i++) cin >> a[i]
#define aout(a , n) for(int i = 0 ; i < (int)n ; i++) cout << a[i] << " "; cend
#define M 998244353ll
#define mp make_pair
#define mt make_tuple
#define cend cout << "\n"
#define all(x) x.begin() , x.end()
#define aout2(a , n , m) for(ll i = 0 ; i < n ; i++){for(ll j = 0 ; j < m ; j++){cout << a[i][j] << " ";} cout << endl;}
#define ain2(a , n , m) for(ll i = 0 ; i < n ; i++){for(ll j = 0 ; j < m ; j++){cin >> a[i][j];}}
#define ff first
#define ss second
#define sz(a) ((long long)(a).size())
#define mset(a , b) memset(a , b , sizeof(a))
#define pb push_back
#define endn '\n'
#define google cout << "Case #" << test_num << ": "
#ifdef PARTH
#define dbg(a) cerr << #a << ": "; _print(a); cerr << endl;
#else
#define dbg(a) 

#endif

using namespace std;
using namespace std::chrono;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef pair <ll , ll> pll;
typedef vector <pair <ll , ll>> vpll;
typedef vector <pair <int, int>> vpi;




void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}


template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



template <class T> T gcd(T a , T b) { while (a != 0) {T temp = a; a = b % a; b = temp;} return b;}
template <class T> T egcd(T a , T b , T &x , T &y) {T gcd , xt , yt; if (a == 0) {gcd = b; x = 0 , y = 1;} else {gcd = egcd(b % a , a , xt , yt); x = yt - (b / a) * xt; y = xt;} return gcd;}
template <class T> T expo(T base , T exp , T mod) {T res = 1; base = base % mod; while (exp > 0) {if (exp & 1)res = (res * base) % mod; exp = exp >> 1; base = (base * base) % mod;} return res;}
template <class T> T modinv(T a , T mod) {T x , y; egcd<T>(a , mod , x , y); while (x < 0) x += mod; while (x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod) {return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b) {return a > b;}
template <class T> ll maxpower(T a , T b) {ll ans = 0; while (a > 0 && a % b == 0) {ans++; a /= b;} return ans;}
template <class T> T mceil(T a, T b) {if (a % b == 0) return a / b; else return a / b + 1;}
template <class T> T lcm(T a, T b) {return (a * b) / gcd<T>(a, b);}
const ll infl = 1e18; const int inf = 1e9 + 5;





template<class T> class segtree_gcd {
public:
	int n;
	vector<T> t;
	vector<T> a;
	vector<T> lazy;
	T invalid;
	void push(int v, int tl, int tr, int tmid) {
		
		if(lazy[v] != 0) {
			t[v] = __gcd(t[v], lazy[v]);
			if(tl != tr) {
				lazy[2*v + 1] = __gcd(lazy[v], lazy[2*v + 1]);
				lazy[2*v + 2] = __gcd(lazy[v], lazy[2*v + 2]);
			}
			lazy[v] = 0;
		}
	}
	void build(int v, int l, int r){
		if(l == r){
			t[v] = a[l];
			return;
		}
		int mid = l + (r - l)/2;
		build(2*v + 1, l, mid);
		build(2*v + 2, mid + 1, r);
		t[v] = __gcd(t[2*v + 1], t[2*v + 2]);
	}
	T sum(int l, int r, int v, int tl, int tr){
		if(l > r) return invalid;
		int tmid = tl + (tr - tl)/2;
		push(v, tl, tr, tmid);
		if(l == tl and r == tr) return t[v];
		return __gcd(sum(l, min(r, tmid), 2*v + 1, tl, tmid), sum(max(l, tmid + 1), r, 2*v + 2, tmid + 1, tr));
	}
	void update(int l, int r, T val, int v, int tl, int tr){
		int tmid = tl + (tr - tl)/2;
		push(v, tl, tr, tmid);
		if(l > r) {
			return;
		}
		if(l == tl and r == tr) {
			lazy[v] = __gcd(lazy[v], val);
			push(v, tl, tr, tmid);
		}
		else{
			update(l, min(r, tmid), val, 2*v + 1, tl, tmid);
			update(max(l, tmid + 1), r, val, 2*v + 2, tmid + 1, tr);
			t[v] = __gcd(t[2*v + 1], t[2*v + 2]);
		}
	}
	segtree_gcd(int si, T inv){
		n = si;
		t.resize(4*si);
		lazy.resize(4*si);
		a.resize(si);
		invalid = inv;
	}
	void build() {
		build(0, 0, n - 1);
	}
	void update(int l, int r, T val) {
		update(l, r, val, 0, 0, n - 1);
	}
	T sum(int l, int r) {
		return sum(l, r, 0, 0, n - 1);
	}
};



template<class T> class segtree_sum {
public:
	int n;
	vector<T> t;
	vector<T> a;
	vector<T> lazy;
	T invalid;
	void push(int v, int tl, int tr, int tmid) {
		
		if(lazy[v] != 0) {
			t[v] = (tr - tl + 1)*lazy[v];
			if(tl != tr) {
				lazy[2*v + 1] = lazy[v];
				lazy[2*v + 2] = lazy[v];
			}
			lazy[v] = 0;
		}
	}
	void build(int v, int l, int r){
		if(l == r){
			t[v] = a[l];
			return;
		}
		int mid = l + (r - l)/2;
		build(2*v + 1, l, mid);
		build(2*v + 2, mid + 1, r);
		t[v] = t[2*v + 1] + t[2*v + 2];
	}
	T sum(int l, int r, int v, int tl, int tr){
		if(l > r) return invalid;
		int tmid = tl + (tr - tl)/2;
		push(v, tl, tr, tmid);
		if(l == tl and r == tr) return t[v];
		return sum(l, min(r, tmid), 2*v + 1, tl, tmid) + sum(max(l, tmid + 1), r, 2*v + 2, tmid + 1, tr);
	}
	void update(int l, int r, T val, int v, int tl, int tr){
		int tmid = tl + (tr - tl)/2;
		push(v, tl, tr, tmid);
		if(l > r) {
			return;
		}
		if(l == tl and r == tr) {
			lazy[v] = val;
			push(v, tl, tr, tmid);
		}
		else{
			update(l, min(r, tmid), val, 2*v + 1, tl, tmid);
			update(max(l, tmid + 1), r, val, 2*v + 2, tmid + 1, tr);
			t[v] = t[2*v + 1] + t[2*v + 2];
		}
	}
	segtree_sum(int si, T inv){
		n = si;
		t.resize(4*si);
		lazy.resize(4*si);
		a.resize(si);
		invalid = inv;
	}
	void build() {
		build(0, 0, n - 1);
	}
	void update(int l, int r, T val) {
		update(l, r, val, 0, 0, n - 1);
	}
	T sum(int l, int r) {
		return sum(l, r, 0, 0, n - 1);
	}
};

struct edge {
	ll l;
	ll r;
	ll w;
};
bool cmp(edge a, edge b) {
	return a.w > b.w;
}

template <class T> class segtree{
public:
	vector <T> tree;
	vector <T> a;
	T invalid;
	T combine(T a, T b);
	void build(int vertex, int left, int right){
		if(left == right){
			tree[vertex] = a[left];
			return;
		}
		int mid = left + (right - left)/2;
		build(2*vertex + 1, left, mid);
		build(2*vertex + 2, mid + 1, right);
		tree[vertex] = combine(tree[2*vertex + 1], tree[2*vertex + 2]);
	}
	T sum(int left, int right, int vertex, int tleft, int tright){
		if(left > right) return invalid;
		if(left == tleft and right == tright) return tree[vertex];
		int tmid = tleft + (tright - tleft)/2;
		return combine(sum(left, min(right, tmid), 2*vertex + 1, tleft, tmid), sum(max(left, tmid + 1), right, 2*vertex + 2, tmid + 1, tright));
	}
	void update(int pos, T val, int vertex, int tleft, int tright){
		if(tleft == tright) {
			tree[vertex] = val;
		}
		else{
			int tmid = tleft + (tright - tleft)/2;
			if(pos <= tmid) update(pos, val, 2*vertex + 1, tleft, tmid);
			else update(pos, val, 2*vertex + 2, tmid + 1, tright);
			tree[vertex] = combine(tree[2*vertex + 1], tree[2*vertex + 2]);
		}
	}
	segtree(int si, T inv){
		tree.resize(4*si);
		a.resize(si);
		invalid = inv;
	}
};
template <class T> inline T segtree<T>::combine(T a, T b){
	return __gcd(a, b);
}




























	
	
















	




























 














template<class T> class SparseTable {
public:
	const int LOGN = 25;
	int n;
	vector<vector<T>> sparse;
	vector<int> logs;
	vector<T> a;

	SparseTable(int num) {
		n = num;
		sparse.assign(n, vector<T>(LOGN + 1));
		a.resize(n);
		logs.resize(n + 1);
	}

	void build() {
		logs[1] = 0;
		for(int i = 2; i <= n; i++) {
			logs[i] = logs[i/2] + 1;
		}
		for(int i = 0; i < n; i++) {
			sparse[i][0] = a[i];
		}
		

		for(int j = 1; j <= LOGN; j++) {
			for(int i = 0; i + (1 << j) - 1 < n; i++) {
				sparse[i][j] = __gcd(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
			}
		}
		

	}

	T query(int l, int r) {
		int j = logs[r - l + 1];
		return __gcd(sparse[l][j], sparse[r - (1 << j) + 1][j]);
	}
};

void test_case(int test_num) {
	ll n, p; cin >> n >> p;
	vector<ll> a(n);
	

	

	SparseTable<long long> st(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		st.a[i] = a[i];
	}
	st.build();
	

	vector<edge> intervals(n);
	for(int i = 0; i < n; i++) {
		int low = i, high = n - 1;
		int right = i;
		while(low <= high) {
			int mid = (low + high)/2;
			ll g = st.query(i, mid);
			vll temp = {i, mid, g};
			dbg(temp)
			if(g == a[i]) {
				right = mid;
				low = mid + 1;
			}	
			else {
				high = mid - 1;
			}
		}
		low = 0, high = i;
		int left = i;
		while(low <= high) {
			int mid = (low + high)/2;
			ll g = st.query(mid, i);
			vll temp = {mid, i, g};
			dbg(temp)
			if(g == a[i]) {
				left = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		intervals[i] = {left, right, min(p, a[i])};
	}
	sort(all(intervals), cmp);
	vll ans(n - 1, -1);
	

	segtree_sum<ll> stree2(n - 1, 0);
	for(int i = 0; i < n; i++) {
		ll l = intervals[i].l;
		ll r = intervals[i].r;
		r--;
		if(l > r) {
			continue;
		}
		stree2.update(l, r, intervals[i].w);
	}
	ll out = 0;
	for(int i = 0; i < n - 1; i++) {
		ll sum = stree2.sum(i, i);
		if(sum == 0) {
			out += p;
		}
		else {
			out += sum;
		}
	}
	cout << out << endn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifdef PARTH
	FILE* inp = freopen("input.txt", "r", stdin);
	FILE* err = freopen("error.txt", "w", stderr);
	FILE* out = freopen("output.txt", "w", stdout);
#endif
	int _;
	_ = 1;
	cin >> _;
	auto start = high_resolution_clock::now();
	cout << setprecision(15);
	for (int t = 1; t <= _; t++) {
		test_case(t);
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
#ifdef PARTH
	cerr << "Time: " << duration.count() / 1000.0 << endl;
#endif
	return 0;
}