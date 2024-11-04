

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

const int N = 50 + 7;

int n, m;
pt a[N], b[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d", &a[i].x, &a[i].y);
		--a[i].x, --a[i].y;
	}
	forn(i, m){
		scanf("%d%d", &b[i].x, &b[i].y);
		--b[i].x, --b[i].y;
	}
	return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool in(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < n;
}

vector<pair<pt, pt>> get(pt a[N], int x, vector<int> &ord){
	vector<char> used(m);
	vector<pair<pt, pt>> res;
	forn(y, m){
		vector<pt> cur;
		forn(i, m) if (!used[i])
			cur.pb(mp(abs(a[i].x - x) + abs(a[i].y - y), i));
		sort(all(cur));
		

		int p = cur[0].y;
		used[p] = true;
		ord.pb(p);
		int i = a[p].x, j = a[p].y;
		while (i != x || j != y){
			forn(k, 4){
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (in(ni, nj) && (ni != x || nj >= y) && abs(ni - x) + abs(nj - y) < abs(i - x) + abs(j - y)){
					res.pb(mp(mp(i, j), mp(ni, nj)));
					i = ni, j = nj;
					break;
				}
			}
		}
	}
	return res;
}

void solve() {
	forn(i, n){
		vector<int> ord1, ord2;
		auto fin = get(a, i, ord1);
		auto tmp = get(b, i, ord2);
		

		forn(j, m) if (ord1[j] != ord2[j]){
			int x = find(all(ord1), ord2[j]) - ord1.begin();
			int ni = i == 0 ? i + 1 : i - 1;
			fin.pb(mp(mp(i, x), mp(ni, x)));
			for (int k = x - 1; k >= j; --k) fin.pb(mp(mp(i, k), mp(i, k + 1)));
			for (int k = x; k > j; --k) fin.pb(mp(mp(ni, k), mp(ni, k - 1)));
			fin.pb(mp(mp(ni, j), mp(i, j)));
			ord1.erase(ord1.begin() + x);
			ord1.insert(ord1.begin() + j, ord2[j]);
		}
		if (sz(fin) + sz(tmp) >= 10800) continue;
		reverse(all(tmp));
		for (auto it : tmp) fin.pb(mp(it.y, it.x));
		printf("%d\n", sz(fin));
		for (auto it : fin)
			printf("%d %d %d %d\n", it.x.x + 1, it.x.y + 1, it.y.x + 1, it.y.y + 1);
		return;
	}
	assert(false);
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