



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

int n, k;
string s;

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

int dpl[N][2];
int dpr[N][2];

bool okl[N], okr[N];

int dp[N];

void solve() {
	reverse(all(s));
	
	memset(dpl, 0, sizeof(dpl));
	
	dpl[0][0] = 1;
	queue<int> lst;
	lst.push(0);
	
	int sum = 1;
	forn(i, n){
		if (!lst.empty() && i + 1 - k == lst.front()){
			sum = add(sum, -dpl[lst.front()][0]);
			lst.pop();
		}
		if (s[i] != 'B')
			dpl[i + 1][1] = sum;
		if (s[i] != 'W')
			dpl[i + 1][0] = add(dpl[i][0], dpl[i][1]);
		if (s[i] == 'B'){
			sum = 0;
			lst = queue<int>();
		}
		sum = add(sum, dpl[i + 1][0]);
		lst.push(i + 1);
	}
	
	memset(dpr, 0, sizeof(dpr));
	
	dpr[n][1] = 1;
	lst = queue<int>();
	lst.push(n);
	
	sum = 1;
	for (int i = n; i > 0; --i){
		if (!lst.empty() && i - 1 + k == lst.front()){
			sum = add(sum, -dpr[lst.front()][1]);
			lst.pop();
		}
		if (s[i - 1] != 'B')
			dpr[i - 1][1] = add(dpr[i][0], dpr[i][1]);
		if (s[i - 1] != 'W')
			dpr[i - 1][0] = sum;
		if (s[i - 1] == 'W'){
			sum = 0;
			lst = queue<int>();
		}
		sum = add(sum, dpr[i - 1][1]);
		lst.push(i - 1);
	}
	
	int prv = -1;
	forn(i, n){
		if (s[i] == 'B')
			prv = i;
		okl[i] = (prv < i - k + 1);
	}
	
	prv = n;
	for (int i = n - 1; i >= 0; --i){
		if (s[i] == 'W')
			prv = i;
		okr[i] = (prv > i + k - 1);
	}
	
	memset(dp, 0, sizeof(dp));
	forn(i, n){
		dp[i + 1] = add(dp[i + 1], mul(dp[i], s[i] == 'X' ? 2 : 1));
		if (okl[i]) dp[i + 1] = add(dp[i + 1], dpl[i - k + 1][0]);
	}
	
	int ans = 0;
	forn(i, n) if (okr[i])
		ans = add(ans, mul(dp[i], dpr[i + k][1]));
	
	printf("%d\n", ans);
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