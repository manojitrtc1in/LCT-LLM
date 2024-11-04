



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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 500 + 7;

int n, k;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%d", &k);
	return true;
}

int dp[N][N];
int val[N][N];

void init(){
	forn(l, n) fore(r, l, n){
		val[l][r] = 0;
		int len = (r - l + 1);
		fore(i, l, l + len / 2)
			val[l][r] += (s[i] != s[r - (i - l)]);
	}
}

int p[N][N];

void get(string s){
	forn(i, sz(s) / 2)
		if (s[i] != s[sz(s) - i - 1])
			s[i] = s[sz(s) - i - 1];
	printf("%s", s.c_str());
}

void solve() {
	init();
	forn(i, N) forn(j, N) dp[i][j] = INF;
	dp[0][0] = 0;
	forn(l, n) forn(j, k) if (dp[l][j] < INF){
		fore(r, l, n) if (dp[r + 1][j + 1] > dp[l][j] + val[l][r]){
			dp[r + 1][j + 1] = dp[l][j] + val[l][r];
			p[r + 1][j + 1] = l;
		}
	}
	int bst = -1;
	forn(i, k + 1)
		if (bst == -1 || dp[n][bst] > dp[n][i])
			bst = i;
	int ans = dp[n][bst];
	vector<pt> res;
	int cur = n;
	for (int i = bst; i > 0; --i){
		res.pb(mp(p[cur][i], cur));
		cur = p[cur][i];
	}
	reverse(all(res));
	printf("%d\n", ans);
	forn(i, sz(res)){
		if (i) printf("+");
		get(s.substr(res[i].x, res[i].y - res[i].x));
	}
	puts("");
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}