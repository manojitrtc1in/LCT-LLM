









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



i64 n, t, k; vi a;





void Input() {
	cin >> n >> t >> k; a.rsz(t+1, 1);
	for (i64 i=1; i<=t; i++) cin >> a[i];
}

void Solve() {
	i64 Min = 1, Max = 1; vi p(n+1, -1);
	for (i64 i=1; i<=t; i++) Min += max(a[i] - a[i-1], 0LL);
	for (i64 i=1; i<=t; i++) Max += (a[i] - 1);
	if (k < Min || Max < k) {cout << "-1"; return;}
	i64 pL = 1, pR = 1, L = 0, R = 0, Leaf = Min;
	for (i64 i=1; i<=t; i++) {
		L = pR + 1; R = pR + a[i];
		for (i64 x=L; x<=R; x++) {
			if (x < L + a[i-1]) p[x] = pL + (x - L);
			else p[x] = pL;
		}
		pL = L; pR = R;
	}
	pL = 1; pR = 1; L = 0; R = 0;
	for (i64 i=1; i<=t; i++) {
		if (Leaf == k) break;
		L = pR + 1; R = pR + a[i];
		if (a[i-1] == 1) {pL = L; pR = R; continue;}
		for (i64 z=pR+2; z<=pR+min(a[i], a[i-1]); z++) {
			if (Leaf == k) break;
			p[z] = pL; Leaf++;
		}
		pL = L; pR = R;
	}
	cout << n << endl;
	for (i64 i=2; i<=n; i++) cout << p[i] << " " << i << endl;
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
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


