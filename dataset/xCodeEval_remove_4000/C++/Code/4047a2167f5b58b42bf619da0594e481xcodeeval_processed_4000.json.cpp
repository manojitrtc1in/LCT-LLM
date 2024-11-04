



using namespace std;













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

const int N = 100 + 7;

int n, m;
string s[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	static char buf[N];
	forn(i, n){
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}

void solve() {
	vector<vector<pt>> ans;
	auto apply = [&](const vector<pt> &val){
		for (auto it : val)
			s[it.x][it.y] = s[it.x][it.y] ^ '0' ^ '1';
	};
	function<void(int, int)> fix;
	fix = [&](int x, int y){
		int cnt = 0;
		forn(dx, 2) forn(dy, 2) cnt += s[x + dx][y + dy] == '1';
		if (cnt == 0){
			return;
		}
		if (cnt == 1){
			ans.pb({});
			forn(dx, 2) forn(dy, 2) if (s[x + 1 - dx][y + 1 - dy] == '0')
				ans.back().pb(mp(x + dx, y + dy));
			assert(sz(ans.back()) == 3);
			apply(ans.back());
			return fix(x, y);
		}
		if (cnt == 2){
			ans.pb({});
			forn(dx, 2) forn(dy, 2) if (s[x + dx][y + dy] == '0')
				ans.back().pb(mp(x + dx, y + dy));
			forn(dx, 2) forn(dy, 2) if (s[x + dx][y + dy] == '1' && sz(ans.back()) < 3)
				ans.back().pb(mp(x + dx, y + dy));
			assert(sz(ans.back()) == 3);
			apply(ans.back());
			return fix(x, y);
		}
		ans.pb({});
		forn(dx, 2) forn(dy, 2) if (s[x + dx][y + dy] == '1' && sz(ans.back()) < 3)
			ans.back().pb(mp(x + dx, y + dy));
		apply(ans.back());
		fix(x, y);
	};
	for (int i = 0; i + 1 < n; i += 2){
		forn(j, m - 1){
			if (s[i][j] == '0' && s[i + 1][j] == '0') continue;
			ans.pb({});
			forn(dx, 2) forn(dy, 2) if (s[i + dx][j + dy] == '1' && sz(ans.back()) < 3)
				ans.back().pb(mp(i + dx, j + dy));
			forn(dx, 2) if (s[i + dx][j + 1] == '0' && sz(ans.back()) < 3)
				ans.back().pb(mp(i + dx, j + 1));
			assert(sz(ans.back()) == 3);
			apply(ans.back());
		}
		fix(i, m - 2);
	}
	if (n & 1){
		for (int j = 0; j + 1 < m; j += 2)
			fix(n - 2, j);
		if (m & 1)
			fix(n - 2, m - 2);
	}
	assert(sz(ans) <= 3 * n * m);
	printf("%d\n", sz(ans));
	for (auto it : ans){
		for (auto jt : it)
			printf("%d %d ", jt.x + 1, jt.y + 1);
		puts("");
	}
	forn(i, n) forn(j, m) assert(s[i][j] == '0');
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}