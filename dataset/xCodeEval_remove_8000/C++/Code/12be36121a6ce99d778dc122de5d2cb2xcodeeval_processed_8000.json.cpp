









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



i64 n, m, ans = LINF, pos = -1; vi a, b;



i64 calc(i64 x) {
	i64 res = 0;
	for (i64 i=0; i<n; i++) {
		if (a[i] >= x) break;
		res += (x - a[i]);
	}
	for (i64 i=m-1; i>=0; i--) {
		if (x >= b[i]) break;
		res += (b[i] - x);
	}
	return res;
}

void update(i64 z) {
	i64 res = calc(z);
	if (ans == LINF) {pos = z; ans = res; return;}
	if (res < ans) {pos = z; ans = res; return;}
}

void id0(i64 top, i64 bot) {
	if (top > bot) return;
	if (bot - top <= 2) {
		for (i64 i=top; i<=bot; i++) update(i);
		return;
	}
	i64 L = top + (bot - top) / 3, R = top + ((bot - top) * 2) / 3;
	i64 val1 = calc(L), val2 = calc(R);
	if (val1 < val2) id0(top, R);
	else id0(L, bot);
}

void Input() {
	cin >> n >> m; a.rsz(n); b.rsz(m);
	for (i64 i=0; i<n; i++) cin >> a[i];
	for (i64 i=0; i<m; i++) cin >> b[i];
}

void Solve() {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	id0(1LL, 1000000000LL);
	cout << ans;
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


