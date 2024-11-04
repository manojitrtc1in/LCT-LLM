

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

const int N = 100 * 1000 + 13;

int n;
int a[N], b[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	return true;
}

bool check(int x){
	li sum1 = (x - n) * 100ll + accumulate(a, a + n, 0ll);
	forn(i, min(n, x / 4)) sum1 -= a[i];
	sum1 -= max(0, x / 4 - n) * 100ll;
	li sum2 = accumulate(b, b + n, 0ll);
	if (x - n < x / 4) forn(i, x / 4 - (x - n)) sum2 -= b[i];
	return sum1 >= sum2;
}

void solve() {
	sort(a, a + n);
	sort(b, b + n);
	int bst = INF;
	forn(rem, 4){
		int l = n / 4, r = INF / 4;
		while (l * 4 + rem < n) ++l;
		int res = -1;
		while (l <= r){
			int m = (l + r) / 2;
			if (check(m * 4 + rem)){
				res = m * 4 + rem;
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		bst = min(bst, res);
	}
	printf("%d\n", bst - n);
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