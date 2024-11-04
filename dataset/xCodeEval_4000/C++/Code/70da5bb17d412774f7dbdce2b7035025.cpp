

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

int n;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	return true;
}

int ask(const vector<int> &l, const vector<int> &r){
	printf("? %d %d\n", sz(l), sz(r));
	for (int x : l) printf("%d ", x + 1);
	puts("");
	for (int x : r) printf("%d ", x + 1);
	puts("");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

vector<int> build(int l, int r){
	vector<int> res(r - l + 1);
	iota(all(res), l);
	return res;
}

void solve() {
	vector<int> res;
	forn(i, n - 1){
		int val = ask(build(0, i), {i + 1});
		if (val != 0){
			int L = 0, R = i;
			while (L < R){
				int m = (L + R) / 2;
				if (ask(build(0, m), {i + 1}) != 0)
					R = m;
				else
					L = m + 1;
			}
			forn(j, i + 1) if (j != L)
				res.pb(j);
			fore(j, i + 2, n) if (ask({i + 1}, {j}) == 0)
				res.pb(j);
			break;
		}
	}
	printf("! %d", sz(res));
	for (int x : res) printf(" %d", x + 1);
	puts("");
	fflush(stdout);
}

int main() {
#ifdef _DEBUG




	
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