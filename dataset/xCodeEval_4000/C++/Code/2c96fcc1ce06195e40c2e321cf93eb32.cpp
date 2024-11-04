




#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
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
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978
#define MultiTest 227420978
#define Interactive 227420978

#undef OImode 

#undef MultiTest 

#undef Interactive 


void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
string cppstr_infile = "FILE.IN";
string cppstr_outfile = "FILE.OUT";



i64 n, m; vector<vc> A; map<char, int> Map; vc IMap(4);
i64 MinDiff = LINF; vector<vc> OptimalTable;



i64 Differs(vector<vc> &Table1, vector<vc> &Table2) {
	i64 res = 0;
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			res += (Table1[i][j] != Table2[i][j]);
		}
	}
	return res;
}

void Input() {
	cin >> n >> m; A.rsz(n, vc(m));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> A[i][j];
		}
	}
	Map['A'] = 0; Map['T'] = 1;
	Map['G'] = 2; Map['C'] = 3;
	IMap[0] = 'A'; IMap[1] = 'T';
	IMap[2] = 'G'; IMap[3] = 'C';
}

void Solve() {
	for (i64 i=0; i<4; i++) {
		for (i64 j=0; j<4; j++) {
			if (j == i) continue;
			for (i64 k=0; k<4; k++) {
				if (k == i) continue;
				if (k == j) continue;
				for (i64 l=0; l<4; l++) {
					if (l == i) continue;
					if (l == j) continue;
					if (l == k) continue;
					vs pattern(2, "");
					pattern[0] += IMap[i]; pattern[0] += IMap[j];
					pattern[1] += IMap[k]; pattern[1] += IMap[l];
					vector<vc> Sample(n, vc(m));
					for (i64 i=0; i<n; i++) {
						vi subdiff(2, 0);
						for (i64 j=0; j<m; j++) {
							subdiff[0] += (pattern[i % 2][j % 2] != A[i][j]);
							subdiff[1] += (pattern[i % 2][1 - j % 2] != A[i][j]);
						}
						if (subdiff[0] <= subdiff[1]) for (i64 j=0; j<m; j++) Sample[i][j] = pattern[i % 2][j % 2];
						else for (i64 j=0; j<m; j++) Sample[i][j] = pattern[i % 2][1 - j % 2];
					}
					i64 Diff = Differs(Sample, A);
					if (Diff < MinDiff) {MinDiff = Diff; OptimalTable = Sample;}
				}
			}
		}
	}
	
	for (i64 i=0; i<4; i++) {
		for (i64 j=0; j<4; j++) {
			if (j == i) continue;
			for (i64 k=0; k<4; k++) {
				if (k == i) continue;
				if (k == j) continue;
				for (i64 l=0; l<4; l++) {
					if (l == i) continue;
					if (l == j) continue;
					if (l == k) continue;
					vs pattern(2, "");
					pattern[0] += IMap[i]; pattern[0] += IMap[j];
					pattern[1] += IMap[k]; pattern[1] += IMap[l];
					vector<vc> Sample(n, vc(m));
					for (i64 j=0; j<m; j++) {
						vi subdiff(2, 0);
						for (i64 i=0; i<n; i++) {
							subdiff[0] += (pattern[j % 2][i % 2] != A[i][j]);
							subdiff[1] += (pattern[j % 2][1 - i % 2] != A[i][j]);
						}
						if (subdiff[0] <= subdiff[1]) for (i64 i=0; i<n; i++) Sample[i][j] = pattern[j % 2][i % 2];
						else for (i64 i=0; i<n; i++) Sample[i][j] = pattern[j % 2][1 - i % 2];
					}
					i64 Diff = Differs(Sample, A);
					if (Diff < MinDiff) {MinDiff = Diff; OptimalTable = Sample;}
				}
			}
		}
	}
	
	for (auto Row: OptimalTable) {
		for (auto Cell: Row) cout << Cell;
		cout << endl;
	}
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	
	#ifndef Interactive
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	#else
	ios_base::sync_with_stdio(0);
	#endif
	
	#ifndef MultiTest
	Input(); TimerStart();
	Solve(); TimerStop();
	#else
	int T; cin >> T; TimerStart();
	while(T--) {Input(); Solve();}
	TimerStop();
	#endif
	
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	char* infile = new char[cppstr_infile.size()+1];
	char* outfile = new char[cppstr_outfile.size()+1];
	strcpy(infile, cppstr_infile.c_str());
	strcpy(outfile, cppstr_outfile.c_str());
	#ifdef Akikaze
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by #Team4T-Akikaze.\n";
	cout << "Current time: ";
	cout << (now->tm_year + 1900) << '-' 
	<< ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
	<< ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
	<< ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
	<< ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
	<< ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
	<< "\n\n";
	
	#ifdef OImode
	cout << "OI-Mode: ON\n";
	cout << "Input file: " << infile << endl;
	cout << "Output file: " << outfile << endl;
	cout << "\n";
	#else
	cout << "OI-Mode: OFF\n";
	cout << "Input file: NULL\n";
	cout << "Output file: NULL\n";
	cout << "\n";
	#endif
	
	#ifdef MultiTest
	cout << "MultiTest-Mode: ON\n";
	#else
	cout << "MultiTest-Mode: OFF\n";
	#endif
	
	#ifdef Interactive
	cout << "Interactive-Mode: ON\n\n";
	#else
	cout << "Interactive-Mode: OFF\n\n";
	#endif
	
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Akikaze
	TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Akikaze
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}



