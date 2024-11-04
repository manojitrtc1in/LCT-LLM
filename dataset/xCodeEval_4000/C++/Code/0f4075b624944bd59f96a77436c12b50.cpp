

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

void solve() {
	vector<pt> pos1;
	vector<int> pos2;
	int mn = 0;
	vector<pt> ans;
	for (int i = n - 1; i >= 0; --i){
		if (a[i] == 0)
			continue;
		if (a[i] == 1){
			pos1.pb(mp(i, mn));
			ans.pb(mp(i, mn));
			++mn;
			continue;
		}
		if (a[i] == 2){
			if (!pos1.empty()){
				int x = pos1.back().y;
				pos1.pop_back();
				ans.pb(mp(i, x));
				pos2.pb(i);
				continue;
			}
			puts("-1");
			return;
		}
		if (a[i] == 3){
			if (!pos2.empty()){
				int x = pos2.back();
				pos2.pop_back();
				ans.pb(mp(i, mn));
				ans.pb(mp(x, mn));
				++mn;
				pos2.pb(i);
				continue;
			}
			if (!pos1.empty()){
				int x = pos1.back().x;
				pos1.pop_back();
				ans.pb(mp(i, mn));
				ans.pb(mp(x, mn));
				++mn;
				pos2.pb(i);
				continue;
			}
			puts("-1");
			return;
		}
	}
	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d %d\n", (n - it.y - 1) + 1, it.x + 1);
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