










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
string id0 = "FILE.IN";
string id1 = "FILE.OUT";



i64 n, m, v, pi; vi p; vector<vi> adj;
vi Map, id2; vector<vi> DepthList(100001);
vector<vi> Table; vi d;



void DFS(i64 z, i64 last, i64 &cnt) {
	Map[z] = cnt;
	if (last != -1) d[Map[z]] = d[Map[last]] + 1;
	DepthList[d[Map[z]]].pub(Map[z]);
	for (auto t: adj[z]) {
		if (t == last) continue;
		cnt++; DFS(t, z, cnt);
		Table[Map[t]].pub(Map[z]);
	}
	id2[Map[z]] = cnt;
}

void ProcessForest() {
	Table.rsz(n); d.rsz(n, 0);
	id2.rsz(n, 0);
	vi Roots;
	for (i64 i=0; i<n; i++) {
		if (p[i] == -1) Roots.pub(i);
	}
	i64 cnt = 0;
	for (auto id: Roots) {
		i64 st = cnt;
		DFS(id, -1, cnt);
		cnt++; i64 en = cnt;
		for (i64 j=1; j<19; j++) {
			for (i64 i=st; i<en; i++) {
				if (Table[i].size() < j) continue;
				if (Table[Table[i][j-1]].size() < j) continue;
				Table[i].pub(Table[Table[i][j-1]][j-1]);
			}
		}
	}
}

i64 ancestor(i64 node, i64 dist) {
	if (dist == 0) return node;
	for (i64 i=18; i>=0; i--) {
		if (dist >= (1LL << i)) {
			return ancestor(Table[node][i], dist - (1LL << i));
		}
	}
}

void Input() {
	cin >> n; p.rsz(n); adj.rsz(n);
	Map.rsz(n); id2.rsz(n);
	for (i64 i=0; i<n; i++) {
		i64 j; cin >> j; j--; p[i] = j;
		if (p[i] == -1) continue;
		adj[i].pub(j); adj[j].pub(i);
	}
}

void Solve() {
	ProcessForest();
	cin >> m;
	while (m--) {
		cin >> v >> pi; v--;
		v = Map[v];
		if (d[v] < pi) {cout << "0 "; continue;}
		i64 Anc = ancestor(v, pi);
		i64 st = Anc, en = id2[Anc];
		i64 lb = lower_bound(DepthList[d[v]].begin(), DepthList[d[v]].end(), st) - DepthList[d[v]].begin();
		i64 ub = upper_bound(DepthList[d[v]].begin(), DepthList[d[v]].end(), en) - DepthList[d[v]].begin();
		cout << (ub - lb - 1) << endl;
	}
	cout << endl;
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
	char* infile = new char[id0.size()+1];
	char* outfile = new char[id1.size()+1];
	strcpy(infile, id0.c_str());
	strcpy(outfile, id1.c_str());
	
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



