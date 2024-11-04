









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
const long double Pi = 3.141592653589793116, EPS = 1e-12, Gold = ((1+sqrt(5))/2);
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



i64 n; vector<pii> A; bool Negative = false, Positive = false;
ld Radius = 0.5L;



ld id0(ld a, ld b) {
	return fabs(a - b)/max(1.0L, (ld)fabs(b));
}

bool Possible(ld R) {
	ld Leftmost = -1e18, Rightmost = 1e18;
	for (auto x: A) {
		ld k = x.se, z = x.fi;
		if (R*R < (k-R)*(k-R)) return false;
		ld HorizontalRequired = sqrtl((R - k + R) * k);
		ld Low = z - HorizontalRequired, High = z + HorizontalRequired;
		

		Leftmost = max(Leftmost, Low); Rightmost = min(Rightmost, High);
	}
	

	return (Leftmost <= Rightmost);
}

void binary_search(ld Min, ld Max) {
	if (id0(Min, Max) <= 1e-9) return;
	ld Mid = (Min + Max) / 2.0L;
	

	if (Possible(Mid)) {Radius = Mid; binary_search(Min, Mid);}
	else binary_search(Mid, Max);
}

void Input() {
	cin >> n; A.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> A[i].fi >> A[i].se;
		if (A[i].se < 0) Negative = true;
		if (A[i].se > 0) Positive = true;
	}
}

void Solve() {
	if (Positive && Negative) {cout << "-1"; return;}
	for (i64 i=0; i<n; i++) A[i].se = abs(A[i].se);
	cout << fixed << setprecision(18);
	binary_search(0.5L, (ld)1e15);
	cout << Radius;
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


