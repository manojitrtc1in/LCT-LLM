








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



i64 n, offset; vector<vc> A, A2, R; vector<pii> Pieces;





void Input() {
	cin >> n; offset = n - 1;
	A.rsz(n, vc(n, '.')); A2.rsz(n, vc(n, '.'));
	R.rsz(offset*2+1, vc(offset*2+1, '.'));
	R[offset][offset] = 'o';
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'o') {
				Pieces.pub(mp(i, j));
				A2[i][j] = 'o';
			}
		}
	}
}

void Solve() {
	vector<pii> Dir;
	for (i64 x=-offset; x<=offset; x++) {
		for (i64 y=-offset; y<=offset; y++) {
			if (x == 0 && y == 0) continue;
			i64 cnt = 0, outbound = 0;
			for (auto z: Pieces) {
				i64 i = z.fi, j = z.se;
				if (i+x < 0 || i+x >= n || j+y < 0 || j+y >= n) {
					outbound++; continue;
				}
				if (A[i+x][j+y] != '.') cnt++;
			}
			if (cnt + outbound != Pieces.size()) continue;
			R[x+offset][y+offset] = 'x'; Dir.pub(mp(x, y));
		}
	}
	for (auto z: Pieces) {
		i64 i = z.fi, j = z.se;
		for (auto z1: Dir) {
			i64 x = z1.fi, y = z1.se;
			if (i+x >= 0 && i+x < n && j+y >= 0 && j+y < n && A[i+x][j+y] != 'o') {
				A2[i+x][j+y] = 'x';
			}
		}
	}
	if (A2 != A) {cout << "NO"; return;}
	cout << "YES\n";
	for (auto r: R) {
		for (auto z: r) {
			cout << z;
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


