








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



i64 n, m, k; vi List; vector<vi> cc;
vector<vector<vi>> Table;



void TableProcess() {
	Table.rsz(m, vector<vi>(n));
	for (i64 x=0; x<m; x++) {
		for (i64 i=0; i<n; i++) Table[x][i].pub(cc[i][x]);
		for (i64 j=1; j<20; j++) {
			for (i64 i=0; i<n; i++) {
				if (Table[x][i].size() < j) continue;
				if (i + (1LL << j) > n) continue;
				if (Table[x][i+(1LL << (j-1))].size() < j) continue;
				Table[x][i].pub(max(Table[x][i][j-1], Table[x][i+(1LL<<(j-1))][j-1]));
			}
		}
	}
}

i64 GetMax(i64 layer, i64 L, i64 R) {
	i64 id = log2(R - L + 1);
	return max(Table[layer][L][id], Table[layer][R-(1LL<<id)+1][id]);
}

bool valid(i64 len, vi &cnt) {
	vector<multiset<i64>> Set(m);
	for (i64 i=0; i<=n-len; i++) {
		i64 shots = 0;
		for (i64 j=0; j<m; j++) {
			cnt[j] = GetMax(j, i, i+len-1);
			shots += cnt[j];
		}
		if (shots <= k) return true;
	}
	return false;
}

void binsearch() {
	i64 top = 1, bot = n, ans = 0;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		vi cnt(m, 0);
		if (valid(mid, cnt)) {
			List = cnt;
			top = mid + 1;
		}
		else bot = mid - 1;
	}
}

void Input() {
	cin >> n >> m >> k;
	cc.rsz(n, vi(m, 0)); List.rsz(m, 0);
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> cc[i][j];
		}
	}
}

void Solve() {
	TableProcess(); binsearch();
	for (auto x: List) cout << x << " ";
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


