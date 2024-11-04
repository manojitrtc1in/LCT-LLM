









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



i64 n, Px, Py; ld id0 = LINF, id2 = -LINF; vector<pii> A;



i64 sqr(i64 z) {
	return (z * z);
}

bool acute(pii X, pii Y, pii Z) {
	vi id1(3);
	id1[0] = sqr(X.fi - Y.fi) + sqr(X.se - Y.se);
	id1[1] = sqr(X.fi - Z.fi) + sqr(X.se - Z.se);
	id1[2] = sqr(Z.fi - Y.fi) + sqr(Z.se - Y.se);
	return (id1[0] + id1[1] > id1[2]);
}

void process(pii X, pii Y) {
	if (!acute(X, Y, mp(Px, Py))) return;
	if (!acute(Y, X, mp(Px, Py))) return;
	i64 b = Y.fi - X.fi;
	i64 a = X.se - Y.se;
	i64 c = -(a * X.fi + b * X.se);
	ld r2 = (ld)(a * Px + b * Py + c) * (a * Px + b * Py + c) / (a * a + b * b);
	id0 = min(id0, r2);
}

void Input() {
	cin >> n >> Px >> Py; A.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> A[i].fi >> A[i].se;
		id2 = max(id2, (ld)sqr(Px-A[i].fi) + sqr(Py-A[i].se));
		id0 = min(id0, (ld)sqr(Px-A[i].fi) + sqr(Py-A[i].se));
	}
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		process(A[i], A[(i+1)%n]);
	}
	cout << fixed << setprecision(18);
	cout << (ld)(id2 - id0) * Pi;
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


