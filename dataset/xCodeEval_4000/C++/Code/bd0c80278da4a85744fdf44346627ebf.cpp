

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

li a, b;

bool read () {
	if (scanf("%lld%lld", &a, &b) != 2)
		return false;
	return true;
}

bool check(li x){
	forn(_, 2){
		if ((a - 1) % x == 0 && (b - 1) % x == 0) return true;
		if ((a - 2) % x == 0 && b % x == 0) return true;
		if ((a - 1) % x == 0 && b % x == 0 && (b - 2) % x == 0) return true;
		swap(a, b);
	}
	return false;
}

void solve() {
	li s = (a + b) * 2ll - 4;
	vector<li> ans;
	for (li d = 1; d * d <= s; ++d) if (s % d == 0){
		if (check(d)) ans.pb(d);
		if (d != s / d && check(s / d)) ans.pb(s / d);
	}
	sort(all(ans));
	printf("%d", sz(ans));
	for (li d : ans) printf(" %lld", d);
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