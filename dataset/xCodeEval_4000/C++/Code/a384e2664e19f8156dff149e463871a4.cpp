

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

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 300 * 1000 + 13;

int n, logn, m;
int a[N];

bool read () {
	if (scanf("%d%d", &logn, &m) != 2)
		return false;
	n = 1 << logn;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

bool st[20];
li t[4 * N];

void build(int v, int l, int r){
	if (l == r - 1){
		t[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

void upd(int v, int i, int l, int r, int pos, int x){
	if (l == r - 1){
		t[v] = x;
		return;
	}
	int m = (l + r) / 2;
	if (pos < m){
		if (!st[i])
			upd(v * 2, i - 1, l, m, pos, x);
		else
			upd(v * 2 + 1, i - 1, l, m, pos, x);
	}
	else{
		if (!st[i])
			upd(v * 2 + 1, i - 1, m, r, pos, x);
		else
			upd(v * 2, i - 1, m, r, pos, x);
	}
	t[v] = t[v * 2] + t[v * 2 + 1];
}

li get(int v, int i ,int l, int r, int L, int R){
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	if (!st[i])
		return get(v * 2, i - 1, l, m, L, min(m, R)) + get(v * 2 + 1, i - 1, m, r, max(m, L), R);
	return get(v * 2 + 1, i - 1, l, m, L, min(m, R)) + get(v * 2, i - 1, m, r, max(m, L), R);
}

void solve() {
	memset(st, 0, sizeof(st));
	build(1, 0, n);
	forn(i, m){
		int t;
		scanf("%d", &t);
		if (t == 1){
			int x, k;
			scanf("%d%d", &x, &k);
			upd(1, logn, 0, n, x - 1, k);
		}
		else if (t == 2){
			int k;
			scanf("%d", &k);
			forn(j, k + 1) st[j] ^= 1;
		}
		else if (t == 3){
			int k;
			scanf("%d", &k);
			st[k + 1] ^= 1;
		}
		else{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", get(1, logn, 0, n, l - 1, r));
		}
	}
}

int main() {
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
	scanf("%d", &tc);
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