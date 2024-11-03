










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
string id2 = "FILE.OUT";



typedef pair<pii, pii> ppp;
string s1, s2, virus; i64 n1, n2, nv;
vector<vi> id1;



void ProceedVirus() {
	id1.rsz(nv, vi(26, 0));
	for (i64 i=0; i<nv; i++) {
		for (i64 j=0; j<26; j++) {
			string pref2 = virus.substr(0, i);
			pref2 += char(65 + j);
			for (i64 x=i+1; x>=0; x--) {
				if (pref2.substr(i+1-x, x) == virus.substr(0, x)) {
					id1[i][j] = x; break;
				}
			}
		}
	}
}

void Input() {
	cin >> s1 >> s2 >> virus; nv = virus.size();
	n1 = s1.size(); n2 = s2.size();
}

void Solve() {
	vector<vi> List1(26), List2(26);
	for (i64 i=0; i<n1; i++) List1[s1[i]-'A'].pub(i);
	for (i64 i=0; i<n2; i++) List2[s2[i]-'A'].pub(i);
	ProceedVirus(); ppp Default = mp(mp((i64)-1, (i64)-1), mp((i64)-1, (i64)-1));
	vector<vector<vector<vb>>> dp(n1, vector<vector<vb>>(n2, vector<vb>(min(n1, n2)+1, vb(nv+1, false))));
	vector<vector<vector<vector<ppp>>>> Last(n1, vector<vector<vector<ppp>>>(n2, vector<vector<ppp>>(min(n1, n2)+1, vector<ppp>(nv+1, Default))));
	for (i64 i=0; i<n1; i++) {
		for (i64 j=0; j<n2; j++) {
			if (s1[i] == s2[j]) dp[i][j][1][id1[0][s1[i]-'A']] = true;
			else dp[i][j][0][0] = true;
		}
	}
	for (i64 x=1; x<min(n1, n2); x++) {
		for (i64 i=0; i<n1-1; i++) {
			for (i64 j=0; j<n2-1; j++) {
				for (i64 y=0; y<nv; y++) {
					if (!dp[i][j][x][y]) continue;
					for (i64 z=0; z<26; z++) {
						if (upper_bound(List1[z].begin(), List1[z].end(), i) == List1[z].end()) continue;
						if (upper_bound(List2[z].begin(), List2[z].end(), j) == List2[z].end()) continue;
						i64 i1 = *upper_bound(List1[z].begin(), List1[z].end(), i);
						i64 j1 = *upper_bound(List2[z].begin(), List2[z].end(), j);
						dp[i1][j1][x+1][id1[y][z]] = true;
						Last[i1][j1][x+1][id1[y][z]] = mp(mp(i, j), mp(x, y));
					}
				}
			}
		}
	}
	for (i64 x=min(n1, n2); x>0; x--) {
		for (i64 y=0; y<nv; y++) {
			for (i64 i=0; i<n1; i++) {
				for (i64 j=0; j<n2; j++) {
					if (!dp[i][j][x][y]) continue;
					i64 I = i, J = j, X = x, Y = y;
					string s = "";
					while (I != -1) {
						s.insert(0, 1, s1[I]);
						ppp Token = Last[I][J][X][Y];
						I = Token.fi.fi; J = Token.fi.se;
						X = Token.se.fi; Y = Token.se.se;
					}
					cout << s << endl; return;
				}
			}
		}
	}
	cout << "0\n";
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
	char* outfile = new char[id2.size()+1];
	strcpy(infile, id0.c_str());
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



