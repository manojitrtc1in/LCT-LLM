








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



i64 n, q, v; vi p, A, Tree, Lazy, Open, Close;
string cmd; vector<vi> adj; vi EulerTour;



void DFS(i64 z) {
	Open[z] = EulerTour.size();
	EulerTour.pub(z);
	for (auto t: adj[z]) {
		if (p[z] != t) DFS(t);
	}
	Close[z] = EulerTour.size() - 1;
}

void BuildST(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {Tree[node] = A[EulerTour[st]]; return;}
	BuildST(node*2, st, (st+en)/2);
	BuildST(node*2+1, (st+en)/2+1, en);
	Tree[node] = Tree[node*2] + Tree[node*2+1];
}

void Propagate(i64 node, i64 st, i64 en) {
	if (Lazy[node] == 0) return;
	Tree[node] = (en - st + 1) - Tree[node];
	if (st != en) {
		Lazy[node*2+0] += Lazy[node];
		Lazy[node*2+0] %= 2;
		Lazy[node*2+1] += Lazy[node];
		Lazy[node*2+1] %= 2;
	}
	Lazy[node] = 0;
}

void Increment(i64 node, i64 st, i64 en, i64 L, i64 R) {
	Propagate(node, st, en);
	if (st > en || R < st || en < L) return;
	if (L <= st && en <= R) {
		Lazy[node]++; Lazy[node] %= 2;
		Propagate(node, st, en); return;
	}
	Increment(node*2, st, (st+en)/2, L, R);
	Increment(node*2+1, (st+en)/2+1, en, L, R);
	Tree[node] = Tree[node*2] + Tree[node*2+1];
}

i64 Get(i64 node, i64 st, i64 en, i64 L, i64 R) {
	Propagate(node, st, en);
	if (st > en || R < st || en < L) return 0;
	if (L <= st && en <= R) return Tree[node];
	i64 p1 = Get(node*2, st, (st+en)/2, L, R);
	i64 p2 = Get(node*2+1, (st+en)/2+1, en, L, R);
	return (p1 + p2);
}

void Input() {
	cin >> n; p.rsz(n, -1); A.rsz(n);
	adj.rsz(n); Open.rsz(n, -1); Close.rsz(n, -1);
	for (i64 i=1; i<n; i++) {
		cin >> p[i]; p[i]--;
		adj[i].pub(p[i]); adj[p[i]].pub(i);
	}
	for (i64 i=0; i<n; i++) cin >> A[i];
}

void Solve() {
	DFS(0); Tree.rsz(n*4); Lazy.rsz(n*4);
	BuildST(1, 0, n-1); cin >> q;
	while (q--) {
		cin >> cmd >> v; v--;
		if (cmd == "pow") Increment(1, 0, n-1, Open[v], Close[v]);
		else cout << Get(1, 0, n-1, Open[v], Close[v]) << endl;
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


