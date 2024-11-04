









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



string s; i64 n; vs A; map<char, set<char>> id0;



void preprocess() {
	for (i64 i=0; i<26; i++) {
		id0[char(65+i)].insert(char(97+i));
		id0[char(97+i)].insert(char(65+i));
	}
	id0['0'].insert('O'); id0['0'].insert('o');
	id0['O'].insert('0'); id0['o'].insert('0');
	id0['1'].insert('L'); id0['1'].insert('l');
	id0['L'].insert('1'); id0['l'].insert('1');
	id0['1'].insert('I'); id0['1'].insert('i');
	id0['I'].insert('1'); id0['i'].insert('1');
	id0['L'].insert('I'); id0['L'].insert('i');
	id0['l'].insert('I'); id0['l'].insert('i');
	id0['I'].insert('L'); id0['I'].insert('l');
	id0['i'].insert('L'); id0['i'].insert('l');
}

bool similar(string x, string y) {
	if (x.size() != y.size()) return false;
	for (i64 i=0; i<x.size(); i++) {
		char a = x[i], b = y[i];
		if (a == b) continue;
		if (id0[a].find(b) == id0[a].end()) return false;
	}
	return true;
}

void Input() {
	cin >> s >> n; A.rsz(n);
	for (i64 i=0; i<n; i++) cin >> A[i];
}

void Solve() {
	preprocess();
	for (i64 i=0; i<n; i++) {
		if (similar(A[i], s)) {cout << "No"; return;}
	}
	cout << "Yes";
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


