
 








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
string id3 = "FILE.OUT";



int n; vector<int> c; vi dp;
vector<vector<int>> adj;
vector<vector<int>> DependencyList;
set<int> FinalList;



void id0(int z, int last, vector<int> &MaxLeaf, vector<int> &MaxID, vector<int> &MaxCnt) {
	dp[z] = 0;
	bool isLeaf = true;
	for (auto t: adj[z]) {
		if (t == last) continue;
		isLeaf = false;
		id0(t, z, MaxLeaf, MaxID, MaxCnt); dp[z] += dp[t];
		if (MaxLeaf[t] >= MaxLeaf[z]) MaxID[z] = MaxID[t];
		if (MaxLeaf[t] > MaxLeaf[z]) MaxCnt[z] = MaxCnt[t];
		else if (MaxLeaf[t] == MaxLeaf[z]) MaxCnt[z] += MaxCnt[t];
		MaxLeaf[z] = max(MaxLeaf[z], MaxLeaf[t]);
	}
	if (isLeaf) {
		MaxLeaf[z] = dp[z] = c[z]; MaxID[z] = z; MaxCnt[z] = 1;
		DependencyList[z].pub(z); return;
	}
	int id2 = -MaxLeaf[z];
	if (id2 + c[z] > 0) return;
	if (id2 + c[z] < 0 && MaxCnt[z] == 1) {
		DependencyList[MaxID[z]].clear();
	}
	if (MaxCnt[z] == 1) DependencyList[MaxID[z]].pub(z);
	else {
		DependencyList[z].pub(z);
		MaxID[z] = z;
	}
	dp[z] += (id2 + c[z]); MaxLeaf[z] = c[z]; MaxCnt[z] = 1;
}

void Input() {
	cin >> n; c.rsz(n); dp.rsz(n); adj.rsz(n);
	DependencyList.rsz(n);
	for (auto &z: c) cin >> z;
	for (int i=1; i<n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].pub(b); adj[b].pub(a);
	}
}

void Solve() {
	vector<int> MaxLeaf(n, -1), MaxID(n, -1), MaxCnt(n, 0);
	id0(0, -1, MaxLeaf, MaxID, MaxCnt);
	for (int id=0; id<n; id++) {
		for (auto z: DependencyList[id]) FinalList.insert(z+1);
	}
	cout << dp[0] << " " << FinalList.size() << endl;
	for (auto it=FinalList.begin(); it!=FinalList.end(); it++) cout << (*it) << " "; cout << endl;
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
	char* outfile = new char[id3.size()+1];
	strcpy(infile, id1.c_str());
	strcpy(outfile, id3.c_str());
	
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


