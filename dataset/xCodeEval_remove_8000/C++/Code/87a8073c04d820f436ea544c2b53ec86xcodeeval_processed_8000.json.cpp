









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



typedef pair<string, string> pss;
typedef pair<pss, i64> msg;
i64 n, d, t, N; string s, r; vector<msg> A;
map<string, int> Map; vs users;





void Input() {
	cin >> n >> d; A.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> s >> r >> t;
		A[i] = mp(mp(s, r), t);
		if (Map.find(s) == Map.end()) {users.pub(s); Map[s] = Map.size();}
		if (Map.find(r) == Map.end()) {users.pub(r); Map[r] = Map.size();}
	}
}

void Solve() {
	N = users.size(); vector<vb> friends(N, vb(N, false));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			if (A[i].fi.fi != A[j].fi.se) continue;
			if (A[i].fi.se != A[j].fi.fi) continue;
			if (abs(A[i].se - A[j].se) > d || A[i].se == A[j].se) continue;
			friends[Map[A[i].fi.fi]][Map[A[i].fi.se]] = true;
		}
	}
	vector<pss> Pair;
	for (i64 i=0; i<N; i++) {
		for (i64 j=i+1; j<N; j++) {
			if (!friends[i][j]) continue;
			Pair.pub(mp(users[i], users[j]));
		}
	}
	cout << Pair.size() << endl;
	for (auto x: Pair) cout << x.fi << " " << x.se << endl;
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


