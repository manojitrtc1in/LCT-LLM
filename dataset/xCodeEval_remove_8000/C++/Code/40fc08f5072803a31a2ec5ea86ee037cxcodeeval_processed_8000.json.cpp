








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



i64 n; string s; i64 dp[5000][5000];
int Hash[5000][5000]; i64 ps[5000][5000];



i64 cmp(i64 L1, i64 R1, i64 L2, i64 R2) {
	i64 Len = R1 - L1 + 1;
	i64 top = 1, bot = Len, ans = 0;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (Hash[L1][L1+mid-1] == Hash[L2][L2+mid-1]) {
			ans = mid; top = mid + 1;
		}
		else bot = mid - 1;
	}
	if (ans == Len) return 0;
	i64 Diff = s[L1+ans] - s[L2+ans];
	if (Diff < 0) return -1; return +1;
}

void Input() {
	cin >> n >> s;
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		for (i64 j=i; j<n; j++) {
			if (i == j) Hash[i][j] = (s[j] - '0');
			else Hash[i][j] = (Hash[i][j-1] * 11 + (s[j] - '0')) % Mod;
		}
	}
	for (i64 i=0; i<n; i++) {
		if (i == n-1 || s[i+1] != '0') {
			dp[0][i]++;
		}
	}
	ps[0][0] = dp[0][0];
	for (i64 j=1; j<n; j++) {
		for (i64 i=0; i<=j; i++) {
			if (s[i] == '0') continue;
			i64 id2 = i - 1, id0 = i - (j - i + 1) + 1;
			i64 sumdp = 0; if (id2 >= 0) sumdp += ps[id2][i-1];
			if (id0 > 0) sumdp -= ps[id0-1][i-1];
			sumdp %= Mod; while (sumdp < 0) sumdp += Mod;
			dp[i][j] += sumdp; dp[i][j] %= Mod;
			if (id0 > 0) {
				i64 L = id0 - 1, R = i - 1;
				i64 zazz = cmp(L, R, i, j);
				if (zazz == -1) {dp[i][j] += dp[L][R]; dp[i][j] %= Mod;}
			}
		}
		ps[0][j] = dp[0][j];
		for (i64 x=1; x<=j; x++) {ps[x][j] = ps[x-1][j] + dp[x][j]; ps[x][j] %= Mod;}
	}
	cout << ps[n-1][n-1];
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


