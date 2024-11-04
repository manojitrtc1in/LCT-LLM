









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



typedef pair<i64, string> pis;
string s; set<pis> S; map<string, i64> Map;



bool valid(string x) {
	if (x[2] != '-') return false;
	if (x[5] != '-') return false;
	for (i64 i=0; i<10; i++) {
		if (i == 2 || i == 5) continue;
		if (x[i] < '0' || x[i] > '9') return false;
	}
	i64 M = (x[3] - '0') * 10 + (x[4] - '0');
	i64 D = (x[0] - '0') * 10 + (x[1] - '0');
	i64 Y = (x[6] - '0') * 1000 + (x[7] - '0') * 100 + (x[8] - '0') * 10 + (x[9] - '0');
	if (M == 2 && D > 29) return false;
	if (M == 2 && D > 28 && ((Y % 100 == 0 && Y % 400 != 0) || (Y % 4 != 0))) return false;
	if (M > 12) return false;
	if (M < 1) return false;
	if (D < 1) return false;
	if (Y < 2013 || Y > 2015) return false;
	if ((M == 4 || M == 6 || M == 9 || M == 11) && D > 30) return false;
	if ((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && D > 31) return false;
	return true;
}

void Input() {
	cin >> s;
}

void Solve() {
	for (i64 i=0; i<=s.size()-10; i++) {
		if (valid(s.substr(i, 10))) {
			if (Map[s.substr(i, 10)]) S.erase(mp(Map[s.substr(i, 10)], s.substr(i, 10)));
			S.insert(mp(Map[s.substr(i, 10)]+1, s.substr(i, 10))); Map[s.substr(i, 10)]++;
		}
	}
	cout << S.rbegin()->se;
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


