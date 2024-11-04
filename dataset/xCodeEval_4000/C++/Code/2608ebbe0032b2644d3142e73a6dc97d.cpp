

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
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

int f[N];

void upd(int x){
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		++f[i];
}

int get(int x){
	int res = 0;
	for (int i = x; i < N; i |= i + 1)
		res += f[i];
	return res;
}

void solve() {
	li pr = 0;
	vector<li> prs;
	forn(i, n){
		pr += a[i];
		prs.pb(pr);
	}
	
	if (*min_element(all(prs)) < 0 || *max_element(all(prs)) != pr){
		puts("-1");
		return;
	}
	
	vector<li> xs = prs;
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	memset(f, 0, sizeof(f));
	
	li ans = 0;
	forn(i, n - 1){
		int x = lower_bound(all(xs), prs[i]) - xs.begin();
		ans += get(x + 1);
		upd(x);
	}
	printf("%lld\n", ans);
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