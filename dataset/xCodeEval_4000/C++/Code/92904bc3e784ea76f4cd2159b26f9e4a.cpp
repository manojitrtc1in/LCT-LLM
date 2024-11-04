

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 

#include <bits/stdc++.h>

using namespace std;




#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef unsigned long long uli;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 + 7;

int n, m, k;
vector<int> a[N], b[N];

bool read () {
	if (!(cin >> n >> m >> k))
		return false;
	forn(i, m){
		int p;
		cin >> p;
		a[i].resize(p);
		forn(j, p){
			cin >> a[i][j];
			--a[i][j];
		}
	}
	forn(i, k){
		int p;
		cin >> p;
		b[i].resize(p);
		forn(j, p){
			cin >> b[i][j];
			--b[i][j];
		}
	}
	return true;
}

uli nums[N];
uli A[N], B[N];

unordered_map<uli, int> mn;

void init(int l, int r, uli cur, int cnt){
	if (l == r){
		if (!mn.count(cur))
			mn[cur] = cnt;
		else
			mn[cur] = min(mn[cur], cnt);
		return;
	}
	init(l + 1, r, cur, cnt);
	init(l + 1, r, cur ^ A[l], cnt + 1);
}

int ans[N];

void brute(int l, int r, uli cur, int cnt){
	if (l == r){
		forn(i, k){
			auto it = mn.find(cur ^ B[i]);
			if (it != mn.end())
				ans[i] = min(ans[i], cnt + it->y);
		}
		return;
	}
	brute(l + 1, r, cur, cnt);
	brute(l + 1, r, cur ^ A[l], cnt + 1);
}

void solve() {
	forn(i, n) nums[i] = rnd64();
	forn(i, m){
		A[i] = 0;
		for (auto it : a[i]) A[i] ^= nums[it];
	}
	forn(i, k){
		B[i] = 0;
		for (auto it : b[i]) B[i] ^= nums[it];
	}
	mn.clear();
	forn(i, k) ans[i] = INF;
	init(m / 2, m, 0, 0);
	brute(0, m / 2, 0, 0);
	forn(i, k) cout << (ans[i] == INF ? -1 : ans[i]) << '\n';
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef MULTITEST
	int tc;
	cin >> tc;
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}