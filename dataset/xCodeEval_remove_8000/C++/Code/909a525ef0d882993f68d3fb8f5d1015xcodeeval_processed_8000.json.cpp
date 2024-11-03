








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



i64 n, T; i64 p[5001], t[5001];
ld afterIntro[5001], maxStocked[5001];
ld dp[5001][5001];





void Input() {
	cin >> n >> T;
	for (i64 i=1; i<=n; i++) {
		cin >> p[i] >> t[i]; ld Last = 1.0;
		afterIntro[i] = 1.0; maxStocked[i] = 1.0;
		for (i64 x=1; x<t[i]; x++) {
			afterIntro[i] -= Last * p[i] / 100;
			maxStocked[i] *= (100 - p[i]); maxStocked[i] /= 100;
			Last *= (100 - p[i]);
			Last /= 100.0;
		}
	}
}

void Solve() {
	dp[0][0] = 1.0;
	for (i64 i=1; i<=n; i++) {
		ld Curr = 0.0;
		for (i64 j=0; j<=T; j++) {
			if (j-t[i] >= 0) {
				dp[i][j] += dp[i-1][j-t[i]] * afterIntro[i];
				Curr -= dp[i-1][j-t[i]] * maxStocked[i];
			}
			dp[i][j] += Curr * p[i] / 100;
			Curr *= (100 - p[i]); Curr /= 100;
			if (j < T) Curr += dp[i-1][j];
		}
		dp[i-1][T] += Curr;
	}
	ld expected = 0;
	for (i64 i=1; i<=n; i++) expected += dp[i][T] * i;
	for (i64 i=0; i<T; i++) expected += dp[n][i] * n;
	cout << fixed << setprecision(12) << expected;
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);

	
		ios_base::sync_with_stdio(0); cin.tie(NULL);
	
		ios_base::sync_with_stdio(0);
	
	
	
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


