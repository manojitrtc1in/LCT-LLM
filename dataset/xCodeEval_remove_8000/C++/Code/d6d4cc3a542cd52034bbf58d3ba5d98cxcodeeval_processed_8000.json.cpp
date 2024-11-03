










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



i64 n, m; vector<pii> Points; map<pii, i64> Map;



ld sqr(i64 z) {
	return (1.0L * z * z);
}

ld caldist(pii A, pii B, pii C, pii D) {
	ld res = 0.0L;
	res += sqrt(sqr(B.fi-A.fi) + sqr(B.se-A.se));
	res += sqrt(sqr(C.fi-B.fi) + sqr(C.se-B.se));
	res += sqrt(sqr(D.fi-C.fi) + sqr(D.se-C.se));
	return res;
}

void Input() {
	cin >> n >> m;
}

void Solve() {
	for (i64 i=0; i<=4; i++) {
		if (!Map[mp(0LL, i+0)] && i+0 >= 0 && i+0 <= m) {Map[mp(0LL, i+0)]++; Points.pub(mp(0LL, i+0));}
		if (!Map[mp(i+0, 0LL)] && i+0 >= 0 && i+0 <= n) {Map[mp(i+0, 0LL)]++; Points.pub(mp(i+0, 0LL));}
		if (!Map[mp(n, m-i)] && m-i >= 0 && m-i <= m) {Map[mp(n, m-i)]++; Points.pub(mp(n, m-i));}
		if (!Map[mp(n-i, m)] && n-i >= 0 && n-i <= n) {Map[mp(n-i, m)]++; Points.pub(mp(n-i, m));}
		if (!Map[mp(n, i+0)] && i+0 >= 0 && i+0 <= m) {Map[mp(n, i+0)]++; Points.pub(mp(n, i+0));}
		if (!Map[mp(n-i, 0LL)] && n-i >= 0 && n-i <= n) {Map[mp(n-i, 0LL)]++; Points.pub(mp(n-i, 0LL));}
		if (!Map[mp(0LL, m-i)] && m-i >= 0 && m-i <= m) {Map[mp(0LL, m-i)]++; Points.pub(mp(0LL, m-i));}
		if (!Map[mp(i+0, m)] && i+0 >= 0 && i+0 <= n) {Map[mp(i+0, m)]++; Points.pub(mp(i+0, m));}
	}
	i64 Token1 = -1, Token2 = -1, Token3 = -1, Token4 = -1;
	ld Dist = 0.0L;
	for (i64 i=0; i<Points.size(); i++) {
		for (i64 j=0; j<Points.size(); j++) {
			if (j == i) continue;
			for (i64 k=0; k<Points.size(); k++) {
				if (k == j || k == i) continue;
				for (i64 l=0; l<Points.size(); l++) {
					if (l == k || l == j || l == i) continue;
					ld NewDist = caldist(Points[i], Points[j], Points[k], Points[l]);
					if (NewDist <= Dist) continue;
					Dist = NewDist;
					Token1 = i; Token2 = j; Token3 = k; Token4 = l;
				}
			}
		}
	}
	cout << Points[Token1].fi << " " << Points[Token1].se << endl;
	cout << Points[Token2].fi << " " << Points[Token2].se << endl;
	cout << Points[Token3].fi << " " << Points[Token3].se << endl;
	cout << Points[Token4].fi << " " << Points[Token4].se << endl;
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



