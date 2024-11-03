
 



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



i64 n; vi a, b; vector<vi> TableMin, TableMax;



void GenerateTable() {
	TableMax.rsz(n); TableMin.rsz(n);
	for (i64 i=0; i<n; i++) {
		TableMax[i].pub(a[i]);
		TableMin[i].pub(b[i]);
	}
	for (i64 j=1; j<18; j++) {
		for (i64 i=0; i<n; i++) {
			if (i + (1 << j) > n) continue;
			TableMax[i].pub(max(TableMax[i][j-1], TableMax[i+(1<<(j-1))][j-1]));
			TableMin[i].pub(min(TableMin[i][j-1], TableMin[i+(1<<(j-1))][j-1]));
		}
	}
}

i64 GetMax(i64 L, i64 R) {
	i64 id = log2(R-L+1);
	return max(TableMax[L][id], TableMax[R+1-(1<<id)][id]);
}

i64 GetMin(i64 L, i64 R) {
	i64 id = log2(R-L+1);
	return min(TableMin[L][id], TableMin[R+1-(1<<id)][id]);
}

i64 binsearch_Min(i64 top, i64 bot) {
	i64 res = bot + 1, R = bot;
	while (top <= bot) {
		i64 L = (top + bot) / 2;
		i64 Mn = GetMin(L, R);
		i64 Mx = GetMax(L, R);
		if (Mx - Mn == 0) res = L;
		if (Mx - Mn <= 0) bot = L - 1;
		else top = L + 1;
	}
	return res;
}

i64 binsearch_Max(i64 top, i64 bot) {
	i64 res = top - 1, R = bot;
	while (top <= bot) {
		i64 L = (top + bot) / 2;
		i64 Mn = GetMin(L, R);
		i64 Mx = GetMax(L, R);
		if (Mx - Mn == 0) res = L;
		if (Mx - Mn < 0) bot = L - 1;
		else top = L + 1;
	}
	return res;
}

void Input() {
	cin >> n; a.rsz(n); b.rsz(n);
	for (auto &z: a) cin >> z;
	for (auto &z: b) cin >> z;
}

void Solve() {
	GenerateTable();
	long long ans = 0;
	for (i64 i=0; i<n; i++) {
		i64 MinIndex = binsearch_Min(0, i);
		i64 MaxIndex = binsearch_Max(0, i);
		ans += max(0, MaxIndex-MinIndex+1);
	}
	cout << ans << endl;
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


