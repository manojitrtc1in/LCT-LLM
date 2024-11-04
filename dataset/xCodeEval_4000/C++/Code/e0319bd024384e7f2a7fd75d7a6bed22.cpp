

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

const int N = 100 * 1000 + 13;

int n, m;
pair<int, pt> q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y.x);
		if (q[i].x == 2) scanf("%d", &q[i].y.y);
	}
	return true;
}

int t[4 * N];

void build(int v, int l, int r){
	if (l == r - 1){
		t[v] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build (v * 2 + 1, m, r);
	

	t[v] = t[v * 2] + t[v * 2 + 1];
}

void upd(int v, int l, int r, int pos, int val){
	if (l == r - 1){
		t[v] += val;
		return;
	}
	int m = (l + r) / 2;
	if (pos < m)
		upd(v * 2, l, m, pos, val);
	else
		upd(v * 2 + 1, m, r, pos, val);
	

	t[v] = t[v * 2] + t[v * 2 + 1];
}

int get(int v, int l, int r, int L, int R){
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	

	return get(v * 2, l, m, L, min(m, R)) + get(v * 2 + 1, m, r, max(m, L), R);
}

void solve() {
	bool rev = false;
	int cl = 0, cr = n;
	build(1, 0, n);
	forn(i, m){
		if (q[i].x == 1){
			if (q[i].y.x * 2 > cr - cl){
				rev ^= 1;
				q[i].y.x = (cr - cl) - q[i].y.x;
			}
			int len = q[i].y.x;
			if (!rev){
				forn(j, len)
					upd(1, 0, n, cl + len * 2 - j - 1, get(1, 0, n, cl + j, cl + j + 1));
				cl += len;
			}
			else{
				forn(j, len)
					upd(1, 0, n, cr - len * 2 + j, get(1, 0, n, cr - j - 1, cr - j));
				cr -= len;
			}
		}
		else{
			int l, r;
			if (!rev) l = cl + q[i].y.x, r = cl + q[i].y.y;
			else l = cr - q[i].y.y, r = cr - q[i].y.x;
			printf("%d\n", get(1, 0, n, l, r));
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