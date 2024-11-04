

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

const int N = 1000 * 1000 + 13;

int n, m, dx, dy;
pt a[N];

bool read () {
	if (scanf("%d%d%d%d", &n, &m, &dx, &dy) != 4)
		return false;
	forn(i, m)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

int cnt[N];
int pos[N], rpos[N];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	rpos[0] = 0;
	fore(i, 1, n)
		rpos[i] = (rpos[i - 1] + dx) % n;
	forn(i, n)
		pos[rpos[i]] = i;
 	forn(i, m)
 		++cnt[((a[i].y - pos[a[i].x] * li(dy)) % n + n) % n];
 	printf("%d %d\n", 0, int(max_element(cnt, cnt + n) - cnt));
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