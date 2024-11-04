



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

const int N = 1000 * 1000 + 13;
const int AL = 26;

int n, m, k;
string s;

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	m = sz(s);
	return true;
}

bool used[AL];

int lst[AL];
int dp[2 * N];

int add(int a, int b){
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

void solve() {
	memset(used, 0, sizeof(used));
	for (int i = m - 1; i >= 0; --i){
		if (used[s[i] - 'a'])
			break;
		used[s[i] - 'a'] = true;
	}
	memset(lst, -1, sizeof(lst));
	forn(i, m)
		lst[s[i] - 'a'] = i;
	vector<pt> bst;
	forn(i, k) if (!used[i])
		bst.pb(mp(lst[i], i));
	sort(all(bst));
	for (auto it : bst) if (!used[it.y] && sz(s) < n + m){
		s += ('a' + it.y);
	}
	while (sz(s) < n + m){
		s += s[sz(s) - k];
	}
	memset(dp, 0, sizeof(dp));
	memset(lst, -1, sizeof(lst));
	dp[0] = 1;
	forn(i, n + m){
		dp[i + 1] = mul(2, dp[i]);
		if (lst[s[i] - 'a'] != -1)
			dp[i + 1] = add(dp[i + 1], -dp[lst[s[i] - 'a']]);
		lst[s[i] - 'a'] = i;
	}
	printf("%d\n", dp[n + m]);
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