









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



vi x(3), y(3); i64 N; vector<vc> Default; string token = "ABC";



bool isSquare(i64 z) {
	i64 t = sqrt(z);
	return (t * t == z);
}

bool allFilled(vector<vc> A) {
	for (i64 i=0; i<N; i++) {
		for (i64 j=0; j<N; j++) {
			if (A[i][j] == '.') return false;
		}
	}
	return true;
}

void Try(i64 id, i64 flipped, vector<vc> Z) {
	if (id == 3) {
		if (allFilled(Z)) {
			cout << N << endl;
			for (auto Z1: Z) {
				for (auto Z2: Z1) cout << Z2;
				cout << endl;
			}
			Exit();
		}
		return;
	}
	i64 A = x[id], B = y[id];
	if (flipped) swap(A, B);
	if (id == 0) {
		for (i64 i=0; i<A; i++) {
			for (i64 j=0; j<B; j++) {
				if (Z[i][j] != '.') return;
				Z[i][j] = token[0];
			}
		}
	}
	else if (id == 1) {
		for (i64 i=N-A; i<N; i++) {
			for (i64 j=0; j<B; j++) {
				if (Z[i][j] != '.') return;
				Z[i][j] = token[1];
			}
		}
	}
	else if (id == 2) {
		for (i64 i=0; i<A; i++) {
			for (i64 j=N-B; j<N; j++) {
				if (Z[i][j] != '.') return;
				Z[i][j] = token[2];
			}
		}
	}
	Try(id+1, 0, Z); Try(id+1, 1, Z);
}

void Input() {
	for (i64 i=0; i<3; i++) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
	}
}

void Solve() {
	if (!isSquare(x[0]*y[0]+x[1]*y[1]+x[2]*y[2])) {cout << "-1"; return;}
	N = sqrt(x[0]*y[0]+x[1]*y[1]+x[2]*y[2]);
	if (x[0] == N) swap(x[0], y[0]);
	if (x[1] == N) swap(x[1], y[1]);
	if (x[2] == N) swap(x[2], y[2]);
	if (x[0] + x[1] + x[2] == N && y[0] == N && y[1] == y[0] && y[2] == y[0]) {
		cout << N << endl;
		for (i64 i=0; i<x[0]; i++) {
			for (i64 j=0; j<N; j++) {
				cout << "A";
			}
			cout << endl;
		}
		for (i64 i=0; i<x[1]; i++) {
			for (i64 j=0; j<N; j++) {
				cout << "B";
			}
			cout << endl;
		}
		for (i64 i=0; i<x[2]; i++) {
			for (i64 j=0; j<N; j++) {
				cout << "C";
			}
			cout << endl;
		}
		return;
	}
	for (i64 i=0; i<3; i++) {
		if (x[i] != N && y[i] != N) {
			swap(x[0], x[i]);
			swap(y[0], y[i]);
			swap(token[0], token[i]);
			break;
		}
	}
	Default.rsz(N, vc(N, '.')); Try(0, 0, Default); Try(0, 1, Default);
	cout << "-1";
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


