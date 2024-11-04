



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

const int N = 150 + 7;

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

int dp[N][N];

void solve(){
	while (n > 1 && count(all(s[n - 1]), 'W') == 0)
		--n;
	
	forn(i, n + 1) forn(j, m) dp[i][j] = INF;
	dp[0][0] = 0;
	forn(i, n) forn(j, m) if (dp[i][j] < INF){
		if (i % 2 == 0){
			bool ok = true;
			forn(k, j) if (s[i][k] == 'W'){
				ok = false;
				break;
			}
			if (!ok) continue;
			int mx = j;
			fore(k, j, m) if (s[i][k] == 'W')
				mx = max(mx, k);
			fore(k, mx, m)
				dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + k - j + 1);
		}
		else{
			bool ok = true;
			fore(k, j + 1, m) if (s[i][k] == 'W'){
				ok = false;
				break;
			}
			if (!ok) continue;
			int mn = j;
			forn(k, j + 1) if (s[i][k] == 'W')
				mn = min(mn, k);
			forn(k, mn + 1)
				dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + j - k + 1);
		}
	}
	printf("%d\n", *min_element(dp[n], dp[n] + m) - 1);
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