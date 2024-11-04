

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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;

int n, m;
pt a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d", &a[i].x, &a[i].y);
		--a[i].x, --a[i].y;
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
	}
	return true;
}

int add(int a, int b){
	return ((a + b) % n + n) % n;
}

bool check(int x){
	set<pt> cur(a, a + m);
	forn(i, m){
		pt nw = mp(add(a[i].x, x), add(a[i].y, x));
		if (nw.x > nw.y) swap(nw.x, nw.y);
		if (!cur.count(nw))
			return false;
		cur.erase(nw);
	}
	return true;
}

void solve() {
	fore(i, 1, n) if (n % i == 0 && check(i)){
		puts("Yes");
		return;
	}
	puts("No");
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