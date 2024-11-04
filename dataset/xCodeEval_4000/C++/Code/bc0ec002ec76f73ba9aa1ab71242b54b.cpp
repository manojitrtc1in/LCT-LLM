

#include <bits/stdc++.h>

using namespace std;

#define MULTITEST

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

const int N = 2021 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

vector<int> res;

void apply(int x){
	reverse(a, a + x);
	if (x > 1) res.pb(x);
}

void solve() {
	forn(i, n) if (a[i] % 2 != i % 2){
		puts("-1");
		return;
	}
	res.clear();
	for (int i = n - 1; i > 0; i -= 2){
		int pos1, pos2;
		pos1 = find(a, a + i + 1, i) - a;
		pos2 = find(a, a + i + 1, i - 1) - a;
		apply(pos1 + 1);
		pos1 = find(a, a + i + 1, i) - a;
		pos2 = find(a, a + i + 1, i - 1) - a;
		apply(pos2);
		pos1 = find(a, a + i + 1, i) - a;
		pos2 = find(a, a + i + 1, i - 1) - a;
		apply(pos2 + 2);
		pos1 = find(a, a + i + 1, i) - a;
		pos2 = find(a, a + i + 1, i - 1) - a;
		apply(3);
		pos1 = find(a, a + i + 1, i) - a;
		pos2 = find(a, a + i + 1, i - 1) - a;
		apply(i + 1);
	}
	printf("%d\n", sz(res));
	for (int x : res) printf("%d ", x);
	puts("");
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