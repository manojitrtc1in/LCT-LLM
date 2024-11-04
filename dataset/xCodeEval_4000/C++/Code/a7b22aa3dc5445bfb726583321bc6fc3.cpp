

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
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		int x;
		scanf("%d", &x);
		a[i].x = x;
		a[i].y = true;
		while (x){
			a[i].y &= x % 10 == 4 || x % 10 == 7;
			x /= 10;
		}
	}
	return true;
}

void solve() {
	bool ok = false;
	forn(i, n) ok |= a[i].y;
	if (!ok){
		bool fl = true;
		forn(i, n - 1) fl &= a[i].x <= a[i + 1].x;
		puts(fl ? "0" : "-1");
		return;
	}
	
	vector<pt> xs;
	forn(i, n) xs.pb(mp(a[i].x, i));
	sort(all(xs));
	forn(i, n) a[i].x = lower_bound(all(xs), mp(a[i].x, i)) - xs.begin();
	
	vector<pt> ans;
	int pos = -1;
	forn(i, n) if (a[i].y == 1) pos = i;
	
	vector<int> check;
	forn(i, n) check.pb(i);
	while (!check.empty()){
		int i = check.back();
		check.pop_back();
		if (i != a[i].x && i != pos){
			int x = a[i].x;
			if (x != pos){
				ans.pb(mp(pos, x));
				swap(a[pos], a[x]);
				check.pb(pos);
				pos = x;
			}
			ans.pb(mp(pos, i));
			swap(a[pos], a[i]);
			pos = i;
		}
	}
	
	assert(sz(ans) <= 2 * n);
	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d %d\n", it.x + 1, it.y + 1);
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