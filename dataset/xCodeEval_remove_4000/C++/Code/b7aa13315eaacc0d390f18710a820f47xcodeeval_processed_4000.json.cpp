



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

bool dp[N][5];
int p[N][5];

void solve(){
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	forn(i, n) forn(j, 5) if (dp[i][j]){
		forn(k, 5){
			if (i == 0 || (a[i - 1] < a[i] && k > j)){
				p[i + 1][k] = j;
				dp[i + 1][k] = true;
			}
			if (i == 0 || (a[i - 1] > a[i] && k < j)){
				p[i + 1][k] = j;
				dp[i + 1][k] = true;
			}
			if (i == 0 || (a[i - 1] == a[i] && k != j)){
				p[i + 1][k] = j;
				dp[i + 1][k] = true;
			}
		}
	}
	
	forn(i, 5) if (dp[n][i]){
		int cur = i;
		vector<int> ans;
		for (int i = n; i > 0; --i){
			ans.pb(cur + 1);
			cur = p[i][cur];
		}
		reverse(all(ans));
		for (auto it : ans)
			printf("%d ", it);
		puts("");
		return;
	}
	
	puts("-1");
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