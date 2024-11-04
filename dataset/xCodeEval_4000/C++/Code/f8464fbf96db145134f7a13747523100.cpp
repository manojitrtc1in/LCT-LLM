

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

const int N = 200 * 1000 + 13;

int n, m;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

struct node{
	li sum;
	int mn, ps;
};

node t[4 * N];

void push(int v, int l, int r){
	if (t[v].ps == -1)
		return;
	if (l + 1 < r){
		t[v * 2].ps = t[v].ps;
		t[v * 2 + 1].ps = t[v].ps;
	}
	t[v].sum = t[v].ps * li(r - l);
	t[v].mn = t[v].ps;
	t[v].ps = -1;
}

void merge(int v){
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
	t[v].mn = min(t[v * 2].mn, t[v * 2 + 1].mn);
}

void build(int v, int l, int r){
	t[v].ps = -1;
	if (l == r - 1){
		t[v] = {a[l], a[l], -1};
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	merge(v);
}

void upd(int v, int l, int r, int L, int R, int val){
	push(v, l, r);
	if (L >= R)
		return;
	if (l == L && r == R){
		t[v].ps = val;
		push(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2, l, m, L, min(m, R), val);
	upd(v * 2 + 1, m, r, max(m, L), R, val);
	merge(v);
}

int getnxt(int v, int l, int r, int L, int R, int val){
	push(v, l, r);
	if (L >= R)
		return -1;
	if (t[v].mn > val)
		return -1;
	if (l == r - 1)
		return l;
	int m = (l + r) / 2;
	int res = getnxt(v * 2, l, m, L, min(m, R), val);
	if (res == -1) res = getnxt(v * 2 + 1, m, r, max(m, L), R, val);
	else push(v * 2 + 1, m, r);
	merge(v);
	return res;
}

int getsum(int v, int l, int r, int L, int R, int &val){
	push(v, l, r);
	if (L >= R)
		return 0;
	if (l == L && r == R){
		if (l == r - 1){
			if (t[v].sum <= val){
				val -= t[v].sum;
				return 1;
			}
			return 0;
		}
		int res;
		int m = (l + r) / 2;
		if (max(t[v * 2].sum, t[v * 2].ps * li(m - l)) <= val){
			push(v * 2, l, m);
			val -= t[v * 2].sum;
			res = m - l + getsum(v * 2 + 1, m, r, m, R, val);
		}
		else{
			res = getsum(v * 2, l, m, L, m, val);
			push(v * 2 + 1, m, r);
		}
		merge(v);
		return res;
	}
	int m = (l + r) / 2;
	int res = getsum(v * 2, l, m, L, min(m, R), val);
	if (res == max(0, min(m, R) - L)) res += getsum(v * 2 + 1, m, r, max(m, L), R, val);
	else push(v * 2 + 1, m, r);
	merge(v);
	return res;
}

void solve() {
	build(1, 0, n);
	forn(i, m){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1){
			int l = getnxt(1, 0, n, 0, x, y);
			if (l != -1) upd(1, 0, n, l, x, y);
		}
		else{
			--x;
			int ans = 0;
			while (true){
				int l = getnxt(1, 0, n, x, n, y);
				if (l == -1) break;
				int val = getsum(1, 0, n, l, n, y);
				ans += val;
				x = l + val;
			}
			printf("%d\n", ans);
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