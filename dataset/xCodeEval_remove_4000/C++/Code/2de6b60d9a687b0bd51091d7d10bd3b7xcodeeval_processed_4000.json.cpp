








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



i64 n; vi x, y;





void Input() {
	cin >> n; x.rsz(n); y.rsz(n);
	for (i64 i=0; i<n; i++) cin >> x[i] >> y[i];
}

void Solve() {
	i64 minx = *min_element(x.begin(), x.end());
	i64 maxx = *max_element(x.begin(), x.end());
	i64 miny = *min_element(y.begin(), y.end());
	i64 maxy = *max_element(y.begin(), y.end());
	i64 id0 = LINF, id2 = -LINF;
	i64 id5 = LINF, id4 = -LINF;
	pii MinX, MaxX, MinY, MaxY; vector<vs> Mask(n); i64 Init = 0;
	for (i64 i=0; i<n; i++) {
		if (x[i] == minx) {Mask[i].pub("minx"); MinX = mp(x[i], y[i]); id0 = min(id0, y[i]); id2 = max(id2, y[i]);}
		if (x[i] == maxx) {Mask[i].pub("maxx"); MaxX = mp(x[i], y[i]); Init = (i + 1) % n; id0 = min(id0, y[i]); id2 = max(id2, y[i]);}
		if (y[i] == miny) {Mask[i].pub("miny"); MinY = mp(x[i], y[i]); id5 = min(id5, x[i]); id4 = max(id4, x[i]);}
		if (y[i] == maxy) {Mask[i].pub("maxy"); MaxY = mp(x[i], y[i]); id5 = min(id5, x[i]); id4 = max(id4, x[i]);}
	}
	bool id6 = false;
	for (i64 i=0; i<n; i++) {
		if (Mask[i].size() > 1) {
			id6 = true;
			break;
		}
	}
	if (id6) {
		for (i64 i=3; i<=n; i++) cout << (maxx - minx + maxy - miny) * 2 << " ";
		return;
	}
	i64 res3 = -LINF; string statex = "min", statey = "max";
	res3 = max(res3, (maxx - minx) * 2 + (maxy - id0) * 2);
	res3 = max(res3, (maxx - minx) * 2 + (id2 - miny) * 2);
	res3 = max(res3, (maxy - miny) * 2 + (maxx - id5) * 2);
	res3 = max(res3, (maxy - miny) * 2 + (id4 - minx) * 2);
	for (i64 z=Init; z<Init+n; z++) {
		i64 i = z % n;
		if (!Mask[i].empty()) {
			if (statex == "min" && statey == "max") statex = "max";
			else if (statex == "max" && statey == "max") statey = "min";
			else if (statex == "max" && statey == "min") statex = "min";
			else if (statex == "min" && statey == "min") statey = "max";
			continue;
		}
		if (statex == "min" && statey == "max") res3 = max(res3, ((max(MaxY.fi, x[i]) - minx)) * 2 + (maxy - min(MinX.se, y[i])) * 2);
		else if (statex == "max" && statey == "max") res3 = max(res3, ((maxx - min(MaxY.fi, x[i]))) * 2 + (maxy - min(MinX.se, y[i])) * 2);
		else if (statex == "max" && statey == "min") res3 = max(res3, ((maxx - min(MaxY.fi, x[i]))) * 2 + (max(MinX.se, y[i]) - miny) * 2);
		else if (statex == "min" && statey == "min") res3 = max(res3, ((max(MaxY.fi, x[i]) - minx)) * 2 + (max(MinX.se, y[i]) - miny) * 2);
	}
	cout << res3 << " ";
	for (i64 i=4; i<=n; i++) cout << (maxx - minx + maxy - miny) * 2 << " ";
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


