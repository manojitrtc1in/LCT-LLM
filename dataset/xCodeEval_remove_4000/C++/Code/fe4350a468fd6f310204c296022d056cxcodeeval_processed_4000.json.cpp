









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





void Input() {
	cin >> n; a.rsz(n);
}

void Solve() {
	for (i64 i=0; i<n; i+=3) {
		i64 s1, s2, s3;
		if (i + 3 > n) break;
		cout << "? " << i+1 << " " << i+2 << endl;
		fflush(stdout); cin >> s3;
		cout << "? " << i+1 << " " << i+3 << endl;
		fflush(stdout); cin >> s2;
		cout << "? " << i+2 << " " << i+3 << endl;
		fflush(stdout); cin >> s1;
		a[i+0] = (s1 + s2 + s3) / 2 - s1;
		a[i+1] = (s1 + s2 + s3) / 2 - s2;
		a[i+2] = (s1 + s2 + s3) / 2 - s3;
	}
	if (n % 3 >= 1) {
		cout << "? 1 " << n << endl;
		fflush(stdout); i64 s; cin >> s;
		a[n-1] = s - a[0];
	}
	if (n % 3 >= 2) {
		cout << "? 1 " << n-1 << endl;
		fflush(stdout); i64 s; cin >> s;
		a[n-2] = s - a[0];
	}
	cout << "!"; for (auto x: a) cout << " " << x; cout << endl; fflush(stdout);
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


