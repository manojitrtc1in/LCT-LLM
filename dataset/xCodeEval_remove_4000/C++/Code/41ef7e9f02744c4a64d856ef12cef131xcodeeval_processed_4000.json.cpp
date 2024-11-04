



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

const int N = 200 * 1000 + 13;

int n;
string s;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

int dp[N];

string al[] = {"RL", "RRL", "RLL", "RRLL"};

int diff(int i, int x){
	int res = 0;
	forn(j, sz(al[x])) res += s[i + j] != al[x][j];
	return res;
}

int get(){
	forn(i, n + 1) dp[i] = INF;
	dp[0] = 0;
	forn(i, n){
		if (i + 2 <= n) dp[i + 2] = min(dp[i + 2], dp[i] + diff(i, 0));
		if (i + 3 <= n) dp[i + 3] = min(dp[i + 3], dp[i] + diff(i, 1));
		if (i + 3 <= n) dp[i + 3] = min(dp[i + 3], dp[i] + diff(i, 2));
		if (i + 4 <= n) dp[i + 4] = min(dp[i + 4], dp[i] + diff(i, 3));
	}

	return dp[n];
}

void solve() {
	int ans = n;
	forn(i, 4){
		rotate(s.begin(), s.begin() + 1, s.end());
		ans = min(ans, get());
	}
	printf("%d\n", ans);
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
