









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



i64 n, m; vector<pii> A; set<pii> B; vi a;





void Input() {
	cin >> n >> m; A.rsz(n); a.rsz(m);
	for (i64 i=0; i<n; i++) cin >> A[i].fi >> A[i].se;
	for (i64 i=0; i<m; i++) {cin >> a[i]; B.insert(mp(a[i], i+1));}
}

void Solve() {
	vector<ppi> PossibleGap(n-1); vi ans(n-1, -1);
	for (i64 i=0; i<n-1; i++) {
		PossibleGap[i].fi.se = A[i+1].fi - A[i].se;
		PossibleGap[i].fi.fi = A[i+1].se - A[i].fi;
		PossibleGap[i].se = i;
	}
	sort(PossibleGap.begin(), PossibleGap.end());
	for (auto z: PossibleGap) {
		i64 Max = z.fi.fi, Min = z.fi.se, id = z.se;
		if (B.lower_bound(mp(Min, -LINF)) == B.lower_bound(mp(Max, +LINF))) {cout << "No"; return;}
		pii q = *B.lower_bound(mp(Min, -LINF)); B.erase(q); ans[id] = q.se;
	}
	cout << "Yes\n"; for (auto x: ans) cout << x << " ";
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


