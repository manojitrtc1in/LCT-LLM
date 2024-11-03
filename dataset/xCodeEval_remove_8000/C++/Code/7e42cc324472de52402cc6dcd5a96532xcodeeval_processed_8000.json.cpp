
 









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



i64 k; vector<vc> Mat(100, vc(100, '0'));



i64 id3(i64 r) {
	i64 top = 0, bot = 100, ans = -1;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (mid * (mid - 1) * (mid - 2) / 6 <= r) {
			ans = mid; top = mid + 1;
		}
		else bot = mid - 1;
	}
	return ans;
}

void id0(i64 L, i64 R) {
	for (i64 i=L; i<=R; i++) {
		for (i64 j=L; j<=R; j++) {
			if (i != j) Mat[i][j] = '1';
		}
	}
}

i64 id4(i64 r) {
	i64 top = 0, bot = 100, ans = -1;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (mid * (mid - 1) / 2 <= r) {
			ans = mid; top = mid + 1;
		}
		else bot = mid - 1;
	}
	return ans;
}

void bridgeFill(i64 src, i64 L, i64 R) {
	for (i64 i=L; i<=R; i++) {
		Mat[src][i] = '1';
		Mat[i][src] = '1';
	}
}

void Input() {
	cin >> k;
}

void Solve() {
	i64 n = id3(k);
	id0(0, n-1); k -= n * (n - 1) * (n - 2) / 6;
	while (k > 0) {
		i64 z = id4(k);
		bridgeFill(n, 0, z-1); n++;
		k -= z * (z - 1) / 2;
	}
	cout << n << endl;
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			cout << Mat[i][j];
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


