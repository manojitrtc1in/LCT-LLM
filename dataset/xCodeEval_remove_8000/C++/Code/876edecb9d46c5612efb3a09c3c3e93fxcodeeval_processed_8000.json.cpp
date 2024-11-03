








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
string id1 = "FILE.IN";
string id2 = "FILE.OUT";



i64 n, m, sa = 0, sb = 0, p, q;
vector<vi> adj; vi a, b;
vector<vi> UsageMatrix;
vector<vi> id4;
vector<vi> CapacityMatrix;
i64 N; vi Last; vb vis;



void id3() {
	N = n * 2 + 2; id4.rsz(N);
	CapacityMatrix.rsz(N, vi(N, 0));
	for (i64 i=0; i<n; i++) {
		id4[0].pub(i+1);
		CapacityMatrix[0][i+1] = a[i];
		id4[i+1].pub(0);
		CapacityMatrix[i+1][0] = a[0];
	}
	for (i64 i=0; i<n; i++) {
		id4[n+i+1].pub(n*2+1);
		CapacityMatrix[n+i+1][n*2+1] = b[i];
		id4[n*2+1].pub(n+i+1);
		CapacityMatrix[n*2+1][n+i+1] = 0;
	}
	for (i64 i=0; i<n; i++) {
		id4[i+1].pub(n+i+1);
		CapacityMatrix[i+1][n+i+1] = LINF;
		id4[n+i+1].pub(i+1);
		CapacityMatrix[n+i+1][i+1] = 0;
		for (auto j: adj[i]) {
			id4[i+1].pub(n+j+1);
			CapacityMatrix[i+1][n+j+1] = LINF;
			id4[n+i+1].pub(j+1);
			CapacityMatrix[n+i+1][j+1] = 0;
		}
	}
}

void id0() {
	Last.clear(); Last.rsz(N, -1);
	vis.clear(); vis.rsz(N, false);
	queue<i64> Q; Q.push(0); vis[0] = true;
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		for (auto it=id4[z].begin(); it!=id4[z].end(); it++) {
			i64 t = *it, d = CapacityMatrix[z][t];
			if (vis[t] || d == 0) continue;
			Last[t] = z; vis[t] = true; Q.push(t);
		}
	}
}

i64 MaxFlow() {
	i64 res = 0; Last.rsz(N, -1);
	do {
		i64 pointer = N - 1, MinimumCapacity = LINF * 4;
		vector<pii> id5;
		while (Last[pointer] != -1) {
			i64 Previous = Last[pointer];
			i64 capacity = CapacityMatrix[Previous][pointer];
			MinimumCapacity = min(MinimumCapacity, capacity);
			id5.pub(mp(Previous, pointer));
			pointer = Previous;
		}
		for (auto Pair: id5) {
			i64 i = Pair.fi, j = Pair.se;
			i64 capIn = CapacityMatrix[i][j];
			i64 capOut = CapacityMatrix[j][i];
			CapacityMatrix[i][j] -= MinimumCapacity;
			CapacityMatrix[j][i] += MinimumCapacity;
			if (i > 0 && j < N-1) {
				if (i <= n && j > n) UsageMatrix[i-1][j-n-1] += MinimumCapacity;
				else UsageMatrix[j-1][i-n-1] -= MinimumCapacity;
			}
		}
		if (MinimumCapacity < LINF * 4) res += MinimumCapacity; id0();
	} while (Last[N-1] != -1);
	return res;
}

void Input() {
	cin >> n >> m; a.rsz(n); b.rsz(n);
	UsageMatrix.rsz(n, vi(n, 0)); adj.rsz(n);
	for (auto &x: a) {cin >> x; sa += x;}
	for (auto &x: b) {cin >> x; sb += x;}
	while (m--) {
		cin >> p >> q; p--; q--;
		adj[p].pub(q); adj[q].pub(p);
	}
}

void Solve() {
	if (sa != sb) {cout << "NO"; return;}
	id3();
	i64 Max = MaxFlow();
	if (Max != sa) {cout << "NO"; return;}
	cout << "YES\n";
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			cout << UsageMatrix[i][j] << " ";
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


