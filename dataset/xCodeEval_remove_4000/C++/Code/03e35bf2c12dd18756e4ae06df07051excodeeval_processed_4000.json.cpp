
 








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
string id2 = "FILE.IN";
string id4 = "FILE.OUT";



i64 n, m; vector<vc> a; vector<vi> W;
map<pii, set<pii>> adjOut, adjIn;
map<pii, pii> id3; map<pii, i64> id5;
map<pii, vector<pii>> id1;



pii id0(pii ID) {
	while (id3.find(ID) != id3.end()) ID = id3[ID];
	return ID;
}

void id6(pii x, pii y) {
	x = id0(x); y = id0(y);
	if (x == y) return;
	if (id5[x] < id5[y]) swap(x, y);
	id3[y] = x; id5[x] += id5[y];
	for (auto z: id1[y]) id1[x].pub(z);
}

bool DFS(pii z, map<pii, i64> &vis) {
	vis[z] = 2; W[z.fi][z.se] = 1;
	for (auto it=adjOut[z].begin(); it!=adjOut[z].end(); it++) {
		pii t = *it;
		if (vis[t] == 1) {W[z.fi][z.se] = max(W[z.fi][z.se], W[t.fi][t.se] + 1); continue;}
		if (vis[t] == 2) return true;
		bool hasCycle = DFS(t, vis);
		if (hasCycle) return true;
		W[z.fi][z.se] = max(W[z.fi][z.se], W[t.fi][t.se] + 1);
	}
	for (auto t: id1[z]) W[t.fi][t.se] = W[z.fi][z.se];
	vis[z] = 1; return false;
}

bool id7() {
	map<pii, i64> vis;
	for (i64 i=0; i<n; i++) vis[mp(0, i)] = 0;
	for (i64 j=0; j<m; j++) vis[mp(1, j)] = 0;
	for (i64 i=0; i<n; i++) {
		if (vis[mp(0, i)]) continue;
		if (id0(mp(0, i)) != mp(0LL, i)) continue;
		bool hasCycle = DFS(mp(0, i), vis);
		if (hasCycle) return false;
	}
	for (i64 j=0; j<m; j++) {
		if (vis[mp(1, j)]) continue;
		if (id0(mp(1, j)) != mp(1LL, j)) continue;
		bool hasCycle = DFS(mp(1, j), vis);
		if (hasCycle) return false;
	}
	return true;
}

void Input() {
	cin >> n >> m; a.rsz(n, vc(m, '=')); W.rsz(2);
	W[0].rsz(n, -LINF); W[1].rsz(m, -LINF);
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	for (i64 i=0; i<n; i++) {id5[mp(0, i)] = 1; id1[mp(0, i)].pub(mp(0, i));}
	for (i64 j=0; j<m; j++) {id5[mp(1, j)] = 1; id1[mp(1, j)].pub(mp(1, j));}
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (a[i][j] == '=') id6(mp(0, i), mp(1, j));
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (id0(mp(0, i)) != id0(mp(1, j))) continue;
			if (a[i][j] != '=') {cout << "No\n"; return;}
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			if (a[i][j] == '>') {
				adjOut[id0(mp(0, i))].insert(id0(mp(1, j)));
				adjIn[id0(mp(1, j))].insert(id0(mp(0, i)));
			}
			if (a[i][j] == '<') {
				adjOut[id0(mp(1, j))].insert(id0(mp(0, i)));
				adjIn[id0(mp(0, i))].insert(id0(mp(1, j)));
			}
		}
	}
	if (!id7()) {cout << "No\n"; return;}
	cout << "Yes\n";
	for (i64 x=0; x<2; x++) {
		for (auto z: W[x]) cout << z << " ";
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
	char* infile = new char[id2.size()+1];
	char* outfile = new char[id4.size()+1];
	strcpy(infile, id2.c_str());
	strcpy(outfile, id4.c_str());
	
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


