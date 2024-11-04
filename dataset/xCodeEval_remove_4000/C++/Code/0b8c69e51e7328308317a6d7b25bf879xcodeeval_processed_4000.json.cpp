









using namespace std;











typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();








void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



i64 n; vi a;
i64 dp[4000][2002][2];









void Input() {
	cin >> n; a.rsz(n*2);
	for (i64 i=0; i<n*2; i++) {
		string s; cin >> s; i64 N = s.size();
		a[i] += (s[N-3] - '0') * 100;
		a[i] += (s[N-2] - '0') * 10;
		a[i] += (s[N-1] - '0') * 1;
	}
	for (i64 i=0; i<4000; i++) {
		for (i64 j=0; j<2002; j++) {
			for (i64 k=0; k<2; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
}

void Solve() {
	dp[0][1][1] = a[0]; dp[0][0][0] = (1000 - a[0]) % 1000;
	for (i64 i=0; i<n*2-1; i++) {
		for (i64 j=0; j<=n; j++) {
			for (i64 k=0; k<2; k++) {
				if (dp[i][j][k] == INF) continue;
				if (k == 0) {
					dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k] + (1000 - a[i+1]) % 1000);
					if (dp[i][j][k] >= a[i+1]) dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k] - a[i+1]);
					else dp[i+1][j+1][1-k] = min(dp[i+1][j+1][1-k], a[i+1] - dp[i][j][k]);
				}
				else if (k == 1) {
					dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k] + a[i+1]);
					if (dp[i][j][k] >= (1000 - a[i+1]) % 1000) dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k] - (1000 - a[i+1]) % 1000);
					else dp[i+1][j][1-k] = min(dp[i+1][j][1-k], (1000 - a[i+1]) % 1000 - dp[i][j][k]);
				}
			}
		}
	}
	cout << fixed << setprecision(3) << (ld)min(dp[n*2-1][n][0], dp[n*2-1][n][1]) / 1000.0L;
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	

	
		Input(); TimerStart();
		Solve(); TimerStop();
	
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by 
	cout << "Current time: ";
	cout << (now->tm_year + 1900) << '-' 
	     << (now->tm_mon + 1) << '-'
	     <<  now->tm_mday << " | "
	     <<  now->tm_hour << ":"
	     <<  now->tm_min << ":"
	     <<  now->tm_sec
	     << "\n\n";
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
	
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


