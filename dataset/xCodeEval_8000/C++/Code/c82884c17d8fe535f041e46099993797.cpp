




#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam



#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<i64> vl;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pll;
typedef pair<i64, pll> plp;
typedef pair<pll, i64> ppl;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, int> ppi;
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



int n, m, q; vi p, a; vector<vi> adj;



void DFS(int z, vb &vis, vi &Stack, vector<pii> &Res) {
	vis[z] = true; Stack.pub(z);
	if (Stack.size() >= n) {
		Res.pub({z, Stack[Stack.size() - n]});
	}
	for (auto t: adj[z]) {
		if (vis[t]) continue;
		DFS(t, vis, Stack, Res);
	}
	Stack.pop_back();
}

vector<pii> ProcessDFS() {
	vb vis(m, false); vector<pii> Res;
	for (int i=m-1; i>=0; i--) {
		if (vis[i]) continue;
		vi Stack; DFS(i, vis, Stack, Res);
	}
	return Res;
}

bool rightfirstSort(pii a, pii b) {
	if (a.se != b.se) return (a.se < b.se);
	return (a.fi > b.fi);
}

void refine(vector<pii> &RangeList) {
	sort(RangeList.begin(), RangeList.end(), rightfirstSort);
	vector<pii> NewList;
	int CurLeft = INT_MIN;
	for (auto P: RangeList) {
		if (P.fi <= CurLeft) continue;
		CurLeft = P.fi; NewList.pub(P);
	}
	sort(NewList.begin(), NewList.end());
	RangeList = NewList;
}

void Input() {
	cin >> n >> m >> q; p.rsz(n); a.rsz(m);
	for (auto &z: p) {cin >> z; z--;}
	for (auto &z: a) {cin >> z; z--;}
}

void Solve() {
	adj.rsz(m); vector<vi> ElePos(n); vi Next(n);
	for (int i=0; i<m; i++) ElePos[a[i]].pub(i);
	Next[p[n-1]] = p[0]; for (int i=0; i<n-1; i++) Next[p[i]] = p[i+1];
	for (int i=0; i<m; i++) {
		auto it = upper_bound(ElePos[Next[a[i]]].begin(), ElePos[Next[a[i]]].end(), i);
		if (it == ElePos[Next[a[i]]].end()) continue;
		int j = *it; adj[j].pub(i);
	}
	vector<pii> Ranges = ProcessDFS();
	refine(Ranges);
	while (q--) {
		int L, R; cin >> L >> R; L--; R--;
		if (lower_bound(Ranges.begin(), Ranges.end(), make_pair(L, INT_MIN)) == Ranges.end()) {cout << "0"; continue;}
		int lowestRequired = lower_bound(Ranges.begin(), Ranges.end(), make_pair(L, INT_MIN))->se;
		cout << (lowestRequired <= R);
	}
	cout << endl;
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
		cout << (now->tm_year + 1900) << "-" 
			<< ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << "-"
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


