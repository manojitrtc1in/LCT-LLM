
 



#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam



#define endl '\n'
#define i64 int
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
long long keymod[] = {2100003221LL, 1000000009LL, 1000000021LL, 1000000033LL};
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



i64 m; vi p; vector<vi> dpOld, dpNew;
i64 TriePos[3000][3000];
i64 TrieSize = 3; vector<vi> adj(3, vi(2, -1));



void Input() {
	cin >> m; p.rsz(m); adj[0][1] = 1; adj[0][2] = 2;
	for (i64 i=0; i<m; i++) cin >> p[i];
	for (i64 i=0; i<m; i++) TriePos[i][i] = p[i] + 1;
}

void Solve() {
	i64 ans = 0; vb vis(2, false);
	dpOld.rsz(m, vi(4, 0)); dpNew.rsz(m, vi(4, 0));
	for (i64 i=0; i<m; i++) {
		if (i == 0) {
			dpNew[i][0] = 1; ans = 1; cout << ans << endl; vis[p[i]] = true;
			dpOld = dpNew; dpNew.clear(); dpNew.rsz(m, vi(4, 0)); continue;
		}
		for (i64 d=0; d<i; d++) {
			for (i64 x=0; x<4; x++) {
				if (x == 0) {dpNew[d][0] = (0LL + dpOld[d][0] + dpOld[d][1] + dpOld[d][2] + dpOld[d][3]) % Mod; continue;}
				if (x < 3) {dpNew[d][x] = dpOld[d][x-1]; continue;}
				if (i < 3) continue;
				if (p[i-3] == 0 && p[i-2] == 0 && p[i-1] == 1 && p[i-0] == 1) continue;
				if (p[i-3] == 0 && p[i-2] == 1 && p[i-1] == 0 && p[i-0] == 1) continue;
				if (p[i-3] == 1 && p[i-2] == 1 && p[i-1] == 1 && p[i-0] == 0) continue;
				if (p[i-3] == 1 && p[i-2] == 1 && p[i-1] == 1 && p[i-0] == 1) continue;
				dpNew[d][x] = dpOld[d][x-1];
			}
			if (adj[TriePos[d][i-1]][p[i]] != -1) {TriePos[d][i] = adj[TriePos[d][i-1]][p[i]]; continue;}
			ans = (0LL + ans + dpNew[d][0] + dpNew[d][1] + dpNew[d][2] + dpNew[d][3]) % Mod;
			adj[TriePos[d][i-1]][p[i]] = TrieSize;
			TriePos[d][i] = TrieSize; adj.pub(vi(2, -1)); TrieSize += 1;
		}
		dpNew[i][0] = 1;
		if (!vis[p[i]]) {
			vis[p[i]] = true;
			ans++; ans %= Mod;
		}
		cout << ans << endl;
		dpOld = dpNew; dpNew.clear(); dpNew.rsz(m, vi(4, 0));
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


