

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

const int N = 300 + 7;

int n;
int a[N][N];
int b[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n) forn(j, n){
		scanf("%d", &a[i][j]);
		--a[i][j];
	}
	forn(i, n){
		scanf("%d", &b[i]);
		--b[i];
	}
	return true;
}

int pr[N];
int rev[N][N];
int ans[N];
int pos[N];

void solve() {
	forn(i, n) pr[b[i]] = i;
	forn(i, n) forn(j, n) rev[i][a[i][j]] = j;
	
	set<pt, less<pt>> bst;
	memset(ans, -1, sizeof(ans));
	memset(pos, -1, sizeof(pos));
	forn(i, n){
		bst.insert(mp(pr[i], i));
		forn(j, n){
			if (j == bst.begin()->y && sz(bst) == 1)
				continue;
			int x = (j == bst.begin()->y ? (++bst.begin())->y : bst.begin()->y);
			if (ans[j] == -1 || (rev[j][ans[j]] > rev[j][x])){
				ans[j] = x;
				pos[j] = i;
			}
		}
	}
	forn(i, n) if (pos[i] == -1)
		pos[i] = n - 1;
	forn(i, n)
		printf("%d ", pos[i] + 1);
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

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}