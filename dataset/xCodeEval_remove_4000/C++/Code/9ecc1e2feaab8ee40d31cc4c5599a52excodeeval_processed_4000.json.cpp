










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
string id2 = "FILE.OUT";



i64 n, m, k, offset; vector<pii> Points;
vector<vector<vi>> id0;





void Input() {
	cin >> n >> m >> k; Points.rsz(k);
	id0.rsz(2, vector<vi>((n+m)*2+2));
	offset = n + m;
	for (i64 i=0; i<k; i++) {
		i64 x, y; cin >> x >> y;
		Points[i] = {x, y};
		id0[0][x+y+offset].pub(i);
		id0[1][x-y+offset].pub(i);
	}
}

void Solve() {
	vi FirstMet(k, -1); vector<vb> vis(2, vb((n+m)*2+2, false));
	i64 x = 0, y = 0, dx = 1, dy = 1, Time = 0; queue<pii> Q;
	Q.push(mp(1LL, offset+0)); vis[1][offset+0] = true;
	while (!Q.empty()) {
		i64 LineType = Q.front().fi, LineID = Q.front().se; Q.pop();
		for (auto id: id0[LineType][LineID]) {
			if (FirstMet[id] != -1) continue;
			i64 delta = (Points[id].fi - x) / dx;
			FirstMet[id] = Time + delta;
		}
		i64 stepx = 0, stepy = 0;
		if (dx == +1) stepx = n - x; else stepx = x;
		if (dy == +1) stepy = m - y; else stepy = y;
		i64 step = min(stepx, stepy);
		x += step * dx; y += step * dy; Time += step;
		if ((x == n && dx == 1) || (x == 0 && dx == -1)) dx = -dx;
		if ((y == m && dy == 1) || (y == 0 && dy == -1)) dy = -dy;
		LineType = (dx == dy); LineID = 0;
		if (LineType == 1) LineID = x - y + offset;
		else LineID = x + y + offset;
		if (!vis[LineType][LineID]) {
			vis[LineType][LineID] = true;
			Q.push(mp(LineType, LineID));
		}
	}
	for (auto x: FirstMet) cout << x << endl;
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	
	
	

	
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
	char* outfile = new char[id2.size()+1];
	strcpy(infile, id1.c_str());
	strcpy(outfile, id2.c_str());
	
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



