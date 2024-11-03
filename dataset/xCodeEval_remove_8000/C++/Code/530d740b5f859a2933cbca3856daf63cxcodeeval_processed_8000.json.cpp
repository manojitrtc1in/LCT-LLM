









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



vector<vc> a(8, vc(8, '.')); i64 sx, sy, ex, ey;





void Input() {
	sx = -1; sy = -1; ex = -1; ey = -1;
	a.clear(); a.rsz(8, vc(8, '.'));
	for (i64 i=0; i<8; i++) {
		for (i64 j=0; j<8; j++) {
			cin >> a[i][j];
			if (a[i][j] != 'K') continue;
			if (sx == -1) {sx = i; sy = j;}
			else {ex = i; ey = j;}
		}
	}
}

void Solve() {
	vector<vb> vis(8, vb(8, false)); vector<vi> d(8, vi(8, LINF));
	queue<pii> Q; Q.push(mp(sx, sy)); vis[sx][sy] = true; d[sx][sy] = 0;
	while (!Q.empty()) {
		pii z = Q.front(); Q.pop();
		i64 x = z.fi, y = z.se;
		for (i64 i=-2; i<=2; i+=4) {
			for (i64 j=-2; j<=2; j+=4) {
				if (x+i < 0 || x+i > 7) continue;
				if (y+j < 0 || y+j > 7) continue;
				if (vis[x+i][y+j]) continue;
				vis[x+i][y+j] = true; Q.push(mp(x+i, y+j));
				d[x+i][y+j] = d[x][y] + 1;
			}
		}
	}
	if (vis[ex][ey] && d[ex][ey] % 2 == 0) cout << "YES\n"; else cout << "NO\n";
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


