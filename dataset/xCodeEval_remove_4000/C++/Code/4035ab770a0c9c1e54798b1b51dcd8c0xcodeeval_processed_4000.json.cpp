








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



typedef pair<pip, i64> pipi;
i64 n; vector<pipi> Points, A; vector<pii> Index;





void Input() {
	cin >> n; Points.rsz(n); Index.rsz(n); A.rsz(n);
	for (i64 i=0; i<n; i++) {
		cin >> Points[i].fi.se.fi >> Points[i].fi.se.se;
		Points[i].fi.fi = Points[i].fi.se.se - Points[i].fi.se.fi;
		Points[i].se = i; A[i] = Points[i]; A[i].fi.fi = A[i].fi.se.se + A[i].fi.se.fi;
	}
	for (i64 i=0; i<n; i++) {
		cin >> Index[i].fi; Index[i].se = i;
	}
}

void Solve() {
	sort(A.rbegin(), A.rend());
	map<pii, i64> ind;
	sort(Points.begin(), Points.end());
	sort(Index.begin(), Index.end());
	vector<pii> Map(n); priority_queue<pipi> Heap;
	for (i64 i=0; i<n; i++) {
		i64 j1 = i, j2 = i, j = 0;
		while (j1+1 < n && Points[i].fi.fi == Points[j1+1].fi.fi) j1++;
		while (j2+1 < n && Index[i].fi == Index[j2+1].fi) j2++;
		if (Points[i].fi.fi != Index[i].fi) {cout << "NO\n"; return;}
		if (j1 != j2) {cout << "NO\n"; return;} j = j1;
		for (i64 x=i; x<=j; x++) {Map[Index[x].se] = Points[x].fi.se; ind[Points[x].fi.se] = Index[x].se;} i = j;
	}
	for (i64 i=0; i<n; i++) {
		i64 x = A[i].fi.se.fi, y = A[i].fi.se.se;
		if (x > 0 && ind[mp(x-1, y)] > ind[mp(x,y)]) {cout << "NO\n"; return;}
		if (y > 0 && ind[mp(x, y-1)] > ind[mp(x,y)]) {cout << "NO\n"; return;}
	}
	cout << "YES\n";
	for (auto x: Map) cout << x.fi << " " << x.se << endl;
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


