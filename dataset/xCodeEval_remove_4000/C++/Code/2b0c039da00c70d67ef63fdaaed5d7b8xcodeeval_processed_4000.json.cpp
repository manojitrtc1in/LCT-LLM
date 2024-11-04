



using namespace std;











typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();





void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



i64 n, k; i64 a[5001];
i64 dp[5001][2501][2];



void Input() {
	cin >> n; k = n / 2 + n % 2;
	for (i64 i=0; i<n; i++) {
	    for (i64 j=0; j<=k; j++) {
	        dp[i][j][0] = LINF;
	        dp[i][j][1] = LINF;
	    }
	}
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	if (n == 1) {cout << "0"; return;}
	if (n == 2) {
		if (a[0] == a[1]) cout << "1";
		else cout << "0"; return;
	}
	dp[0][1][1] = max(a[1] - a[0] + 1, 0LL);
	dp[1][1][1] = max(a[0] - a[1] + 1, 0LL) + max(a[2] - a[1] + 1, 0LL);
	dp[1][0][0] = 0; dp[0][0][0] = 0; dp[1][1][0] = dp[0][1][1];
	for (i64 i=2; i<n; i++) {
		for (i64 j=0; j<=k; j++) dp[i][j][0] = min(dp[i][j][0], min(dp[i-1][j][0], dp[i-1][j][1]));
		for (i64 j=1; j<=k; j++) {
			i64 tmp1 = dp[i-2][j-1][0], tmp2 = dp[i-2][j-1][1];
			

			tmp1 += max(a[i-1] - a[i] + 1, 0LL);
			if (i != n-1) tmp1 += max(a[i+1] - a[i] + 1, 0LL);
			tmp2 += max(min(a[i-2]-1, a[i-1]) - a[i] + 1, 0LL);
			if (i != n-1) tmp2 += max(a[i+1] - a[i] + 1, 0LL);
			

			dp[i][j][1] = min(dp[i][j][1], min(tmp1, tmp2));
		}
	}












	vi ans(k+1, LINF);
	for (i64 i=1; i<=k; i++) ans[i] = min(ans[i], min(dp[n-1][i][0], dp[n-1][i][1]));
	for (i64 i=0; i<n; i++) {
	    for (i64 j=0; j<=k; j++) {
	        dp[i][j][0] = LINF;
	        dp[i][j][1] = LINF;
	    }
	}
	reverse(a, a+n);
	dp[0][1][1] = max(a[1] - a[0] + 1, 0LL);
	dp[1][1][1] = max(a[0] - a[1] + 1, 0LL) + max(a[2] - a[1] + 1, 0LL);
	dp[1][0][0] = 0; dp[0][0][0] = 0; dp[1][1][0] = dp[0][1][1];
	for (i64 i=2; i<n; i++) {
		for (i64 j=0; j<=k; j++) dp[i][j][0] = min(dp[i][j][0], min(dp[i-1][j][0], dp[i-1][j][1]));
		for (i64 j=1; j<=k; j++) {
			i64 tmp1 = dp[i-2][j-1][0], tmp2 = dp[i-2][j-1][1];
			

			tmp1 += max(a[i-1] - a[i] + 1, 0LL);
			if (i != n-1) tmp1 += max(a[i+1] - a[i] + 1, 0LL);
			tmp2 += max(min(a[i-2]-1, a[i-1]) - a[i] + 1, 0LL);
			if (i != n-1) tmp2 += max(a[i+1] - a[i] + 1, 0LL);
			

			dp[i][j][1] = min(dp[i][j][1], min(tmp1, tmp2));
		}
	}
	for (i64 i=1; i<=k; i++) ans[i] = min(ans[i], min(dp[n-1][i][0], dp[n-1][i][1]));
	for (i64 i=1; i<=k; i++) cout << ans[i] << " ";
}



int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	Input(); TimerStart();
	Solve(); TimerStop();
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
	freopen("filename.inp", "r", stdin);
	freopen("filename.out", "w", stdout);
	
}

void TimerStart() {
	
	TimeStart = chrono::steady_clock::now();
	
}

void TimerStop() {
	
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	
}

void Exit() {
	TimerStop(); exit(0);
}



































































































































































































































































