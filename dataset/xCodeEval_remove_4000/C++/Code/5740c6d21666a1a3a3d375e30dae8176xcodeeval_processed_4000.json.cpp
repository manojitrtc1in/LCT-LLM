









using namespace std;











typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
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




i64 n, m, k, i, j; vector<vb> a;



void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



void Input() {
	cin >> n >> m >> k; a.rsz(n, vb(m, false));
}

void Solve() {
	for (i64 z=1; z<=k; z++) {
		cin >> i >> j; i--; j--; a[i][j] = true;
		if (i-1 >= 0 && j-1 >= 0 && a[i-1][j] && a[i][j-1] && a[i-1][j-1]) {cout << z; return;}
		if (i-1 >= 0 && j+1 < m && a[i-1][j] && a[i][j+1] && a[i-1][j+1]) {cout << z; return;}
		if (i+1 < n && j-1 >= 0 && a[i+1][j] && a[i][j-1] && a[i+1][j-1]) {cout << z; return;}
		if (i+1 < n && j+1 < m && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {cout << z; return;}
	}
	cout << "0";
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



































































































































































































































































