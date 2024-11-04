








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
string id3 = "FILE.OUT";



i64 n, m, q; vs a; map<string, i64> id;
i64 t; string x, y;
vi id2, id4, Antonym;



i64 id0(i64 z) {
	if (z == -1) return -1;
	while (id2[z] != -1) z = id2[z];
	return z;
}

void id5(i64 id1, i64 id2) {
	i64 z1 = id0(id1), z2 = id0(id2);
	if (z1 == z2) return;
	if (id4[z1] < id4[z2]) swap(z1, z2);
	id4[z1] += id4[z2]; id2[z2] = z1;
	if (Antonym[z2] != -1) Antonym[Antonym[z2]] = z1;
	if (Antonym[z1] == -1) Antonym[z1] = Antonym[z2];
}

void Input() {
	cin >> n >> m >> q; a.rsz(n);
	id2.rsz(n, -1); id4.rsz(n, +1);
	Antonym.rsz(n, -1);
	for (i64 i=0; i<n; i++) {
		cin >> a[i]; id[a[i]] = i;
	}
	while (m--) {
		

		

		

		cin >> t >> x >> y;
		i64 rootx = id0(id[x]), rooty = id0(id[y]);
		i64 antx = id0(Antonym[rootx]), anty = id0(Antonym[rooty]);
		if (t == 1) {
			if (Antonym[rootx] == rooty) {cout << "NO\n"; continue;}
			if (antx != -1 && anty != -1 && Antonym[antx] == anty) {cout << "NO\n"; continue;}
			id5(rootx, rooty);
			if (antx != -1 && anty != -1) id5(antx, anty);
			cout << "YES\n"; continue;
		}
		if (rootx == rooty || (antx != -1 && antx == anty)) {cout << "NO\n"; continue;}
		if (anty != -1) id5(rootx, anty); if (antx != -1) id5(rooty, antx);
		rootx = id0(rootx); rooty = id0(rooty);
		Antonym[rootx] = rooty; Antonym[rooty] = rootx;
		cout << "YES\n"; continue;
	}
		

		

		

}

void Solve() {
	while (q--) {
		cin >> x >> y;
		i64 rootx = id0(id[x]), rooty = id0(id[y]);
		if (rootx == rooty) {cout << "1\n"; continue;}
		if (Antonym[rootx] == rooty) cout << "2\n"; else cout << "3\n";
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


