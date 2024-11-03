









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



i64 n; vi a, dp, Next, vis;



void DFS(i64 z) {
	vis[z] = 2; if (z < n) dp[z] = a[z]; else dp[z] = a[z-n];
	if (Next[z] == -1) {vis[z] = 1; return;}
	if (vis[Next[z]] == 2 || Next[z] == 0) dp[z] = LINF;
	else {
		if (vis[Next[z]] == 0) DFS(Next[z]);
		dp[z] += dp[Next[z]];
		dp[z] = min(dp[z], LINF);
	}
	vis[z] = 1;
}

void Input() {
	cin >> n; a.rsz(n, -1);
	dp.rsz(n*2, 0); Next.rsz(n*2, -1); vis.rsz(n*2, 0);
	for (i64 i=1; i<n; i++) {
		cin >> a[i];
		if (i + a[i] < n) Next[i] = n+i+a[i];
		if (i - a[i] >= 0) Next[n+i] = i-a[i];
	}
}

void Solve() {
	for (i64 i=1; i<n*2; i++) {
		if (i == n) continue;
		if (vis[i] == 0) DFS(i);
	}
	for (i64 i=1; i<n; i++) {
		if (dp[n+i] == LINF) cout << "-1\n";
		else cout << dp[n+i] + i << endl;
	}
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
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


