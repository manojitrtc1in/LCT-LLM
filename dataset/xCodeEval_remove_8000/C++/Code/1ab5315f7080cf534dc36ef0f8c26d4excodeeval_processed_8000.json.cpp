
 








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
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());



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
string id1 = "FILE.IN";
string id2 = "FILE.OUT";



i64 n; vi a; map<int, int> Map;





void Input() {
	cin >> n; a.rsz(n*n);
	for (auto &z: a) {cin >> z; Map[z]++;}
}

void Solve() {
	vector<vi> A(n, vi(n, -1));
	if (n % 2 != 0) {
		i64 cntodd = 0, lastodd = -1;
		for (auto it=Map.begin(); it!=Map.end(); it++) {
			i64 k = it->fi, v = it->se;
			if (v % 2 != 0) {cntodd++; lastodd = k;}
		}
		if (cntodd != 1) {cout << "NO\n"; return;}
		Map[lastodd]--; A[n/2][n/2] = lastodd;
		vector<int> id0;
		for (auto it=Map.begin(); it!=Map.end(); it++) {
			i64 k = it->fi, v = it->se;
			if (v % 4 == 2) id0.pub(k);
		}
		if (id0.size() > n - 1) {cout << "NO\n"; return;}
		if (((n - 1) - id0.size()) % 2 != 0) {cout << "NO\n"; return;}
		for (auto it=Map.begin(); it!=Map.end(); it++) {
			if (id0.size() == n - 1) break;
			i64 k = it->fi, v = it->se;
			if (v % 4 != 0) continue;
			while (v > 0 && id0.size() < n - 1) {id0.pub(k); id0.pub(k); v -= 4;}
		}
		if (id0.size() != n - 1) {cout << "NO\n"; return;}
		for (i64 i=0; i<n/2; i++) {A[n/2][i] = A[n/2][n-1-i] = id0[i]; Map[id0[i]] -= 2;}
		for (i64 i=n/2; i<n-1; i++) {A[i-n/2][n/2] = A[n-1-i+n/2][n/2] = id0[i]; Map[id0[i]] -= 2;}
	}
	i64 i_ = 0, j_ = 0;
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 k = it->fi, v = it->se;
		if (v % 4 != 0) {cout << "NO\n"; return;}
		while (v > 0) {
			v -= 4; A[i_][j_] = A[n-1-i_][n-1-j_] = k;
			A[i_][n-1-j_] =  A[n-1-i_][j_] = k;
			j_++; if (j_ == n/2) {i_++; j_ = 0;}
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			if (A[i][j] == -1) {cout << "NO\n"; return;}
		}
	}
	cout << "YES\n";
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
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
	char* infile = new char[id1.size()+1];
	char* outfile = new char[id2.size()+1];
	strcpy(infile, id1.c_str());
	strcpy(outfile, id2.c_str());
	
		time_t t = time(0);
		tm* now = localtime(&t);
		cout << "Source code by 
		cout << "Current time: ";
		cout << (now->tm_year + 1900) << '-' 
			 << ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
			 << ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
			 << ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
			 << ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
			 << ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
			 << "\n\n";
		
		
			cout << "OI-Mode: ON\n";
			cout << "Input file: " << infile << endl;
			cout << "Output file: " << outfile << endl;
			cout << "\n";
		
			cout << "OI-Mode: OFF\n";
			cout << "Input file: NULL\n";
			cout << "Output file: NULL\n";
			cout << "\n";
		
		
		
			cout << "MultiTest-Mode: ON\n";
		
			cout << "MultiTest-Mode: OFF\n";
		
		
		
			cout << "Interactive-Mode: ON\n\n";
		
			cout << "Interactive-Mode: OFF\n\n";
		
		
		if (argc > 1) assert(freopen(argv[1], "r", stdin));
		if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
		freopen(infile, "r", stdin);
		freopen(outfile, "w", stdout);
	
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


