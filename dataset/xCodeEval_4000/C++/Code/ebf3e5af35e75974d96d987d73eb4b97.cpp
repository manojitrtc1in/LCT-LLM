

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

int n, m, a, b;
int A[N], B[N];
int l[N];

bool read () {
	if (scanf("%d%d%d%d", &n, &m, &a, &b) != 4)
		return false;
	forn(i, n)
		scanf("%d", &A[i]);
	forn(i, m)
		scanf("%d", &B[i]);
	forn(i, m)
		scanf("%d", &l[i]);
	return true;
}

ld dist(int x, int y, int l){
	return sqrtl(sqr(li(x)) + sqr(li(a))) + sqrtl(sqr(li(a - b)) + sqr(li(x - y))) + l;
}

ld f(int i, int& pos){
	pos = -1;
	ld ans = INF64;
	forn(j, m){
		ld cur = dist(A[i], B[j], l[j]);
		if (cur < ans){
			ans = cur;
			pos = j;
		}
	}
	return ans;
}

void solve() {
	int l = 0, r = n - 2;
	int tmp;
	while (l < r - 1){
		int m = (l + r) / 2;
		if (f(m, tmp) < f(m + 1, tmp))
			r = m;
		else
			l = m;
	}
	while (l < n - 1 && f(l + 1, tmp) < f(l, tmp))
		++l;
	f(l, tmp);
	printf("%d %d\n", l + 1, tmp + 1);
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}