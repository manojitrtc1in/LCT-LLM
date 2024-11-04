

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

int n;
pair<li, li> a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%lld%lld", &a[i].x, &a[i].y);
	return true;
}

li prmn[N], sumn[N];
li prmx[N], sumx[N];

bool check(li d){
	int j = 0;
	forn(i, n){
		while (j < n && a[j].x - a[i].x <= 2 * d)
			++j;
		if (max(sumx[j], prmx[i]) - min(sumn[j], prmn[i]) <= 2 * d)
			return true;
	}
	return false;
}

void solve() {
	forn(i, n) a[i] = mp(2 * (a[i].x + a[i].y), 2 * (a[i].x - a[i].y));
	sort(a, a + n);
	
	prmn[0] = 4ll * INF;
	forn(i, n) prmn[i + 1] = min(prmn[i], a[i].y);
	sumn[n] = 4ll * INF;
	for (int i = n - 1; i >= 0; --i) sumn[i] = min(sumn[i + 1], a[i].y);
	
	prmx[0] = -4ll * INF;
	forn(i, n) prmx[i + 1] = max(prmx[i], a[i].y);
	sumx[n] = -4ll * INF;
	for (int i = n - 1; i >= 0; --i) sumx[i] = max(sumx[i + 1], a[i].y);
	
	li ans = -1;
	li l = 0, r = 4ll * INF;
	while (l <= r){
		li m = l + (r - l) / 2;
		if (check(m)){
			ans = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	

	printf("%.15Lf\n", ld(ans) / 2);
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